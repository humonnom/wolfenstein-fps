/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:32:56 by juepark           #+#    #+#             */
/*   Updated: 2020/10/19 11:29:25 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*putdata(char *arr, const char *str, size_t start, size_t end)
{
	int	i;

	i = 0;
	while (i + start <= end)
	{
		arr[i] = str[i + start];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

size_t		ft_getlen(char const *str, char const *set, size_t step)
{
	size_t	index;

	index = 0;
	while (*str && ft_strchr(set, *str))
	{
		str += step;
		index++;
	}
	return (index);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	size_t	start;
	size_t	end;
	size_t	s1_len;

	if (!set)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(""));
	s1_len = ft_strlen(s1);
	start = ft_getlen(s1, set, 1);
	if (start == s1_len)
		return (ft_strdup(""));
	end = s1_len - ft_getlen(s1 + s1_len - 1, set, -1) - 1;
	arr = (char *)malloc(sizeof(char) * end - start + 2);
	if (!arr)
		return (0);
	arr = putdata(arr, s1, start, end);
	return (arr);
}
