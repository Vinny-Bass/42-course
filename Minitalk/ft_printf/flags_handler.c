/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:34:12 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/12/17 22:34:13 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_flag(const char c)
{
	if (c == '-' || c == '0' || c == ' ')
		return (1);
	if (c == '#' || c == '+' || c == '.')
		return (1);
	if (ft_isdigit(c))
		return (1);
	return (0);
}

static void	init_flags(t_format_flags *flags)
{
	flags->left_align = 0;
	flags->zero_pad = 0;
	flags->space = 0;
	flags->hashtag = 0;
	flags->plus = 0;
	flags->dot = 0;
	flags->width = 0;
	flags->precision = 0;
}

static int	handle_float(t_format_flags *flags, int i, const char *str)
{
	flags->dot = 1;
	i++;
	while (ft_isdigit(str[i]))
	{
		flags->precision = flags->precision * 10 + (str[i] - '0');
		i++;
	}
	return (i);
}

static void	handle_common_flags(t_format_flags *flags, const char *str, int i)
{
	if (str[i] == '-')
	{
		flags->left_align = 1;
		flags->zero_pad = 0;
	}
	if (str[i] == ' ')
		flags->space = 1;
	if (str[i] == '#')
		flags->hashtag = 1;
	if (str[i] == '+')
		flags->plus = 1;
}

int	assign_flags(const char *str, int i, t_format_flags *flags)
{
	init_flags(flags);
	while (is_flag(str[i]))
	{
		handle_common_flags(flags, str, i);
		if (str[i] == '.')
		{
			flags->zero_pad = 0;
			i = handle_float(flags, i, str);
			continue ;
		}
		if (str[i] == '0' && !flags->left_align)
			if (!flags->width && !flags->dot && str[i + 1] != '.')
				flags->zero_pad = 1;
		if (ft_isdigit(str[i]))
			flags->width = flags->width * 10 + (str[i] - '0');
		i++;
	}
	return (i);
}
