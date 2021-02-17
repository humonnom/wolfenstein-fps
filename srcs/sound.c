#include "cub3d.h"

int		run_sound()
{
//	
//	ALCdevice	*device;
//
//	device = alcOpenDevice(NULL);
//	if (!device)
//		printf("sound err\n");
//	else
//		printf("sound\n");
//	return 0;
////	ALboolean enumeration;
////	
////	enumeration = alcIsExtensionPresent(NULL, "ALC_ENUMERATION_EXT");
////	if (enumeration == AL_FALSE)
////	        // enumeration not supported
////	else
////	        // enumeration supported
	return 0;
}

void	handle_sound(int step)
{
	(void)step;
	ps("sound control");
	run_sound();
}
