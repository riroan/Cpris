#pragma once
#include "resources/Game2D.h"

class Block : public Game2D
{
public:
    float x = 0.0f, y = 0.0f;

    void drawSquare(){
        drawFilledSquare(Colors::black, 0.11f);
        drawFilledSquare(Colors::skyblue, 0.09f);
    }

    void draw()
    {
        beginTransformation();
        translate(x, y);
        drawSquare();
        endTransformation();

        beginTransformation();
        translate(x + 0.1f, y);
        drawSquare();
        endTransformation();

        beginTransformation();
        translate(x, y+0.1f);
        drawSquare();
        endTransformation();

        beginTransformation();
        translate(x - 0.1f, y);
        drawSquare();
        endTransformation();
    }

    void update() override
    {
        draw();
        if (isKeyPressedAndReleased(GLFW_KEY_LEFT))
        {
            x -= 0.1f;
        }
        if (isKeyPressedAndReleased(GLFW_KEY_RIGHT))
        {
            x += 0.1f;
        }
    }
};