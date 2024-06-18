#include "cub.h"

void	parse_map(t_state *state, char *file_path)
{
	char	*file_content;

	file_content = read_file(file_path);
	line_len = 0;
	state->map.rows = 0;
	while (1)
	{
		line_tmp = get_next_line(map_fd);
		if (!line_tmp)
			break ;
		validate_line(state, &line_tmp, &line_len, map_tmp);
		append_line_to_map(&map_tmp, line_tmp);
		free(line_tmp);
		state->map.rows++;
	}
	close(map_fd);
	check_for_empty_line(map_tmp, state);
	state->map.full = ft_split(map_tmp, '\n');
	init_map(state);
	free(map_tmp);
}