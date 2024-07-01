#include "snake.h"
#include "globals.h"
#include <raylib.h>
#include <vector>

using namespace std;

vector<Rectangle> Snake::body;
bool Snake::paused = false;

Snake::Snake()
{
    head = {tileSize * 5, tileSize * 5, tileSize, tileSize};
    length = 1;
    direction = "up";
    step = 0;
    stepNext = 12;

    body.push_back(head);
}

void Snake::update()
{
    if (!paused)
    {
        step += 1;

        if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) && direction != "down")
        {
            direction = "up";
            step = stepNext;
        }
        else if ((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) && direction != "up")
        {
            direction = "down";
            step = stepNext;
        }
        else if ((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) && direction != "right")
        {
            direction = "left";
            step = stepNext;
        }
        else if ((IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) && direction != "left")
        {
            direction = "right";
            step = stepNext;
        }

        if (step >= stepNext)
        {
            if (direction == "up")
                head.y -= tileSize;
            if (direction == "down")
                head.y += tileSize;
            if (direction == "left")
                head.x -= tileSize;
            if (direction == "right")
                head.x += tileSize;

            body.insert(body.begin(), head);

            if (body.size() > length)
            {
                body.pop_back();
            }

            step = 0;
        }
    }
}

void Snake::reset()
{
    body.clear();
    head = {tileSize * 5, tileSize * 5, tileSize, tileSize};
    length = 1;
    direction = "up";
    step = 0;
    stepNext = 12;

    body.push_back(head);
}