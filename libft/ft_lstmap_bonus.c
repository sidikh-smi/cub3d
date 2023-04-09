/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:42:39 by skhaliff          #+#    #+#             */
/*   Updated: 2021/11/27 21:38:50 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*free_list(t_list *lst, void (*del)(void *))
{
	ft_lstclear(&lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy;
	t_list	*new;
	t_list	*tmp;
	void	*test;

	tmp = lst;
	copy = NULL;
	if (!lst || !f)
		return (NULL);
	while (tmp)
	{
		test = f(tmp->content);
		if (!test)
			return (free_list(copy, del));
		new = ft_lstnew(test);
		if (!new)
		{
			return (free_list(copy, del));
		}
		ft_lstadd_back(&copy, new);
		tmp = tmp->next;
	}
	return (copy);
}
