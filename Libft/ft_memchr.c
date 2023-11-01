/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:12:12 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/10/31 14:12:13 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	char				*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if ((int)str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
