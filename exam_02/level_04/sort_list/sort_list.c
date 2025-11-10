#include "list.h"
#include <stdlib.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*aux;
	int		tem;

	aux = lst;
	if (!aux)
		return (NULL);
	if (aux->next == NULL)
		return (aux);
	while (aux->next)
	{
		if ((*cmp)(aux->data, aux->next->data) == 0)
		{
			tem = aux->data;
			aux->data = aux->next->data;
			aux->next->data = tem;
			aux = lst;
		}
		else
			aux = aux->next;
	}
	return (lst);
}
