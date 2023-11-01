/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:09:16 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/10/30 20:09:17 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>  

void	*ft_memmove(void *to, const void *from, size_t numBytes)
{
	char			*src_char;
	char			*dest_char;
	char			*tmp;
	unsigned int	i;

	src_char = (char *)from;
	dest_char = (char *)to;
	tmp = (char *)malloc(sizeof(char) * numBytes);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (i < numBytes)
	{
		*(tmp + i) = *(src_char + i);
		i++;
	}
	i = 0;
	while (i < numBytes)
	{
		*(dest_char + i) = *(tmp + i);
		i++;
	}
	return (to);
}
