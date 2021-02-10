/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:29:03 by juepark           #+#    #+#             */
/*   Updated: 2020/10/15 20:25:47 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *target, size_t len)
{
	size_t s_len;
	size_t t_len;
	size_t i;

	i = 0;
	s_len = ft_strlen(str);
	t_len = ft_strlen(target);
	if (!t_len)
		return ((char *)str);
	if (len < t_len || s_len < t_len)
		return (0);
	while (str[i] && i <= len - t_len)
	{
		if (str[i] == *target)
			if (!ft_memcmp(str + i, target, t_len))
				return ((char *)(str + i));
		i++;
	}
	return (0);
}
