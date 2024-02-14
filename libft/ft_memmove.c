#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	int		i;

	if (!dst && !src)
		return (NULL);
	d = dst;
	s = (void *)src;
	i = -1;
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	else
		while ((size_t)++i < len)
			d[i] = s[i];
	return (dst);
}
