#include "game.h"
#include <iostream>
#include <SDL.h>

void game_main()
{
	std::cout << "Hello from game" << std::endl;
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	SDL_Quit();

}