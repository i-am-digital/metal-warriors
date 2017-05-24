#include "game.h"
#include "context.h"
#include <iostream>
#include <SDL.h>
#include <exception>

void game_main(std::string const& applicationPath)
{
	try
	{
		Context sdlContext;

		std::cout << "Hello from game" << std::endl;

		SDL_Window* window = SDL_CreateWindow("Metal Warriors",
			10, 100, 640, 480, SDL_WINDOW_SHOWN);

		if (window != nullptr)
		{
			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
				SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

			if (renderer != nullptr)
			{

				SDL_Surface* tankSprite = SDL_LoadBMP("tank-sprite.bmp");
				if (tankSprite != nullptr)
				{
					SDL_Texture* tankTexture = SDL_CreateTextureFromSurface(renderer, tankSprite);
					if (tankTexture != nullptr)
					{
						bool isRunning = true;
						while (isRunning)
						{
							SDL_Event event;
							while (SDL_PollEvent(&event))
							{
								switch (event.type)
								{
								case SDL_QUIT:
									isRunning = false;
									break;
								case SDL_KEYDOWN:
									if (event.key.keysym.sym == SDLK_ESCAPE)
									{
										isRunning = false;
									}
									break;
								default:
									break;
								}
							}

							SDL_RenderClear(renderer);

							SDL_Rect tankLocation;
							tankLocation.x = 10;
							tankLocation.y = 20;
							tankLocation.w = 100;
							tankLocation.h = 100;

							SDL_RenderCopy(renderer, tankTexture, nullptr, &tankLocation);
							SDL_RenderPresent(renderer);
						}
						SDL_DestroyTexture(tankTexture);
					}
					SDL_FreeSurface(tankSprite);
				}
				else
				{
					std::cout << "Unable to load tank sprite" << std::endl;
				}


				SDL_DestroyRenderer(renderer);
			}

			SDL_DestroyWindow(window);
		}


		std::cout << "Bye from game" << std::endl;

	}
	catch(std::exception const& gameException)
	{
		std::cout << "Something went wrong :(" << std::endl;
	}
}