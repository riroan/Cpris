#pragma once
#include "resources/Game2D.h"

class Block : public Game2D
{
public:
    int shape[4][4][4];
    float x = 0.0f, y = 0.0f;
    int rotationCount = 0;
    RGB color = Colors::red;

    Block()
    {
    }

    Block(Block *right, int direction = -1)
    {
        this->setShape(right->shape);
        this->x = right->x;
        this->y = right->y;
        if (direction == -1)
            this->rotationCount = right->rotationCount;
        else
            this->rotationCount = direction;
        this->color = right->color;
    }

    void setShape(const int block[4][4][4])
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                    shape[i][j][k] = block[i][j][k]; // 블럭 객체 정보 저장
    }

    void drawSquare(const RGB &color, float ratio = 0.1f)
    {
        drawFilledSquare(Colors::black, 1.1f * ratio);
        drawFilledSquare(color, 0.9f * ratio);
    }

    void draw(float ratio = 0.1f)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                beginTransformation();
                translate(x + ratio * i, y + ratio * j);
                if (shape[rotationCount][i][j])
                    drawSquare(color, ratio);
                endTransformation();
            }
        }
    }

    void moveLeft()
    {
        x -= 0.1f;
    }

    void moveRight()
    {
        x += 0.1f;
    }

    void moveDown()
    {
        y -= 0.1f;
    }

    void moveUp() // 하드드랍 처리용?
    {
        y += 0.1f;
    }

    void rotate()
    {
        rotationCount = (rotationCount + 1) % 4;
    }
};