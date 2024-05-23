#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define LEN_MIN 15 // 기차 길이 최소값
#define LEN_MAX 50 // 기차 길이 최대값
#define PROB_MIN 10 // 확률 최소값
#define PROB_MAX 90 // 확률 최대값

int len, C, Z, M, p;

void intro(void) {
    srand((unsigned int)time(NULL));

    printf("-------------------------------------------------------------\n");
    printf("-------------------부산행 start------------------------------\n");
    printf("--------------------20242401---------------------------------\n\n\n");

    Sleep(2000);
}

void trainfiset(void) {
    printf("기차 길이 (15~50) >> ");
    scanf_s("%d", &len);
    printf("확률 p (10~90) >> ");
    scanf_s("%d", &p);
    M = len - 2;
    Z = len - 3;
    C = len - 6; // 위치 번호를 할당합니다. 0부터 시작합니다.

    if (len > LEN_MAX || len < LEN_MIN || p > PROB_MAX || p < PROB_MIN) {
        exit(0); // 입력값이 잘못되면 종료
    }
}

void set(void) {
    // 초기 상태 출력
    for (int i = 0; i < len; i++) {
        printf("#");
    }
    printf("\n"); // 첫 번째 줄

    printf("#");
    for (int i = 1; i < C; i++) {
        printf(" ");
    }
    printf("C");
    for (int i = C + 1; i < Z; i++) {
        printf(" ");
    }
    printf("Z");
    for (int i = Z + 1; i < M; i++) {
        printf(" ");
    }
    printf("M");
    printf("#\n"); // 두 번째 줄

    for (int i = 0; i < len; i++) {
        printf("#");
    }
    printf("\n\n\n"); // 세 번째 줄
}

void citizen(void) {
    int r = rand() % 100; // 시민 이동 여부
    if (p <= r && r < 100) {
        C--;
    }
}

void zombie(void) {
    int k = rand() % 100; // 좀비 이동 여부
    if (0 <= k && k < p) {
        Z--;
    }
}

void trainset(void) {
    // 열차 상태 출력
    for (int i = 0; i < len; i++) {
        printf("#");
    }
    printf("\n");

    printf("#");
    for (int i = 1; i < C; i++) {
        printf(" ");
    }
    printf("C");
    for (int i = C + 1; i < Z; i++) {
        printf(" ");
    }
    printf("Z");
    for (int i = Z + 1; i < M; i++) {
        printf(" ");
    }
    printf("M");
    printf("#\n");

    for (int i = 0; i < len; i++) {
        printf("#");
    }
    printf("\n\n\n");
}

void odd(void) {
    int r = rand() % 100;
    int k = rand() % 100;

    // 홀수 턴 시민, 좀비 상태 출력
    if (p <= r && r < 100) {
        printf("시민: %d -> %d\n", C + 1, C);
    }
    else {
        printf("시민: 유지 %d\n", C);
    }

    if (0 <= k && k < p) {
        printf("좀비: %d -> %d\n", Z + 1, Z);
    }
    else {
        printf("좀비: 유지 %d\n", Z);
    }
    printf("\n\n\n");
}

void evencitizen(void) {
    int h = rand() % 100;
    if (p <= h && h < 100) {
        C--;
    }
}

void trainset2(void) {
    // 열차 상태 출력
    for (int i = 0; i < len; i++) {
        printf("#");
    }
    printf("\n");

    printf("#");
    for (int i = 1; i < C; i++) {
        printf(" ");
    }
    printf("C");
    for (int i = C + 1; i < Z; i++) {
        printf(" ");
    }
    printf("Z");
    for (int i = Z + 1; i < M; i++) {
        printf(" ");
    }
    printf("M");
    printf("#\n");

    for (int i = 0; i < len; i++) {
        printf("#");
    }
    printf("\n\n\n");
}

void even(void) {
    int h = rand() % 100;

    // 짝수 턴 시민 상태 출력
    if (p <= h && h < 100) {
        printf("시민: %d -> %d\n", C + 1, C);
    }
    else {
        printf("시민: 유지 %d\n", C);
    }

    printf("좀비: 유지 %d (움직일 수 없음)\n", Z);
    printf("\n\n\n");
}

int main(void) {
    intro();
    trainfiset();
    set();

    while (1) {
        odd();
        citizen();
        zombie();
        trainset();

        if (Z - C == 1 || C == 1) {
            break;
        }
        Sleep(4000);

        evencitizen();
        trainset2();
        even();

        if (Z - C == 1 || C == 1) {
            break;
        }
        Sleep(4000);
    }

    if (Z - C == 1) {
        printf("게임 오버!\n시민이 좀비에게 공격받았습니다.");
    }
    if (C == 1) {
        printf("스테이지 클리어!\n시민이 다음 기차로 도망쳤습니다.");
    }

    return 0;
}
