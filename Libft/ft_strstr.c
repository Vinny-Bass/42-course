/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:30:09 by vsouza-v          #+#    #+#             */
/*   Updated: 2023/10/31 14:30:11 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*solve(char *str, char *to_find, int i, int controler)
{
	int	j;
	int	diff;

	while (str[i] != '\0')
	{
		j = 0;
		diff = 0;
		if (str[i] == to_find[j])
		{
			controler = i + 1;
			j++;
			while (to_find[j] != '\0' && !diff)
			{
				if (to_find[j] != str[controler])
					diff = 1;
				j++;
				controler++;
			}
			if (!diff)
				return (&str[i]);
		}
		i++;
	}
	return ((void *)0);
}

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		controler;
	char	*final_str;

	i = 0;
	controler = 0;
	final_str = (char *)str;
	if (to_find[0] == '\0')
		return (final_str);
	return (solve(final_str, (char *)to_find, i, controler));
}
