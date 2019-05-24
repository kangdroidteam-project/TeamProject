#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#if defined(_WIN32) || defined(__CYGWIN__) || defined(_WIN64)
    #include <windows.h>
    #include <conio.h>
#else
    #include <unistd.h>
    #include <termios.h>
#endif

#define SLEEP_SECOND 2
#define MAX_WORD 9896
#define MAX_WORD_SHORT 2184
#define MAX_WORD_MID 5460
#define MAX_WORD_HD 2243

int showMenu();
int showTypingMenu();
int showMiniGameMenu();
int showTimeAttackMenu();
int showMainScoreMenu();
int showVocabMenu();
void printArray(int** input_array, int col_count);
void resetArray(int** input_array, int col_count);
void moveLogic(int** input_array, int what, int col_count, int* x, int* y);
void sleepfor(int sec);
void clearScreen();
void showVocab(char list_word[][18], int max_word_end);
void mini_maze();
int getInput();
void saveLogic(char *save_dir);
void save(char* wtf, char *save_file_dir);
void makeArray(int value, char* wtf);
void load(char *save_file_dir);
int slMenu();

typedef struct typing_score {
    int easy;
    int moderate;
    int hard;
    int extreme;
} TYPSCORE;

typedef struct minigame_score {
    int timecalc;
    int find_road;
    int fight_computer;
    int mem_word;
} MINISCORE;

typedef struct timeattack_score {
    int word_n1;
    int word_n2;
    int word_n3;
} TIMEATTSCORE;

TYPSCORE type_score;
MINISCORE mini_score;
TIMEATTSCORE timeat_score;

extern char word_list[9990][30];
extern char short_word[MAX_WORD_SHORT][18];
extern char mid_word[MAX_WORD_MID][18];
extern char long_word[MAX_WORD_HD][18];