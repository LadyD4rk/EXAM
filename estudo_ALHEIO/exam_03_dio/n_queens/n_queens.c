
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void    print_positions(int nb, int *positions)
{
    int i = 0;

    while (i < nb)
    {
        printf("%d", positions[i]);
        if (i + 1 != nb)
            printf(" ");
        i++;
    }
    printf("\n");
}

bool    is_valid(int pos, int *positions, int row)
{
    int i = row - 1;

    while (i >= 0 && positions[i] != -1)
    {
        int t = positions[i];
        if (pos == t || pos == t + (row - i) || pos == t - (row - i))
            return (false);
        i--;
    }
    return (true);
}

void    solve(int nb, int *positions, int row)
{
    int pos = 0;

    while (pos < nb)
    {
        if (is_valid(pos, positions, row))
        {
            positions[row] = pos;
            if (row + 1 == nb)
                print_positions(nb, positions);
            else
                solve(nb, positions, row + 1);
        }
        positions[row] = -1;
        pos++;
    }
}

int main(int ac, char **av)
{
    int nb = 0;
    int positions[11] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    if (ac != 2)
        return (write(2, "Invalid n of arguments\n", 23));
    nb = atoi(av[1]);
    solve(nb, positions, 0);

    /* PER GESTIRE NUMERI PIU' GRANDI DI 11 (spoiler, è inutile :)*/
    // int nb = 0;
    // int *positions;

    // if (ac != 2)
    //     return (write(2, "Invalid n of arguments\n", 23));
    // nb = atoi(av[1]);
    // positions = malloc(nb * sizeof(int));
    // for (int i = 0; i < nb; i++)
    //     positions[i] = -1;
    // solve(nb, positions, 0);
}