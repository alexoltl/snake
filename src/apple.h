#ifndef APPLE_H
#define APPLE_H

#include <raylib.h>
#include <vector>

struct Apple {
    Rectangle rect;
    Apple();
    void reposition(const std::vector<Rectangle>& snakeBody);
};

#endif // APPLE_H