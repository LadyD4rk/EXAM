#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*aux;

	aux = begin_list;
	i = 0;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}
