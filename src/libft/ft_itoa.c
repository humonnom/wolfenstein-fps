/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:08:35 by juepark           #+#    #+#             */
/*   Updated: 2020/10/19 13:14:33 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbrlen(long n)
{
	int		count;

	count = 0;
	if (n < 0)
		n *= -1;
	while (n /= 10)
		count++;
	return (count + 1);
}

char			*ft_itoa(int nbr)
{
	long			n;
	char			*str;
	int				sign;
	int				length;

	sign = 0;
	n = nbr;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	length = ft_nbrlen(n) + sign;
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (0);
	str[length] = '\0';
	while (length)
	{
		str[--length] = n % 10 + '0';
		n = n / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
