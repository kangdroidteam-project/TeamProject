#include "test.h"

int main(void) {
    //Change Seed based on time
    srand((unsigned)time(NULL));
    startGame(word);
    return 0;
}

void startGame(char word_list[][30]) {
    char user_input[60];
    int which_one, check; // Which one are you going to show?
    //unsigned long count = sizeof(word_list)/sizeof(word_list[0]); // VERTICAL COUNT

    for (int i = 0; i < 5; i++) {
        //Select which word computer is going to show 2 user.
        which_one = rand() % 9896;

        //Show word that computer chose, and get input from user.
        printf("%s\n", word_list[which_one]);
        scanf("%s", user_input);

        //Check whether user entered same thing with computer.
        if (!strcmp(word_list[which_one], user_input)) {
            printf("You are correct!\n");
        } else {
            printf("You are wrong!\n");
        }
        printf("\n");
    }
}

// TODO: EXCEPTION MAINTANCE
void generateDict(char word[][30]) {
    char ch;
    int lines = 0, x = 0;
    FILE * fp = fopen("/Users/kangdroid/Desktop/test.txt", "r");
    while (!feof(fp)) {
        ch = fgetc(fp);
        //printf("LINES: %d\nX: %d\n", lines, x);
        if (ch == '\n') {
            lines++;
            x = 0;
        } else {
            word[lines][x] = ch;
            x++;
        }
    }
    if (word[lines][strlen(word[lines]) - 1] == -1) {
        word[lines][strlen(word[lines]) - 1] = '\0';
    }
    fclose(fp);
}