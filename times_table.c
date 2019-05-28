#include "game.h"

#define TIME_LIMIT 10
void start_game_time_table();
void show_rule_time_table();

void times_table() {
	int input_start, exit_signal = 0;

	srand(time(NULL));

	printf("������ ������ �����մϴ�.\n");

	do {
		printf("���� : 1, ��Ģ : 2, ������ : 3\n");

		scanf("%d", &input_start);
		while (getchar() != '\n');

		switch (input_start) {
		case 1:
			start_game_time_table();
			break;
		case 2:
			show_rule_time_table();
			break;
		case 3:
			exit_signal = 1;
			break;
		default:
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			break;
		}
	} while (exit_signal != 1);
}

void show_question(int*result, char number_list[][30]) { // ���� ����
	int question_1 = (rand() % 9) + 1;
	int question_2 = (rand() % 9) + 1;

	printf("%s x %s?\n", number_list[question_1], number_list[question_2]);
	*result = question_1 * question_2;
}

void get_the_digit(int calculate, char *answer, char number_1[][30], char number_2[][30], char number_3[][30], char number_4[][30])	{ // �ڸ��� ���ϰ� �ڸ����� �ش��ϴ� ���� �Է�, answer ���ϱ�
	int one_digit = 0, ten_digit = 0, hundred_digit = 0;
	// if calculate = 16
	one_digit = calculate % 10; // == 6
	calculate /= 10;
	ten_digit = calculate % 10; // == 1
	calculate /= 10;
	hundred_digit = calculate % 10; // == 0

	if (hundred_digit != 0)	{ // �����̽� ó���� ���� ��������
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
	} else if (ten_digit != 0) {
		if (ten_digit == 1) {
			strcat(answer, number_3[one_digit]); // one_digit == 6 --> number_3[6] == sixteen;
		} else {
			strcat(answer, number_2[ten_digit]); 
			if (one_digit != 0) {
				strcat(answer, " "); // Put space because eg: 68 is sixty eight;
				strcat(answer, number_1[one_digit]); // sixty + eight
			}
		}
	} else {
		strcat(answer, number_1[one_digit]); //if answer is something like 8 or one-digit value
	}
}
void value_clear(int*count, char answer[], char player_answer[]) { // �� �ʱ�ȭ
	char clear[30] = { 0 };
	*count = 0;
	strcpy(answer, clear);
	strcpy(player_answer, clear);
}

void start_game_time_table() {
	char number_1[10][30] = { { "" },{ "one" },{ "two" },{ "three" },{ "four" },{ "five" },{ "six" },{ "seven" },{ "eight" },{ "nine" } };				// 1~9
	char number_2[10][30] = { { "" },{ "ten" },{ "twenty" },{ "thirty" },{ "forty" },{ "fifty" },{ "sixty" },{ "seventy" },{ "eighty" },{ "ninety" } };	// ���� ����
	char number_3[10][30] = { { "ten" },{ "eleven" },{ "twelve" },{ "thirteen" },{ "fourteen" },{ "fifteen" },{ "sixteen" },{ "seventeen" },{ "eighteen" },{ "nineteen" } };	// 11~19
	char number_4[10][30] = { { "" },{ "onehundred" },{ "twohundred" },{ "threehundred" },{ "fourhundred" },{ "fivehundred" },{ "sixhundred" },{ "sevenhundred" },{ "eighthundred" },{ "ninehundred" } };	// ���� ����
	char ch, user_start[20];

	int s_time, flag = 2, one_digit = 0, ten_digit = 0, hundred_digit = 0, count = 0, calculate = 0;
	char player_answer[30] = { 0 }, answer[30] = { 0 };

	for (int i = 0; i < 3; i++) { // 3�ʵ� ����
		system("cls");
		printf("%d...\n", 3 - i);
		Sleep(1000);
	}
	system("cls");
	printf("����!\n");
	Sleep(1000);
	system("cls");
	value_clear(&count, answer, player_answer);
	show_question(&calculate, number_1);
	get_the_digit(calculate, answer, number_1, number_2, number_3, number_4); //generate answer(computer)

	s_time = time(0);

	while (1) {
		if (time(0) == s_time + TIME_LIMIT) {
			system("cls");
			printf("�ð� �ʰ��Ǿ����ϴ�.\n");
			value_clear(&count, answer, player_answer);
			show_question(&calculate, number_1);
			get_the_digit(calculate, answer, number_1, number_2, number_3, number_4);
			s_time = time(0);
		}
		if (_kbhit()) {
			ch = _getch();

			if (ch == 27) {
				printf("������ ��ư�� �����̽��ϴ�.\n");
				break;
			}

			if (ch == '\b' && count > 0) {
				printf("\b \b");
				count--;
			} else if (ch == '\b' && count == 0) {
				// Do nothing
			} else {
				printf("%c", ch);
			}

			if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || ch == ' ') { // ���� �ҹ���, �빮��, �����̽��� ó��
				player_answer[count] = ch;
				count++;
			}
		}
		if (count == strlen(answer)) { // ������ ������ ���̸�ŭ �Է� �� ���� ��
			for (int i = 0; i < strlen(answer); i++) {
				if (player_answer[i] != answer[i]) { // ���� �ϳ��� Ʋ���� flag 0���� �ٲ�� ���� ó��
					flag = 0;
					break;
				} else {
					flag = 1;
				}
			}
			if (flag == 1) {
				system("cls");
				printf("������ %s �Դϴ�.\n", answer);
				printf("�����Դϴ�.\n");
			} else {
				system("cls");
				printf("������ %s �Դϴ�.\n", answer);
				printf("%s �� �Է��ϼ̽��ϴ�.\n", player_answer);
				printf("�����Դϴ�.\n");
			}

			s_time = time(0);
			value_clear(&count, answer, player_answer);
			show_question(&calculate, number_1);
			get_the_digit(calculate, answer, number_1, number_2, number_3, number_4);
		}
	}
}

void show_rule_time_table() {
	printf("--------------------------------------------------------------------------\n");
	printf("����� ������ �ܿ��\n");
	printf("escŰ�� ���� ���ӿ��� ���������� ��ӵ˴ϴ�.\n");
	printf("���� �Է��� 10�� �̻� �ɸ��� �ð� �ʰ��� ���� ������ �Ѿ�� �˴ϴ�.\n");
	printf("�ٸ� �ڸ��� ���̿��� ���⸦ ���ž� �մϴ�.\n");
	printf("��) 146 => \'onehundred forty six\'\n");
	printf("���� �Է� �� ���� �����ְ� ���� ������ �Ѿ�ϴ�.\n");
	printf("--------------------------------------------------------------------------\n");
}