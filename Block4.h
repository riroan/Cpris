#pragma once
#include "Block.h"

class Block4 : public Block
{
public:
    Block4() : Block()
    {
        color = Colors::olive;
        int block[4][4][4] = {
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
        };
        setShape(block);
    }
};