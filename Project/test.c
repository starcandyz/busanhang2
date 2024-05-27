#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define LEN_MIN 15 // 기차 길이 최소값
#define LEN_MAX 50 // 기차 길이 최대값
#define STH_MIN 0  // 마동석 체력 최소값
#define STH_MAX 5  // 마동석 체력 최대값
#define PROB_MIN 10 // 확률 최소값
#define PROB_MAX 90 // 확률 최대값
#define AGGRO_MIN 0 // 어그로 범위 최소값
#define AGGRO_MAX 5 // 어그로 범위 최대값

// 마동석 이동 방향
#define MOVE_LEFT 1
#define MOVE_STAY 0

// 좀비의 공격 대상
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2

// 마동석 행동
#define ACTION_REST 0
#define ACTION_CITIZEN 1
#define ACTION_PULL 2

int len, C, Z, M, p, S;
int citizen_agg = 1;
int dongseok_agg = 1;
int dongseck_move;

void intro(void) {
    srand((unsigned int)time(NULL));

    printf("-------------------------------------------------------------\n");
    printf("-------------------부산행 start------------------------------\n");
    printf("--------------------20242401---------------------------------\n");
    printf("-------------------------------------------------------------\n\n\n");

    Sleep(2000);
}

void fiset(void) {
    do {
        printf("기차 길이 (15~50) >> ");
        scanf_s("%d", &len);
    } while (len > LEN_MAX || len < LEN_MIN);

    do {
        printf("마동석 체력(0~5) >> ");
        scanf_s("%d", &S);
    } while (S > STH_MAX && S < STH_MIN);

    do {
        printf("확률 p (10~90) >> ");
        scanf_s("%d", &p);
    } while (p > PROB_MAX && p < PROB_MIN);
    M = len - 2;
    Z = len - 3;
    C = len - 6; // 위치 번호를 할당합니다. 0부터 시작합니다.
}

void set(void) {
    // 초기 상태 출력
    for (int i = 0; i < len; i++) {
        printf("#");
    }
    printf("\n"); // 첫 번째 줄

    for (int i = 0; i < len; i++) {
        if (i == 0 || i == len - 1) {
            printf("#");
        }
        else if (i == C) {
            printf("C");
        }
        else if (i == Z) {
            printf("Z");
        }
        else if (i == M) {
            printf("M");
        }
        else {
            printf(" ");
        }
    }
    printf("\n"); // 두 번째 줄

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
        printf("시민: %d -> %d (어그로: %d)\n", C + 1, C, citizen_agg);
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
    printf("\n");
    do {
        printf("마동석 이동(0 : stay, 1:left) >> ");
        scanf_s("%d", &dongseck_move);
    } while (dongseck_move <= MOVE_STAY && dongseck_move >= MOVE_LEFT);
    printf("\n");
}

void evencitizen(void) {
    int h = rand() % 100;
    if (p <= h && h < 100) {
        C--;
    }
}

void trainset2(void) { // 열차 상태 출력
    for (int i = 0; i < len; i++) {
        printf("#");
    }
    printf("\n"); // 첫 번째 줄

    for (int i = 0; i < len; i++) {
        if (i == 0 || i == len - 1) {
            printf("#");
        }
        else if (i == C) {
            printf("C");
        }
        else if (i == Z) {
            printf("Z");
        }
        else if (i == M) {
            printf("M");
        }
        else {
            printf(" ");
        }
    }
    printf("\n"); // 두 번째 줄

    for (int i = 0; i < len; i++) {
        printf("#");
    }
    printf("\n\n\n"); // 세 번째 줄
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
    fiset();
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
        printf("게임 오버!\n시민 모두 좀비에게 공격받았습니다.");
    }
    if (C == 1) {
        printf("스테이지 클리어!\n시민이 다음 기차로 도망쳤습니다.");
    }

    return 0;
}
