#pragma once
#include "Block.h"

class Block5 : public Block
{
public:
    Block5() : Block()
    {
        color = Colors::gold;
        int block[4][4][4] = {
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
        };
        setShape(block);
    }
};