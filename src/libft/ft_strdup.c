/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:41:53 by juepark           #+#    #+#             */
/*   Updated: 2020/10/15 17:46:43 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		size;

	size = ft_strlen(s1);
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (0);
	ft_memcpy(new, s1, size);
	new[size] = '\0';
	if (!new)
		return (0);
	return (new);
}
