/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:50:09 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/10/30 19:50:10 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *to, const void *from, size_t numBytes)
{
	char	*src_char;
	char	*dest_char;

	src_char = (char *)from;
	dest_char = (char *)to;
	if (dest_char != NULL && src_char != NULL)
	{
		while (numBytes)
		{
			*(dest_char++) = *(src_char++);
			--numBytes;
		}
	}
	return (to);
}
