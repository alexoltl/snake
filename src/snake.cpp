#include "snake.h"
#include "globals.h"
#include <raylib.h>
#include <vector>

using namespace std;

vector<Rectangle> Snake::body;

Snake::Snake() {
    head = {tileSize * 5, tileSize * 5, tileSize, tileSize};
    length = 1;
    direction = "up";
    step = 0;
    stepNext = 12;

    body.push_back(head);
}

void Snake::update() {
    step += 1;

    if (IsKeyPressed(KEY_UP) && direction != "down") {
        direction = "up";
        step = stepNext;
    } else if (IsKeyPressed(KEY_DOWN) && direction != "up") {
        direction = "down";
        step = stepNext;
    } else if (IsKeyPressed(KEY_LEFT) && direction != "right") {
        direction = "left";
        step = stepNext;
    } else if (IsKeyPressed(KEY_RIGHT) && direction != "left") {
        direction = "right";
        step = stepNext;
    }

    if (step >= stepNext) {
        if (direction == "up") head.y -= tileSize;
        if (direction == "down") head.y += tileSize;
        if (direction == "left") head.x -= tileSize;
        if (direction == "right") head.x += tileSize;

        body.insert(body.begin(), head);

        if (body.size() > length) {
            body.pop_back();
        }

        step = 0;
    }
}
