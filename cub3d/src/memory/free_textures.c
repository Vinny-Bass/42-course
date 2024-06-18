#include "cub.h"

void free_textures(t_state *state)
{
	if (state->map.style.no)
		free(state->map.style.no);
	if (state->map.style.so)
		free(state->map.style.so);
	if (state->map.style.ea)
		free(state->map.style.ea);
	if (state->map.style.we)
		free(state->map.style.we);
}