#include "libft.h"

size_t	ft_2strlen(char *const *s)
{
	int i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}
