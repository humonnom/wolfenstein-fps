/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:07:14 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 16:08:22 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_2strdup(char *const *s1)
{
	char	**s2;
	size_t	len;
	int		i;

	len = ft_2strlen(s1);
	if (!(s2 = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
	{
		if (!(s2[i] = ft_strdup(s1[i])))
			return (NULL);
	}
	s2[len] = NULL;
	return (s2);
}
