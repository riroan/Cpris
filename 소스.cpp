#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


#define Up 72
#define Left 75
#define Right 77
#define Down 80
/*
← 좌측 방향키 : 75

→ 우측 방향키 : 77

↑ 위 방향키 : 72

↓ 아래 방향키 : 80

Enter키 : 13

이거 참고해서 구현해볼예정

*/ 

//블록 클래스에서 x, y좌표 선언한다 하면
void Move(const block, int key) { //블록객체랑 키값 받고

    if (key == Up) {
        rotate(); //회전함수
    }
    else if (key == Down) { //아래
        y += 1;
    }
    else if (key == Left) { //왼쪽
        x -= 1;
    }
    else if (key == Right) { //오른쪽
        x += 1;
    }
    
}


//움직였을 때 테이블에서 벗어나는지 체크
void validate(const block) {
    boolean valid = true; //기본값

    if (x < 0 || y < 0) { //블록의 현재 x좌표와 y좌표가 0보다 작아진다면
        valid = false;
    }

    // 테이블 가로, 세로 크기 넘어가면 valid false 주는 거 구현

    return valid;
} 

void validMove(const block, int key) { //최종 무브
    const clone = clone(block);
    Move(clone, key);  //실제 블록말고 클론 생성해서 얘로 미리 체크
    if (validate(clone)) { //클론으로 움직였을 때 이상없다면 실제 블록 움직임
        Move(block, key);
    }
}

//validRotate 이런식으로 하면 되나요??