#pragma once
#include "resources/Game2D.h"

class Tetris : public Game2D{
public:
    float time = 0;
    const float size = 0.1f;
    const int width = 10;
    const int height = 15;
    const int delta = height-8;

    void update() override
    {
        drawBoard();
    }

    void drawBoard(){
        for (int i = 0; i < height;i++){
            beginTransformation();
            translate(-width * size / 2, (i - delta) * size);
            drawFilledSquare(Colors::black, 0.11f);
            drawFilledSquare(Colors::skyblue, 0.09f);
            endTransformation();

            beginTransformation();
            translate(width * size / 2, (i-delta) * size);
            drawFilledSquare(Colors::black, 0.11f);
            drawFilledSquare(Colors::skyblue, 0.09f);
            endTransformation();
        }
        for (int i = -width / 2+1; i < width / 2;i++){
            beginTransformation();
            translate(-i * size, -delta * size);
            drawFilledSquare(Colors::black, 0.11f);
            drawFilledSquare(Colors::skyblue, 0.09f);
            endTransformation();
        }
    }
};