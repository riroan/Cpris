#pragma once
#include "Block.h"

class Block7 : public Block
{
public:
    Block7() : Block()
    {
        color = Colors::gray;
        int block[4][4][4] = {
            {{0, 0, 0, 0},
             {0, 0, 2, 0},
             {0, 2, 2, 0},
             {0, 2, 0, 0}},
            {{0, 0, 0, 0},
             {2, 2, 0, 0},
             {0, 2, 2, 0},
             {0, 0, 0, 0}
            },
            {{0, 0, 0, 0},
             {0, 0, 2, 0},
             {0, 2, 2, 0},
             {0, 2, 0, 0}
            },
            {{0, 0, 0, 0},
             {2, 2, 0, 0},
             {0, 2, 2, 0},
             {0, 0, 0, 0}
            },
        };
        setShape(block);
    }
};