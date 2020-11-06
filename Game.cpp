#include "Game.h"

Game::Game () {
    createWindow();
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
	
	this->init();
}

Game::Game (const char *title, int32_t width, int32_t height) {
    this->title = title;
	this->width = width;
	this->height = height;
	
	createWindow();
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
	
	this->init();
}

Game::~Game () {
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}

void Game::createWindow () {
	this->window = SDL_CreateWindow (
		this->title, SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		this->width,
		this->height,
		SDL_WINDOW_SHOWN
	);
}

void Game::clear () {
	SDL_RenderClear(this->renderer);
}

void Game::render () {
	this->draw();
	SDL_RenderPresent(this->renderer);
}

void Game::quit () {
	this->running = false;
}

void Game::start () {
	this->running = true;

    // Game loop
	while (this->running) {
		this->render();
		this->update();
	}

}