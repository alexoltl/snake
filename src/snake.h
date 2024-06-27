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
        int length;
        void update();
        Snake();
};

#endif // SNAKE_H
