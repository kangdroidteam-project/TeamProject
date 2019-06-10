#include "game.h"
void start_game_time_table();		// ���ӽ���
void show_rule_time_table();		// ��Ģ
void score_time_table();			// ����
void clear_buffer_arr(char *input);	// �����ִ� ���� �ʱ�ȭ
void game_difficulty();				// ���̵� ����

struct minigame_score mini_score;
int difficulty = 0, limit_time=10;	// �ʱ� ���� => ���̵� : normal, �Է����ѽð� : 10��

void times_table() {
	int input_start, exit_signal = 0;	// input_start : ����� �޴� ����, exit_signal : 1�� �� ���� ����
	char tt_ch;		// tt_ch : Sleep�� �ٸ��� �Է������� �������� �Ѿ �� �ֵ��� ���� ����

	srand(time(NULL));	// rand �õ尪 �ʱ�ȭ

	do {
		game_title_headline(0, "����� ������ �ܿ��");

		gotoxy(30, 13);
		printf("1. ����");

		gotoxy(30, 15);
		printf("2. ��Ģ");

		gotoxy(30, 17);
		printf("3. ���̵� ����");

		gotoxy(30, 19);
		printf("4. ȹ���� ���� ����");

		gotoxy(30, 21);
		printf("5. ������");

		gotoxy(30, 25);
		printf("����� ������? ");
		scanf("%d", &input_start);	// ����� �޴� ����
		while (getchar() != '\n');

		switch (input_start) {
		case 1:
			start_game_time_table();	// ����
			break;
		case 2:
			show_rule_time_table();		// ��Ģ
			break;
		case 3:
			game_difficulty();			// ���̵� ����
			break;
		case 4:
			score_time_table();			// ����
			break;
		case 5:						// ������
			exit_signal = 1;
			game_title_headline(0, "����� ������ �ܿ��");
			gotoxy(30, 18);
			printf("������ �����մϴ�.");
			Sleep(1500);
			break;
		default:				// �߸��� �� �Է�
			game_title_headline(0, "����� ������ �ܿ��");
			gotoxy(30, 18);
			printf("�߸� �Է��ϼ̽��ϴ�.");
			Sleep(1000);
			break;
		}
	} while (exit_signal != 1);
}

void show_question(int*result, char *number_list[]) { // ���� ����
	if (difficulty == 0) {	// normal �ϋ�
		int question_1 = (rand() % 9) + 1;
		int question_2 = (rand() % 9) + 1;

		gotoxy(33, 5);
		printf("%s x %s?", number_list[question_1], number_list[question_2]);
		*result = question_1 * question_2;
	}
	else if (difficulty == 1) {	// extreme �� ��
		int question_1 = (rand() % 30) + 1;
		int question_2 = (rand() % 30) + 1;

		gotoxy(38, 5);
		printf("%d x %d?", question_1, question_2);
		*result = question_1 * question_2;
	}
	gotoxy(30, 20);
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

	if (hundred_digit != 0) {						// ������ 100 �̻��� ��
		strcpy(answer, number_4[hundred_digit]);	// ���� �ڸ����� ���� ����
		switch (ten_digit) {
		case 1:										// ���� �ڸ� ���ڰ� 1�� ��� ten, eleven ���� ����� ����
			strcat(answer, " ");					// ��ĭ �����
			strcat(answer, number_3[one_digit]);	// ���� �ڸ� ���ڿ� ���� �̾�ֱ�
			break;
		case 0:										// ���� �ڸ� ���ڰ� 0�� ���
			if (one_digit != 0) {					// ���� �ڸ� ���ڰ� 0�� �ƴϸ�
				strcat(answer, " ");				
				strcat(answer, number_1[one_digit]);// one, two, three ���� ���� �ڸ� ���ڸ� �̾�ֱ�
			}
			break;
		default:									// ���� �ڸ� ���ڰ� 2~9�� ���
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
	*count = 0;
	clear_buffer_arr(answer);
	clear_buffer_arr(player_answer);
}

void clear_buffer_arr(char *input) { // ���� �ʱ�ȭ
	for (int i = 0; i < 30; i++) {
		input[i] = 0;
	}
}

void start_game_time_table() {
	char *number_1[] = { "","one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine" };			// 1~9
	char *number_2[] = {  "" , "ten" , "twenty" , "thirty" , "forty","fifty" , "sixty" , "seventy" , "eighty" , "ninety"  };	// ���� ����
	char *number_3[] = { "ten" , "eleven" , "twelve" , "thirteen" , "fourteen" , "fifteen" , "sixteen" , "seventeen" , "eighteen" , "nineteen"  };	// 11~19
	char *number_4[] = {  "" , "onehundred" , "twohundred" ,"threehundred" , "fourhundred" , "fivehundred" , "sixhundred" , "sevenhundred" , "eighthundred" , "ninehundred"  };	// ���� ����
	char ch;	// ch : ����ڰ� �Է��� ����

	int s_time, flag = 2, one_digit = 0, ten_digit = 0, hundred_digit = 0, count = 0, calculate = 0;
	// s_time : �����Ҷ��� �ð�, flag : 0�϶� ����, 1�϶� ���� , count : ����ڰ� �Է��� �� ���� ����, calculate : ������ ����(����)
	char player_answer[30] = { 0 }, answer[30] = { 0 };
	// player_answer : ����ڰ� �Է��� ����, answer : ������ ����(����)

	game_title_headline(1, "����� ������ �ܿ��");

	for (int i = 0; i < 3; i++) { // 3�ʵ� ����
		gotoxy(38, 5);
		printf("%d...", 3 - i);
		Sleep(1000);
	}
	gotoxy(36, 5);
	printf("����!");
	Sleep(1000);
	
	game_title_headline(1, "����� ������ �ܿ��\n");
	value_clear(&count, answer, player_answer);	// �� �ʱ�ȭ
	show_question(&calculate, number_1);		// ���� ����
	get_the_digit(calculate, answer, number_1, number_2, number_3, number_4); // ������ ���� ��� �� ���� ��ȯ

	s_time = time(0);

	while (1) {
		if (time(0) == s_time + limit_time) {
			game_title_headline(1, "����� ������ �ܿ��");
			gotoxy(30, 12);
			printf("�ð� �ʰ��Ǿ����ϴ�.\n");
			value_clear(&count, answer, player_answer);
			show_question(&calculate, number_1);
			get_the_digit(calculate, answer, number_1, number_2, number_3, number_4);
			s_time = time(0);
		}
		if (_kbhit()) {
			ch = _getch();

			if (ch == 27) {	// esc ������ ����
				game_title_headline(1, "����� ������ �ܿ��");
				gotoxy(28, 5);
				printf("������ ��ư�� �����̽��ϴ�.");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));	// ���� �ʱ�ȭ
				Sleep(1000);
				break;
			}

			if (ch == '\b' && count > 0) {	// �齺���̽� �Է½� �Է��ߴ� ���� ����
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
			(mini_score.timecalc_try)++;	// �õ� Ƚ�� ����
			for (int i = 0; i < strlen(answer); i++) {
				if (player_answer[i] != answer[i]) { // ���� �ϳ��� Ʋ���� flag 0���� �ٲ�� ���� ó��
					flag = 0;
					break;
				} else {
					flag = 1;
				}
			}
			if (flag == 1) {
				(mini_score.timecalc_ans)++;	// ���� Ƚ�� ����
				game_title_headline(1, "����� ������ �ܿ��");
				gotoxy(30, 13);
				printf("������ %s �Դϴ�.", answer);
				gotoxy(32, 15);
				printf("�����Դϴ�.");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			} else {
				game_title_headline(1, "����� ������ �ܿ��");
				gotoxy(30, 13);
				printf("������ %s �Դϴ�.", answer);
				gotoxy(25, 15);
				printf("%s �� �Է��ϼ̽��ϴ�.", player_answer);
				gotoxy(32, 17);
				printf("�����Դϴ�.");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			}
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			s_time = time(0);
			value_clear(&count, answer, player_answer);
			show_question(&calculate, number_1);
			get_the_digit(calculate, answer, number_1, number_2, number_3, number_4);
		}
	}
}

void score_time_table() {
	char tt_ch;

	game_title_headline(0, "����� ������ �ܿ��");
	gotoxy(30, 14);
	printf("�õ� Ƚ�� : %d", (mini_score.timecalc_try));
	gotoxy(30, 16);
	printf("���� Ƚ�� : %d", (mini_score.timecalc_ans));
	gotoxy(30, 20);
	printf("����� : %lf(%%)", ((mini_score.timecalc_try) != 0) ? (double)(mini_score.timecalc_ans) / (mini_score.timecalc_try) * 100 : 0);

	gotoxy(19, 24);
	printf("�޴��� ���ư����� �ƹ�Ű�� �Է��ϼ���.");
	scanf("%c", &tt_ch);
}

void show_rule_time_table() {
	char tt_ch;
	game_title_headline(0, "����� ������ �ܿ��");
	gotoxy(14, 12);
	printf("escŰ�� ���� ���ӿ��� ���������� ��ӵ˴ϴ�.");
	gotoxy(14, 14);
	printf("���� �Է��� 10�� (extreme�� ��� 30��) �̻� �ɸ���");
	gotoxy(16, 16);
	printf("�ð� �ʰ��� ���� ������ �Ѿ�� �˴ϴ�.");
	gotoxy(14, 18);
	printf("�ٸ� �ڸ��� ���̿��� ���⸦ ���ž� �մϴ�.");
	gotoxy(14, 20);
	printf("��) 146 => \'onehundred forty six\'");
	gotoxy(14, 22);
	printf("���� �Է� �� ���� �����ְ� ���� ������ �Ѿ�ϴ�.");
	gotoxy(19, 26);
	printf("�޴��� ���ư����� �ƹ�Ű�� �Է��ϼ���.");
	scanf("%c", &tt_ch);
}

void game_difficulty() {
	int user_difficult, exit_sig_dif = 0;
	do {
		game_title_headline(0, "����� ������ �ܿ��");

		gotoxy(34, 11);
		printf("���̵� ����");

		gotoxy(17, 13);
		printf("normal �� 0 ��, extreme �� 1 �� �����ϼ���!");
		gotoxy(6, 15);
		printf("normal�� 1���� 9������ ���ڰ� �����ǰ� �ܾ��Է����ѽð��� 10���Դϴ�.");
		gotoxy(5, 17);
		printf("extreme�� 1���� 30������ ���ڰ� �����ǰ� �ܾ��Է����ѽð��� 30���Դϴ�.");
		gotoxy(14, 21);
		printf("��, extreme�� ������ ��� �ƴ� ���ڷ� ǥ�õ˴ϴ�.");

		gotoxy(22, 25);
		printf("�ش��ϴ� ���̵� ��ȣ�� �Է��ϼ���: ");
		scanf("%d", &user_difficult);
		while (getchar() != '\n');
		switch (user_difficult) {
		case 0:	// normal
			game_title_headline(0, "����� ������ �ܿ��");
			gotoxy(28, 18);
			printf("normal�� �����Ǿ����ϴ�.");
			difficulty = 0;
			limit_time = 10;
			exit_sig_dif = 1;
			Sleep(1500);
			break;
		case 1:	// extreme
			game_title_headline(0, "����� ������ �ܿ��");
			gotoxy(26, 18);
			printf("extreme ���� �����Ǿ����ϴ�.");
			difficulty = 1;
			limit_time = 30;
			exit_sig_dif = 1;
			Sleep(1500);
			break;
		default:	// �߸��� �� �Է�
			game_title_headline(0, "����� ������ �ܿ��");
			gotoxy(30, 15);
			printf("�߸� �Է��ϼ̽��ϴ�.");
			Sleep(1000);
			continue;
		}
	} while (exit_sig_dif != 1);
}