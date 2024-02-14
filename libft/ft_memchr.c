#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*str;

	str = (void *)s;
	i = -1;
	while ((size_t)++i < n)
		if (str[i] == (char) c)
			return (&str[i]);
	return (NULL);
}
