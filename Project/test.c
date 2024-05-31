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

int len, C, Z, M, p, dongseok_stamina;
int citizen_agg = 1;
int dongseok_agg = 1;
int dongseok_move;
int dongseok_action;
int zombie_next_turn_disabled = 0;

int random;
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
        scanf_s("%d", &dongseok_stamina);
    } while (dongseok_stamina > STH_MAX || dongseok_stamina < STH_MIN);

    do {
        printf("확률 p (10~90) >> ");
        scanf_s("%d", &p);
    } while (p > PROB_MAX || p < PROB_MIN);
    M = len - 2;
    Z = len - 3;
    C = len - 6; // 위치 번호를 할당합니다. 0부터 시작합니다.
}


void citizen(void) {
    random = rand() % 100; // 시민 이동 여부
    if (random < 100 - p) {
        C--;
        citizen_agg++;
    }
    else {
        citizen_agg--;
        if (citizen_agg < AGGRO_MIN) citizen_agg = AGGRO_MIN;
    }
}

void zombie(void) {
    if (citizen_agg >= dongseok_agg) {
        Z--;
    }
    // 좀비가 시민이나 마동석과 인접한 경우
    if ((Z == C + 1 || Z == C + 1) && (Z == M + 1 || Z == M - 1)) {
        if (citizen_agg > dongseok_agg) {
            printf("게임 오버!\n시민 모두 좀비에게 공격받았습니다.\n");
            exit(0);
        }
        else {
            dongseok_stamina--;
            if (dongseok_stamina <= 0) {
                printf("마동석의 체력이 모두 소모되었습니다.\n");
                exit(0);
            }
        }
    }
    else if (Z == C + 1 || Z == C - 1) {
        printf("게임 오버!\n시민 모두 좀비에게 공격받았습니다.\n");
        exit(0);
    }
    else if (Z == M + 1 || Z == M - 1) {
        dongseok_stamina--;
        if (dongseok_stamina <= 0) {
            printf("마동석이 죽었습니다! 게임 오버!\n");
            exit(0);
        }
    }
}

void trainset(void) {
    // 열차 상태 출력
    for (int i = 0; i < len; i++) {
        printf("#");
    }
    printf("\n");

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
    printf("\n");

    for (int i = 0; i < len; i++) {
        printf("#");
    }
    printf("\n\n\n");
}

void odd(void) {
    int k = rand() % 100;

    // 홀수 턴 시민, 좀비 상태 출력
    if (random < 100 - p) {
        printf("시민: %d -> %d (어그로: %d)\n", C + 1, C, citizen_agg);
    }
    else {
        printf("시민: 유지 %d (어그로: %d)\n", C, citizen_agg);
    }

    if (0 <= k && k < p) {
        printf("좀비: %d -> %d\n", Z + 1, Z);
    }
    else {
        printf("좀비: 유지 %d\n", Z);
    }
    printf("\n");
}

void dongseokmove(void) {
    do {
        printf("마동석 이동(0: stay, 1:left) >> ");
        scanf_s("%d", &dongseok_move);
    } while (dongseok_move < MOVE_STAY || dongseok_move > MOVE_LEFT);
    printf("\n");
    if (dongseok_move == MOVE_LEFT) {
        M--;
    }
    else if (dongseok_move == MOVE_STAY) {
        dongseok_agg--;
        if (dongseok_agg < AGGRO_MIN) dongseok_agg = AGGRO_MIN;
        printf("마동석: stay %d (aggro: %d -> %d, stamina: %d)\n\n", M, dongseok_agg + 1, dongseok_agg, dongseok_stamina);
    }
    trainset(); // 마동석 이동 후 열차 상태 출력
}

void nothing() {
    if (C == 1) {
        printf("Game Clear!!");
    }
    printf("시민은 아무것도 하지않는다.\n");
}

void zombie_not_attack() {
    if (Z == C - 1 && Z == M + 1) {
        printf("zombie attacked nobody.\n");
    }
}

void dongseokaction() {
    printf("마동석 행동(0: 휴식, 1: 도발, 2: 붙잡기)>> ");
    scanf_s("%d", &dongseok_action);
    if (dongseok_action == 1) {
        dongseok_agg == AGGRO_MAX;
    }
    else if(dongseok_action == 2) {
        dongseok_agg += 2;
        dongseok_stamina--;
        printf("마동석이 붙잡기 시도! (aggro: %d, stamina: %d)\n", dongseok_agg, dongseok_stamina);
        random = rand() % 100;
        if (random < 100 - p) {
            printf("붙잡기 성공! 좀비는 다음 턴에 이동할 수 없습니다.\n");
            zombie_next_turn_disabled = 1;
        }
        else {
            printf("붙잡기 실패...\n");
        }
    }
     else {
            printf("마동석이 휴식 중입니다.\n");
            dongseok_agg--;
            dongseok_stamina++;
            }
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

    printf("좀비: %d (움직일 수 없음)\n", Z);
    printf("\n\n\n");
}

int main(void) {
    intro();
    fiset();
    trainset();

    while (1) {
        citizen();
        zombie();
        trainset();
        odd();
        if (Z - C == 1 || C == 1) {
            break;
        }
        Sleep(4000);
        dongseokmove();
        nothing();
        zombie_not_attack();
        dongseokaction();
        trainset();
        even();
    }

    if (Z - C == 1) {
        printf("게임 오버!\n시민 모두 좀비에게 공격받았습니다.");
    }
    
    if (C == 1) {
        printf("스테이지 클리어!\n시민이 다음 기차로 도망쳤습니다.");
    }

    return 0;
}
