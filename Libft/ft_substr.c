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

	if (s == NULL || len == 0 || start > ft_strlen(s))
		return (NULL);
	result = malloc(sizeof (char) * len);
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
	return (result);
}
