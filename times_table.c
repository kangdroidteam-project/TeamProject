#include "game.h"
void start_game_time_table();
void show_rule_time_table();
void score_time_table();
void clear_buffer_arr(char *input);
void game_difficulty();

struct minigame_score mini_score;
int difficulty = 0, limit_time=10;

void times_table() {
	int input_start, exit_signal = 0;
	char tt_ch;

	srand(time(NULL));

	do {
		game_title_headline(0, "����� ������ �ܿ��\n");

		gotoxy(30, 12);
		printf("1. ����");

		gotoxy(30, 14);
		printf("2. ��Ģ");

		gotoxy(30, 16);
		printf("3. ���̵� ����");

		gotoxy(30, 18);
		printf("4. ȹ���� ���� ����");

		gotoxy(30, 20);
		printf("5. ������");

		gotoxy(30, 22);
		printf("����� ������? ");
		scanf("%d", &input_start);
		while (getchar() != '\n');

		switch (input_start) {
		case 1:
			start_game_time_table();
			break;
		case 2:
			game_title_headline(0, "����� ������ �ܿ��\n");
			gotoxy(0, 11);
			show_rule_time_table();
			gotoxy(10, 21);
			printf("�޴��� ���ư����� �ƹ�Ű�� �Է��ϼ���.");
			scanf("%c", &tt_ch);
			break;
		case 3:
			game_difficulty();
			break;
		case 4:
			score_time_table();
			break;
		case 5:
			exit_signal = 1;
			game_title_headline(0, "����� ������ �ܿ��\n");
			gotoxy(30, 15);
			printf("������ �����մϴ�.");
			Sleep(1500);
			break;
		default:
			game_title_headline(0, "����� ������ �ܿ��\n");
			gotoxy(30, 16);
			printf("�߸� �Է��ϼ̽��ϴ�.");
			Sleep(1000);
			break;
		}
	} while (exit_signal != 1);
}

void show_question(int*result, char *number_list[]) { // ���� ����
	if (difficulty == 0) {
		int question_1 = (rand() % 9) + 1;
		int question_2 = (rand() % 9) + 1;

		gotoxy(33, 5);
		printf("%s x %s?", number_list[question_1], number_list[question_2]);
		*result = question_1 * question_2;
	}
	else if (difficulty == 1) {
		int question_1 = (rand() % 30) + 1;
		int question_2 = (rand() % 30) + 1;

		gotoxy(38, 5);
		printf("%d x %d?", question_1, question_2);
		*result = question_1 * question_2;
	}
	gotoxy(30, 18);
	printf("���� : ");
}

void get_the_digit(int calculate, char *answer, char *number_1[], char *number_2[], char *number_3[], char* number_4[]) { // �ڸ��� ���ϰ� �ڸ����� �ش��ϴ� ���� �Է�, answer ���ϱ�
	int one_digit = 0, ten_digit = 0, hundred_digit = 0;
	// if calculate = 16
	one_digit = calculate % 10; // == 6
	calculate /= 10;
	ten_digit = calculate % 10; // == 1
	calculate /= 10;
	hundred_digit = calculate % 10; // == 0

	if (hundred_digit != 0) { // �����̽� ó���� ���� ��������
		strcpy(answer, number_4[hundred_digit]);
		switch (ten_digit) {
		case 1:
			strcat(answer, " ");
			strcat(answer, number_3[one_digit]);
			break;
		case 0:
			if (one_digit != 0) {
				strcat(answer, " ");
				strcat(answer, number_1[one_digit]);
			}
			break;
		default:
			strcat(answer, " ");
			strcat(answer, number_2[ten_digit]);
			if (one_digit != 0) {
				strcat(answer, " ");
				strcat(answer, number_1[one_digit]);
			}
			break;
		}
	}
	else if (ten_digit != 0) {
		if (ten_digit == 1) {
			strcat(answer, number_3[one_digit]); // one_digit == 6 --> number_3[6] == sixteen;
		}
		else {
			strcat(answer, number_2[ten_digit]);
			if (one_digit != 0) {
				strcat(answer, " "); // Put space because eg: 68 is sixty eight;
				strcat(answer, number_1[one_digit]); // sixty + eight
			}
		}
	}
	else {
		strcat(answer, number_1[one_digit]); //if answer is something like 8 or one-digit value
	}
}
void value_clear(int*count, char answer[], char player_answer[]) { // �� �ʱ�ȭ
	char clear[30] = { 0 };
	*count = 0;
	clear_buffer_arr(answer);
	clear_buffer_arr(player_answer);
}

void clear_buffer_arr(char *input) {
	for (int i = 0; i < 30; i++) {
		input[i] = 0;
	}
}

void start_game_time_table() {
	char *number_1[] = { "","one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine" };			// 1~9
	char *number_2[] = {  "" , "ten" , "twenty" , "thirty" , "forty","fifty" , "sixty" , "seventy" , "eighty" , "ninety"  };	// ���� ����
	char *number_3[] = { "ten" , "eleven" , "twelve" , "thirteen" , "fourteen" , "fifteen" , "sixteen" , "seventeen" , "eighteen" , "nineteen"  };	// 11~19
	char *number_4[] = {  "" , "onehundred" , "twohundred" ,"threehundred" , "fourhundred" , "fivehundred" , "sixhundred" , "sevenhundred" , "eighthundred" , "ninehundred"  };	// ���� ����
	char ch, user_start[20];

	int s_time, flag = 2, one_digit = 0, ten_digit = 0, hundred_digit = 0, count = 0, calculate = 0;
	char player_answer[30] = { 0 }, answer[30] = { 0 };

	game_title_headline(1, "����� ������ �ܿ��\n");

	for (int i = 0; i < 3; i++) { // 3�ʵ� ����
		gotoxy(38, 5);
		printf("%d...", 3 - i);
		Sleep(1000);
	}
	gotoxy(36, 5);
	printf("����!");
	Sleep(1000);
	
	game_title_headline(1, "����� ������ �ܿ��\n");
	value_clear(&count, answer, player_answer);
	show_question(&calculate, number_1);
	get_the_digit(calculate, answer, number_1, number_2, number_3, number_4); //generate answer(computer)

	s_time = time(0);

	while (1) {
		if (time(0) == s_time + limit_time) {
			game_title_headline(1, "����� ������ �ܿ��\n");
			gotoxy(30, 12);
			printf("�ð� �ʰ��Ǿ����ϴ�.\n");
			value_clear(&count, answer, player_answer);
			show_question(&calculate, number_1);
			get_the_digit(calculate, answer, number_1, number_2, number_3, number_4);
			s_time = time(0);
		}
		if (_kbhit()) {
			ch = _getch();

			if (ch == 27) {
				game_title_headline(1, "����� ������ �ܿ��\n");
				gotoxy(28, 5);
				printf("������ ��ư�� �����̽��ϴ�.");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				Sleep(1000);
				break;
			}

			if (ch == '\b' && count > 0) {
				printf("\b \b");
				count--;
			}
			else if (ch == '\b' && count == 0) {
				// Do nothing ( �ƹ��͵� ��ģ ���¿��� �齺���̽� ���� �� ���ٷ� �Ѿ�� �� ���� )
			}
			else if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || ch == ' ') {
				printf("%c", ch);
			}
			else;	// �ѱ��̳� ���� ���� ���� ��¹���

			if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || ch == ' ') { // ���� �ҹ���, �빮��, �����̽��� ó��
				player_answer[count] = ch;
				count++;
			}
		}
		if (count == strlen(answer)) { // ������ ������ ���̸�ŭ �Է� �� ���� ��
			(mini_score.timecalc_try)++;
			for (int i = 0; i < strlen(answer); i++) {
				if (player_answer[i] != answer[i]) { // ���� �ϳ��� Ʋ���� flag 0���� �ٲ�� ���� ó��
					flag = 0;
					break;
				} else {
					flag = 1;
				}
			}
			if (flag == 1) {
				(mini_score.timecalc_ans)++;
				game_title_headline(1, "����� ������ �ܿ��\n");
				gotoxy(30, 12);
				printf("������ %s �Դϴ�.", answer);
				gotoxy(32, 13);
				printf("�����Դϴ�.");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			} else {
				game_title_headline(1, "����� ������ �ܿ��\n");
				gotoxy(30, 12);
				printf("������ %s �Դϴ�.", answer);
				gotoxy(25, 13);
				printf("%s �� �Է��ϼ̽��ϴ�.", player_answer);
				gotoxy(32, 14);
				printf("�����Դϴ�.");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			}
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			s_time = time(0);
			value_clear(&count, answer, player_answer);
			show_question(&calculate, number_1);
			get_the_digit(calculate, answer, number_1, number_2, number_3, number_4);
			score_time_table;
		}
	}
}

void score_time_table() {
	char tt_ch;

	game_title_headline(0, "����� ������ �ܿ��\n");
	gotoxy(31, 12);
	printf("�õ� Ƚ�� : %d", (mini_score.timecalc_try));
	gotoxy(31, 13);
	printf("���� Ƚ�� : %d", (mini_score.timecalc_ans));
	gotoxy(31, 14);
	printf("����� : %lf(%%)", ((mini_score.timecalc_try) != 0) ? (double)(mini_score.timecalc_ans) / (mini_score.timecalc_try) * 100 : 0);

	gotoxy(19, 18);
	printf("�޴��� ���ư����� �ƹ�Ű�� �Է��ϼ���.");
	scanf("%c", &tt_ch);
}

void show_rule_time_table() {
	gotoxy(10, 12);
	printf("����� ������ �ܿ��");
	gotoxy(10, 13);
	printf("escŰ�� ���� ���ӿ��� ���������� ��ӵ˴ϴ�.");
	gotoxy(10, 14);
	printf("���� �Է��� 10�� (extreme�� ��� 30��) �̻� �ɸ���");
	gotoxy(12, 15);
	printf("�ð� �ʰ��� ���� ������ �Ѿ�� �˴ϴ�.");
	gotoxy(10, 16);
	printf("�ٸ� �ڸ��� ���̿��� ���⸦ ���ž� �մϴ�.");
	gotoxy(10, 17);
	printf("��) 146 => \'onehundred forty six\'");
	gotoxy(10, 18);
	printf("���� �Է� �� ���� �����ְ� ���� ������ �Ѿ�ϴ�.");
}

void game_difficulty() {
	int user_difficult, exit_sig_dif = 0;
	do {
		game_title_headline(0, "����� ������ �ܿ��\n");

		gotoxy(34, 13);
		printf("���̵� ����");

		gotoxy(10, 15);
		printf("normal �� 0��, extreme �� 1�� �����ϼ���!");
		gotoxy(10, 16);
		printf("normal�� 1���� 9������ ���ڰ� �����ǰ�");
		gotoxy(12, 17);
		printf("extreme�� 1���� 30������ ���ڰ� �����˴ϴ�.");
		gotoxy(10, 18);
		printf("��, extreme�� ������ ��� �ƴ� ���ڷ� ǥ�õ˴ϴ�.");

		gotoxy(22, 20);
		printf("�ش��ϴ� ���̵� ��ȣ�� �Է��ϼ���: ");
		scanf("%d", &user_difficult);
		while (getchar() != '\n');
		switch (user_difficult) {
		case 0:
			game_title_headline(0, "����� ������ �ܿ��\n");
			gotoxy(28, 15);
			printf("normal�� �����Ǿ����ϴ�.");
			difficulty = 0;
			limit_time = 10;
			exit_sig_dif = 1;
			Sleep(1500);
			break;
		case 1:
			game_title_headline(0, "����� ������ �ܿ��\n");
			gotoxy(26, 15);
			printf("extreme ���� �����Ǿ����ϴ�.");
			difficulty = 1;
			limit_time = 30;
			exit_sig_dif = 1;
			Sleep(1500);
			break;
		default:
			game_title_headline(0, "����� ������ �ܿ��\n");
			gotoxy(30, 15);
			printf("�߸� �Է��ϼ̽��ϴ�.");
			Sleep(1000);
			continue;
		}
	} while (exit_sig_dif != 1);
}