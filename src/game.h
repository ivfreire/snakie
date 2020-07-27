#include <iostream>
#include <SDL2/SDL.h>
#include "world.h"

class Game {
private:
	float buffer;

public:
	int* width, * height;
	int rate;

	World* world;

	Game(int* width, int* height);

	void Start();
	void Update(float dtime);
	void Render(SDL_Renderer* rdr);
	void PollEvent(SDL_Event ev);

	void Tick();

	~Game();
};