#include "libft.h"

int	ft_tolower(int c)
{
	if (64 < c && c < 91)
		return (c + 32);
	return (c);
}
