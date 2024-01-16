/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:58:25 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/12/17 20:58:26 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	get_ptr_len(uintptr_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	write_hex(uintptr_t n, int upper)
{
	if (n >= 16)
	{
		write_hex(n / 16, upper);
		write_hex(n % 16, upper);
	}
	else if (n <= 9)
	{
		if (upper)
			ft_putchar_fd(ft_toupper((n + '0')), STD_OUT);
		else
			ft_putchar_fd((n + '0'), STD_OUT);
	}
	else
	{
		if (upper)
			ft_putchar_fd(ft_toupper((n - 10 + 'a')), STD_OUT);
		else
			ft_putchar_fd((n - 10 + 'a'), STD_OUT);
	}
}

int	fill_width(t_format_flags flags, int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		if (!flags.zero_pad)
			ft_putchar_fd(' ', STD_OUT);
		else
			ft_putchar_fd('0', STD_OUT);
		count++;
		n--;
	}
	return (count);
}

char	*get_to_write(int digit)
{
	char	*to_write;

	if (digit < 0)
	{
		if (digit <= INT_MIN)
			to_write = ft_strdup("2147483648");
		else
		{
			digit *= -1;
			to_write = ft_itoa(digit);
		}
	}
	else
		to_write = ft_itoa(digit);
	return (to_write);
}

int	get_str_precision_limiter(t_format_flags flags, int str_len)
{
	if (flags.dot && !flags.precision)
		return (0);
	if (flags.dot && flags.precision > 0 && flags.precision < str_len)
		return (flags.precision);
	return (str_len);
}
