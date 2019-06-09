#include "game.h"
struct typing_score type_score;
void word_game(int mode) {
	int i = 0, ran, s_time, j = 0, is_practice = 0;
	char input_word[70], input, showing[65];
	// First bits starts
	srand(time(0));
	showString(showing, mode, i);
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	s_time = time(0);

	// After first round, we need to take while loop
	while (1) {
		if (mode == 0) {
			if (i >= 5) {
				printf("축하드립니다!\n 게임을 모두 끝내셨어요!\n");
				type_score.extreme_unlock = mode;
				Sleep(1500);
				break;
			}
		}
		else if (mode == 1 || mode == 2 || mode == 3 || mode == 4) {
			if (i >= 15) {
				printf("축하드립니다!\n 게임을 모두 끝내셨어요!\n");
				type_score.extreme_unlock = mode + 1;
				Sleep(1500);
				if (mode == 4)
					break;
				if (correct > 0)
				{
					mode++;
					i = 0;
					j = 0;
					showString(showing, mode, i);
					continue;
				}
			}
		}
		if (time(0) == s_time + 10) {
			printf("시간 초과되었습니다.\n");
			j = 0;
			i++;
			Sleep(1000);
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			if (mode == 0) {
				if (i != 5) {
					system("cls");
					showString(showing, mode, i);
				}
			}
			if (mode == 1 || mode == 2 || mode == 3 || mode == 4) {
				if (i != 15) {
					system("cls");
					showString(showing, mode, i);
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
						switch (mode) {
						case 0:
							break;
						case 1:
							type_score.easy++;
							break;
						case 2:
							type_score.moderate += (int)(5 * (1 - (time(0) - s_time-2) / TIME_LIMIT));
							break;
						case 3:
							type_score.hard += (int)(5 * (1 - (time(0) - s_time-1) / TIME_LIMIT));
								break;
						case4:
							type_score.extreme+= (int)(5 * (1 - (time(0) - s_time) / TIME_LIMIT));
								break;
						}
						j = 0;
						i++;
						correct++;
						Sleep(1000);
						FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
						if (mode == 0) {
							if (i != 5) {
								system("cls");
								showString(showing, mode, i);
							}
						}
						if (mode == 1 || mode == 2 || mode == 3 || mode == 4) {
							if (i != 15) {
								system("cls");
								showString(showing, mode, i);
							}
						}
						s_time = time(0);
					}
					else {
						j = 0;
						i++;
						printf("틀렸습니다\n");
						if (mode == 4)
							if(type_score.extreme!=0)
							     type_score.extreme--;
						Sleep(1000);
						FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
						if (i != 15) {
							system("cls");
							showString(showing, mode, i);
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
