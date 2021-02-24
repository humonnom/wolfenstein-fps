#include "libft.h"
#include <stdio.h>
size_t	ft_2strlen(char *const *s)
{
	int i;

	i = 0;
	while (*(s + i))
	{
		printf("%s\n", *(s + i));
		if ((ft_strncmp(*(s + i), "", ft_strlen(*(s + i)))))
			printf("it's not empty string.\n");
		i++;
	}
	return (i);
}
