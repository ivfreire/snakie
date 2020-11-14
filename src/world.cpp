#include "world.h"

World::World(int width, int height, int cellwidth, int cellheight) {
	this->width = width;
	this->height = height;
	this->cellwidth = cellwidth;
	this->cellheight = cellheight;

	this->snake = new Snake(1, 4, 4, this->cellwidth, this->cellheight);

	for (int i = 0; i < MAX_APPLES; i++) this->apples[i] = NULL;
}


void World::Start() {
	this->snake->Start();
	this->SpawnRedApple();
}

void World::Update(float dtime) {
	this->snake->Update(dtime);
	this->snake->KeepInScreen(this->width, this->height);
	for (int i = 0; i < MAX_APPLES; i++) if (this->apples[i]) this->apples[i]->Update(dtime);
	this->CheckForApples();
}

void World::Render(SDL_Renderer* rdr) {
	for (int i = 0; i < MAX_APPLES; i++) if (this->apples[i]) this->apples[i]->Render(rdr);
	this->snake->Render(rdr);
}


void World::Tick() {
	this->snake->Tick();
}


void World::SpawnRedApple() {
	bool found = false;
	for (int i = 0; i < MAX_APPLES && !found; i++)
		if (this->apples[i] == NULL) {
			int x = rand() % this->width;
			int y = rand() % this->height;

			bool inTail = true;
			while (inTail) {
				for (Tail tail : this->snake->tails) {
					if (x == tail.x && y == tail.y) {
						x = (x + 1) % this->width;
						break;
					}
				}
				inTail = false;
			}

			this->apples[i] = new Apple(
				x, y,
				this->cellwidth,
				this->cellheight,
				0
			);
			found = true;
		}
}

void World::CheckForApples() {
	for (int i = 0; i < MAX_APPLES; i++) if (this->apples[i])
		if (this->snake->x == this->apples[i]->x && this->snake->y == this->apples[i]->y) {
			this->AppleEffect(this->apples[i]);
			this->apples[i] = NULL;
		}
}

void World::AppleEffect(Apple* apple) {
	if (apple->type == 0) {
		this->snake->Grow();
		this->SpawnRedApple();
	}
}


World::~World() {
	this->snake->~Snake();
}