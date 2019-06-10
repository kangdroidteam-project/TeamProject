#include "game.h"

struct typing_score type_score;

int showTypingMenu() {
	int user_input_typing;
	char input[5];
	game_title_headline(0, "타자연습 메뉴 화면\n");
	gotoxy(30, 12);
	printf("1. 초급\n");
	gotoxy(30, 14);
	printf("2. 중급\n");
	gotoxy(30, 16);
	printf("3. 고급\n");
	gotoxy(30, 18);
	printf("4. 최상급\n");
	gotoxy(30, 20);
	printf("5. 단계 설명\n");
	gotoxy(30, 22);
	printf("6. 규칙(점수 산정 기준)\n");
	gotoxy(30, 24);
	printf("7. 연습해보기\n");
	gotoxy(30, 26);
	printf("0. 전 메뉴로 돌아가기\n");
	gotoxy(30, 28);
	printf("원하는 단계를 입력해주세요! ");
	scanf("%d", &user_input_typing);
	while (getchar() != '\n');

	switch (user_input_typing) {
	case 1:
		// Beginner
		word_game(1);
		break;
	case 2:
		// Intermediates
		word_game(2);
		break;
	case 3:
		// Expert
		word_game(3);
		break;
	case 4:
		// Extremely-hard
		if (type_score.extreme_unlock == 4) {
			word_game(4);
		}
		else {
			system("cls");
			printf("고급 단계를 클리어 하신 분들만 최상급 단계를 플레이 할 수 있습니다!\n");
			Sleep(3000);
		}
		break;
	case 5:
		// Explanation of Steps, Level
		system("cls");
		game_title_headline(0, "타자연습모드 설명\n");
		gotoxy(0, 12);
		printf("연습단계는 영어문자가 하나씩 나타나고 \n총 5문제의 주어진 문자를 입력해야 한다,\n");
		gotoxy(0, 15);
		printf("easy mode는 1~5글자의 영어글자가 하나씩 나타나고 \n총15문제의 주어진 문자를 입력해야 한다,\n");
		gotoxy(0, 18);
		printf("moderate mode는 5~10글자의 영어글자가 나타나고 \n총 15문제의 주어진 문자를 입력해야 한다.\n");
		gotoxy(0, 21);
		printf("hard mode는 10글자 이상의 영어글자가 나타나고 \n총 15문제의 주어진 문자를 입력해야 한다.\n");
		gotoxy(0, 24);
		printf("Extreme mode는 영어 문장이 나타나고 \n총 15문제의 주어진 문자를 입력해야한다.\n");
		gotoxy(0, 27);
		printf("엔터키를 누르면 전 메뉴로 돌아갑니다..");
		fgets(input, sizeof(input), stdin);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		//Sleep(5000);
		break;
	case 6:
		// Explanation of Rule with Score agenda.
		system("cls");
		game_title_headline(0, "타자연습모드 점수산정 설명\n");
		gotoxy(0, 12);
		printf("점수는 문자를 맞은 경우에 1점씩 얻는다.\n");
		gotoxy(0, 14);
		printf("easy mode를 제외한 모드는 시간도 점수산정에 영향을 미칩니다.\n ");
		gotoxy(0, 16);
		printf("extreme mode는 틀리면 1점씩 감점 됩니다.\n");
		gotoxy(0, 18);
		printf("엔터키를 누르면 전 메뉴로 돌아갑니다..");
		fgets(input, sizeof(input), stdin);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		//Sleep(5000);
		break;
	case 7:
		// Practice mode(beginner)
		word_game(0);
		break;
	case 0:
		// Return to last menu
		return 0;
	default:
		// Get another input;
		return 10;
	}
}