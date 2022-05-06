#pragma once
#include "Block.h"

class Block1 : public Block
{
public:
    Block1() : Block()
    {
        color = Colors::red;
        int block[4][4][4] = {
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
             {0, 0, 2, 0}}};
        setShape(block);
    }
};