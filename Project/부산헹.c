//#include <stdio.h>
//#include <stdlib.h>
//#include<windows.h>
//#include<time.h>
//
//#define LEN_MIN 15 //기차길이
//#define LEN_MAX 50
//#define STM_MIN 10 // 마동석 체력
//#define STM_MAX 5
//#define PROB_MIN 10
//#define PROB_MAX 90
//#define AGGRO_MIN 0
//#define AGGRO_MAX 5
//
//
//int intro(void) {
//	
//	srand((unsigned int)time(NULL));
//
//	printf("-------------------------------------------------------------\n");
//	printf("-------------------부산헹 start------------------------------\n");
//	printf("--------------------20242401---------------------------------\n\n\n");
//
//	Sleep(2000);
//}
//int trainfiset(void) {
//
//	int len, c, z, m, p;
//	printf("train length(15~50)>>");  scanf_s("%d", &len);
//	printf("percentile probability 'p'(10~90)>>"); scanf_s("%d", &p);
//	m = len - 2; z = len - 3; c = len - 6;//각 변수에 할당하는 값은 위치번호. 0부터 시작.
//
//	if (len > len_max || len <len_min || p > prob_max || p < prob_min) { exit(0); }//입력값 잘못되면 종료
//}
//int set(void) {
//
//	//초기 상태 출력
//	for (int i = 0; i <= len - 1; i++) { printf("#"); } 
//	printf("\n");//first line
//
//	printf("#"); 
//	for (int i = 1; i < C; i++) { printf(" "); }
//	printf("C");
//	for (int i = C + 1; i < Z; i++) { printf(" "); }
//	printf("Z");
//	for (int i = Z + 1; i < M; i++) { printf(" "); }
//	printf("M"); printf("#");  printf("\n");//second line
//
//	for (int i = 0; i <= len - 1; i++) { printf("#"); } //third line
//	printf("\n\n\n");
//}
//
//
//	while (1) {//홀수 턴 시민이나 좀비 상태 조정
//
//int citizen(void) {
//
//		int r = rand() % 100; //citizen staying or moving
//		if (p <= r && r < 100) { C--; }
//		else { C; }
//}
//int zombie(void) {
//
//		int k = rand() % 100; //zombie staying or moving
//		if (0 <= k && k < p) { Z--; }
//		else { Z; }
//}
//int trainset(void) {
//
//		//열차 상태 출력
//		for (int i = 0; i <= len - 1; i++) { printf("#"); } //first line
//		printf("\n");
//
//		printf("#"); //second line
//		for (int i = 1; i < C; i++) { printf(" "); }
//		printf("C");
//		for (int i = C + 1; i < Z; i++) { printf(" "); }
//		printf("Z");
//		for (int i = Z + 1; i < M; i++) { printf(" "); }
//		printf("M"); printf("#");  printf("\n");
//
//		for (int i = 0; i <= len - 1; i++) { printf("#"); } //third line
//		printf("\n\n\n");
//}
//int odd(void) {
//
//
//		//홀수 턴 시민, 좀비 상태 출력
//		if (p <= r && r < 100) { printf("citizen : %d -> %d\n", C + 1, C); }
//		else { printf("citizen : stay %d\n", C); }
//
//		if (0 <= k && k < p) { printf("zombie : %d -> %d\n", Z + 1, Z); }
//		else { printf("zombie : stay %d\n", Z); }
//		printf("\n\n\n");
//	//홀수 턴 끝
//		if (Z - C == 1 || C == 1) { break; }
//		Sleep(4000);
//}
//
//int evencitizen(void) {
//
//		//짝수 턴 시민 상태 조정 (좀비는 짝수 턴에 움직이지 않는다.)
//		int h = rand() % 100;
//		if (p <= h && h < 100) { C--; }
//		else { C; }
//}
//int trainset2(void) {
//
//
//		//열차 상태 출력
//
//		for (int i = 0; i <= len - 1; i++) { printf("#"); } //first line
//		printf("\n");
//
//		printf("#"); //second line
//		for (int i = 1; i < C; i++) { printf(" "); }
//		printf("C");
//		for (int i = C + 1; i < Z; i++) { printf(" "); }
//		printf("Z");
//		for (int i = Z + 1; i < M; i++) { printf(" "); }
//		printf("M"); printf("#");  printf("\n");
//
//		for (int i = 0; i <= len - 1; i++) { printf("#"); } //third line
//		printf("\n\n\n");
//}
//int even(void) {
//
//		//짝수 턴 시민, 좀비 상태 출력
//		if (p <= h && h < 100) { printf("citizen : %d -> %d\n", C + 1, C); }
//		else { printf("citizen : stay %d\n", C); }
//
//		printf("zombie : stay %d (cannot move)\n", Z);
//		printf("\n\n\n");
//		//짝수 턴 끝
//
//		if (Z - C == 1 || C == 1) { break; }
//		Sleep(4000);
//	}
//}
//	if (Z - C == 1) { printf("GAME OVER!\nCitizen(s) has(have) been attaked by a zombie"); }
//	if (C == 1) { printf("STAGE CLEAR!\ncitizen(s) escaped to the next train"); }
//
//
//
//	return 0;
