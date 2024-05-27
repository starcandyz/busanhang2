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

int len, C, Z, M, p, S;
int citizen_agg = 1;
int dongseok_agg = 1;
int dongseck_move;

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
        scanf_s("%d", &S);
    } while (S > STH_MAX && S < STH_MIN);

    do {
        printf("Ȯ�� p (10~90) >> ");
        scanf_s("%d", &p);
    } while (p > PROB_MAX && p < PROB_MIN);
    M = len - 2;
    Z = len - 3;
    C = len - 6; // ��ġ ��ȣ�� �Ҵ��մϴ�. 0���� �����մϴ�.
}

void set(void) {
    // �ʱ� ���� ���
    for (int i = 0; i < len; i++) {
        printf("#");
    }
    printf("\n"); // ù ��° ��

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
    printf("\n"); // �� ��° ��

    for (int i = 0; i < len; i++) {
        printf("#");
    }
    printf("\n\n\n"); // �� ��° ��
}

void citizen(void) {
    int r = rand() % 100; // �ù� �̵� ����
    if (p <= r && r < 100) {
        C--;
    }
}

void zombie(void) {
    int k = rand() % 100; // ���� �̵� ����
    if (0 <= k && k < p) {
        Z--;
    }
}

void trainset(void) {
    // ���� ���� ���
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

    // Ȧ�� �� �ù�, ���� ���� ���
    if (p <= r && r < 100) {
        printf("�ù�: %d -> %d (��׷�: %d)\n", C + 1, C, citizen_agg);
    }
    else {
        printf("�ù�: ���� %d\n", C);
    }

    if (0 <= k && k < p) {
        printf("����: %d -> %d\n", Z + 1, Z);
    }
    else {
        printf("����: ���� %d\n", Z);
    }
    printf("\n");
    do {
        printf("������ �̵�(0 : stay, 1:left) >> ");
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

void trainset2(void) { // ���� ���� ���
    for (int i = 0; i < len; i++) {
        printf("#");
    }
    printf("\n"); // ù ��° ��

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
    printf("\n"); // �� ��° ��

    for (int i = 0; i < len; i++) {
        printf("#");
    }
    printf("\n\n\n"); // �� ��° ��
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

    printf("����: ���� %d (������ �� ����)\n", Z);
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
        printf("���� ����!\n�ù� ��� ���񿡰� ���ݹ޾ҽ��ϴ�.");
    }
    if (C == 1) {
        printf("�������� Ŭ����!\n�ù��� ���� ������ �����ƽ��ϴ�.");
    }

    return 0;
}
