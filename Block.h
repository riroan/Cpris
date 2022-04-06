#pragma once
#include "resources/Game2D.h"

//블럭 정의
/*1번 블럭*/
const int blocks[5][4][4][4] = {{
                                    {{0, 0, 0, 0},
                                     {0, 0, 0, 0},
                                     {2, 2, 2, 2},
                                     {0, 0, 0, 0}},
                                    {{0, 0, 2, 0},
                                     {0, 0, 2, 0},
                                     {0, 0, 2, 0},
                                     {0, 0, 2, 0}},
                                    {{0, 0, 0, 0},
                                     {0, 0, 0, 0},
                                     {2, 2, 2, 2},
                                     {0, 0, 0, 0}},
                                    {{0, 0, 2, 0},
                                     {0, 0, 2, 0},
                                     {0, 0, 2, 0},
                                     {0, 0, 2, 0}},
                                },
                                {
                                    {{0, 0, 0, 0},
                                     {0, 2, 2, 0},
                                     {0, 2, 2, 0},
                                     {0, 0, 0, 0}},
                                    {{0, 0, 0, 0},
                                     {0, 2, 2, 0},
                                     {0, 2, 2, 0},
                                     {0, 0, 0, 0}},
                                    {{0, 0, 0, 0},
                                     {0, 2, 2, 0},
                                     {0, 2, 2, 0},
                                     {0, 0, 0, 0}},
                                    {{0, 0, 0, 0},
                                     {0, 2, 2, 0},
                                     {0, 2, 2, 0},
                                     {0, 0, 0, 0}},
                                },
                                {
                                    {{0, 2, 0, 0},
                                     {0, 2, 0, 0},
                                     {0, 2, 2, 0},
                                     {0, 0, 0, 0}},
                                    {{0, 0, 0, 0},
                                     {0, 2, 2, 2},
                                     {0, 2, 0, 0},
                                     {0, 0, 0, 0}},
                                    {{0, 2, 2, 0},
                                     {0, 0, 2, 0},
                                     {0, 0, 2, 0},
                                     {0, 0, 0, 0}},
                                    {{0, 0, 0, 0},
                                     {0, 0, 2, 0},
                                     {2, 2, 2, 0},
                                     {0, 0, 0, 0}},
                                },
                                {
                                    {{0, 0, 0, 0},
                                     {0, 2, 0, 0},
                                     {0, 2, 2, 0},
                                     {0, 0, 2, 0}},
                                    {{0, 0, 0, 0},
                                     {0, 2, 2, 0},
                                     {2, 2, 0, 0},
                                     {0, 0, 0, 0}},
                                    {{0, 0, 0, 0},
                                     {0, 2, 0, 0},
                                     {0, 2, 2, 0},
                                     {0, 0, 2, 0}},
                                    {{0, 0, 0, 0},
                                     {0, 2, 2, 0},
                                     {2, 2, 0, 0},
                                     {0, 0, 0, 0}},
                                },
                                {
                                    {{0, 0, 0, 0},
                                     {0, 2, 2, 2},
                                     {0, 0, 2, 0},
                                     {0, 0, 0, 0}},
                                    {{0, 0, 2, 0},
                                     {0, 2, 2, 0},
                                     {0, 0, 2, 0},
                                     {0, 0, 0, 0}},
                                    {{0, 0, 2, 0},
                                     {0, 2, 2, 2},
                                     {0, 0, 0, 0},
                                     {0, 0, 0, 0}},
                                    {{0, 0, 2, 0},
                                     {0, 0, 2, 2},
                                     {0, 0, 2, 0},
                                     {0, 0, 0, 0}},
                                }};

class Block : public Game2D
{
public:
    float x = 0.0f, y = 0.0f;
    int direction = 0;
    int kind = 0;
    RGB color[5] = {Colors::red, Colors::gold, Colors::blue, Colors::green, Colors::olive};

    void drawSquare(const RGB& color)
    {
        drawFilledSquare(Colors::black, 0.11f);
        drawFilledSquare(color, 0.09f);
    }

    void draw(const int block[4][4][4])
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                beginTransformation();
                translate(x + 0.1f * i, y + 0.1f * j);
                if (block[direction][i][j])
                {
                    drawSquare(color[kind]);
                }
                endTransformation();
            }
        }
    }

    void update() override
    {
        draw(blocks[kind]);
        if (isKeyPressedAndReleased(GLFW_KEY_LEFT))
        {
            x -= 0.1f;
        }
        if (isKeyPressedAndReleased(GLFW_KEY_RIGHT))
        {
            x += 0.1f;
        }
        if(isKeyPressedAndReleased(GLFW_KEY_UP)){
            direction = (direction + 1) % 4;
        }
        if (isKeyPressedAndReleased(GLFW_KEY_DOWN)){
            kind = (kind + 1) % 5;
        }
    }
};