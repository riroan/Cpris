#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

#define TABLE_X 15 //������ ���� ũ��
#define TABLE_Y 30 //������ ���� ũ��
#define GAME_OVER 6 //���ӿ��� ����
#define LEFT 75 
#define RIGHT 77  
#define UP 72 
#define DOWN 80
vector<vector<int>> table; // ���̺�� ����� ���ߺ���

/*
���� = 0
�� = 1 : �׵θ�
�� = 2 : �������� ���
�ٴ��̳� ��Ͽ� ���� �� = 3
�ٴڿ� �ִ� �� = 4
�� = ���ӿ��� ���
*/
void CursorView(char show) {
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}//Ŀ�� �����

void gotoxy(int x, int y) {
    //x, y ��ǥ ����
    COORD pos = { x,y };
    //Ŀ�� �̵�
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//���ϴ� ��ġ�� Ŀ�� �̵�
/*1�� ��*/
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
/*2�� ��*/
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
/*3�� ��*/
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
/*4�� ��*/
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
/*5�� ��*/
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
/*6�� ��*/
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
/*7�� ��*/
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
/*�� �θ� Ŭ����*/
class Block {
protected:
    int shape[4][4][4]; // shape[rotate][y][x]
    int x; // x��ǥ
    int y; // y��ǥ
    int rotationCount; // shape[0][y][x], shape[1][y][x], shape[2][y][x], shaoe[3][y][x]�� 4���� ���� ǥ��
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
    void down() { // �� �� ĭ �Ʒ� �̵�
        y++;
    }
    void left() { // �� �� ĭ ���� �̵�
        x--;
    }
    void right() { // �� �� ĭ ������ �̵�
        x++;
    }
    void rotate() { // �� ȸ��
        rotationCount = (rotationCount + 1) % 4; // 0 , 1, 2 , 3 ���� ȸ�� ǥ��
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
    void up() { //hard drop ó���� �� �� ĭ ���� �̵�
        y--;
    }
};
/*1�� �� Ŭ����*/
class Block1 : public Block {
public:
    Block1() {
        x = TABLE_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
        y = 2;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block1[i][j][k]; // �� ��ü ���� ����
                }
            }
        }
    }
};
/*2�� �� Ŭ����*/
class Block2 : public Block {
public:
    Block2() {
        x = TABLE_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
        y = 2;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block2[i][j][k]; // �� ��ü ���� ����
                }
            }
        }
    }
};
/*3�� �� Ŭ����*/
class Block3 : public Block {
public:
    Block3() {
        x = TABLE_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
        y = 2;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block3[i][j][k]; // �� ��ü ���� ����
                }
            }
        }
    }
};
/*4�� �� Ŭ����*/
class Block4 : public Block {
public:
    Block4() {
        x = TABLE_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
        y = 2;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block4[i][j][k]; // �� ��ü ���� ����
                }
            }
        }
    }
};
/*5�� �� Ŭ����*/
class Block5 : public Block {
public:
    Block5() {
        x = TABLE_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
        y = 2;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block5[i][j][k]; // �� ��ü ���� ����
                }
            }
        }
    }
};

/*6�� �� Ŭ����*/
class Block6 : public Block {
public:
    Block6() {
        x = TABLE_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
        y = 2;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block6[i][j][k]; // �� ��ü ���� ����
                }
            }
        }
    }
};

/*7�� �� Ŭ����*/
class Block7 : public Block {
public:
    Block7() {
        x = TABLE_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
        y = 2;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block7[i][j][k]; // �� ��ü ���� ����
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
        //�������� ä���� ���� ���� ���� <- �������� Ʋ�� ���
        for (int i = 0; i < x; i++) {
            table[0][i] = 1;
            table[y - 1][i] = 1;
        }
        for (int i = 1; i < y - 1; i++) {
            table[i][0] = 1;
            table[i][x - 1] = 1;
        }
        //�ٴ� ���� ����� 1�� ä��
        for (int i = 1; i < x - 1; i++) {
            table[y - 1][i] = 4;
        }
        //�ٴ��� 4�� ä��
        for (int i = 1; i < x - 1; i++) {
            table[GAME_OVER][i] = 5;
        }
    }
    void DrawTable() {
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (table[i][j] == 1 || table[i][j] == 4) {
                    cout << "��";
                }
                else if (table[i][j] == 2 || table[i][j] == 3) {
                    cout << "��";
                }
                else if (table[i][j] == 5) {
                    cout << "��";
                }
                else cout << "  ";
            }
            cout << "\n";
        }
    }
    //������
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
                if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue; //�������� ����
                table[Y][X] = blockobject->getShape(blockobject->getRotationCount(), i, j);
            }
        }
    }
    //��� �������� �����ؼ� ���̺� ������Ʈ
    void RotateBlock() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockobject->getY();
                int X = i + blockobject->getX();
                if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue; //�������� ����
                if (table[Y][X] == 2) {
                    table[Y][X] = 0;
                }
            }
        }
        //������ �������� �ִ� ����� ���̺��� ������
        blockobject->rotate();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockobject->getY();
                int X = i + blockobject->getX();
                if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue; //�������� ����
                table[Y][X] = blockobject->getShape(blockobject->getRotationCount(), i, j);
            }
        }
    }
    //��� ȸ����Ű��
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
        //1��° ��� ���� ����
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
        //2��° ��� ���� ����
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
        //3��° ��� ���� ����
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
        //4��° ��� ���� ����
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
        //5��° ��� ���� ����






















        return nextblock1;
    }
    //������ ���� ��� 5���� �����ֱ�



    void LineClear() {

    }
    //����Ŭ���� ����


    void GameOver() {

    }
    //���ӿ��� ����
};




void DemoSketch() {
    Table* demo = new Table(TABLE_X, TABLE_Y);
    demo->DrawTable();
};
//�׸���



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

