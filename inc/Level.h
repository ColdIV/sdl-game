#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <fstream>

class Level {
    private:
        const static int _X = 10;
        const static int _Y = 5;
        int data[_X][_Y];
        char *filename = "level.txt";

    public:
        Level ();

        ~Level ();

        void save ();
        void load ();
};

#endif