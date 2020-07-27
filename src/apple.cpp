#include "apple.h"

Apple::Apple(int x, int y, int width, int height, int type) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->type = type;

	if (type == 0) this->color = { 255, 0, 0, 255 };
	if (type == 1) this->color = { 0, 0, 255, 255 };

	this->buffer = 0;
} 


void Apple::Start() {

}

void Apple::Update(float dtime) {
	this->rect = {
		this->x * this->width,
		this->y * this->height,
		this->width,
		this->height
	};


	this->UpdateColor(dtime);
}

void Apple::Render(SDL_Renderer* rdr) {
	SDL_SetRenderDrawColor(rdr, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(rdr, &this->rect);
}


void Apple::UpdateColor(float dtime) {
	this->buffer += dtime;
	if (this->type == 0) this->color.r = Uint8(200 + 55 * sin(4*buffer));
	if (this->type == 1) this->color.b = Uint8(200 + 55 * sin(4*buffer));
}


Apple::~Apple() {

}