#include <stdio.h>
#include "../Stone/Core/SApp.h"

#undef main
int main()
{
	if(SAPP->init("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		800, 600, SDL_WINDOW_SHOWN))
		SAPP->run();

	return 0;
}