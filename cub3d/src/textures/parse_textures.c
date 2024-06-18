#include "cub.h"

static void	validate_textures(t_state *state)
{
	bool	is_valid;

	is_valid = true;
	if (state->map.style.no == NULL)
		is_valid = false;
	if (state->map.style.so == NULL)
		is_valid = false;
	if (state->map.style.ea == NULL)
		is_valid = false;
	if (state->map.style.we == NULL)
		is_valid = false;
	if (!is_valid)
		err_and_free_state(TEXTURE_ARGS_ERR, state);
}

static void set_texture(char *line, char **texture)
{
	char **arr;

	arr = ft_split(line, ' ');
	if (arr && arr[1])
	{
		*texture = ft_strdup(arr[1]);
		free(arr[0]);
		free(arr[1]);
	}
	else
	{
		free(arr[0]);
		*texture = NULL;
	}
	return ;
}

void	parse_textures(t_state *state)
{
	int		i;
	char	*line;

	i = 0;
	while (state->matrix[i])
	{
		line = state->matrix[i];
		if (line[0] == 'N')
			set_texture(line, &state->map.style.no);
		if (line[0] == 'S')
			set_texture(line, &state->map.style.so);
		if (line[0] == 'E')
			set_texture(line, &state->map.style.ea);
		if (line[0] == 'W')
			set_texture(line, &state->map.style.we);
		i++;
	}
	validate_textures(state);
	return ;
}