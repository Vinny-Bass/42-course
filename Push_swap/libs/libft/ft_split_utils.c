/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:32:12 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/02/20 20:32:14 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**create_result(int words)
{
	char	**result;

	result = malloc((words + 2) * sizeof(char *));
	if (!result)
		return (NULL);
	result[0] = (NULL);
	return (result);
}
