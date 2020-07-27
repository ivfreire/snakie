#include <iostream>
#include <SDL2/SDL.h>
#include "game.h"

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);

	Uint32 before;
	float dtime;
	int width, height;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Game* game;
	
	if (argv[1] != NULL && argv[2] != NULL) {
		width = atoi(argv[1]);
		height = atoi(argv[2]);
	} else {
		width = 1000;
		height = 800;
	}
	window = SDL_CreateWindow(
		"Snaky",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width, height,
		SDL_WINDOW_SHOWN
	);
	renderer = SDL_CreateRenderer(window, -1, 0);

	game = new Game(&width, &height);
	game->Start();

	before = SDL_GetTicks();
	dtime = 0.0f;

	bool running = true;
	while (running) {
		SDL_Event ev;
		SDL_PollEvent(&ev);
		if (ev.type == SDL_QUIT) running = false;
		if (ev.type == SDL_KEYDOWN) if (ev.key.keysym.sym == SDLK_ESCAPE) running = false;
		game->PollEvent(ev);

		game->Update(dtime);

		SDL_SetRenderDrawColor(renderer, 33, 33, 33, 255);
		SDL_RenderClear(renderer);
		game->Render(renderer);
		SDL_RenderPresent(renderer);

		Uint32 dtick = float(SDL_GetTicks() - before);
		dtime = dtick / 1000.0f; 
		before = SDL_GetTicks();
		if (dtick < 16) SDL_Delay(16 - dtick);
	}

	game->~Game();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}