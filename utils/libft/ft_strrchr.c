/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:15:05 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 16:15:07 by juepark          ###   ########.fr       */
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
