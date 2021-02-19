/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jackjoo <jackjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:11:38 by juepark           #+#    #+#             */
/*   Updated: 2021/02/19 13:17:50 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	index;
	unsigned int	s_len;

	if (!s)
		return (0);
	index = 0;
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	while (s[index + start] && len--)
	{
		substr[index] = s[index + start];
		index++;
	}
	substr[index] = '\0';
	return (substr);
}
