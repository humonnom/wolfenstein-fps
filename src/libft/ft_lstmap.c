/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:23:30 by juepark           #+#    #+#             */
/*   Updated: 2020/10/19 13:18:27 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *origin, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *before;
	t_list *new_head;

	new = 0;
	before = 0;
	new_head = 0;
	while (origin)
	{
		new = ft_lstnew(f(origin->content));
		if (!new)
		{
			if (new_head)
				ft_lstclear(&new_head, del);
			return (0);
		}
		if (!new_head)
			new_head = new;
		if (before)
			before->next = new;
		before = new;
		origin = origin->next;
	}
	return (new_head);
}
