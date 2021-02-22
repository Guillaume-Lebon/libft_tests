#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	write(1, lst, 1);
	write(1, f, 1);
	write(1, del, 1);
	return (NULL);
}
