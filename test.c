#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int compareStrings(char word_list[][30], char *user_input, int which_one);
void generateDict(char word[][30]);
void startGame(char word_list[][30]);
int main(void) {
    char word[1000][30] = {""};
    //Change Seed based on time
    srand((unsigned)time(NULL));
    generateDict(word);
    printf("Word saved!\n");
    //printf("%s", word[990]);
    //startGame(word);

    //enerateWordList(filedir);

    startGame(word);
    return 0;
}

void startGame(char word_list[][30]) {
    char user_input[60];
    int which_one, check; // Which one are you going to show?
    //unsigned long count = sizeof(word_list)/sizeof(word_list[0]); // VERTICAL COUNT

    for (int i = 0; i < 5; i++) {
        //Select which word computer is going to show 2 user.
        which_one = rand() % 1000;

        //Show word that computer chose, and get input from user.
        printf("%s\n", word_list[which_one]);
        scanf("%s", user_input);

        //Check whether user entered same thing with computer.
        check = compareStrings(word_list, user_input, which_one);
        if (check == 1) {
            printf("You are correct!\n");
        } else if (check == 0) {
            printf("You are wrong!\n");
        }
        printf("\n");
    }
}

int compareStrings(char word_list[][30], char *user_input, int which_one) {
    int counter = 0;

    //If user entered same thing with computer, strlen(user_input) and strlen(word_list[which_one]) should be same.
    //But anyway, the important part is, each part of array SHOULD BE SAME with both computer and user input. So let's check that
    for (int i = 0; i < strlen(user_input); i++) {
        if (word_list[which_one][i] == user_input[i]) {
            counter++;
        } else {
            // No need to loop till strlen(user_input), just exit loop.
            break;
        }
    }
    if (counter == strlen(user_input)) {
        return 1; //You are correct
    } else {
        return 0; //You are wrong
    }
}

// TODO: EXCEPTION MAINTANCE
void generateDict(char word[][30]) {
    char ch;
    int lines = 0, x = 0;
    FILE * fp = fopen("/Users/kangdroid/Desktop/University/1st/CPrgramming/TeamProject/source/dict.txt", "r");
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