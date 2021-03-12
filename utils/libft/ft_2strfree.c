/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2strfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:08:44 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 16:08:46 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2strfree(char **string)
{
	int i;

	i = -1;
	while (string[++i])
		string[i] = ft_free(string[i]);
	free(string);
	string = NULL;
}
