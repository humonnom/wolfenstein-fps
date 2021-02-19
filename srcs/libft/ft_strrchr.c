/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jackjoo <jackjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:36:20 by juepark           #+#    #+#             */
/*   Updated: 2021/02/19 13:17:50 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *last_one;

	last_one = 0;
	while (*s)
	{
		if (*s == c)
			last_one = (char *)s;
		s++;
	}
	if (!c)
		return (char *)s;
	return (last_one);
}
