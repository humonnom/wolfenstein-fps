/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:24:53 by juepark           #+#    #+#             */
/*   Updated: 2020/10/14 16:23:53 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_c;
	unsigned char	*s2_c;

	i = -1;
	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	while (++i < n)
		if (s1_c[i] != s2_c[i])
			return (s1_c[i] - s2_c[i]);
	return (0);
}
