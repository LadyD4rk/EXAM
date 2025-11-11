#include "getnline.h"


static size_t   ft_strlen (char *str)
{
    size_t i = 0;
    while (str && str[i] && str[i] != '\n')
        i++;
    if (str && str[i] == '\n')
        i++;
    return i;
}

static char *ft_strjoin(char *str, char *buff)
{
    size_t i = 0;
    size_t l = 0;
    char *line = malloc(ft_strlen(str) + ft_strlen(buff) + 1);
    if (!line)
        return (NULL);
    while (str && str[i])
    {
        line[i] = str[i];
        i++;
    }
    while (buff && buff[i] && buff[i] != '\n') 
    {
        line[i + l] = buff[l];
        l++;
    }
    if (buff == '\n')
    {
        line[i + l] = '\n';
        l++;
    }
    line[i + l] = '\0';
    free(str);
    return (buff);
}

static void buff_cleaner(char *str)
{
    size_t i = 0;
    size_t l = 0;
    while (str && str[i] && str[i] != '\n')
        i++;
    if (str && str[i] == '\n')
        i++;
    while (str && str[i])
    {
        str[l] = str[i + l];
        l++;
    }
}

char *get_n_line(int	fd)
{
	char		*str;
	static char	buf [BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;
	while(buf[0] || read(fd, buf, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buf);
		if (!str)
			return (NULL);
		buff_cleaner(buf);
		if (str[ft_strlen(str) - 1] == '\n')
			return (str);
	}
	return (str);
}

int main()
{
	int i = 0;
	
	int fd = open("test.txt", O_RDONLY);
	while (i < 3)
	{
		printf("%s\n", get_n_line(fd));
		i++;
	}
	return 0;
} 