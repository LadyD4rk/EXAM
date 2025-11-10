#include <stdlib.h>

int		ft_count_word(char *str)
{
	int		word;
	int		i;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] != '\n' && str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			word++;
		while (str[i] != '\n' && str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			i++;
	}
	return (word);
}

int		strlen_word(char *str, int start)
{
	int		i;

	i = start;
	while (str[i] != '\n' && str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		i++;
	return (i - start);
}

char	*copy_word(char *str, int start, int len)
{
	int		i;
	char	*word;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char    **ft_split(char *str)
{
	char	**array;
	int		cw;
	int		i;
	int		len;
	int		word;

	cw = ft_count_word(str);
	array = malloc(sizeof(char *) * (cw + 1));
	if (!array)
		return (NULL);
	i = 0;
	len = 0;
	while (cw)
	{
		while (str[len] == '\n' || str[len] == ' ' || str[len] == '\t')
			len++;
		word = strlen_word(str, len);
		array[i] = copy_word(str, len, word);
		len = word + len;
		i++;
		cw--;
	}
	array[i] = NULL;
	return(array);
}
