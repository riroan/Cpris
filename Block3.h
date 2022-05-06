#pragma once
#include "Block.h"

class Block3 : public Block
{
public:
    Block3() : Block()
    {
        color = Colors::purple;
        int block[4][4][4] = {
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
        };
        setShape(block);
    }
};