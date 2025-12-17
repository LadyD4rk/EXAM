#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
    int i = 0;
    while (s[i] != c && s[i])
        i++;
    if (s[i] == c)
        return s + i;
    else
        return NULL;
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t	i;

	i = 0;
	while (i < n)
	{
        ((char*)dest)[i] = ((char*)src)[i];
		i++;
	}
    return dest;
}

size_t ft_strlen(char *s)
{
    size_t ret = 0;

    while (s[ret])
        ret++;
    return (ret);
}

int str_append_mem(char **s1, char *s2, size_t size2)
{
    size_t	size1;

	if (!*s1 || !s1)
		size1 = 0;
	else
		size1 = ft_strlen(*s1);
    char *tmp = malloc(size2 + size1 + 1);
    if (!tmp)
        return 0;
    if (*s1)
		ft_memcpy(tmp, *s1, size1);
    ft_memcpy(tmp + size1, s2, size2);
    tmp[size1 + size2] = 0;
    free(*s1);
    *s1 = tmp;
    return 1;
}

int str_append_str(char **s1, char *s2)
{
    return str_append_mem(s1, s2, ft_strlen(s2));
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d = dest;
    const unsigned char *s = src;

    if (d == s || n == 0)
        return dest;
    if (d < s)
    {
        size_t i = 0;
        while (i < n)
        {
            d[i] = s[i];
            i++;
        }
    }
    else
    {
        size_t i = n;
        while (i > 0)
        {
            d[i - 1] = s[i - 1];
            i--;
        }
    }
    return dest;
}

char *get_next_line(int fd)
{
    static char b[BUFFER_SIZE + 1] = "";
    char *ret = NULL;
	int read_ret;

	if (!b[0])
	{
		read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret < 0)
			return (NULL);
		b[read_ret] = '\0';
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
    		{
        		b[0] = '\0';
        		return ret;
    		}
    		free(ret);
    		b[0] = '\0';
    		return NULL;
		}
        b[read_ret] = 0;
    }
    if (!str_append_mem(&ret, b, tmp - b + 1))
    {
        free(ret);
        return NULL;
    }
	ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
    return ret;
}
