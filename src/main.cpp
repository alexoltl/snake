#include "globals.h"
#include "snake.h"
#include "apple.h"
#include <iostream>
#include <raylib.h>
#include <vector>
#include <string>

using namespace std;

const float tileSize = 32;
const int gridSize = 9;
const int screenWidth = gridSize * tileSize;
const int screenHeight = gridSize * tileSize;
bool gameOver = false;
int score = 0;
vector<Rectangle> tiles;

Snake bro;
Apple apple;

int main () {
    InitWindow(screenWidth, screenHeight, "snake");
    SetTargetFPS(60);

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            Rectangle rec = {i * tileSize, j * tileSize, tileSize, tileSize};
            tiles.push_back(rec);
        }
    }

    while (!WindowShouldClose()) {
        if (gameOver) {
            BeginDrawing();
                ClearBackground(BLACK);
                DrawText(TextFormat("Score: %i", score), 100, 100, 24, GREEN);
            EndDrawing();
            if (IsKeyPressed(KEY_R)) {
                bro.reset();
                score = 0;
                gameOver = false;
            }
        } else if (!gameOver) {
            bro.update();

            if (CheckCollisionRecs(bro.body[0], apple.rect)) {
                score+=1;
                bro.length++;
                apple.reposition(bro.body);
            }

            if (bro.body[0].x < 0 || bro.body[0].x >= screenWidth ||
                bro.body[0].y < 0 || bro.body[0].y >= screenHeight) {
                gameOver = true;
            }

            for (size_t i = 1; i < bro.body.size(); i++) {
                if (CheckCollisionRecs(bro.body[0], bro.body[i])) {
                    gameOver = true;
                }
            }

            BeginDrawing();
                ClearBackground(BLACK);
                for (Rectangle rect : tiles) {
                    DrawRectangleLinesEx(rect, 1, GRAY);
                }
                for (Rectangle snakebody : bro.body) {
                    DrawRectanglePro(snakebody, {0, 0}, 0, WHITE);
                }
                DrawRectanglePro(apple.rect, {0, 0}, 0, RED);
                DrawText(TextFormat("Score: %i", score), 12, 12, 24, GREEN);
            EndDrawing();
        }
    }

    CloseWindow();
    return 0;
}