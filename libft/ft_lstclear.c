#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = (*lst);
	next = (*lst);
	while (current)
	{
		next = next->next;
		ft_lstdelone(current, (*del));
		current = next;
	}
	*lst = NULL;
}
