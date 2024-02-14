#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*tab;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	tab = NULL;
	current = lst;
	while (current)
	{
		new = ft_lstnew((*f)(current->content));
		if (!new)
		{
			ft_lstclear(&tab, (*del));
			return (NULL);
		}
		ft_lstadd_back(&tab, new);
		current = current->next;
	}
	return (tab);
}
