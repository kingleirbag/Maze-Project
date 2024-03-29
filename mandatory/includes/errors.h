#ifndef ERRORS_H
# define ERRORS_H

# define ERR_MALLOC "Malloc failed"
# define ERR_GNL "get_next_line failed"
# define ERR_FORK "Fork failed"

# define CONFIG_NOT_FOUND "UHH... Where is your config file ??"

# define FILE_NOT_FOUND "File not found"
# define FILE_PERMISSION_DENIED "You don't have permission to read a file"
# define FILE_UNKNOWN_ERROR "Error while opening a file"

# define EXTENSION_NO_OCCUR "Where is your file extension mate ?? o.O"
# define EXTENSION_MULTIPLE "WDYM multiple points in your filename ??"
# define EXTENSION_INVALID "Invalid file extension buddy... Please use .cub"

# define CONFIG_INVALID_LINE "Invalid line in your config file"

# define MAP_EMPTY_LINE "Empty line in your map"
# define MAP_INVALID_IDENTIFIER "Invalid identifier in your map"
# define MAP_DUPLICATE_IDENTIFIER "Duplicate identifier in your map"
# define MAP_TEXTURE_NOT_FOUND "A texture in your config file not found"
# define MAP_TEXTURE_PERMISSION "You don't have permissions to read a texture"
# define MAP_TEXTURE_UNKNOWN_ERROR "Error while reading a texture"
# define MAP_INVALID_COLOR "Invalid color in your config file"
# define MAP_INVALID_COLOR_RANGE "Invalid color range in your config [#0-255]"
# define MAP_INDEX_OUT_OF_RANGE "Indexed map out of range"
# define MAP_INVALID_CHAR "Invalid character in your map"
# define MAP_INVALID_BORDER "Invalid border in your map"
# define MAP_NO_PLAYERS "No players found in your map"
# define MAP_MULTIPLE_PLAYERS "Multiple players found in your map"

#endif
