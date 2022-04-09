#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

#define TABLE_X 15 //게임판 가로 크기
#define TABLE_Y 30 //게임판 세로 크기
#define GAME_OVER 6 //게임오버 기준
#define LEFT 75 
#define RIGHT 77  
#define UP 72 
#define DOWN 80
vector<vector<int>> table; // 테이블로 사용할 이중벡터

/*
공백 = 0
□ = 1 : 테두리
■ = 2 : 내려오는 블록
바닥이나 블록에 쌓인 ■ = 3
바닥에 있는 □ = 4
▽ = 게임오버 블록
*/
void CursorView(char show) {
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}//커서 숨기기

void gotoxy(int x, int y) {
    //x, y 좌표 설정
    COORD pos = { x,y };
    //커서 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//원하는 위치로 커서 이동
/*1번 블럭*/
const int block1[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {2, 2, 2, 2},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0}

        },
        {
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {2, 2, 2, 2},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0}
        },

};
/*2번 블럭*/
const int block2[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },

};
/*3번 블럭*/
const int block3[4][4][4] = {
        {
                        {0, 2, 0, 0},
                        {0, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 2},
                        {0, 2, 0, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 2, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 0, 0},
                        {0, 0, 2, 0},
                        {2, 2, 2, 0},
                        {0, 0, 0, 0}

        },

};
/*4번 블럭*/
const int block4[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 2, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {2, 2, 0, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 2, 0}

        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {2, 2, 0, 0},
                        {0, 0, 0, 0}

        },

};
/*5번 블럭*/
const int block5[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 2},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 2, 0},
                        {0, 2, 2, 2},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 2, 0},
                        {0, 0, 2, 2},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}

        },

};
/*6번 블럭*/
const int block6[4][4][4] = {
        {
                        {0, 2, 0, 0},
                        {0, 2, 0, 0},
                        {2, 2, 0, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 2, 0, 0},
                        {0, 2, 2, 2},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 2, 2},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {2, 2, 2, 0},
                        {0, 0, 2, 0}

        },

};
/*7번 블럭*/
const int block7[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 0, 2, 0},
                        {0, 2, 2, 0},
                        {0, 2, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {2, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 0, 0},
                        {0, 0, 2, 0},
                        {0, 2, 2, 0},
                        {0, 2, 0, 0}

        },
        {
                        {0, 0, 0, 0},
                        {2, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}

        },

};
/*블럭 부모 클래스*/
class Block {
protected:
    int shape[4][4][4]; // shape[rotate][y][x]
    int x; // x좌표
    int y; // y좌표
    int rotationCount; // shape[0][y][x], shape[1][y][x], shape[2][y][x], shaoe[3][y][x]로 4가지 상태 표현
public:
    int getShape(int rotationCount, int y, int x) {
        return shape[rotationCount][y][x];
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    int getRotationCount() {
        return rotationCount;
    }
    void down() { // 블럭 한 칸 아래 이동
        y++;
    }
    void left() { // 블럭 한 칸 왼쪽 이동
        x--;
    }
    void right() { // 블럭 한 칸 오른쪽 이동
        x++;
    }
    void rotate() { // 블럭 회전
        rotationCount = (rotationCount + 1) % 4; // 0 , 1, 2 , 3 으로 회전 표현
    }
    void setX(int x) {
        this->x = x;
    }
    void setY(int y) {
        this->y = y;
    }
    void setRotationCount(int r) {
        this->rotationCount = r;
    }
    void setShape(int r, int y, int x, int value) {
        this->shape[r][y][x] = value;
    }
    void up() { //hard drop 처리용 블럭 한 칸 위로 이동
        y--;
    }
};
/*1번 블럭 클래스*/
class Block1 : public Block {
public:
    Block1() {
        x = TABLE_X / 2 - 3; // 초기 생성 맨 위 중앙 쯤으로 맞춤
        y = 2;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block1[i][j][k]; // 블럭 객체 정보 저장
                }
            }
        }
    }
};
/*2번 블럭 클래스*/
class Block2 : public Block {
public:
    Block2() {
        x = TABLE_X / 2 - 3; // 초기 생성 맨 위 중앙 쯤으로 맞춤
        y = 2;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block2[i][j][k]; // 블럭 객체 정보 저장
                }
            }
        }
    }
};
/*3번 블럭 클래스*/
class Block3 : public Block {
public:
    Block3() {
        x = TABLE_X / 2 - 3; // 초기 생성 맨 위 중앙 쯤으로 맞춤
        y = 2;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block3[i][j][k]; // 블럭 객체 정보 저장
                }
            }
        }
    }
};
/*4번 블럭 클래스*/
class Block4 : public Block {
public:
    Block4() {
        x = TABLE_X / 2 - 3; // 초기 생성 맨 위 중앙 쯤으로 맞춤
        y = 2;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block4[i][j][k]; // 블럭 객체 정보 저장
                }
            }
        }
    }
};
/*5번 블럭 클래스*/
class Block5 : public Block {
public:
    Block5() {
        x = TABLE_X / 2 - 3; // 초기 생성 맨 위 중앙 쯤으로 맞춤
        y = 2;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block5[i][j][k]; // 블럭 객체 정보 저장
                }
            }
        }
    }
};

/*6번 블럭 클래스*/
class Block6 : public Block {
public:
    Block6() {
        x = TABLE_X / 2 - 3; // 초기 생성 맨 위 중앙 쯤으로 맞춤
        y = 2;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block6[i][j][k]; // 블럭 객체 정보 저장
                }
            }
        }
    }
};

/*7번 블럭 클래스*/
class Block7 : public Block {
public:
    Block7() {
        x = TABLE_X / 2 - 3; // 초기 생성 맨 위 중앙 쯤으로 맞춤
        y = 2;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block7[i][j][k]; // 블럭 객체 정보 저장
                }
            }
        }
    }
};
class Table {
private:
    int x;
    int y;
public:
    Table(int x, int y) {
        this->x = x;
        this->y = y;
        for (int i = 0; i < y; i++) {
            vector<int> temp;
            for (int j = 0; j < x; j++) {
                temp.push_back(0);
            }
            table.push_back(temp);
        }
        //공백으로 채워진 이중 벡터 생성 <- 게임판의 틀로 사용
        for (int i = 0; i < x; i++) {
            table[0][i] = 1;
            table[y - 1][i] = 1;
        }
        for (int i = 1; i < y - 1; i++) {
            table[i][0] = 1;
            table[i][x - 1] = 1;
        }
        //바닥 제외 삼면을 1로 채움
        for (int i = 1; i < x - 1; i++) {
            table[y - 1][i] = 4;
        }
        //바닥을 4로 채움
        for (int i = 1; i < x - 1; i++) {
            table[GAME_OVER][i] = 5;
        }
    }
    void DrawTable() {
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (table[i][j] == 1 || table[i][j] == 4) {
                    cout << "□";
                }
                else if (table[i][j] == 2 || table[i][j] == 3) {
                    cout << "■";
                }
                else if (table[i][j] == 5) {
                    cout << "▽";
                }
                else cout << "  ";
            }
            cout << "\n";
        }
    }
    //게임판
};

class GameCore {
public:
    Block* blockobject = nullptr;
    int nextcount = 0;
    void CreateBlock() {
        srand((unsigned int)time(NULL));
        int choice = rand() % 7 + 1;
        if (choice == 1) {
            blockobject = new Block1();
        }
        else if (choice == 2) {
            blockobject = new Block2();
        }
        else if (choice == 3) {
            blockobject = new Block3();
        }
        else if (choice == 4) {
            blockobject = new Block4();
        }
        else if (choice == 5) {
            blockobject = new Block5();
        }
        else if (choice == 6) {
            blockobject = new Block6();
        }
        else if (choice == 7) {
            blockobject = new Block7();
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockobject->getY();
                int X = i + blockobject->getX();
                if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue; //범위오류 방지
                table[Y][X] = blockobject->getShape(blockobject->getRotationCount(), i, j);
            }
        }
    }
    //블록 랜덤으로 생성해서 테이블에 업데이트
    void RotateBlock() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockobject->getY();
                int X = i + blockobject->getX();
                if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue; //범위오류 방지
                if (table[Y][X] == 2) {
                    table[Y][X] = 0;
                }
            }
        }
        //기존에 내려오고 있던 블록을 테이블에서 지워줌
        blockobject->rotate();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockobject->getY();
                int X = i + blockobject->getX();
                if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue; //범위오류 방지
                table[Y][X] = blockobject->getShape(blockobject->getRotationCount(), i, j);
            }
        }
    }
    //블록 회전시키기
    Block* NextBlock() {
        Block* nextblock1 = nullptr;
        Block* nextblock2 = nullptr;
        Block* nextblock3 = nullptr;
        Block* nextblock4 = nullptr;
        Block* nextblock5 = nullptr;
        srand((unsigned int)time(NULL));
        int next1 = rand() % 7 + 1;
        if (next1 == 1) {
            nextblock1 = new Block1();
        }
        else if (next1 == 2) {
            nextblock1 = new Block2();
        }
        else if (next1 == 3) {
            nextblock1 = new Block3();
        }
        else if (next1 == 4) {
            nextblock1 = new Block4();
        }
        else if (next1 == 5) {
            nextblock1 = new Block5();
        }
        else if (next1 == 6) {
            nextblock1 = new Block6();
        }
        else if (next1 == 7) {
            nextblock1 = new Block7();
        }
        //1번째 블록 랜덤 생성
        srand((unsigned int)time(NULL));
        int next2 = rand() % 7 + 1;
        if (next2 == 1) {
            nextblock2 = new Block1();
        }
        else if (next2 == 2) {
            nextblock2 = new Block2();
        }
        else if (next2 == 3) {
            nextblock2 = new Block3();
        }
        else if (next2 == 4) {
            nextblock2 = new Block4();
        }
        else if (next2 == 5) {
            nextblock2 = new Block5();
        }
        else if (next2 == 6) {
            nextblock2 = new Block6();
        }
        else if (next2 == 7) {
            nextblock2 = new Block7();
        }
        //2번째 블록 랜덤 생성
        srand((unsigned int)time(NULL));
        int next3 = rand() % 7 + 1;
        if (next3 == 1) {
            nextblock3 = new Block1();
        }
        else if (next3 == 2) {
            nextblock3 = new Block2();
        }
        else if (next3 == 3) {
            nextblock3 = new Block3();
        }
        else if (next3 == 4) {
            nextblock3 = new Block4();
        }
        else if (next3 == 5) {
            nextblock3 = new Block5();
        }
        else if (next3 == 6) {
            nextblock3 = new Block6();
        }
        else if (next3 == 7) {
            nextblock3 = new Block7();
        }
        //3번째 블록 랜덤 생성
        srand((unsigned int)time(NULL));
        int next4 = rand() % 7 + 1;
        if (next4 == 1) {
            nextblock4 = new Block1();
        }
        else if (next4 == 2) {
            nextblock4 = new Block2();
        }
        else if (next4 == 3) {
            nextblock4 = new Block3();
        }
        else if (next4 == 4) {
            nextblock4 = new Block4();
        }
        else if (next4 == 5) {
            nextblock4 = new Block5();
        }
        else if (next4 == 6) {
            nextblock4 = new Block6();
        }
        else if (next4 == 7) {
            nextblock4 = new Block7();
        }
        //4번째 블록 랜덤 생성
        srand((unsigned int)time(NULL));
        int next5 = rand() % 7 + 1;
        if (next5 == 1) {
            nextblock5 = new Block1();
        }
        else if (next5 == 2) {
            nextblock5 = new Block2();
        }
        else if (next5 == 3) {
            nextblock5 = new Block3();
        }
        else if (next5 == 4) {
            nextblock5 = new Block4();
        }
        else if (next5 == 5) {
            nextblock5 = new Block5();
        }
        else if (next5 == 6) {
            nextblock5 = new Block6();
        }
        else if (next5 == 7) {
            nextblock5 = new Block7();
        }
        //5번째 블록 랜덤 생성






















        return nextblock1;
    }
    //다음에 나올 블록 5개를 보여주기



    void LineClear() {

    }
    //라인클리어 여부


    void GameOver() {

    }
    //게임오버 여부
};




void DemoSketch() {
    Table* demo = new Table(TABLE_X, TABLE_Y);
    demo->DrawTable();
};
//그리기



int main() {
    GameCore* gg = new GameCore();
    CursorView(false);
	system("mode con: cols=100 lines=50");
    DemoSketch();
    Sleep(1000);
    gg->CreateBlock();
    system("cls");
    DemoSketch();
    Sleep(1000);
    gg->RotateBlock();
    system("cls");
    DemoSketch();
    Sleep(1000);
    _getch();
	return 0;
}

