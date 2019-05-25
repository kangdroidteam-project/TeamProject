#include "game.h"

#define TIME_LIMIT 10

void times_table()
{
	char number_1[10][30] = { {""}, {"one"},{"two"},{"three"},{"four"},{"five"},{"six"},{"seven"},{"eight"},{"nine"} };				// 1~9
	char number_2[10][30] = { {""},{"ten"},{"twenty"},{"thirty"},{"forty"},{"fifty"},{"sixty"},{"seventy"},{"eighty"},{"ninety"} };	// 십의 단위
	char number_3[10][30] = { {"ten"},{"eleven"},{"twelve"},{"thirteen"},{"fourteen"},{"fifteen"},{"sixteen"},{"seventeen"},{"eighteen"},{"nineteen"} };	// 11~19
	char number_4[10][30] = { {""},{"onehundred"},{"twohundred"},{"threehundred"},{"fourhundred"},{"fivehundred"},{"sixhundred"},{"sevenhundred"},{"eighthundred"},{"ninehundred"} };	// 백의 단위
	char player_answer[30] = { 0 }, answer[30] = { 0 }, ch, user_start[20], start[10] = "start", rule[10] = "rule", quit[10] = "quit";
	//	사용자 입력 값 저장소		문제의 정답		  입력값
	int s_time, count = 0, flag = 2, calculate = 0, one_digit = 0, ten_digit = 0, hundred_digit = 0, i;
	//							문제의 정답(정수형)
	srand(time(NULL));

	printf("구구단 게임을 시작합니다.\n");

	do
	{
		printf("시작 : start, 규칙 : rule, 나가기 : quit\n");

		fgets(user_start, 20, stdin);			// 시작, 규칙, 나가기
		for (i = 0; user_start[i] != 0; i++)
		{
			if (user_start[i] == '\n')
			{
				user_start[i] = 0;
				break;
			}
		}
		if (!(strcmp(user_start, rule)))		// 규칙
		{
			printf("--------------------------------------------------------------------------\n");
			printf("영어로 구구단 외우기\n");
			printf("esc키를 눌러 게임에서 나갈때까지 계속됩니다.\n");
			printf("정답 입력이 10초 이상 걸리면 시간 초과로 다음 문제로 넘어가게 됩니다.\n");
			printf("다른 자릿수 사이에는 띄어쓰기를 쓰셔야 합니다.\n");
			printf("예) 146 => \'onehundred forty six\'\n");
			printf("오답 입력 시 답을 보여주고 다음 문제로 넘어갑니다.\n");
			printf("--------------------------------------------------------------------------\n");
		}
		else if (!(strcmp(user_start, start)))	// 시작
		{
			for (i = 0; i < 3; i++)			// 3초뒤 시작
			{
				system("cls");
				printf("%d...\n", 3 - i);
				Sleep(1000);
			}
			system("cls");
			printf("시작!\n");
			Sleep(1000);
			system("cls");
			value_clear(&count, answer, player_answer);
			show_question(&calculate, number_1);
			get_the_digit(calculate, answer, number_1, number_2, number_3, number_4);

			s_time = time(0);

			while (1)
			{
				if (time(0) == s_time + TIME_LIMIT)		// 시간 초과
				{
					system("cls");
					printf("시간 초과되었습니다.\n");
					value_clear(&count, answer, player_answer);
					show_question(&calculate, number_1);
					get_the_digit(calculate, answer, number_1, number_2, number_3, number_4);
					s_time = time(0);
				}
				if (_kbhit())
				{
					ch = _getch();
					if (ch == 27)		// esc
					{
						printf("나가기 버튼을 누르셨습니다.\n");
						break;
					}
					if (ch == '\b' && count > 0)	// 백스페이스 처리
					{
						printf("\b \b");
						count--;
					}
					else if (ch == '\b' && count == 0);
					else
						printf("%c", ch);
					if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || ch == ' ')	// 영어 소문자, 대문자, 스페이스바 처리
					{
						player_answer[count] = ch;
						count++;
					}
				}
				if (count == strlen(answer))	// 문제의 정답의 길이만큼 입력 시 정답 비교
				{
					for (int i = 0; i < strlen(answer); i++)
					{
						if (player_answer[i] != answer[i])	// 글자 하나라도 틀리면 flag 0으로 바뀌고 오답 처리
						{
							flag = 0;
							break;
						}
						else
							flag = 1;
					}
					if (flag == 1)
					{
						system("cls");
						printf("정답은 %s 입니다.\n", answer);
						printf("정답입니다.\n");
					}
					else
					{
						system("cls");
						printf("정답은 %s 입니다.\n", answer);
						printf("%s 를 입력하셨습니다.\n", player_answer);
						printf("오답입니다.\n");
					}
					s_time = time(0);
					value_clear(&count, answer, player_answer);
					show_question(&calculate, number_1);
					get_the_digit(calculate, answer, number_1, number_2, number_3, number_4);
				}
			}
		}
		else if (!(strcmp(user_start, quit)))	// 나가기
			break;
		else
			printf("잘못입력하셨습니다.\n");
	} while (1);
	return 0;
}

void show_question(int*result, char number_list[][30])	// 문제 출제
{
	int question_1 = (rand() % 9) + 1;
	int question_2 = (rand() % 9) + 1;

	printf("%s x %s?\n", number_list[question_1], number_list[question_2]);
	*result = question_1 * question_2;
}

void get_the_digit(int calculate, char *answer, char number_1[][30], char number_2[][30], char number_3[][30], char number_4[][30])	// 자릿수 구하고 자릿수에 해당하는 영어 입력, answer 구하기
{
	int one_digit = 0, ten_digit = 0, hundred_digit = 0;

	one_digit = calculate % 10;
	calculate /= 10;
	ten_digit = calculate % 10;
	calculate /= 10;
	hundred_digit = calculate % 10;

	if (hundred_digit != 0)		// 스페이스 처리로 인해 복잡해짐
	{
		strcpy(answer, number_4[hundred_digit]);
		if (ten_digit == 1)
		{
			strcat(answer, " ");
			strcat(answer, number_3[one_digit]);
		}
		else if (ten_digit == 0)
		{
			if (one_digit != 0)
			{
				strcat(answer, " ");
				strcat(answer, number_1[one_digit]);
			}
		}
		else
		{
			strcat(answer, " ");
			strcat(answer, number_2[ten_digit]);
			if (one_digit != 0)
			{
				strcat(answer, " ");
				strcat(answer, number_1[one_digit]);
			}
		}
	}
	else if (ten_digit != 0)
	{
		if (ten_digit == 1)
			strcat(answer, number_3[one_digit]);
		else
		{
			strcat(answer, number_2[ten_digit]);
			if (one_digit != 0)
			{
				strcat(answer, " ");
				strcat(answer, number_1[one_digit]);
			}
		}
	}
	else
		strcat(answer, number_1[one_digit]);
}
void value_clear(int*count, char answer[], char player_answer[])	// 값 초기화
{
	char clear[30] = { 0 };
	*count = 0;
	strcpy(answer, clear);
	strcpy(player_answer, clear);
}