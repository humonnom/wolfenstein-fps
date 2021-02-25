#include "libft.h"

void	ft_2strfree(char **string)
{
	int i;

	i = -1;
	while (string[++i])
		string[i] = ft_free(string[i]);
	free(string);
}
