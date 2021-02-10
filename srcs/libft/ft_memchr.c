/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:24:35 by juepark           #+#    #+#             */
/*   Updated: 2020/10/14 16:24:16 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*str_c;

	i = -1;
	str_c = (char *)str;
	while (++i < n)
		if (str_c[i] == (char)c)
			return ((void *)str_c + i);
	return (0);
}
