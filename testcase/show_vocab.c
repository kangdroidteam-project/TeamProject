#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "start_game_prototype.h"

// TESTCASE
// Show word list by page - by - page

int main(void) {
    char array[10];
    for (int i = 0; i < MAX_WORD; i++) {
        printf("%s\n", word[i]);
        if (i != 0) {
            if (i % 20 == 0) {
                printf("Press enter to continue, enter up to see previous word, enter exit to finish: ");
                fgets(array, 10, stdin);
                array[strlen(array) - 1] = 0;
                clearScreen();
                if (!strcmp(array, "up")) {
                    if (i <= 40) {
                        i = 0;
                    } else if (i > 40) {
                        i = i - 40;
                    }
                } else if (!strcmp(array, "exit")) {
                    i = MAX_WORD + 2;
                }
            }
        }
    }
    return 0;
}

void clearScreen() {
    #if defined(_WIN32) || defined(__CYGWIN__) || defined(_WIN64)
    // Clear Console for Windows
    system("cls");
    #else
    system("clear && printf '\e[3J'");
    #endif
}