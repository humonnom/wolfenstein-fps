#include "cub3d.h"

int		ft_strerr(int err)
{
	(err == -1) ? ft_printerr("Couldn't open file (FD)\n") : 0;
	(err == -2) ? ft_printerr("Couldn't parse file (GNL)\n") : 0;
	(err == -3) ? ft_printerr("Resolution specified twice\n") : 0;
	(err == -4) ? ft_printerr("Invalid resolution\n") : 0;
	(err == -5) ? ft_printerr("Floor/ceiling specified twice\n") : 0;
	(err == -6) ? ft_printerr("Invalid floor/ceiling line\n") : 0;
	(err == -7) ? ft_printerr("Texture path specified twice\n") : 0;
	(err == -8) ? ft_printerr("Malloc fail (texture path)\n") : 0;
	(err == -9) ? ft_printerr("Invalid texture image\n") : 0;
	(err == -10) ? ft_printerr("Invalid line in file\n") : 0;
	(err == -11) ? ft_printerr("Malloc fail (map table)\n") : 0;
	(err == -12) ? ft_printerr("Invalid map\n") : 0;
	(err == -13) ? ft_printerr("Map isn't a rectangle\n") : 0;
	(err == -14) ? ft_printerr("No resolution specified\n") : 0;
	(err == -15) ? ft_printerr("Missing texture\n") : 0;
	(err == -16) ? ft_printerr("Missing floor/ceiling color\n") : 0;
	(err == -17) ? ft_printerr("No starting position\n") : 0;
	(err == -18) ? ft_printerr("Multiple starting positions\n") : 0;
	(err == -19) ? ft_printerr("Map isn't surrounded by walls\n") : 0;
	(err == -21) ? ft_printerr("Minimap mark fail\n") : 0;
	(err == -22) ? ft_printerr("Invalid argument number\n") : 0;
	(err == -23) ? ft_printerr("Invalid map name\n") : 0;
	(err == -24) ? ft_printerr("Save fail\n") : 0;
	return (-1);
}

void	ft_printerr(const char *s)
{
	write(2, s, ft_strlen(s)); 
}
