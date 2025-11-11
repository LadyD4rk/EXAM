#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == c)
			return(&s[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	i = 0;

	if (!s)
		return (0);
	while(s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i = 0;

	if (!dest || !src)
		return (NULL);
	while (i < n)
	{
		((char*)dest)[i] = ((char*)src)[i];
		i++;
	}
	return (dest);
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t size1;
	if (!*s1)
		size1 = 0;
	else
		size1 = ft_strlen(*s1);
	char *tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	if (s1 && *s1)
		ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = '\0';
	free(*s1);
	*s1 = tmp;
	return (1);
}

int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
    if (dest > src)
    {
        while (--n > 0)
            ((char*)dest)[n - 1] = ((char*)src)[n - 1];
    }
    else if (dest < src)
        return ft_memcpy(dest, src, n);
    else if (dest == src)
        return dest;
    return dest;
}

char *get_next_line(int fd)
{
    static char b[BUFFER_SIZE + 1] = "";
    char *ret = NULL;
    int read_ret = 0;

    if (!b[0])
    {
        read_ret = read(fd, b, BUFFER_SIZE);
        if (read_ret <= 0)
            return NULL;
        b[read_ret] = 0;
    }
    char *tmp = ft_strchr(b, '\n');
    while (!tmp)
    {
        if (!str_append_str(&ret, b))
            return NULL;
        read_ret = read(fd, b, BUFFER_SIZE);
        if (read_ret <= 0)
        {
            if (ret && *ret)
                break ;
            free (ret);
            return NULL;
        }
        b[read_ret] = 0;
        tmp = ft_strchr(b, '\n');
    }
    if (!str_append_mem(&ret, b, tmp - b + 1))
    {
        free(ret);
        return NULL;
    }
    ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
    return ret;
}

