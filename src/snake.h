#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>

#define MAX_TAILS 1024

struct Tail {
	int x, y;
	int lifetime;
	bool is_live = false;
	SDL_Rect rect, _rect;

	void Animate(float dtime, int length);
	void Tick();
	void Render(SDL_Renderer* rdr);
};

class Snake {
private:
	SDL_Rect rect;

public:
	int length;
	int x, y;
	int width, height;
	int facing;

	Tail tails[MAX_TAILS];


	Snake(int length, int x, int y, int width, int height);

	void Start();
	void Update(float dtime);
	void Render(SDL_Renderer* rdr);

	void Tick();
	void Grow();

	void KeepInScreen(int width, int height);
	void CheckForCollision(Tail tail);
	void Rebirth();

	~Snake();
};