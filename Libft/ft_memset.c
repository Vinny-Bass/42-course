/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:12:54 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/10/30 19:12:56 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*destiny;

	destiny = str;
	while (n > 0)
	{
		*destiny = (unsigned char) c;
		destiny++;
		n--;
	}
	return (str);
}
