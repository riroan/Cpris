#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstdlib> // rand
#include <ctime> // time
#include <algorithm> // copy
using namespace std;

#define TABLE_X 20 //��Ʈ���� �� x �� ����
#define TABLE_Y 38 //��Ʈ���� �� y �� ����
#define LEFT 75 // ��
#define RIGHT 77  // ��
#define UP 72 // ��
#define DOWN 80 // ��

//�� Ŭ����, ��� Ŭ����, ���� ���� ���� �Լ��� ��Ƴ��� Ŭ����
//Ŭ���� �̿��� �Ÿ� ���� �ڵ忡 ���缭 ���� ��� �����ϴ� �� ���� ��

//�� ����
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


//�� �θ� Ŭ����
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
};



/*1�� �� Ŭ����*/
class Block1 : public Block {
public:
    Block1() {
        x = TABLE_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
        y = 1;
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
        y = 1;
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
        y = 1;
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
        y = 1;
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
        y = 1;
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



/*��, table ����� Ŭ����*/
class backup {
public:
    /*�� ���*/
    static void updateBlock(Block* source, Block& backupBlock) {
        backupBlock.setX(source->getX()); // ���� x��ǥ ���
        backupBlock.setY(source->getY()); // ���� y��ǥ ���
        backupBlock.setRotationCount(source->getRotationCount()); // ���� ȸ�� ���� ���� ���
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    backupBlock.setShape(i, j, k, source->getShape(i, j, k)); // ���� ��� ���
                }
            }
        }
    }
    /*table ���*/
    static void updateTable(vector<vector<int> >& source, vector<vector<int> >& backupTable) {
        backupTable.resize(source.size(), vector<int>(source.size())); // ���� table�� ũ�⸸ŭ 2���� ���� ũ�� �Ҵ�
        copy(source.begin(), source.end(), backupTable.begin()); // ���� table vector�� backupTable vector�� ���
    }
};


//���� ���� ���� �Լ���
/*��Ʈ���� ���� ���̺� Ŭ����*/
class GameTable {
private:
    int x; // ����
    int y; // ����
    Block* blockObject;
    vector<vector<int> > table; // �� ���� ����� table[y][x]
public:
    GameTable(int x, int y) { //��Ʈ���� �� ���� ����
        blockObject = nullptr;
        this->x = x;
        this->y = y;
        for (int i = 0; i < y; i++) {
            vector<int> temp;
            for (int j = 0; j < x; j++) {
                temp.push_back(0);
            }
            table.push_back(temp);
        }
        //���� �ڸ� ���� ��ĥ
        for (int i = 0; i < x; i++) {
            table[0][i] = 1;
            table[y - 1][i] = 1;
        }
        for (int i = 1; i < y - 1; i++) {
            table[i][0] = 1;
            table[i][x - 1] = 1;
        }
        /*�� �عٴ� ������ 4*/
        for (int i = 1; i < x - 1; i++) {
            table[y - 1][i] = 4; // �� ���� ���� 4
        }
    }
    /*������ �׸��� �Լ�*/
    void DrawGameTable() {
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (table[i][j] == 1 || table[i][j] == 4) cout << "��";
                else if (table[i][j] == 2 || table[i][j] == 3) cout << "��";
                else cout << "  "; // �� ĭ ����
            }
            cout << "\n";
        }
    }


    //�� ����
    void createBlock() {
        srand((unsigned int)time(NULL));
        int select = rand() % 5 + 1; // 1 ~ 5 ��
        if (select == 1) blockObject = new Block1(); // 1�� �� ����
        else if (select == 2)blockObject = new Block2(); // 2�� �� ����
        else if (select == 3)blockObject = new Block3(); // 3�� �� ����
        else if (select == 4)blockObject = new Block4(); // 4�� �� ����
        else if (select == 5)blockObject = new Block5(); // 5�� �� ����
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();
                table[Y][X] = blockObject->getShape(blockObject->getRotationCount(), i, j);
                //�� ��ü�� ���̺� ������Ʈ
            }
        }
    }
    


    //���⼭���� ���� �Ҹ���?
    //�� �̵�
    void MoveBlock(int key) {
        /*���*/
        Block backupBlock; // ����� Block ��ü
        vector<vector<int> > backupTable; // ����� table vector
        backup::updateBlock(blockObject, backupBlock); // block ���
        backup::updateTable(table, backupTable); // table ���
        /*���̺��� �� ��ü �����*/
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();
                if (table[Y][X] == 2) { // ���� ���̸�
                    table[Y][X] = 0; // ���̺��� �����
                }
            }
        }
        /*�� �̵�*/
        if (key == DOWN) blockObject->down(); // ���� ���ڷ� ���� key�� �Ʒ� �����̸� ���� �Ʒ��� �̵�
        else if (key == LEFT) blockObject->left();  // ���� ���ڷ� ���� key�� ���� �����̸� ���� �������� �̵�
        else if (key == RIGHT) blockObject->right(); // ���� ���ڷ� ���� key�� ������ �����̸� ���� ���������� �̵�
        /*�̵��� �� ���¸� ���̺� ���� or ���*/
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();
                int blockValue = blockObject->getShape(blockObject->getRotationCount(), i, j); //�� �迭 �� ���
                if (blockValue != 2) continue; // ���� �ƴϸ� ���� (���� 2�� �̷��������)
                if (table[Y][X] == 0) { // ������̸� (����)
                    table[Y][X] = blockValue; // ���� �̵���Ŵ
                }
                else if (table[Y][X] == 1) { // ���� �� �� ���鿡 ������ (���)
                    copy(backupTable.begin(), backupTable.end(), table.begin()); // table ���
                    blockObject->setX(backupBlock.getX()); // �� x ��ǥ ���
                    blockObject->setY(backupBlock.getY()); // �� y ��ǥ ���
                    return; // �Լ� ����
                }
                else if (table[Y][X] == 3) { // �̹� �׿��� ���� �����ϸ�
                    copy(backupTable.begin(), backupTable.end(), table.begin()); // table ���
                    blockObject->setX(backupBlock.getX()); // �� x ��ǥ ���
                    blockObject->setY(backupBlock.getY()); // �� y ��ǥ ���
                    if (key == DOWN) { // ���� �Ʒ� ������ ��쿡
                        BuildBlock(); // ���� �װ�
                        createBlock(); // ���ο� ���� ����
                    }
                    return; // �Լ� ����
                }
                else if (table[Y][X] == 4) { //���࿡ �� �عٴڿ� ����������
                    copy(backupTable.begin(), backupTable.end(), table.begin()); // table ���
                    blockObject->setX(backupBlock.getX()); // �� x ��ǥ ���
                    blockObject->setY(backupBlock.getY()); // �� y ��ǥ ���
                    if (key == DOWN) { // ���� �Ʒ� ������ ��쿡
                        BuildBlock(); // ���� �װ�
                        createBlock(); // ���ο� ���� ����
                    }
                    return; // �Լ� ����
                }
            }
        }
    }
    
    //�� ȸ��
    void RotateBlock() {
        /*���*/
        Block backupBlock; // ����� Block ��ü
        vector<vector<int> > backupTable; // ����� table vector
        backup::updateBlock(blockObject, backupBlock); // block ���
        backup::updateTable(table, backupTable); // table ���
        /*���̺��� �� ��ü �����*/
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();
                if (table[Y][X] == 2) { // ���� ���̸�
                    table[Y][X] = 0; // ���̺��� �����
                }
            }
        }
        /*�� ȸ��*/
        blockObject->rotate(); // ���� ȸ��
        /*ȸ���� �� ���¸� ���̺� ���� �� ���*/
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();
                int blockValue = blockObject->getShape(blockObject->getRotationCount(), i, j); //�� �迭 �� ���
                if (blockValue != 2) continue; // ���� �ƴϸ� ���� (���� 2�� �̷��������)
                if (table[Y][X] == 0) { //������� ��쿡 �̵��� �� ������ ���̺� ����
                    table[Y][X] = blockObject->getShape(blockObject->getRotationCount(), i, j);
                }
                else if (table[Y][X] == 1 || table[Y][X] == 3 || table[Y][X] == 4) { // ��&��, ��&�� ���� �� ���
                    copy(backupTable.begin(), backupTable.end(), table.begin()); // table ���
                    blockObject->setRotationCount(backupBlock.getRotationCount()); // ȸ���ϱ� �� ���·� ���
                    return; // ������Ʈ ���
                }
            }
        }
    }
    /*���� table�� �ױ�*/
    void BuildBlock() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();
                int blockValue = blockObject->getShape(blockObject->getRotationCount(), i, j); //�� �迭 �� ���
                if (blockValue != 2) continue; // ���� �ƴϸ� ���� (���� 2�� �̷��������)
                table[Y][X] = 3;
            }
        }
    }

};
//���� ���� Ŭ����
class GamePlay {
private:
    GameTable* gt;
public:
    GamePlay() {
        gt = new GameTable(TABLE_X, TABLE_Y); //���� �� �׸��� ��ü ����
        gt->createBlock(); // �ʱ� �� ����
        gt->DrawGameTable(); // �������� �׸���.
        while (true) { // ����Ű �Է� �̺�Ʈ
            int nSelect;
            if (_kbhit()) {
                nSelect = _getch();
                if (nSelect == 224) {
                    nSelect = _getch();
                    switch (nSelect) {
                    case UP: // ȭ��ǥ �� ������ ��
                        gt->RotateBlock(); // ���� 90�� ȸ�� 
                        break;
                    case DOWN: // ȭ��ǥ �Ʒ� ������ ��
                        gt->MoveBlock(DOWN); // ���� �� ĭ �Ʒ��� �̵�
                        break;
                    case LEFT: // ȭ��ǥ ���� ������ ��
                        gt->MoveBlock(LEFT); // ���� �� ĭ �������� �̵�
                        break;
                    case RIGHT: // ȭ��ǥ ������ ������ ��
                        gt->MoveBlock(RIGHT); // ���� �� ĭ ���������� �̵�
                        break;
                    default:
                        break;
                    }
                }
            }
            //gotoxy(0, 0); //system("cls") �Ⱦ��� (0, 0)���� Ŀ�� �̵� ��
            //gt->DrawGameTable(); // �ٽ� �׸���
        }
    }
    ~GamePlay() { // ���� ���� �̺�Ʈ
        delete gt;
    }
};

