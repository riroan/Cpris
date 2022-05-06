#pragma once
#include "resources/Game2D.h"
#include "Block.h"
#include "Block1.h"
#include "Block2.h"
#include "Block3.h"
#include "Block4.h"
#include "Block5.h"
#include "Block6.h"
#include "Block7.h"

class Tetris : public Game2D
{
public:
    float time = 0;
    const float size = 0.1f;
    const int tableX = 11;
    const int tableY = 14;
    const int width = tableX + 1;
    const int height = tableY + 1;
    const int delta = height - 8;
    const float init_x = -0.7f, init_y = 0.6f;
    std::random_device rd;
    std::mt19937 gen = std::mt19937(rd());
    std::uniform_int_distribution<int> uid, uuid; // 랜덤 숫자 생성기(랜덤 블록, 랜덤 방향)
    // 전체 블록 7종류
    std::vector<Block *> blocks{new Block1(), new Block2(), new Block3(), new Block4(), new Block5(), new Block6(), new Block7()};
    std::list<Block *> nextBlocks;                // 다음 나올 블록 5개
    std::unique_ptr<Block> blockObject = nullptr; // 현재 떨어지는 블록

    Tetris()
    {
        uid = std::uniform_int_distribution<int>(0, blocks.size() - 1);
        uuid = std::uniform_int_distribution<int>(0, 3);
        blockObject = std::make_unique<Block>(getRandomBlock());
        blockObject->x = init_x;
        blockObject->y = init_y;
        for (int i = 0; i < 5; i++)
            nextBlocks.push_back(getRandomBlock());
    }

    ~Tetris()
    {
        for (auto *block : blocks)
            delete block;
    }

    void update() override
    {
        beginTransformation();
        translate(-0.5f, 0);
        drawGrid();
        drawBoard();
        endTransformation();
        drawNextBlock();
        blockObject->draw();

        if (isKeyPressedAndReleased(GLFW_KEY_SPACE))
            getNextBlock();
        if (isKeyPressedAndReleased(GLFW_KEY_LEFT))
            blockObject->moveLeft();
        if (isKeyPressedAndReleased(GLFW_KEY_RIGHT))
            blockObject->moveRight();
        if (isKeyPressedAndReleased(GLFW_KEY_DOWN))
            blockObject->moveDown();
        if (isKeyPressedAndReleased(GLFW_KEY_UP))
            blockObject->rotate();

        blockObject->y -= this->getTimeStep() * 0.1f;
        time += this->getTimeStep();
    }

    Block *getRandomBlock()
    {
        return new Block(blocks[uid(gen)], uuid(gen));
    }

    void getNextBlock()
    {
        blockObject = std::make_unique<Block>(nextBlocks.front());
        blockObject->x = init_x;
        blockObject->y = init_y;
        nextBlocks.pop_front();
        nextBlocks.push_back(getRandomBlock());
    }

    void drawNextBlock()
    {
        drawLine(Colors::black, vec2(0.7f, -5), Colors::black, vec2(0.7f, 5));
        int i = 0;
        for (auto *nextBlock : nextBlocks)
        {
            beginTransformation();
            translate(1.1f, -0.6 + 0.3f * i);
            drawWiredBox(Colors::black, 0.3f, 0.3f);
            endTransformation();
            beginTransformation();
            translate(1.01f, 0.51 - 0.3 * i);
            nextBlock->draw(0.06f);
            endTransformation();
            i++;
        }
    }

    void drawGrid()
    {
        for (int i = 0; i < height; i++)
        {
            beginTransformation();
            drawLine(Colors::black, vec2(-width * size / 2, (i - delta + 0.5f) * size), Colors::black, vec2(width * size / 2, (i - delta + 0.5f) * size));
            endTransformation();
        }
        for (int i = -width / 2 + 1; i < width / 2; i++)
        {
            beginTransformation();
            drawLine(Colors::black, vec2((-i + 0.5f) * size, (-delta + 0.5f) * size), Colors::black, vec2((-i + 0.5f) * size, (delta + 0.5f) * size));
            endTransformation();
        }
    }

    void drawBoard()
    {
        for (int i = 0; i < height; i++)
        {
            beginTransformation();
            translate(-width * size / 2, (i - delta) * size);
            drawFilledSquare(Colors::black, 0.11f);
            drawFilledSquare(Colors::skyblue, 0.09f);
            endTransformation();

            beginTransformation();
            translate(width * size / 2, (i - delta) * size);
            drawFilledSquare(Colors::black, 0.11f);
            drawFilledSquare(Colors::skyblue, 0.09f);
            endTransformation();
        }
        for (int i = -width / 2 + 1; i < width / 2; i++)
        {
            beginTransformation();
            translate(-i * size, -delta * size);
            drawFilledSquare(Colors::black, 0.11f);
            drawFilledSquare(Colors::skyblue, 0.09f);
            endTransformation();
        }
    }
};