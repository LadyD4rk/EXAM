/* Expected files   : *.c *.h
Allowed functions: puts, malloc, calloc, realloc, free, write */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src, int len)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	print_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		free(array[i]);
		i++;
	}
	free(array);
}

void	permutations(char **m, char *str, int *size_m, int limit, int i)
{
	int		x;

	if (i == limit - 1)
	{
		m[*size_m] = ft_strdup(str, limit);
		(*size_m)++;
	}
	else
	{
		x = i;
		while (x < limit)
		{
			ft_swap(&str[i], &str[x]);
			permutations(m, str, size_m, limit, i + 1);
			ft_swap(&str[i], &str[x]);
			x++;
		}
	}
}

int		fat(int len)
{
	int		res;

	res = 1;
	while (len > 0)
	{
		res = res * len;
		len--;
	}
	return (res);
}

int	ft_strcmp(char *str, char *src)
{
	int		i;

	i = 0;
	while (str[i] && src[i] && str[i] == src[i])
		i++;
	return (str[i] - src[i]);
}

void	sort_alpha_last(char **arr, int size, char last, int len)
{
	int		start;
	int		i;
	int		j;
	char	*tmp;

	start = 0;
	while (start < size && arr[start][len - 1] != last)
		start++;
	if (start >= size)
		return;
	i = 0;
	while (i < size - start - 1)
	{
		j = start;
		while (j < size - 1 - i)
		{
			if (ft_strcmp(arr[j], arr[j + 1]) > 0)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		len;
	int		a;
	char	**array;
	char	last;

	if (ac != 2)
		return (1);
	len = ft_strlen(av[1]);
	array = calloc((fat(len) + 1), (sizeof(char *)));
	a = 0;
	last = av[1][len - 1];
	permutations(array, av[1], &a, len, 0);
	sort_alpha(array, fat(len), last, len);
	print_array(array);
	return (0);
}
