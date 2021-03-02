#include <stdio.h>
#include <stdlib.h>

typedef struct	s_inver
{
	double a;
	double b;
	double c;
	double d;
}				t_inver;

static t_inver	*get_inverse(t_inver *src)
{
	t_inver *ret;
	double	devider;

	ret = (t_inver *)malloc(sizeof (t_inver));
	devider = (src->a * src->d) - (src->b * src->c);
	ret->a = src->d / devider;
	ret->b = -(src->b) / devider;
	ret->c = -(src->c) / devider;
	ret->d = src->a / devider;
	return (ret);
}

int main()
{
	t_inver *src;
	t_inver *ret;

	src = (t_inver *)malloc(sizeof (t_inver));
	src->a = 4;
	src->b = 7;
	src->c = 2;
	src->d = 6;
	ret = get_inverse(src);
	printf("[a] : %f", ret->a);
	printf("[b] : %f", ret->b);
	printf("[c] : %f", ret->c);
	printf("[d] : %f", ret->d);
	free(src);
	free(ret);
}
