#ifndef _TIMER_H_
#define _TIMER_H_

#include <SDL2/SDL.h>

class Timer {
    private:
        Uint32 startTicks;
        Uint32 pausedTicks;
        bool paused;
        bool started;

    public:
        Timer();

        void start ();

        void stop ();

        void pause ();

        void resume ();

        Uint32 getTicks ();

        bool isStarted ();

        bool isPaused ();
};

#endif