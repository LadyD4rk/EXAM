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
            // Última linha sem \n - retorna o que temos
            if (ret && *ret)
            {
                b[0] = '\0'; // Limpa o buffer estático
                return ret;
            }
            free(ret);
            return NULL;
        }
        b[read_ret] = 0;
        tmp = ft_strchr(b, '\n');
    }
    
    // Encontrou \n - adiciona até ele (inclusive)
    if (!str_append_mem(&ret, b, tmp - b + 1))
    {
        free(ret);
        return NULL;
    }
    ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
    return ret;
}