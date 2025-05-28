#include <cub.h>
#include <error.h>

static const char *get_error_message(int err_code)
{
	if (err_code == ERR_TEXTURE_PATH)
		return MSG_TEXTURE_PATH;
	if (err_code == ERR_COLOR_FORMAT)
		return MSG_COLOR_FORMAT;
	if (err_code == ERR_COLOR_RANGE)
		return MSG_COLOR_RANGE;
	if (err_code == ERR_FILE_OPEN)
		return MSG_FILE_OPEN;
	if (err_code == ERR_MEMORY_ALLOC)
		return MSG_MEMORY_ALLOC;
	if (err_code == ERR_MAP_FORMAT)
		return MSG_MAP_FORMAT;
	if (err_code == ERR_MISSING_PLAYER)
		return MSG_MISSING_PLAYER;
	if (err_code == ERR_MISSING_TEXTURE)
		return MSG_MISSING_TEXTURE;
	return "Unknown error.";
}

void	handle_parse_error(t_parse *parse, int err_code)
{
	const char *msg = get_error_message(err_code);

	fprintf(stderr, "Error: %s\n", msg);
	free_parse(parse);
	exit(EXIT_FAILURE);
}
