/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:27:40 by juepark           #+#    #+#             */
/*   Updated: 2020/10/19 19:49:22 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countlines(const char *str, char c)
{
	size_t	i;
	size_t	flag;
	size_t	count;
	size_t	str_len;

	i = 0;
	count = 0;
	str_len = ft_strlen(str);
	flag = 0;
	while (str[i])
	{
		if (str[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (str[i] == c)
		{
			flag = 0;
		}
		i++;
	}
	return (count);
}

static int		ft_setlines(char **arr, const char *str, char c, size_t n)
{
	size_t	index;
	size_t	len;
	char	*begin;

	index = 0;
	while (*str && index < n)
	{
		len = 0;
		while (*str && *str == c)
			str++;
		begin = (char *)str;
		while (*str && *str != c)
		{
			len++;
			str++;
		}
		if (len)
		{
			if (!(arr[index] = (char *)malloc(sizeof(char) * (len + 1))))
				return (0);
			ft_strlcpy(arr[index], begin, len + 1);
			index++;
		}
	}
	return (1);
}

char			**ft_split(const char *str, char c)
{
	char	**arr;
	size_t	split_cnt;

	if (!str)
		return (0);
	split_cnt = ft_countlines(str, c);
	arr = (char **)malloc(sizeof(char *) * (split_cnt + 1));
	if (!arr)
		return (0);
	arr[split_cnt] = 0;
	if (!ft_setlines(arr, str, c, split_cnt))
		return (0);
	return (arr);
}
