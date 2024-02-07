/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:02:18 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/12/17 21:02:19 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_text(char *arg, t_format_flags flags, int len, int total_len)
{
	if (!flags.left_align && flags.width && flags.width > len)
	{
		total_len += fill_width(flags, flags.width - len);
		ft_putnstr_fd(arg, STD_OUT, len);
	}
	else if (flags.left_align && flags.width && flags.width > len)
	{
		ft_putnstr_fd(arg, STD_OUT, len);
		total_len += fill_width(flags, flags.width - len);
	}
	else
		ft_putnstr_fd(arg, STD_OUT, len);
	return (total_len);
}

static int	str_flags(t_format_flags flags, int len, unsigned long long ptr)
{
	int	total_len;

	total_len = len;
	if (!flags.left_align && flags.width && flags.width > len)
	{
		total_len += fill_width(flags, flags.width - len);
		write(STD_OUT, "0x", 2);
		write_hex(ptr, 0);
	}
	else if (flags.left_align && flags.width && flags.width > len)
	{
		write(STD_OUT, "0x", 2);
		write_hex(ptr, 0);
		total_len += fill_width(flags, flags.width - len);
	}
	else
	{
		write(STD_OUT, "0x", 2);
		write_hex(ptr, 0);
	}
	return (total_len);
}

int	handle_char(va_list *args, t_format_flags flags)
{
	char	arg;
	int		total_len;

	arg = va_arg(*args, int);
	total_len = 1;
	if (!flags.left_align && flags.width && flags.width > 1)
	{
		total_len += fill_width(flags, flags.width - 1);
		ft_putchar_fd(arg, STD_OUT);
	}
	else if (flags.left_align && flags.width && flags.width > 1)
	{
		ft_putchar_fd(arg, STD_OUT);
		total_len += fill_width(flags, flags.width - 1);
	}
	else
		ft_putchar_fd(arg, STD_OUT);
	return (total_len);
}

int	handle_str(va_list *args, t_format_flags flags)
{
	char	*arg;
	int		len;
	int		total_len;

	arg = va_arg(*args, char *);
	if (!arg && (!flags.precision || flags.precision > 5))
		arg = "(null)";
	else if (!arg)
		return (0);
	len = ft_strlen(arg);
	len = get_str_precision_limiter(flags, len);
	total_len = len;
	total_len = write_text(arg, flags, len, total_len);
	return (total_len);
}

int	handle_pointer(va_list *args, t_format_flags flags)
{
	int					len;
	int					total_len;
	unsigned long long	ptr;

	ptr = va_arg(*args, unsigned long long);
	if (ptr == 0)
		total_len = write_text("(nil)", flags, 5, 5);
	else
	{
		len = get_ptr_len(ptr) + 2;
		total_len = len;
		total_len = str_flags(flags, len, ptr);
	}
	return (total_len);
}
