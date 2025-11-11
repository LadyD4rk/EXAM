#include <stdio.h>
#include <stdlib.h>

void print_set(int *set, int size)
{
    int i = 0;

    while (i < size)
    {
        printf("%d", set[i]);
        if (i < size - 1)
        {
            printf(" ");
        }
        i++;
    }
    printf("\n");
}


void find_sets(int size, int *nums, int soma, int *set, int set_index, int index, int target)
{
    int i = index;
    
    while (i < size)
    {
        int num = nums[i];
        int next_soma = soma + num;

        set[set_index] = num;
        if (next_soma == target)
        {
            print_set(set, set_index + 1);
        }
        find_sets(size, nums, next_soma, set, set_index + 1, i + 1, target);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac < 3)
        return 1; 
    int n = ac - 2; 
    int soma = 0;
    int target = atoi(av[1]);
    int i = 0;
    if (target == 0) {
        printf("\n");
    }
    if (n <= 0)
        return 0; 
    int *nums = (int *)malloc(sizeof(int) * n);
    int *set = (int *)malloc(sizeof(int) * n); 
    while (i < n)
    {
        nums[i] = atoi(av[i + 2]);
        i++;
    }
    find_sets(n, nums, soma, set, 0, 0, target);
    free(set);
    free(nums);
    return 0;
}