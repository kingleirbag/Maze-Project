#include "libft.h"

void	ft_putptr_fd(unsigned long long n, int fd)
{
	if (n > 15)
	{
		ft_putptr_fd(n / 16, fd);
		ft_putptr_fd(n % 16, fd);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd(n + 48, fd);
		else
			ft_putchar_fd(n - 10 + 97, fd);
	}
}
