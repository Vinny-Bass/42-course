/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:53:11 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/11/01 21:53:12 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*solve(char *str, char *to_find, size_t size)
{
	size_t	j;
	size_t	i;
	size_t found;

	i = 0;
	while (str[i] && i < size)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			found = i;
			while (str[i+j] && to_find[j] && i+j < size && str[i+j] == to_find[j])
				j++;
			if (!to_find[j])
				return (&str[found]);
		}
	}
	return (NULL);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	if (to_find[0] == '\0')
		return ((char *)str);
	return (solve((char *)str, (char *)to_find, size));
}
