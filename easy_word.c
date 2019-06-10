#include "game.h"
struct typing_score type_score;
void word_game(int mode) {
	int i = 0, ran, s_time, j = 0, correct = 0, flash_score = 0;
	char input_word[70], input, showing[65];
	// First bits starts
	srand(time(0));
	system("cls");
	game_title_headline(0, "타자연습시작\n");
	gotoxy(30, 12);
	showString(showing, mode, i);
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	s_time = time(0);
	printf("나가시려면 esc를 눌러주세요\n");
	printf("사용자가 입력하고 있는 단어:");
	gotoxy(32, 14);

	// After first round, we need to take while loop
	while (1)
	{
		if (mode == 0) {
			if (i >= 5) {
				game_title_headline(0, "축하드립니다! 연습모드 게임을 모두 끝내셨어요!\n");
				type_score.extreme_unlock = mode;
				Sleep(1500);
				break;
			}
		}
		else if (mode == 1 || mode == 2 || mode == 3 || mode == 4) {
			if (i >= 15) {
				game_title_headline(0, "축하드립니다! 게임을 모두 끝내셨어요!");
				Sleep(1500);
				gotoxy(30, 12);
				type_score.extreme_unlock = mode + 1;
				if (mode == 1)
					type_score.easy += flash_score;
				else if (mode == 2)
					type_score.moderate += flash_score;
				else if (mode == 3)
					type_score.hard += flash_score;
				else if (mode == 4)
					type_score.extreme += flash_score;
				if (correct >= 10)
					if (mode < 4)
					{
						game_title_headline(0, "잘했으니 다음 라운드 갈까?");
						Sleep(1500);
						system("cls");
						game_title_headline(0, "다음 모드로 넘어갑니다.");
						mode++;
						flash_score = 0;
						i = 0;
						j = 0;
						Sleep(1500);
						system("cls");
						game_title_headline(0, "타자연습시작!!\n");
						gotoxy(30, 12);
						showString(showing, mode, i);
						printf("나가시려면 esc를 눌러주세요\n");
						printf("사용자가 입력하고 있는 단어:");
						gotoxy(32, 14);
						continue;
					}
				break;
			}
		}
		if (time(0) == s_time + 10) {
			printf("\n시간 초과되었습니다.\n");
			j = 0;
			i++;
			printf("현재 점수는 %d입니다.\n", flash_score);
			Sleep(1000);
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			if (mode == 0) {
				if (i != 5) {
					system("cls");
					game_title_headline(0, "타자연습중\n");
					gotoxy(30, 12);
					showString(showing, mode, i);
					printf("나가시려면 esc를 눌러주세요\n");
					printf("사용자가 입력하고 있는 단어:");
					gotoxy(32, 14);
				}
			}
			if (mode == 1 || mode == 2 || mode == 3 || mode == 4) {
				if (i != 15) {
					system("cls");
					game_title_headline(0, "타자연습중\n");
					gotoxy(30, 12);
					showString(showing, mode, i);
					printf("나가시려면 esc를 눌러주세요\n");
					printf("사용자가 입력하고 있는 단어:");
					gotoxy(32, 14);
				}
			}
			s_time = time(0);
		}
		if (_kbhit()) {
			input = _getch();
			if (input == 27) {
				break;
			}
			if (input == '\b') {
				printf("\b \b");
				j = j - 1;
			}
			else if ((input >= 'a'&&input <= 'z') || (input >= 'A'&&input <= 'Z') || (input >= ' ' && input <= '/')) {
				printf("%c", input);
				input_word[j] = input;
				j++;
				if (j == strlen(showing)) {
					input_word[j] = 0;
					if (!strcmp(input_word, showing)) {
						printf("\n정답입니다\n");
						correct++;
						switch (mode) {
						case 0:
						case 1:
							flash_score++;
							break;
						case 2:
							flash_score += (int)(5 * (1 - (time(0) - s_time - 2) / TIME_LIMIT));
							break;
						case 3:
							flash_score += (int)(5 * (1 - (time(0) - s_time - 1) / TIME_LIMIT));
							break;
						case 4:
							flash_score += (int)(5 * (1 - (time(0) - s_time - 1) / TIME_LIMIT));
						}
						j = 0;
						i++;
						printf("현재 점수는 %d입니다.\n", flash_score);
						Sleep(1000);
						FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
						if (mode == 0) {
							if (i != 5) {
								system("cls");
								game_title_headline(0, "타자연습 잘하는 중\n");
								gotoxy(30, 12);
								showString(showing, mode, i);
								printf("나가시려면 esc를 눌러주세요\n");
								printf("사용자가 입력하고 있는 단어:");
								gotoxy(32, 14);
							}
						}
						if (mode == 1 || mode == 2 || mode == 3 || mode == 4) {
							if (i != 15) {
								system("cls");
								game_title_headline(0, "타자연습 잘하는 중\n");
								gotoxy(30, 12);
								showString(showing, mode, i);
								printf("나가시려면 esc를 눌러주세요\n");
								printf("사용자가 입력하고 있는 단어:");
								gotoxy(32, 14);
							}
						}
						s_time = time(0);
					}
					else {
						j = 0;
						i++;
						printf("\n틀렸습니다\n");
						printf("현재 점수는 %d입니다.\n", flash_score);
						if (mode == 4)
							flash_score--;
						Sleep(1000);
						FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
						if (mode == 0) {
							if (i != 5) {
								system("cls");
								game_title_headline(0, "타자연습모드인데 틀렸,,,? \n");
								gotoxy(30, 12);
								showString(showing, mode, i);
								printf("나가시려면 esc를 눌러주세요\n");
								printf("사용자가 입력하고 있는 단어:");
								gotoxy(32, 14);
							}
						}
						else {
							if (i != 15) {
								system("cls");
								game_title_headline(0, "타자연습 못하는 중 ㅠㅠ 잘좀해라..\n");
								gotoxy(30, 12);
								showString(showing, mode, i);
								printf("나가시려면 esc를 눌러주세요\n");
								printf("사용자가 입력하고 있는 단어:");
								gotoxy(32, 14);
							}
						}
						s_time = time(0);
					}
				}
			}
		}
	}
}
void showString(char *input, int mode, int count) {
	int ran = rand() % 720;
	/*
	* Mode 1: Easy Mode
	* Mode 2: Moderate Mode
	* Mode 3: Hard Mode
	* Mode 4: Extreme Mode
	* Mode 0: Practice Mode(without calculation)
	*/
	switch (mode) {
	case 1:
		strcpy(input, short_word[ran]);
		break;
	case 2:
		strcpy(input, mid_word[ran]);
		break;
	case 3:
		strcpy(input, long_word[ran]);
		break;
	case 4:
		strcpy(input, extreme_sentence[ran]);
		break;
	case 0:
		strcpy(input, short_word[ran]);
		break;
	default: //to Practice mode
		strcpy(input, short_word[ran]);
		break;
	}
	printf("%d) %s\n", count + 1, input);
}