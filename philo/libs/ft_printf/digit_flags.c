/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:09:07 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/12/24 19:09:08 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_digit_flags(t_format_flags flags, int digit, int w_len, int p_len)
{
	int		total_len;
	char	*to_write;

	total_len = 0;
	to_write = get_to_write(digit);
	if (!flags.left_align)
	{
		total_len += fill_digit_width((digit < 0), flags, w_len);
		total_len += fill_digit_precision((digit < 0), flags, p_len);
		ft_putnstr_fd(to_write, STD_OUT, get_digit_len(flags, to_write));
	}
	else
	{
		total_len += fill_digit_precision((digit < 0), flags, p_len);
		ft_putnstr_fd(to_write, STD_OUT, get_digit_len(flags, to_write));
		total_len += fill_digit_width((digit < 0), flags, w_len);
	}
	free(to_write);
	return (total_len);
}

int	handle_unsigned_digit_flags(t_format_flags f, int w_len, int p_len, char *s)
{
	int	total_len;

	total_len = 0;
	if (!f.left_align)
	{
		total_len += fill_digit_width(0, f, w_len);
		total_len += fill_digit_precision(0, f, p_len);
		ft_putnstr_fd(s, STD_OUT, get_digit_len(f, s));
	}
	else
	{
		total_len += fill_digit_precision(0, f, p_len);
		ft_putnstr_fd(s, STD_OUT, get_digit_len(f, s));
		total_len += fill_digit_width(0, f, w_len);
	}
	free(s);
	return (total_len);
}

int	handle_space_plus_flags(t_format_flags flags, int digit)
{
	int	count;

	count = 0;
	if (digit >= 0)
	{
		if (flags.space)
			ft_putchar_fd(' ', STD_OUT);
		if (flags.plus)
			ft_putchar_fd('+', STD_OUT);
		if (flags.space || flags.plus)
			count++;
	}
	return (count);
}

int	handle_hex_hashtag_flag(t_format_flags flags, long digit, int upper)
{
	int	counter;

	counter = 0;
	if (flags.hashtag && digit != 0 && digit <= LONG_MAX && digit > LONG_MIN)
	{
		counter += 2;
		if (upper)
			ft_putstr_fd("0X", STD_OUT);
		else
			ft_putstr_fd("0x", STD_OUT);
	}
	return (counter);
}
