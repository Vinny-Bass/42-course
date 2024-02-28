/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:04:37 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/12/17 21:04:38 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list			args;
	t_format_flags	flags;
	int				i;
	int				counter;

	if (!str || *str == '\0')
		return (0);
	va_start(args, str);
	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], STD_OUT);
			i++;
			counter++;
			continue ;
		}
		i = assign_flags(str, ++i, &flags);
		counter += handle_format(str[i], &args, flags);
		i++;
	}
	va_end(args);
	return (counter);
}
