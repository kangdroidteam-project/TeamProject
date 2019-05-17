#include "start_game_prototype.h"

// This is the example of how to use getch

int main(void) {
    if (getch() == '\033') { // if the first value is esc
        getch(); // skip the [
        switch(getch()) { // the real value
            case 'A':
                // code for arrow up
                break;
            case 'B':
                // code for arrow down
                break;
            case 'C':
                // code for arrow right
                break;
            case 'D':
                // code for arrow left
                break;
        }
    }
    return 0;
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