/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:48:58 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/12/18 16:48:59 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef STD_OUT
#  define STD_OUT 1
# endif

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct format_flags
{
	int	left_align;
	int	zero_pad;
	int	space;
	int	width;
	int	hashtag;
	int	plus;
	int	dot;
	int	precision;
}	t_format_flags;

int		ft_printf(const char *str, ...);
int		assign_flags(const char *str, int i, t_format_flags *flags);
int		handle_format(const char c, va_list *args, t_format_flags flags);
int		handle_char(va_list *args, t_format_flags flags);
int		handle_str(va_list *args, t_format_flags flags);
int		handle_pointer(va_list *args, t_format_flags flags);
int		handle_digit(va_list *args, t_format_flags flags);
void	write_hex(uintptr_t n, int upper);
int		get_ptr_len(uintptr_t n);
int		handle_digit_hex(va_list *args, int upper, t_format_flags flags);
int		handle_unsigned_digit(va_list *args, t_format_flags flags);
char	*get_to_write(int digit);
int		fill_width(t_format_flags flags, int n_printed);
int		get_digit_len(t_format_flags flags, char *to_write);
int		get_digit_width(t_format_flags f, int is_negative, int p_len, char *s);
int		get_digit_precision(t_format_flags flags, int len);
int		fill_digit_width(int is_negative, t_format_flags f, int width_to_fill);
int		fill_digit_precision(int is_negative, t_format_flags f, int p_to_fill);
int		handle_digit_flags(t_format_flags f, int d, int width, int precision);
int		handle_unsigned_digit_flags(t_format_flags f, int w, int p, char *s);
int		handle_space_plus_flags(t_format_flags flags, int digit);
int		handle_hex_hashtag_flag(t_format_flags flags, long digit, int upper);
int		get_str_precision_limiter(t_format_flags flags, int str_len);
#endif
