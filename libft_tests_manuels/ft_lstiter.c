#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	write(1, lst, 1);
	write(1, f, 1);
}
