#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define SLEEP_SECOND 2000
#define MAX_WORD 9896
#define MAX_WORD_SHORT 2184
#define MAX_WORD_MID 5460
#define MAX_WORD_HD 2243
#define TIME_LIMIT 5
#define TIME_LIMIT_TIMES 10

int showMenu();
int showTypingMenu();
int showMiniGameMenu();
int showMainScoreMenu();
int showVocabMenu();
void printArray(int** input_array, int col_count);
void resetArray(int** input_array, int col_count);
void moveLogic(int** input_array, int what, int col_count, int* x, int* y);
void showVocab(char *list_word[], int max_word_end);
void mini_maze();
void saveLogic(char *save_dir);
void save(char* wtf, char *save_file_dir);
void makeArray(int value, char* wtf);
void load(char *save_file_dir);
int slMenu();
void fight_computer();
void show_rule();
void set_difficulty(struct difficulty_var *diff_var);
void start_game(struct difficulty_var *diff_var);
void get_the_digit(int, char*, char number_1[][30], char number_2[][30], char number_3[][30], char number_4[][30]);
void show_question(int*, char number_list[][30]);
void value_clear(int*count, char answer[], char player_answer[]);
void word_game(int);
void showString(char *input, int mode, int count);
void gotoxy(int x, int y);
void showDefMenu();


static void game_title_headline(int select, char *input)
{
	int i, x, y;

	system("cls");

	x = 0;
	y = 0;
	gotoxy(x, y);
	printf("¦£");
	for (i = 1; i < 79; i++) {
		gotoxy(x + i, y);
		printf("¦¡");
	}
	gotoxy(78, 0);
	printf("¦¤");

	for (i = 1; i < 11; i++)
	{
		y++;
		gotoxy(x, y);
		printf("¦¢");

		if (i == 5 && select == 0)
		{
			gotoxy(30, i);
			printf(input);
		}

		x += 78;
		gotoxy(x, y);
		printf("¦¢");
		x = 0;
	}

	gotoxy(x, y);
	printf("¦¦");
	for (i = 1; i < 79; i++) {
		gotoxy(x + i, y);
		printf("¦¡");
	}
	gotoxy(78, 10);
	printf("¦¥");

	gotoxy(0, 0);
}

struct typing_score {
    int easy;
    int moderate;
    int hard;
    int extreme;
	int extreme_unlock;
} TYPSCORE;

struct minigame_score {
    int timecalc_try;
	int timecalc_ans;
	int timecalc_try_extreme;
	int timecalc_ans_extreme;
    int find_road;
    int fight_computer;
	int fight_computer_lock_info;
    int mem_word;
} MINISCORE;

struct timeattack_score {
	int alp_n1;
	int alp_n2;
	int alp_n3;
    int word_n1;
    int word_n2;
    int word_n3;
} TIMEATTSCORE;

extern struct typing_score type_score;
extern struct minigame_score mini_score;
extern struct timeattack_score timeat_score;

extern char *word_list[];
extern char *short_word[];
extern char *mid_word[];
extern char *long_word[];
extern char *extreme_sentence[];