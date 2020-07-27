#include <iostream>
#include <SDL2/SDL.h>

#define MAX_TAILS 1024

struct Tail {
	int x, y;
	int lifetime;
	bool is_live = false;
	SDL_Rect rect;
	void tick() { this->lifetime -= 1; if (this->lifetime <= 0) this->is_live = false; }
	void render(SDL_Renderer* rdr) { SDL_RenderFillRect(rdr, &this->rect); }
};

class Snake {
private:
	SDL_Rect rect;
	Tail tails[MAX_TAILS];

public:
	int length;
	int x, y;
	int width, height;
	int facing;

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