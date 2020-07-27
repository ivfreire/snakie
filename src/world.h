#include <iostream>
#include <SDL2/SDL.h>
#include "snake.h"
#include "apple.h"

#define MAX_APPLES 8

class World {
private:


public:
	int width, height;
	int cellwidth, cellheight;

	Snake* snake;
	Apple* apples[MAX_APPLES];

	World(int width, int height, int cellwidth, int cellheight);

	void Start();
	void Update(float dtime);
	void Render(SDL_Renderer* rdr);

	void Tick();

	void SpawnRedApple();
	void CheckForApples();
	void AppleEffect(Apple* apple);

	~World();

};