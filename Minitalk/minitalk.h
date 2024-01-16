#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft/libft.h" 
# include "ft_printf/ft_printf.h"

typedef struct s_message {
    char                c;
    struct s_message    *next;
}   t_message;

#endif