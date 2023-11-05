/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:26:22 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/11/04 20:26:24 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_begin(char const *s1, char c)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (s1[i] != '\0' && s1[i] == c)
	{
		total++;
		i++;
	}
	return (total);
}

static int	count_end(char const *s1, char c)
{
	int		total;
	int		s1_len;

	total = 0;
	s1_len = ft_strlen(s1);
	while (s1_len > 0 && s1[s1_len - 1] == c)
	{
		--s1_len;
		total++;
	}
	return (total);
}

static int	calc_size(char const *s1, char const *set)
{
	int		begin_total;
	int		end_total;
	int		i;

	begin_total = 0;
	end_total = 0;
	i = 0;
	while (set[i] != '\0')
	{
		begin_total += count_begin(s1, set[i]);
		end_total += count_end(s1, set[i]);
		i++;
	}
	return ((ft_strlen(s1)) - (begin_total + end_total));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		i;
	int		size;
	int		j;

	size = calc_size(s1, set);
	result = malloc(size);
	if (result == NULL)
		return (NULL);
	i = count_begin(s1, set[0]);
	j = 0;
	while (s1[i] != '\0' && j < size)
	{
		result[j] = s1[i];
		i++;
		j++;
	}
	return (result);
}
