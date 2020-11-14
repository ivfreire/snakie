#include "snake.h"

Snake::Snake(int length, int x, int y, int width, int height) {
	this->length = length;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	this->facing = 0;
}


void Snake::Start() {

}

void Snake::Update(float dtime) {
	this->rect = {
		this->x * this->width,
		this->y * this->height,
		this->width,
		this->height
	};

	for (int i = 0; i < MAX_TAILS; i++) if (this->tails[i].is_live) this->tails[i].Animate(dtime, this->length);
}

void Snake::Render(SDL_Renderer* rdr) {
	SDL_SetRenderDrawColor(rdr, 0, 255, 0, 255);
	SDL_RenderFillRect(rdr, &this->rect);

	for (int i = 0; i < MAX_TAILS; i++) if (this->tails[i].is_live)
		this->tails[i].Render(rdr);
}


void Snake::Tick() {
	if (this->length > 1) {
		bool found = false;
		for (int i = 0; i < MAX_TAILS && !found; i++) if (!this->tails[i].is_live) {
			this->tails[i].is_live = true;
			this->tails[i].lifetime = this->length;
			this->tails[i].x = this->x;
			this->tails[i].y = this->y;
			this->tails[i].rect = { this->tails[i].x * this->width, this->tails[i].y  * this->height, this->width, this->height };
			found = true;
		}
	}
	
	if (this->facing == 0) this->x += 1;
	if (this->facing == 1) this->y -= 1;
	if (this->facing == 2) this->x -= 1;
	if (this->facing == 3) this->y += 1;

	for (int i = 0; i < MAX_TAILS; i++) if (this->tails[i].is_live) {
		this->tails[i].Tick();
		this->CheckForCollision(this->tails[i]);
	}
}


void Snake::Grow() {
	this->length += 1;
}


void Snake::KeepInScreen(int width, int height) {
	if (this->x < 0) this->x = width - 1;
	if (this->y < 0) this->y = height - 1;
	if (this->x >= width) this->x = 0;
	if (this->y >= height) this->y = 0;
}

void Snake::CheckForCollision(Tail tail) {
	if (tail.x == this->x && tail.y == this->y)
		this->Rebirth();
}

void Snake::Rebirth() {
	for (int i = 0; i < MAX_TAILS; i++) this->tails[i].is_live = false;
	this->length = 1;
}


Snake::~Snake() {

}




void Tail::Animate(float dtime, int length) {
	this->_rect.w = (int)(this->rect.w * this->lifetime / length);
	this->_rect.h = (int)(this->rect.h * this->lifetime / length);
	this->_rect.x = this->rect.x + (int)((this->rect.w - this->_rect.w) / 2);
	this->_rect.y = this->rect.y + (int)((this->rect.h - this->_rect.h) / 2);
}

void Tail::Tick() {
	this->lifetime -= 1;
	if (this->lifetime <= 0)
	this->is_live = false;
}

void Tail::Render(SDL_Renderer* rdr) {
	SDL_RenderFillRect(rdr, &this->_rect);
}