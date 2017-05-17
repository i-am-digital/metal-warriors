#include "surface.h"
#include "renderer.h"
#include "window.h"
#include "game.h"
#include "context.h"
#include <iostream>
#include <SDL.h>
#include <exception>

void game_main()
{
	try
	{
		Context sdlContext;
		Window sdlWindow;
		Renderer sdlRenderer(sdlWindow);
		Surface tankSurface("tank-sprite.bmp");

		std::cout << "Hello from game" << std::endl;

			SDL_Texture* tankTexture = SDL_CreateTextureFromSurface(sdlRenderer.getRenderer(), tankSurface.getSurface());
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

					sdlRenderer.clear();

					SDL_Rect tankLocation;
					tankLocation.x = 10;
					tankLocation.y = 20;
					tankLocation.w = 100;
					tankLocation.h = 100;

					SDL_RenderCopy(sdlRenderer.getRenderer(), tankTexture, nullptr, &tankLocation);
					sdlRenderer.present();
				}
				SDL_DestroyTexture(tankTexture);
			}

		std::cout << "Bye from game" << std::endl;
	}
	catch (std::exception const&)
	{
		std::cout << "Something went wrong :(" << std::endl;
	}
}