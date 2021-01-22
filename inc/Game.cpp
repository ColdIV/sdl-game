#include "Game.h"

Game::Game () {
    createWindow();
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
	this->texture = SDL_CreateTexture(this->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, this->width, this->height);
	
	this->init();
}

Game::Game (char *title, int32_t width, int32_t height) {
    this->title = title;
	this->width = width;
	this->height = height;
	
	createWindow();
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
	this->texture = SDL_CreateTexture(this->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, this->width, this->height);
	
	this->init();
}

Game::~Game () {
	SDL_DestroyTexture(this->texture);
	SDL_DestroyRenderer(this->renderer);
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
	// Render to texture
	SDL_SetRenderTarget(this->renderer, this->texture);
	SDL_RenderClear(this->renderer);
	
	this->draw();
	
	// Detach from texture
	SDL_SetRenderTarget(this->renderer, NULL);

	// Render texture to screen
	SDL_RenderClear(this->renderer);
	SDL_RenderCopyEx(this->renderer, this->texture, NULL, NULL, 0, NULL, SDL_FLIP_NONE);
	SDL_RenderPresent(this->renderer);
}

void Game::quit () {
	this->running = false;
}

void Game::start () {
	this->running = true;

    // Game loop
	while (this->running) {
		this->fpsTimer.start();

		this->render();
		this->update();

		while(this->fpsTimer.getTicks() < 1000 / this->FRAMES_PER_SECOND) {}
	}

}