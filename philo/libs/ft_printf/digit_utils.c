/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:58:54 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/12/24 18:58:55 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_digit_len(t_format_flags flags, char *to_write)
{
	int	len;

	if (to_write[0] == '0' && flags.dot && flags.precision == 0)
		len = 0;
	else
		len = ft_strlen(to_write);
	return (len);
}

int	get_digit_width(t_format_flags flags, int is_negative, int p_len, char *s)
{
	int	width;
	int	len;

	width = 0;
	len = get_digit_len(flags, s);
	if (flags.width > len)
	{
		width = flags.width - (p_len + len);
		if (is_negative)
			width--;
	}
	return (width);
}

int	get_digit_precision(t_format_flags flags, int len)
{
	int	precision;

	precision = 0;
	if (flags.precision > len)
		precision = flags.precision - len;
	return (precision);
}

int	fill_digit_width(int is_negative, t_format_flags flags, int width_to_fill)
{
	int	i;
	int	count;

	if (is_negative && flags.width && flags.zero_pad)
		ft_putchar_fd('-', STD_OUT);
	i = 0;
	count = 0;
	while (i < width_to_fill)
	{
		if (flags.zero_pad)
			ft_putchar_fd('0', STD_OUT);
		else
			ft_putchar_fd(' ', STD_OUT);
		i++;
		count++;
	}
	return (count);
}

int	fill_digit_precision(int is_negative, t_format_flags flags, int p_len)
{
	int	i;
	int	count;

	if (is_negative && (!flags.width || !flags.zero_pad))
		ft_putchar_fd('-', STD_OUT);
	i = 0;
	count = 0;
	while (i < p_len)
	{
		ft_putchar_fd('0', STD_OUT);
		i++;
		count++;
	}
	return (count);
}
