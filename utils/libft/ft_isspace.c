/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:10:04 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 16:10:06 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || \
		c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int		ft_spaceskip(const char *s, int *i)
{
	while (ft_isspace(s[*i]))
		(*i)++;
	return (1);
}
