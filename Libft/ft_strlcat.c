/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:54:36 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/10/30 21:54:39 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *to_concat, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	to_concat_len;

	dest_len = 0;
	to_concat_len = ft_strlen(to_concat);
	i = 0;
	while (dest[dest_len] != '\0' && dest_len < size)
		dest_len++;
	
	if (size <= dest_len)
		return (to_concat_len + size);
	while (to_concat[i] != '\0' && (dest_len + i) < (size - 1))
	{
		dest[dest_len + i] = to_concat[i];
		i++;
	}
	if (dest_len + i < size)
    {
        dest[dest_len + i] = '\0';
    }

	return (dest_len + to_concat_len);
}
