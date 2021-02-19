#include "cub3d.h"

static void	write_err(const char *s)
{
	write(2, s, ft_strlen(s)); 
}

int		report_err(int err)
{
	(err == -1) ? write_err("Couldn't open file (FD)\n") : 0;
	(err == -2) ? write_err("Couldn't parse file (GNL)\n") : 0;
	(err == -3) ? write_err("Resolution specified twice\n") : 0;
	(err == -4) ? write_err("Invalid resolution\n") : 0;
	(err == -5) ? write_err("Floor/ceiling specified twice\n") : 0;
	(err == -6) ? write_err("Invalid floor/ceiling line\n") : 0;
	(err == -7) ? write_err("Texture path specified twice\n") : 0;
	(err == -8) ? write_err("Malloc fail (texture path)\n") : 0;
	(err == -9) ? write_err("Invalid texture image\n") : 0;
	(err == -10) ? write_err("Invalid line in file\n") : 0;
	(err == -11) ? write_err("Malloc fail (map table)\n") : 0;
	(err == -12) ? write_err("Invalid map\n") : 0;
	(err == -13) ? write_err("Map isn't a rectangle\n") : 0;
	(err == -14) ? write_err("No resolution specified\n") : 0;
	(err == -15) ? write_err("Missing texture\n") : 0;
	(err == -16) ? write_err("Missing floor/ceiling color\n") : 0;
	(err == -17) ? write_err("No starting position\n") : 0;
	(err == -18) ? write_err("Multiple starting positions\n") : 0;
	(err == -19) ? write_err("Map isn't surrounded by walls\n") : 0;
	(err == -21) ? write_err("Minimap mark fail\n") : 0;
	(err == -22) ? write_err("Invalid argument number\n") : 0;
	(err == -23) ? write_err("Invalid map name\n") : 0;
	(err == -24) ? write_err("Save fail\n") : 0;
	return (-1);
}

