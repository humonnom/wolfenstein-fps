/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:59:04 by juepark           #+#    #+#             */
/*   Updated: 2020/10/19 11:18:47 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **pointer, t_list *new)
{
	t_list *last;

	if (!pointer || !new)
		return ;
	if (!*pointer)
	{
		*pointer = new;
		return ;
	}
	last = ft_lstlast(*pointer);
	last->next = new;
}
