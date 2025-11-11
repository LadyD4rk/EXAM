#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while(1)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("%s", line);
			free(line);
		}
		else
			break;
	}
	close(fd);
	printf("%c", '\n');
	return (0);
}
