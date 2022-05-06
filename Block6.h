#pragma once
#include "Block.h"

class Block6 : public Block
{
public:
    Block6() : Block()
    {
        color = Colors::silver;
        int block[4][4][4] = {
            {{0, 2, 0, 0},
             {0, 2, 0, 0},
             {2, 2, 0, 0},
             {0, 0, 0, 0}},
            {{0, 2, 0, 0},
             {0, 2, 2, 2},
             {0, 0, 0, 0},
             {0, 0, 0, 0}
            },
            {{0, 0, 2, 2},
             {0, 0, 2, 0},
             {0, 0, 2, 0},
             {0, 0, 0, 0}
            },
            {{0, 0, 0, 0},
             {0, 0, 0, 0},
             {2, 2, 2, 0},
             {0, 0, 2, 0}
            },
        };
        setShape(block);
    }
};