#ifndef ERROR_H
# define ERROR_H

// Error codes
# define ERR_TEXTURE_PATH    1
# define ERR_COLOR_FORMAT    2
# define ERR_COLOR_RANGE     3
# define ERR_FILE_OPEN       4
# define ERR_MEMORY_ALLOC    5
# define ERR_MAP_FORMAT      6
# define ERR_MISSING_PLAYER  7
# define ERR_MISSING_TEXTURE  8

// Error messages
# define MSG_TEXTURE_PATH    "Invalid texture path."
# define MSG_COLOR_FORMAT    "Color format is invalid. Expected format: R,G,B."
# define MSG_COLOR_RANGE     "Color value out of range (0-255)."
# define MSG_FILE_OPEN       "Failed to open texture file."
# define MSG_MEMORY_ALLOC    "Memory allocation failed."
# define MSG_MAP_FORMAT      "Invalid map format."
# define MSG_MISSING_PLAYER  "Player start position not found."
# define MSG_MISSING_TEXTURE "Texture is missing."


//# include <cub.h>

//void	handle_parse_error(struct s_parse *parse, int err_code);

#endif
