/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:15:18 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 16:15:20 by juepark          ###   ########.fr       */
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
