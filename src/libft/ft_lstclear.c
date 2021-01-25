/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:22:17 by juepark           #+#    #+#             */
/*   Updated: 2020/10/19 11:20:33 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **pointer, void (*del)(void *))
{
	t_list	*target;
	t_list	*current;

	if (!pointer || !*pointer || !del)
		return ;
	current = *pointer;
	while (current)
	{
		target = current;
		current = current->next;
		ft_lstdelone(target, del);
	}
	*pointer = 0;
}
