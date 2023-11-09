/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:52:51 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/11/04 18:52:52 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	i;
	unsigned int	j;

	if (len > ft_strlen(s) && ft_strlen(s) > start)
		result = malloc((ft_strlen(s) - start) + 1);
	else if (ft_strlen(s) < start)
		result = malloc(ft_strlen(s));
	else
		result = malloc(len + 1);
	if (result == 0)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < len)
	{
		result[j] = s[i];
		j++;
		i++;
	}
	result[j] = '\0';
	return (result);
}
