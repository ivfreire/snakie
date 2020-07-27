#include "game.h"

Game::Game(int* width, int* height) {
	this->width = width;
	this->height = height;

	this->rate = 15;

	int size = 25;
	this->world = new World(*width / size, *height / size, size, size);
}


void Game::Start() {
	this->world->Start();
}

void Game::Update(float dtime) {
	if (this->buffer >= 1.0f / this->rate) {
		this->world->Tick();
		this->buffer = 0.0f;
	} else this->buffer += dtime;
	this->world->Update(dtime);
}

void Game::Render(SDL_Renderer* rdr) {
	this->world->Render(rdr);
}

void Game::PollEvent(SDL_Event ev) {
	if (ev.type == SDL_KEYDOWN) {
		if (ev.key.keysym.sym == SDLK_d && this->world->snake->facing != 2) this->world->snake->facing = 0;
		if (ev.key.keysym.sym == SDLK_w && this->world->snake->facing != 3) this->world->snake->facing = 1;
		if (ev.key.keysym.sym == SDLK_a && this->world->snake->facing != 0) this->world->snake->facing = 2;
		if (ev.key.keysym.sym == SDLK_s && this->world->snake->facing != 1) this->world->snake->facing = 3;
	}
}


void Game::Tick() {
	this->world->Tick();
}


Game::~Game() {
	this->world->~World();
}