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
