#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int    is_valid(char *s)
{
    int balance = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '(')
            balance++;
        else if (s[i] == ')')
        {
            if (balance == 0)
                return 0;
            balance--;
        }
    }
    return (balance == 0);
}

int fixer(char *s)
{
    int opened = 0;
    int closed = 0;
    for (int x = 0; s[x]; x++)
    {
        if (s[x]== '(')
            opened++;
        else if (s[x]== ')')
        {
            if (opened > 0)
                opened--;
            else
                closed++;
        }
    }
    return (closed + opened);
}

void	solve(char *s, int must_fix, int fixed, int pos)
{
	if(must_fix == fixed && is_valid(s))
	{
		puts(s);
		return ;
	}
	for(int x = pos; s[x]; x++)
	{
		if(s[x] == '(' || s[x] == ')')
		{
			char c = s[x];
			s[x] = ' ';
			solve(s, must_fix, fixed + 1, x + 1);
			s[x] = c;
            while (s[x + 1] == c)
                x++;
		}
	}
}

int main (int ac, char **av)
{
    if (ac != 2)
        return 1;
    char s[1000];
    strncpy(s, av[1], 999);
    s[999] = 0;
    int must_fix = fixer(s);
    solve(s, must_fix, 0, 0);
    return 0;
}