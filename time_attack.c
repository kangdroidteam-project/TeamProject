#include"game.h"

void showInitScreen();
void doSomethingWithRank(int timespent, int mode, int word_count);
void startGame(int count, int mode);

struct timeattack_score timeat_score;

void showDefMenu(void) {
	int number1, number2; //메뉴 선택 변수, 랜덤 숫자 변수

	srand(time(0));

	do {
		do {
			game_title_headline(0, "과연 최고 기록을 깰 수 있을까?!! \n\n                              타임 어택에 오신 것을 환영합니다.");

			gotoxy(30, 13);
			printf("1) 알파벳 타임어택    \n");

			gotoxy(30, 17);
			printf("2) 단어 타임어택      \n");

			gotoxy(30, 21);
			printf("3) 뒤로 가기          \n");

			gotoxy(30,25);
			printf("하고 싶은 메뉴를 선택하세요: ");

			scanf("%d", &number1);
			while (getchar() != '\n');
			system("cls");

		} while (number1 != 1 && number1 != 2 && number1 != 3);

		if (number1 == 3) {
			break;
		}

		do {
			game_title_headline(0, "과연 최고 기록을 깰 수 있을까?!! \n\n                              타임 어택에 오신 것을 환영합니다.");

			gotoxy(30, 13);
			printf("1) 5개 뿌시기         \n");

			gotoxy(30, 17);
			printf("2) 8개 뿌시기         \n");

			gotoxy(30, 21);
			printf("3) 10개 뿌시기        \n");

			gotoxy(30, 25);
			printf("하고 싶은 메뉴를 선택하세요: ");

			scanf("%d", &number2);
			while (getchar() != '\n');
			system("cls");

		} while (number2 != 1 && number2 != 2 && number2 != 3);

		showInitScreen();

		switch (number1) { // Select Alphabet
		case 1: // alphabet
			if (number2 == 1) { //알파벳 5개
				startGame(5, 1);
			}
			else if (number2 == 2) { //알파벳 8개
				startGame(8, 1);
			}
			else if (number2 == 3) {  //알파벳 10개
				startGame(10, 1);
			}
			break;
		case 2: //단어 선택
			if (number2 == 1) { //단어 5개
				startGame(5, 0);
			}
			else if (number2 == 2) {
				startGame(8, 0);
			}
			else if (number2 == 3) {
				startGame(10, 0);
			}
			break;
		}
		printf("\n게임을 새로 시작합니다.\n 잠시만 기다려주세요");
		Sleep(5000);
		system("cls");
	} while (1);
}

void showInitScreen() {
	//3,2,1 끝난 뒤 시작
	printf("  ■■■■■■■■\n");
	printf("                ■\n");
	printf("                ■\n");
	printf("  ■■■■■■■■\n");
	printf("                ■\n");
	printf("                ■\n");
	printf("  ■■■■■■■■\n");
	Sleep(1000);
	system("cls");

	printf("  ■■■■■■■■\n");
	printf("                ■\n");
	printf("                ■\n");
	printf("  ■■■■■■■■\n");
	printf("  ■              \n");
	printf("  ■              \n");
	printf("  ■■■■■■■■\n");

	Sleep(1000);
	system("cls");

	printf("           ■     \n");
	printf("      ■   ■     \n");
	printf("           ■       \n");
	printf("           ■      \n");
	printf("           ■      \n");
	printf("           ■      \n");
	printf("     ■■■■■■■   \n");

	Sleep(1000);
	system("cls");
}

void doSomethingWithRank(int timespent, int mode, int word_count) {
	char input_rank;
	int score;

	if (timespent < 21) {
		score = 110 - timespent*5 ;
	}
	else {
		score = 0;
	}

	if (mode) { //alp
		switch (word_count) {
		case 5:
			timeat_score.alp_n1 = score;
			break;
		case 8:
			timeat_score.alp_n2 = score+5;
			break;
		case 10:
			timeat_score.alp_n3 = score+10;
			break;
		}
	}
	else { // word
		switch (word_count) {
		case 5:
			timeat_score.word_n1 = score+20;
			break;
		case 8:
			timeat_score.word_n2 = score + 30;
			break;
		case 10:
			timeat_score.word_n3 = score+40;
			break;
		}
	}

	printf("\n걸린시간은 %d 초 이고 점수는 %d 점 입니다..\n", timespent, score);
}

void startGame(int count, int isAlphabet) {
	int start, end, timespent, life; //시간 재기 변수
	int disap[11], arr[11]; //단어 사라지게하는 변수
	int answer_counter = 0, counter_end = 0; //word count
	char user_input[30], alp[11], answer1; //알파벳, 단어 생성 배열

	life = 3; //생명부여

	for (int i = 0; i < 11; i++) { //사라지는 변수 초기화, 랜덤 알파벳 생성
		if (isAlphabet) {
			disap[i] = 0;
			alp[i] = 'a' + rand() % 26;
		}
		else {
			disap[i] = 0;
			arr[i] = rand() % 9800;
		}
	}

	start = time(0); //시간 시작

	do {
		printf("◆◇◆◇◆◇◆◇◆◇◆◇◆◇\n\n");
		printf("life : ");//생명
		if (life == 3) {
			printf("♥♥♥");
		}
		else if (life == 2) {
			printf("♥♥");
		}
		else if (life == 1) {
			printf("♥");
		}

		answer_counter = 0;

		printf("\n\n");

		for (int i = 0; i < count; i++) {
			if (disap[i] == 0) {
				if (isAlphabet) {
					printf(" %d)    %c      \n\n", i + 1, alp[i]);
				}
				else {
					printf(" %d)    %s      \n\n", i + 1, word_list[arr[i]]);
				}
			}
		}

		printf("◆◇◆◇◆◇◆◇◆◇◆◇◆◇\n\n");

		printf("입력하시오:");
		if (isAlphabet) {
			scanf("%c", &answer1);
		}
		else {
			scanf("%s", user_input);
		}
		while (getchar() != '\n');

		for (int i = 0; i < count; i++) {
			if (isAlphabet) {
				if (alp[i] == answer1) {
					disap[i]++;
					answer_counter++;
					counter_end++;
				}
			}
			else {
				if (!(strcmp(word_list[arr[i]], user_input))) {
					disap[i]++;
					answer_counter++;
					counter_end++;
				}
			}
		}

		if (answer_counter == 0) {
			life--;
		}

		system("cls");

		if (life < 1)
			break;

	} while (counter_end != count);

	end = time(0);//시간 끝
	timespent = end - start;

	if (life > 0) { //걸린시간 보여주기, 랭킹등록, 탈락
		doSomethingWithRank(timespent, isAlphabet, count);
	}
	else {
		printf("\n아쉽지만 탈락입니다.\n");
	}
}