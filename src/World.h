#ifndef _WORLD_H_
#define _WORLD_H_

#include <SDL2/SDL.h>
#include <vector>
#include "Player.h"
#include "Level.h"
#include "GameView.h"

class World {
    private:
        int32_t width = 1000;
        int32_t height = 500;

        Level level = Level ();
        int32_t tileSize = 50;
        std::vector <Object> obstacles;

    public:
        GameView gameView = GameView ();
        Player player = Player ({ 50, 50 }, 25, 25);

        World ();
        
        World (SDL_Point position, int32_t width, int32_t height);

        ~World ();

        int32_t getWidth ();

        int32_t getHeight ();

        void update ();

        void draw (SDL_Renderer *renderer);

        void loadObstacles ();

        void loadLevel (int index);

        void nextLevel ();

        void setLevel (int index);
};

#endif