#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


#define Up 72
#define Left 75
#define Right 77
#define Down 80
/*
�� ���� ����Ű : 75

�� ���� ����Ű : 77

�� �� ����Ű : 72

�� �Ʒ� ����Ű : 80

EnterŰ : 13

�̰� �����ؼ� �����غ�����

*/ 

//��� Ŭ�������� x, y��ǥ �����Ѵ� �ϸ�
void Move(const block, int key) { //��ϰ�ü�� Ű�� �ް�

    if (key == Up) {
        rotate(); //ȸ���Լ�
    }
    else if (key == Down) { //�Ʒ�
        y += 1;
    }
    else if (key == Left) { //����
        x -= 1;
    }
    else if (key == Right) { //������
        x += 1;
    }
    
}


//�������� �� ���̺��� ������� üũ
void validate(const block) {
    boolean valid = true; //�⺻��

    if (x < 0 || y < 0) { //����� ���� x��ǥ�� y��ǥ�� 0���� �۾����ٸ�
        valid = false;
    }

    // ���̺� ����, ���� ũ�� �Ѿ�� valid false �ִ� �� ����

    return valid;
} 

void validMove(const block, int key) { //���� ����
    const clone = clone(block);
    Move(clone, key);  //���� ��ϸ��� Ŭ�� �����ؼ� ��� �̸� üũ
    if (validate(clone)) { //Ŭ������ �������� �� �̻���ٸ� ���� ��� ������
        Move(block, key);
    }
}

//validRotate �̷������� �ϸ� �ǳ���??