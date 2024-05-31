#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define LEN_MIN 15 // ���� ���� �ּҰ�
#define LEN_MAX 50 // ���� ���� �ִ밪
#define STH_MIN 0  // ������ ü�� �ּҰ�
#define STH_MAX 5  // ������ ü�� �ִ밪
#define PROB_MIN 10 // Ȯ�� �ּҰ�
#define PROB_MAX 90 // Ȯ�� �ִ밪
#define AGGRO_MIN 0 // ��׷� ���� �ּҰ�
#define AGGRO_MAX 5 // ��׷� ���� �ִ밪

// ������ �̵� ����
#define MOVE_LEFT 1
#define MOVE_STAY 0

// ������ ���� ���
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2

// ������ �ൿ
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
    printf("-------------------�λ��� start------------------------------\n");
    printf("--------------------20242401---------------------------------\n");
    printf("-------------------------------------------------------------\n\n\n");

    Sleep(2000);
}

void fiset(void) {
    do {
        printf("���� ���� (15~50) >> ");
        scanf_s("%d", &len);
    } while (len > LEN_MAX || len < LEN_MIN);

    do {
        printf("������ ü��(0~5) >> ");
        scanf_s("%d", &dongseok_stamina);
    } while (dongseok_stamina > STH_MAX || dongseok_stamina < STH_MIN);

    do {
        printf("Ȯ�� p (10~90) >> ");
        scanf_s("%d", &p);
    } while (p > PROB_MAX || p < PROB_MIN);
    M = len - 2;
    Z = len - 3;
    C = len - 6; // ��ġ ��ȣ�� �Ҵ��մϴ�. 0���� �����մϴ�.
}


void citizen(void) {
    random = rand() % 100; // �ù� �̵� ����
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
    // ���� �ù��̳� �������� ������ ���
    if ((Z == C + 1 || Z == C + 1) && (Z == M + 1 || Z == M - 1)) {
        if (citizen_agg > dongseok_agg) {
            printf("���� ����!\n�ù� ��� ���񿡰� ���ݹ޾ҽ��ϴ�.\n");
            exit(0);
        }
        else {
            dongseok_stamina--;
            if (dongseok_stamina <= 0) {
                printf("�������� ü���� ��� �Ҹ�Ǿ����ϴ�.\n");
                exit(0);
            }
        }
    }
    else if (Z == C + 1 || Z == C - 1) {
        printf("���� ����!\n�ù� ��� ���񿡰� ���ݹ޾ҽ��ϴ�.\n");
        exit(0);
    }
    else if (Z == M + 1 || Z == M - 1) {
        dongseok_stamina--;
        if (dongseok_stamina <= 0) {
            printf("�������� �׾����ϴ�! ���� ����!\n");
            exit(0);
        }
    }
}

void trainset(void) {
    // ���� ���� ���
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

    // Ȧ�� �� �ù�, ���� ���� ���
    if (random < 100 - p) {
        printf("�ù�: %d -> %d (��׷�: %d)\n", C + 1, C, citizen_agg);
    }
    else {
        printf("�ù�: ���� %d (��׷�: %d)\n", C, citizen_agg);
    }

    if (0 <= k && k < p) {
        printf("����: %d -> %d\n", Z + 1, Z);
    }
    else {
        printf("����: ���� %d\n", Z);
    }
    printf("\n");
}

void dongseokmove(void) {
    do {
        printf("������ �̵�(0: stay, 1:left) >> ");
        scanf_s("%d", &dongseok_move);
    } while (dongseok_move < MOVE_STAY || dongseok_move > MOVE_LEFT);
    printf("\n");
    if (dongseok_move == MOVE_LEFT) {
        M--;
    }
    else if (dongseok_move == MOVE_STAY) {
        dongseok_agg--;
        if (dongseok_agg < AGGRO_MIN) dongseok_agg = AGGRO_MIN;
        printf("������: stay %d (aggro: %d -> %d, stamina: %d)\n\n", M, dongseok_agg + 1, dongseok_agg, dongseok_stamina);
    }
    trainset(); // ������ �̵� �� ���� ���� ���
}

void nothing() {
    if (C == 1) {
        printf("Game Clear!!");
    }
    printf("�ù��� �ƹ��͵� �����ʴ´�.\n");
}

void zombie_not_attack() {
    if (Z == C - 1 && Z == M + 1) {
        printf("zombie attacked nobody.\n");
    }
}

void dongseokaction() {
    printf("������ �ൿ(0: �޽�, 1: ����, 2: �����)>> ");
    scanf_s("%d", &dongseok_action);
    if (dongseok_action == 1) {
        dongseok_agg == AGGRO_MAX;
    }
    else if(dongseok_action == 2) {
        dongseok_agg += 2;
        dongseok_stamina--;
        printf("�������� ����� �õ�! (aggro: %d, stamina: %d)\n", dongseok_agg, dongseok_stamina);
        random = rand() % 100;
        if (random < 100 - p) {
            printf("����� ����! ����� ���� �Ͽ� �̵��� �� �����ϴ�.\n");
            zombie_next_turn_disabled = 1;
        }
        else {
            printf("����� ����...\n");
        }
    }
     else {
            printf("�������� �޽� ���Դϴ�.\n");
            dongseok_agg--;
            dongseok_stamina++;
            }
    }

void even(void) {
    int h = rand() % 100;

    // ¦�� �� �ù� ���� ���
    if (p <= h && h < 100) {
        printf("�ù�: %d -> %d\n", C + 1, C);
    }
    else {
        printf("�ù�: ���� %d\n", C);
    }

    printf("����: %d (������ �� ����)\n", Z);
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
        printf("���� ����!\n�ù� ��� ���񿡰� ���ݹ޾ҽ��ϴ�.");
    }
    
    if (C == 1) {
        printf("�������� Ŭ����!\n�ù��� ���� ������ �����ƽ��ϴ�.");
    }

    return 0;
}
