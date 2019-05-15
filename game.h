#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#if defined(_WIN32) || defined(__CYGWIN__) || defined(_WIN64)
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#define SLEEP_SECOND 2
#define MAX_WORD 9896

int showMenu();
int showTypingMenu();
int showMiniGameMenu();
int showTimeAttackMenu();
int showMainScoreMenu();
void printArray(int** input_array, int col_count);
void resetArray(int** input_array, int col_count);
void moveLogic(int** input_array, int what, int col_count, int* x, int* y);
void sleepfor(int sec);
void clearScreen();
void mini_maze();

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