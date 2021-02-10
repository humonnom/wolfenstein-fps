/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:36:20 by juepark           #+#    #+#             */
/*   Updated: 2020/10/15 20:41:11 by juepark          ###   ########.fr       */
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
