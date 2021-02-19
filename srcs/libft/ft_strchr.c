/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jackjoo <jackjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:27:08 by juepark           #+#    #+#             */
/*   Updated: 2021/02/19 13:17:50 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (0);
}

int		ft_strchr_i(const char *s, int c)
{
	int i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			return (i);
		i++;
	}
	if (*s == '\0' && c == '\0')
		return (ft_strlen(s));
	return (-1);
}

