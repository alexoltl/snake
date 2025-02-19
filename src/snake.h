#ifndef SNAKE_H
#define SNAKE_H

#include <raylib.h>
#include <vector>
#include <string>

using namespace std;

struct Snake {
    private:
        int step;
        int stepNext;
        Rectangle head;
        string direction;
        vector<Vector2> positions;
    public:
        static vector<Rectangle> body;
        static bool paused;
        int length;
        void update();
        void reset();
        Snake();
};

#endif // SNAKE_H
