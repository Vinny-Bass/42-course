/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:24:41 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/10/30 19:24:43 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*destiny;

	destiny = str;
	while (n > 0)
	{
		*destiny = '\0';
		destiny++;
		n--;
	}
	return ;
}
