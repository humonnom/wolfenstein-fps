/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:47:20 by juepark           #+#    #+#             */
/*   Updated: 2021/01/21 13:10:32 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		confirm_line(char **line, char *new, char **next, int result)
{
	if (new)
		result = 1;
	if (result == 0 && *next)
	{
		new = ft_strdup(*next);
		*next = ft_free(*next);
	}
	if (result != -1)
		*line = new ? new : ft_strdup("");
	return (result > 0 ? 1 : result);
}

char	*devide_line(char **next, char *target)
{
	int		new_line;
	char	*tmp;
	char	*new;

	if ((new_line = ft_strchr_i(target, '\n')) == -1)
		return (0);
	new = NULL;
	tmp = *next;
	*next = ft_strdup(&target[new_line + 1]);
	target[new_line] = '\0';
	new = ft_strdup(target);
	tmp = ft_free(tmp);
	return (new);
}

char	*combine_line(char *s1, char *s2)
{
	char	*combine;

	if (!s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	combine = ft_strjoin(s1, s2);
	s1 = ft_free(s1);
	return (combine);
}

int		get_next_line(int fd, char **line)
{
	static char	*next[OPEN_MAX];
	char		*buf;
	char		*new;
	int			result;

	if (BUFFER_SIZE <= 0 || line == NULL || fd < 0 || fd > OPEN_MAX)
		return (-1);
	new = NULL;
	while (!new)
	{
		if (next[fd] && (new = devide_line(&next[fd], next[fd])) != NULL)
			break ;
		buf = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if ((result = read(fd, buf, BUFFER_SIZE)) <= 0)
		{
			buf = ft_free(buf);
			break ;
		}
		*(buf + result) = '\0';
		next[fd] = combine_line(next[fd], buf);
		buf = ft_free(buf);
	}
	return (confirm_line(line, new, &next[fd], result));
}
