#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, size * count);
	return (tab);
}
