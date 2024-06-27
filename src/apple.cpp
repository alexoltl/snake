#include "apple.h"
#include "globals.h"
#include <cstdlib>
#include <ctime>

Apple::Apple() {
    srand(time(NULL));
    rect = {0, 0, tileSize, tileSize};
    reposition({});
}

void Apple::reposition(const std::vector<Rectangle>& snakeBody) {
    bool collision;
    do {
        collision = false;
        int x = rand() % gridSize;
        int y = rand() % gridSize;
        rect = {x * tileSize, y * tileSize, tileSize, tileSize};

        for (const auto& segment : snakeBody) {
            if (CheckCollisionRecs(rect, segment)) {
                collision = true;
                break;
            }
        }
    } while (collision);
}