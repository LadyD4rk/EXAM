#include "ft_list.h"

void	fill(char **tab, t_point size, t_point begin, char c)
{
	t_point		esquerda = {begin.x - 1, begin.y};
	t_point		direita = {begin.x + 1, begin.y};
	t_point		cima = {begin.x, begin.y + 1};
	t_point		baixo = {begin.x, begin.y - 1};
	int			x = begin.x;
	int			y = begin.y;
	
	if (x >= size.x || y >= size.y || x < 0 || y < 0 )
		return ;
	if (tab[begin.y][begin.x] == 'F' || tab[begin.y][begin.x] != c)
		return ;
	tab[begin.y][begin.x] = 'F';
	fill(tab, size, esquerda, c);
	fill(tab, size, direita, c);
	fill(tab, size, cima, c);
	fill(tab, size, baixo, c);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char	orig;

	orig = tab[begin.y][begin.x];
	fill(tab, size, begin, orig);
}
