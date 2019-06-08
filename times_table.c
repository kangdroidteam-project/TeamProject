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
		game_title_headline(0, "영어로 구구단 외우기\n");

		gotoxy(30, 12);
		printf("1. 시작");

		gotoxy(30, 14);
		printf("2. 규칙");

		gotoxy(30, 16);
		printf("3. 난이도 설정");

		gotoxy(30, 18);
		printf("4. 획득한 점수 보기");

		gotoxy(30, 20);
		printf("5. 나가기");

		gotoxy(30, 22);
		printf("당신의 선택은? ");
		scanf("%d", &input_start);
		while (getchar() != '\n');

		switch (input_start) {
		case 1:
			start_game_time_table();
			break;
		case 2:
			game_title_headline(0, "영어로 구구단 외우기\n");
			gotoxy(0, 11);
			show_rule_time_table();
			gotoxy(10, 21);
			printf("메뉴로 돌아가려면 아무키나 입력하세요.");
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
			game_title_headline(0, "영어로 구구단 외우기\n");
			gotoxy(30, 15);
			printf("게임을 종료합니다.");
			Sleep(1500);
			break;
		default:
			game_title_headline(0, "영어로 구구단 외우기\n");
			gotoxy(30, 16);
			printf("잘못 입력하셨습니다.");
			Sleep(1000);
			break;
		}
	} while (exit_signal != 1);
}

void show_question(int*result, char *number_list[]) { // 문제 출제
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
	printf("정답 : ");
}

void get_the_digit(int calculate, char *answer, char *number_1[], char *number_2[], char *number_3[], char* number_4[]) { // 자릿수 구하고 자릿수에 해당하는 영어 입력, answer 구하기
	int one_digit = 0, ten_digit = 0, hundred_digit = 0;
	// if calculate = 16
	one_digit = calculate % 10; // == 6
	calculate /= 10;
	ten_digit = calculate % 10; // == 1
	calculate /= 10;
	hundred_digit = calculate % 10; // == 0

	if (hundred_digit != 0) { // 스페이스 처리로 인해 복잡해짐
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
void value_clear(int*count, char answer[], char player_answer[]) { // 값 초기화
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
	char *number_2[] = {  "" , "ten" , "twenty" , "thirty" , "forty","fifty" , "sixty" , "seventy" , "eighty" , "ninety"  };	// 십의 단위
	char *number_3[] = { "ten" , "eleven" , "twelve" , "thirteen" , "fourteen" , "fifteen" , "sixteen" , "seventeen" , "eighteen" , "nineteen"  };	// 11~19
	char *number_4[] = {  "" , "onehundred" , "twohundred" ,"threehundred" , "fourhundred" , "fivehundred" , "sixhundred" , "sevenhundred" , "eighthundred" , "ninehundred"  };	// 백의 단위
	char ch, user_start[20];

	int s_time, flag = 2, one_digit = 0, ten_digit = 0, hundred_digit = 0, count = 0, calculate = 0;
	char player_answer[30] = { 0 }, answer[30] = { 0 };

	game_title_headline(1, "영어로 구구단 외우기\n");

	for (int i = 0; i < 3; i++) { // 3초뒤 시작
		gotoxy(38, 5);
		printf("%d...", 3 - i);
		Sleep(1000);
	}
	gotoxy(36, 5);
	printf("시작!");
	Sleep(1000);
	
	game_title_headline(1, "영어로 구구단 외우기\n");
	value_clear(&count, answer, player_answer);
	show_question(&calculate, number_1);
	get_the_digit(calculate, answer, number_1, number_2, number_3, number_4); //generate answer(computer)

	s_time = time(0);

	while (1) {
		if (time(0) == s_time + limit_time) {
			game_title_headline(1, "영어로 구구단 외우기\n");
			gotoxy(30, 12);
			printf("시간 초과되었습니다.\n");
			value_clear(&count, answer, player_answer);
			show_question(&calculate, number_1);
			get_the_digit(calculate, answer, number_1, number_2, number_3, number_4);
			s_time = time(0);
		}
		if (_kbhit()) {
			ch = _getch();

			if (ch == 27) {
				game_title_headline(1, "영어로 구구단 외우기\n");
				gotoxy(28, 5);
				printf("나가기 버튼을 누르셨습니다.");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				Sleep(1000);
				break;
			}

			if (ch == '\b' && count > 0) {
				printf("\b \b");
				count--;
			}
			else if (ch == '\b' && count == 0) {
				// Do nothing ( 아무것도 안친 상태에서 백스페이스 누를 시 윗줄로 넘어가는 것 방지 )
			}
			else if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || ch == ' ') {
				printf("%c", ch);
			}
			else;	// 한글이나 숫자 등의 문자 출력방지

			if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || ch == ' ') { // 영어 소문자, 대문자, 스페이스바 처리
				player_answer[count] = ch;
				count++;
			}
		}
		if (count == strlen(answer)) { // 문제의 정답의 길이만큼 입력 시 정답 비교
			(mini_score.timecalc_try)++;
			for (int i = 0; i < strlen(answer); i++) {
				if (player_answer[i] != answer[i]) { // 글자 하나라도 틀리면 flag 0으로 바뀌고 오답 처리
					flag = 0;
					break;
				} else {
					flag = 1;
				}
			}
			if (flag == 1) {
				(mini_score.timecalc_ans)++;
				game_title_headline(1, "영어로 구구단 외우기\n");
				gotoxy(30, 12);
				printf("정답은 %s 입니다.", answer);
				gotoxy(32, 13);
				printf("정답입니다.");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			} else {
				game_title_headline(1, "영어로 구구단 외우기\n");
				gotoxy(30, 12);
				printf("정답은 %s 입니다.", answer);
				gotoxy(25, 13);
				printf("%s 를 입력하셨습니다.", player_answer);
				gotoxy(32, 14);
				printf("오답입니다.");
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

	game_title_headline(0, "영어로 구구단 외우기\n");
	gotoxy(31, 12);
	printf("시도 횟수 : %d", (mini_score.timecalc_try));
	gotoxy(31, 13);
	printf("맞춘 횟수 : %d", (mini_score.timecalc_ans));
	gotoxy(31, 14);
	printf("정답률 : %lf(%%)", ((mini_score.timecalc_try) != 0) ? (double)(mini_score.timecalc_ans) / (mini_score.timecalc_try) * 100 : 0);

	gotoxy(19, 18);
	printf("메뉴로 돌아가려면 아무키나 입력하세요.");
	scanf("%c", &tt_ch);
}

void show_rule_time_table() {
	gotoxy(10, 12);
	printf("영어로 구구단 외우기");
	gotoxy(10, 13);
	printf("esc키를 눌러 게임에서 나갈때까지 계속됩니다.");
	gotoxy(10, 14);
	printf("정답 입력이 10초 (extreme의 경우 30초) 이상 걸리면");
	gotoxy(12, 15);
	printf("시간 초과로 다음 문제로 넘어가게 됩니다.");
	gotoxy(10, 16);
	printf("다른 자릿수 사이에는 띄어쓰기를 쓰셔야 합니다.");
	gotoxy(10, 17);
	printf("예) 146 => \'onehundred forty six\'");
	gotoxy(10, 18);
	printf("오답 입력 시 답을 보여주고 다음 문제로 넘어갑니다.");
}

void game_difficulty() {
	int user_difficult, exit_sig_dif = 0;
	do {
		game_title_headline(0, "영어로 구구단 외우기\n");

		gotoxy(34, 13);
		printf("난이도 설정");

		gotoxy(10, 15);
		printf("normal 은 0을, extreme 은 1을 선택하세요!");
		gotoxy(10, 16);
		printf("normal은 1부터 9까지의 숫자가 출제되고");
		gotoxy(12, 17);
		printf("extreme은 1부터 30까지의 숫자가 출제됩니다.");
		gotoxy(10, 18);
		printf("단, extreme은 문제가 영어가 아닌 숫자로 표시됩니다.");

		gotoxy(22, 20);
		printf("해당하는 난이도 번호를 입력하세요: ");
		scanf("%d", &user_difficult);
		while (getchar() != '\n');
		switch (user_difficult) {
		case 0:
			game_title_headline(0, "영어로 구구단 외우기\n");
			gotoxy(28, 15);
			printf("normal로 설정되었습니다.");
			difficulty = 0;
			limit_time = 10;
			exit_sig_dif = 1;
			Sleep(1500);
			break;
		case 1:
			game_title_headline(0, "영어로 구구단 외우기\n");
			gotoxy(26, 15);
			printf("extreme 으로 설정되었습니다.");
			difficulty = 1;
			limit_time = 30;
			exit_sig_dif = 1;
			Sleep(1500);
			break;
		default:
			game_title_headline(0, "영어로 구구단 외우기\n");
			gotoxy(30, 15);
			printf("잘못 입력하셨습니다.");
			Sleep(1000);
			continue;
		}
	} while (exit_sig_dif != 1);
}