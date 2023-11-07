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
#include <stdio.h>

static int	count_occ(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((char)s[i] == c)
			count++;
		i++;
	}
	return (count);
}

static void	init_controllers(int *i, int *begin, int *word, int *controller)
{
	*i = 0;
	*begin = 0;
	*word = 0;
	*controller = 0;
}

static void	handle_controllers(char **r, int *word, int *c, int *begin)
{
	r[*word][*c + 1] = '\0';
	*word += 1;
	*begin += 1;
	*c = 0;
}

static void	insert_words(char *s, char c, char **result)
{
	int	i;
	int	begin;
	int	word;
	int	controller;

	init_controllers(&i, &begin, &word, &controller);
	while (s[i])
	{
		if ((char)s[i] == c || !s[i + 1])
		{
			if (!s[i + 1])
				i++;
			result[word] = malloc((i - begin) + 1);
			while (begin < i)
			{
				result[word][controller] = s[begin];
				begin++;
				controller++;
			}
			handle_controllers(result, &word, &controller, &begin);
		}
		i++;
	}
	result[word] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	*trim_s;
	char	**result;

	trim_s = ft_strtrim(s, &c);
	result = malloc((count_occ(trim_s, c) + 2) * sizeof (char *));
	if (!result)
	{
		free(trim_s);
		return (NULL);
	}
	insert_words(trim_s, c, result);
	free(trim_s);
	return (result);
}
