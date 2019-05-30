#include "game.h"
void word_game(int mode) {
	int i = 0, ran, s_time, j = 0, is_practice = 0;
	int tpye_score_easy, type_score_morderate, tpye_score_hard, tpye_score_extreme,correct_word;
	char input_word[20], input, showing[30];
	// First bits starts
	srand(time(0));
	showString(showing, mode, i);
	s_time = time(0);

	// After first round, we need to take while loop
	while (1) {
		if (i >= 5) {
			break;
		}
		if (time(0) == s_time + TIME_LIMIT) {
			system("cls");
			i++;
			showString(showing, mode, i);
			s_time = time(0);
			j = 0;
		}
		if (_kbhit()) {
			input = _getch();
			if (input == 27) {
				break;
			}
			if (input == '\b') {

				printf("\b \b");
				j = j - 1;
			} else if ((input >= 'a'&&input <= 'z') || (input >= 'A'&&input <= 'Z')) {
				printf("%c", input);
				input_word[j] = input;
				j++;
				if (j == strlen(showing)) {
					input_word[j] = 0;
					if (!strcmp(input_word, showing)) {
						printf("\n정답입니다");
						if(mode==0||mode==1)
	                        correct_word++:
	                    if(mode==2)
	                    	type_score_morderate=(int)(5*(1-(time(0)-s_time)/TIME_LIMIT));
	                    if(mode==3)
	                        tpye_score_hard=(int)(5*(1-(time(0)-s_time)/TIME_LIMIT));
						Sleep(1000);
						i++;
						system("cls");
						showString(showing, mode, i);
						s_time = time(0);
						j = 0;
					} else {
						j = 0;
						printf("틀렸습니다");
						Sleep(1000);
					}
				}
			}
		}
	}
	is_practice=correct_word;
	tpye_score_easy=correct_word;
}
void showString(char *input, int mode, int count) {
	int ran = rand() % MAX_WORD_SHORT;
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
		strcpy(input, long_word[ran]);
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