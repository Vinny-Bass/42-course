/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:42:56 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/11/01 20:42:57 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	minus_count;
	int	result;

	i = 0;
	minus_count = 0;
	result = 0;
	while (str[i] != '\0' && !result)
	{
		if (str[i] == '-')
			minus_count++;
		if (ft_isdigit(str[i]))
		{
			while (str[i] != '\0' && ft_isdigit(str[i]))
			{
				result *= 10;
				result += str[i] - 48;
				i++;
			}
		}
		i++;
	}
	if (minus_count % 2 == 0)
		return (result);
	return (result *= -1);
}
