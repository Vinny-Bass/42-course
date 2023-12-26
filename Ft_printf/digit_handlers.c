/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:44:49 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/12/18 15:44:50 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_digit(va_list *args, t_format_flags flags)
{
	int		digit;
	int		total_len;
	int		p_len;
	int		width_to_fill;
	char	*to_write;

	digit = va_arg(*args, int);
	if (flags.dot && !flags.precision && !flags.width && digit == 0)
		return (0);
	to_write = get_to_write(digit);
	if (!to_write)
		return (0);
	total_len = get_digit_len(flags, to_write);
	p_len = get_digit_precision(flags, total_len);
	width_to_fill = get_digit_width(flags, digit < 0, p_len, to_write);
	total_len += handle_space_plus_flags(flags, digit);
	total_len += handle_digit_flags(flags, digit, width_to_fill, p_len);
	if (digit < 0)
		total_len++;
	free(to_write);
	return (total_len);
}

int	handle_unsigned_digit(va_list *args, t_format_flags flags)
{
	unsigned int	digit;
	int				total_len;
	int				p_len;
	int				w_len;
	char			*to_write;

	digit = va_arg(*args, unsigned int);
	if (flags.dot && !flags.precision && !flags.width && digit == 0)
		return (0);
	to_write = ft_uitoa(digit);
	if (!to_write)
		return (0);
	total_len = get_digit_len(flags, to_write);
	p_len = get_digit_precision(flags, total_len);
	w_len = get_digit_width(flags, 0, p_len, to_write);
	total_len += handle_unsigned_digit_flags(flags, w_len, p_len, to_write);
	return (total_len);
}

static void	build_hex_string(unsigned int n, char *str, int *index, int upper)
{
	if (n >= 16)
	{
		build_hex_string(n / 16, str, index, upper);
		n %= 16;
	}
	if (n <= 9)
		str[(*index)++] = n + '0';
	else if (upper)
		str[(*index)++] = 'A' + (n - 10);
	else
		str[(*index)++] = 'a' + (n - 10);
}

static char	*get_to_write_hex(unsigned int n, int upper)
{
	int		len;
	char	*hex_str;
	int		index;

	if (n == 0)
		len = 1;
	else
		len = get_ptr_len(n);
	hex_str = malloc(len + 1);
	if (hex_str == NULL)
		return (NULL);
	index = 0;
	build_hex_string(n, hex_str, &index, upper);
	hex_str[index] = '\0';
	return (hex_str);
}

int	handle_digit_hex(va_list *args, int upper, t_format_flags flags)
{
	unsigned int	digit;
	char			*to_write;
	int				total_len;
	int				p_len;
	int				w_len;

	digit = va_arg(*args, unsigned int);
	if (flags.dot && !flags.precision && !flags.width && digit == 0)
		return (0);
	to_write = get_to_write_hex(digit, upper);
	if (!to_write)
		return (0);
	total_len = get_digit_len(flags, to_write);
	p_len = get_digit_precision(flags, total_len);
	w_len = get_digit_width(flags, 0, p_len, to_write);
	total_len += handle_hex_hashtag_flag(flags, digit, upper);
	total_len += handle_unsigned_digit_flags(flags, w_len, p_len, to_write);
	return (total_len);
}
