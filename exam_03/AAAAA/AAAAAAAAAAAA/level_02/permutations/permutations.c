/* Allowed functions: puts, malloc, calloc, realloc, free, write */

#include <stdio.h>
#include <stdlib.h>

void	clear_array(char **table)
{
	int		i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		count_per(int i)
{
	int		per;

	per = i;
	i--;
	while (i > 0)
	{
		per = per * i;
		i--;
	}
	return (per);
}

char	*ft_strdup(char *str, int len)
{
	int		i;
	char	*src;

	src = malloc(sizeof(char) * (len + 1));
	if (!src)
		return (NULL);
	i = 0;
	while (str[i])
	{
		src[i] = str[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}

void	ft_swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	print_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		printf("LINE %i -> %s\n", i + 1, array[i]);
		i++;
	}
}

void	permutation(char **array, char *str, int l, int r, int *x)
{
	int		len;
	int		i;

	if (l == r - 1)
	{
		len = ft_strlen(str);
		array[*x] = ft_strdup(str, len);
		(*x)++;
	}
	else
	{
		i = l;
		while (i < r)
		{
			ft_swap(&str[l], &str[i]);
			permutation (array, str, l + 1, r, x);
			ft_swap(&str[l], &str[i]);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	int		per;
	int		len;
	int		x;
	char	**array;

	if (ac != 2)
		return (1);
	len = ft_strlen(av[1]);
	per = count_per(len);
	array = calloc(per + 1, (sizeof(char *)));
	if (!array)
		return (1);
	x = 0;
	permutation(array, av[1], 0, len, &x);
	print_array(array);
	clear_array(array);
	return (0);
}
