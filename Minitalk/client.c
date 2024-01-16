#include "minitalk.h"

int has_response = 0;

static void handle_signal(int signal)
{
    if (signal == SIGUSR1)
        has_response = 1;
    else if (signal == SIGUSR2)
    {
        ft_printf("The message was sent to the server");
        exit(EXIT_SUCCESS);
    }
}

static void send_char(int pid, unsigned char c)
{
    int bit_index;
    unsigned char bit_mask;

    bit_index = 7;
    bit_mask = 1u << bit_index;
    while (bit_mask)
    {
        has_response = 0;
        if (bit_mask & c)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        if (!has_response)
            pause();
        bit_index--;
        bit_mask >>= 1;
    }
}

static void handle_msg(int pid, char *msg)
{
    int i;

    i = 0;
    while (msg[i])
    {
        send_char(pid, msg[i]);
        i++;
    }
    send_char(pid, 0);
}

int main(int argc, char **argv)
{
    struct sigaction sa;
    pid_t pid;

    if (argc != 3)
    {
        ft_printf("Process ID or message is missing\n");
        exit(EXIT_FAILURE);
    }
    pid = ft_atoi(argv[1]);
    if (!pid)
    {
        ft_printf("The PID: %d is invalid", pid);
        exit(EXIT_FAILURE);
    }
    if (kill(pid, 0) < 0)
    {
        ft_printf("Process ID: %d do not exists",pid);
        exit(EXIT_FAILURE);
    }
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR2, &sa, NULL);
    sigaction(SIGUSR1, &sa, NULL);
    handle_msg(pid, argv[2]);

    return (0);
}