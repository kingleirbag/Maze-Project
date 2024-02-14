#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	int		i;

	last = NULL;
	i = -1;
	while (s[++i])
		if (s[i] == (char) c)
			last = (char *) &s[i];
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	return (last);
}
