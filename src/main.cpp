#include <iostream>
#include <SDL2/SDL.h>
#include "game.h"

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);

	int width, height;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Game* game;
	
	width = 800;
	height = 600;
	window = SDL_CreateWindow(
		"Snaky",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width, height,
		SDL_WINDOW_SHOWN
	);
	renderer = SDL_CreateRenderer(window, -1, 0);

	game = new Game(&width, &height);

	bool running = true;
	while (running) {
		SDL_Event ev;
		SDL_PollEvent(&ev);
		if (ev.type == SDL_QUIT) running = false;
		game->PollEvent(ev);

		game->Update(0.016f);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		// Rendering code here...
		game->Render(renderer);

		SDL_RenderPresent(renderer);
	}

	game->~Game();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}