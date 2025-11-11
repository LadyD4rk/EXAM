
#define _GNU_SOURCE
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    if (argc != 2 || !*argv[1])
        return (1);

    char buffer[BUFFER_SIZE];
    char *pattern = argv[1];
    size_t pattern_len = strlen(pattern);
    ssize_t bytes_read;

    while ((bytes_read = read(0, buffer, BUFFER_SIZE)) > 0)
    {
        char *current = buffer;
        char *match;

        while ((match = memmem(current, buffer + bytes_read - current, pattern, pattern_len)))
        {
            write(1, current, match - current);

            size_t i = 0;
            while (i++ < pattern_len)
                write(1, "*", 1);

            current = match + pattern_len;
        }
        if (current < buffer + bytes_read)
            write(1, current, buffer + bytes_read - current);
    }
    return (bytes_read < 0);
}
