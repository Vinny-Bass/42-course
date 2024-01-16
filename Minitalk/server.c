#include "minitalk.h"

static void is_process_running(pid_t pid)
{
    if (kill(pid, 0) < 0)
    {
        ft_printf("The process %d is not running anymore", pid);
        exit(EXIT_FAILURE);
    }
}

static void handle_signal(int signal, siginfo_t *info, void *ucontext)
{
    (void)ucontext;
    static int bitCount = -1;
    static unsigned char c;

    is_process_running(info->si_pid);
    if (bitCount < 0)
        bitCount = 7;
    if (signal == SIGUSR1)
        c |= (1 << bitCount);
    bitCount--;
    if (bitCount < 0 && c)
    {
        ft_putchar_fd(c, STD_OUT);
        c = 0;
    }
    else if (bitCount < 0 && !c)
    {
        kill(info->si_pid, SIGUSR2);
        ft_printf("\nIncoming message: ");
    }
        
    kill(info->si_pid, SIGUSR1);
}

int main(void)
{
    int             pid;
    struct sigaction sa;

    pid = getpid();
    ft_printf("PID: %d\n", pid);
    ft_printf("Incoming message: ");

    sa.sa_flags = SA_SIGINFO | SA_RESTART;
    sa.sa_sigaction = handle_signal;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_printf("Not possible to configure an handler to the signals");
        exit(EXIT_FAILURE);
    }

    while (1)
        sleep(1);

    return (0);
}