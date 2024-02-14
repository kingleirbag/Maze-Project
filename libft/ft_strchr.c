#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
		if (s[i] == (char) c)
			return ((char *) &s[i]);
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	return (NULL);
}
