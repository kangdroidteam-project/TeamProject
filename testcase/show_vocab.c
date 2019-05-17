#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "start_game_prototype.h"

// TESTCASE
// Show word list by page - by - page

int main(void) {
    char array[10];
    int success = 0;
    for (int i = 0; i < MAX_WORD; i++) {
        printf("%s\n", word[i]);
        if (i != 0) {
            if (i % 20 == 0) {
                printf("Press up key to move 1 page up, press down key to move to next page, press left/right key to exit.");
                success = 0;
                while (success == 0) {
                    switch(getInput()) {
                        case 1:
                            if (i <= 40) {
                                i = 0;
                            } else {
                                i = i - 40;
                            }
                            success = 1;
                            break;
                        case 2:
                            success = 1;
                            break;
                        case 3:
                            i = MAX_WORD + 2;
                            success = 1;
                            break;
                        case 0:
                            success = 0;
                            break;
                    }
                }
                clearScreen();
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

int getInput() {
    if (getch() == '\033') { // if the first value is esc
        getch(); // skip the [
        switch(getch()) { // the real value
            case 'A':
                // code for arrow up
                return 1;
                break;
            case 'B':
                // code for arrow down
                return 2;
                break;
            case 'C': case 'D':
                // code for arrow right
                return 3;
                break;
            default:
                printf("Please enter arrow key!\n");
                return 0;
                break;
        }
    }
}

#if defined(__APPLE__) || defined(__linux__) || defined(__unix__) || defined(__unix) || defined(unix)
int getch(void) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif