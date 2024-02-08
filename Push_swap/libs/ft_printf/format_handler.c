/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:06:39 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/12/17 21:06:40 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_percent(void)
{
	char	a;

	a = 37;
	write(1, &a, 1);
	return (1);
}

int	handle_format(const char format, va_list *args, t_format_flags flags)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += handle_char(args, flags);
	else if (format == 's')
		count += handle_str(args, flags);
	else if (format == 'p')
		count += handle_pointer(args, flags);
	else if (format == 'd' || format == 'i')
		count += handle_digit(args, flags);
	else if (format == 'u')
		count += handle_unsigned_digit(args, flags);
	else if (format == 'x')
		count += handle_digit_hex(args, 0, flags);
	else if (format == 'X')
		count += handle_digit_hex(args, 1, flags);
	else if (format == '%')
		count += handle_percent();
	return (count);
}
