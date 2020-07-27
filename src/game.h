#include <iostream>
#include <SDL2/SDL.h>

class Game {
public:
	int* width, * height;

	Game(int* width, int* height);

	void Start();
	void Update(float dtime);
	void Render(SDL_Renderer* rdr);
	void PollEvent(SDL_Event ev);

	~Game();

private:
};