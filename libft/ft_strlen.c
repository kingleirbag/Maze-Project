#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		;
	return (i);
}
