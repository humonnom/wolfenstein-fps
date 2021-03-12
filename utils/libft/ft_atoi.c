/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:09:18 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 16:09:20 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	nbr;
	long long	nbr_tmp;

	i = 0;
	nbr = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr_tmp = nbr;
		nbr = (nbr * 10) + (str[i] - '0');
		if (ft_isoverflow(nbr_tmp, nbr))
			return (sign == -1 ? 0 : -1);
		i++;
	}
	return (nbr * sign);
}

int			ft_atoiskip(const char *str, int *i)
{
	int			sign;
	long long	nbr;
	long long	nbr_tmp;

	nbr = 0;
	sign = 1;
	ft_spaceskip(str, i);
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nbr_tmp = nbr;
		nbr = (nbr * 10) + (str[*i] - '0');
		if (ft_isoverflow(nbr_tmp, nbr))
			return (sign == -1 ? 0 : -1);
		(*i)++;
	}
	return (nbr * sign);
}
