/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:17:10 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/11/05 18:17:20 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

void	init_controllers(int *word_index, int *start, int *end)
{
	*word_index = 0;
	*start = 0;
	*end = 0;
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**result;
	int		word_index;
	int		start;
	int		end;

	words = word_count(s, c);
	init_controllers(&word_index, &start, &end);
	if (!s)
		return (NULL);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (s[end])
	{
		if (s[end] != c && (end == 0 || s[end - 1] == c))
			start = end;
		if (s[end] == c && (end > 0 && s[end - 1] != c))
			result[word_index++] = strndup(s + start, end - start);
		end++;
	}
	if (s[end - 1] != c)
		result[word_index++] = strndup(s + start, end - start);
	result[words] = (NULL);
	return (result);
}
