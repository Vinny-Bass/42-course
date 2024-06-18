#include "cub.h"

void	no_mem_free_err(char *message)
{
	printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}

void	err_and_free_char(char *message, char *to_free)
{
	if (to_free)
		free(to_free);
	printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}

void	err_and_free_state(char *message, t_state *state)
{
	if (state->matrix)
		free_matrix(state);
	if (state->raw_content)
		free(state->raw_content);
	free_textures(state);
	free(state);
	printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}