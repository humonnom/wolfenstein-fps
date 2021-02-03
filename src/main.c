#include "cub3d.h"

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
