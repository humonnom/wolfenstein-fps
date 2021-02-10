/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:25:54 by juepark           #+#    #+#             */
/*   Updated: 2020/10/19 13:13:38 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_c;
	char	*src_c;

	i = -1;
	if (!dst && !src)
		return (0);
	dst_c = dst;
	src_c = (char *)src;
	if (src_c < dst_c)
		while ((int)(--len) >= 0)
			dst_c[len] = src_c[len];
	else
		while (++i < len)
			dst_c[i] = src_c[i];
	return (dst);
}
