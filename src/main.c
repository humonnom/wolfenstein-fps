#include "cub3d.h"


// for TEST only //
void print_struct(t_all s)	
{
	printf("s.mlx.ptr:%p\n", s.mlx.ptr);
	printf("s.win.ptr:%p\n", s.win.ptr);
	printf("s.img.ptr:%p\n", s.img.ptr);
	printf("s.img.adr:%p\n", s.img.adr);
	printf("s.win.x:  %d\n", s.win.x);
	printf("s.win.y:  %d\n", s.win.y);
	printf("s.img.fsh:%d\n", s.img.fsh);
	printf("s.err.n:  %d\n", s.err.n);
	printf("s.err.m:  %d\n", s.err.m);
	printf("s.err.p:  %d\n", s.err.p);
	printf("s.tex.n : %p\n ", s.tex.n );
	printf("s.tex.s : %p\n ", s.tex.s );
	printf("s.tex.e : %p\n ", s.tex.e );
	printf("s.tex.w : %p\n ", s.tex.w );
	printf("s.tex.i : %p\n ", s.tex.i );
	printf("s.spr :   %p\n ", s.spr  );
	printf("s.stk :   %p\n ", s.stk  );
	printf("s.map.x : %d\n ", s.map.x );
	printf("s.map.y : %d\n ", s.map.y );
	printf("s.map.spr:%d\n ", s.map.spr);
	printf("s.tex.c : %u\n ", s.tex.c );
	printf("s.tex.f : %u\n ", s.tex.f );
}
///////////////////


int		ft_exit(t_arg arg)
{
	write(1, "Invalid...", 10);
	if (!arg.num)
		write(1, " [ argument number ]", 20);
	 if (!arg.map)
		write(1, " [ map name ]", 13);
	if (!arg.save)
		write(1, " [ save option ]", 16);
	write(1, "\n", 1);
	return (ERR);
}

int		main(int argc, char **argv)
{
	t_arg	arg;
	
	arg.num = (argc >= 2 && argc <= 3);
	arg.map = (argc >= 2 && !ft_strncmp_reverse(argv[1], ".cub", 4));
	arg.save = (argc == 2 || !ft_strncmp(argv[2], "--save", 6));
	if (!(arg.num * arg.map * arg.save))
		return(ft_exit(arg));
	ft_init(argv[1], argc == 3);
	return(0);
}
