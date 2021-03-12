/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:10:41 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 16:10:43 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del(void *target)
{
	target = 0;
}

void	*ft_free(void *target)
{
	free(target);
	return (0);
}

double	ft_max(double x, double y)
{
	return (x > y ? x : y);
}

double	ft_min(double x, double y)
{
	return (x > y ? y : x);
}

int		ft_cumulate(int x)
{
	int	result;

	result = 0;
	while (x)
	{
		result += x;
		x--;
	}
	return (result);
}
