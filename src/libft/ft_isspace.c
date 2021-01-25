#include "libft.h"

int		ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || \
		c == '\r'|| c == '\v' || c == '\f')
		return (1);
	return(0);
}

int		ft_spaceskip(const char *s, int *i)
{
	while (ft_isspace(s[*i]))
		(*i)++;
	return (1);
}
