/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:16:36 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/02/02 21:16:38 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_line(t_state *s, char **l_tmp, int *l_len, char *m_tmp)
{
	int	current_len;

	if (*l_tmp != NULL)
	{
		current_len = ft_strlen(*l_tmp) - ft_strchr(*l_tmp, '\n');
		if (s->map.rows > 0 && *l_len != current_len)
		{
			free(m_tmp);
			free(*l_tmp);
			game_error(s, "The map is not in rectangular shape");
		}
		*l_len = current_len;
	}
}

void	append_line_to_map(char **map_tmp, char *line_tmp)
{
	char	*new_map_tmp;

	new_map_tmp = ft_strjoin(*map_tmp, line_tmp);
	free(*map_tmp);
	*map_tmp = new_map_tmp;
}
