#include <iostream>
#include <SDL2/SDL.h>

class Apple {
private:
	SDL_Rect rect;
	SDL_Color color;
	float buffer;

public:
	int x, y;
	int width, height;
	int type;

	Apple(int x, int y, int width, int height, int type);

	void Start();
	void Update(float dtime);
	void Render(SDL_Renderer* rdr);

	void UpdateColor(float dtime);

	~Apple();

};