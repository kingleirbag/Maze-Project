#include "libft.h"

int	ft_putset(char c, int len)
{
	int	i;

	if (len <= 0)
		return (0);
	i = -1;
	while (++i < len)
		ft_putchar_fd(c, 1);
	return (len);
}
