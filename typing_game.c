#include "game.h"

struct typing_score type_score;

int showTypingMenu() {
	int user_input_typing;
	char input[5];
	game_title_headline(0, "Ÿ�ڿ��� �޴� ȭ��\n");
	gotoxy(30, 12);
	printf("1. �ʱ�\n");
	gotoxy(30, 14);
	printf("2. �߱�\n");
	gotoxy(30, 16);
	printf("3. ���\n");
	gotoxy(30, 18);
	printf("4. �ֻ��\n");
	gotoxy(30, 20);
	printf("5. �ܰ� ����\n");
	gotoxy(30, 22);
	printf("6. ��Ģ(���� ���� ����)\n");
	gotoxy(30, 24);
	printf("7. �����غ���\n");
	gotoxy(30, 26);
	printf("0. �� �޴��� ���ư���\n");
	gotoxy(30, 28);
	printf("���ϴ� �ܰ踦 �Է����ּ���! ");
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
			printf("��� �ܰ踦 Ŭ���� �Ͻ� �е鸸 �ֻ�� �ܰ踦 �÷��� �� �� �ֽ��ϴ�!\n");
			Sleep(3000);
		}
		break;
	case 5:
		// Explanation of Steps, Level
		system("cls");
		game_title_headline(0, "Ÿ�ڿ������ ����\n");
		gotoxy(0, 12);
		printf("�����ܰ�� ����ڰ� �ϳ��� ��Ÿ���� \n�� 5������ �־��� ���ڸ� �Է��ؾ� �Ѵ�,\n");
		gotoxy(0, 15);
		printf("easy mode�� 1~5������ ������ڰ� �ϳ��� ��Ÿ���� \n��15������ �־��� ���ڸ� �Է��ؾ� �Ѵ�,\n");
		gotoxy(0, 18);
		printf("moderate mode�� 5~10������ ������ڰ� ��Ÿ���� \n�� 15������ �־��� ���ڸ� �Է��ؾ� �Ѵ�.\n");
		gotoxy(0, 21);
		printf("hard mode�� 10���� �̻��� ������ڰ� ��Ÿ���� \n�� 15������ �־��� ���ڸ� �Է��ؾ� �Ѵ�.\n");
		gotoxy(0, 24);
		printf("Extreme mode�� ���� ������ ��Ÿ���� \n�� 15������ �־��� ���ڸ� �Է��ؾ��Ѵ�.\n");
		gotoxy(0, 27);
		printf("����Ű�� ������ �� �޴��� ���ư��ϴ�..");
		fgets(input, sizeof(input), stdin);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		//Sleep(5000);
		break;
	case 6:
		// Explanation of Rule with Score agenda.
		system("cls");
		game_title_headline(0, "Ÿ�ڿ������ �������� ����\n");
		gotoxy(0, 12);
		printf("������ ���ڸ� ���� ��쿡 1���� ��´�.\n");
		gotoxy(0, 14);
		printf("easy mode�� ������ ���� �ð��� ���������� ������ ��Ĩ�ϴ�.\n ");
		gotoxy(0, 16);
		printf("extreme mode�� Ʋ���� 1���� ���� �˴ϴ�.\n");
		gotoxy(0, 18);
		printf("����Ű�� ������ �� �޴��� ���ư��ϴ�..");
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