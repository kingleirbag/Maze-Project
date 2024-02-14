#include "maze.h"

int	count_occurences(char *str, char c)
{
	int	i;
	int	occur;

	occur = 0;
	i = -1;
	while (str[++i])
		if (str[i] == c)
			occur++;
	return (occur);
}

int	count_int_occurences(int *arr, size_t size, int n)
{
	int	i;
	int	occur;

	occur = 0;
	i = -1;
	while ((size_t)++i < size)
		if (arr[i] == n)
			occur++;
	return (occur);
}
