#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int showMenu();
int showTypingMenu();
int showMiniGameMenu();
int showTimeAttackMenu();
int showMainScoreMenu();
void clearScreen();

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