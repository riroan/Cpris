#pragma once
#include "Block.h"

class Block2 : public Block
{
public:
    Block2() : Block()
    {
        color=Colors::blue;
        int block[4][4][4] = {
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
        };
        setShape(block);
    }
};