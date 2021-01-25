/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:19:04 by juepark           #+#    #+#             */
/*   Updated: 2020/10/19 11:19:11 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **pointer, t_list *new)
{
	if (!pointer && !new)
		return ;
	if (*pointer)
		new->next = *pointer;
	*pointer = new;
}
