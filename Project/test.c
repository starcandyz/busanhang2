#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define LEN_MIN 15 // ���� ���� �ּҰ�
#define LEN_MAX 50 // ���� ���� �ִ밪
#define PROB_MIN 10 // Ȯ�� �ּҰ�
#define PROB_MAX 90 // Ȯ�� �ִ밪

int len, C, Z, M, p;

void intro(void) {
    srand((unsigned int)time(NULL));

    printf("-------------------------------------------------------------\n");
    printf("-------------------�λ��� start------------------------------\n");
    printf("--------------------20242401---------------------------------\n\n\n");

    Sleep(2000);
}

void trainfiset(void) {
    printf("���� ���� (15~50) >> ");
    scanf_s("%d", &len);
    printf("Ȯ�� p (10~90) >> ");
    scanf_s("%d", &p);
    M = len - 2;
    Z = len - 3;
    C = len - 6; // ��ġ ��ȣ�� �Ҵ��մϴ�. 0���� �����մϴ�.

    if (len > LEN_MAX || len < LEN_MIN || p > PROB_MAX || p < PROB_MIN) {
        exit(0); // �Է°��� �߸��Ǹ� ����
    }
}

void set(void) {
    // �ʱ� ���� ���
    for (int i = 0; i < len; i++) {
        printf("#");
    }
    printf("\n"); // ù ��° ��

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
    printf("#\n"); // �� ��° ��

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

    // Ȧ�� �� �ù�, ���� ���� ���
    if (p <= r && r < 100) {
        printf("�ù�: %d -> %d\n", C + 1, C);
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
    printf("\n\n\n");
}

void evencitizen(void) {
    int h = rand() % 100;
    if (p <= h && h < 100) {
        C--;
    }
}

void trainset2(void) {
    // ���� ���� ���
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
        printf("���� ����!\n�ù��� ���񿡰� ���ݹ޾ҽ��ϴ�.");
    }
    if (C == 1) {
        printf("�������� Ŭ����!\n�ù��� ���� ������ �����ƽ��ϴ�.");
    }

    return 0;
}
