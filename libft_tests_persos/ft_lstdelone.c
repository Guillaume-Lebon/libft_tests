#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	write(1, lst, 1);
	write(1, del, 1);
}
