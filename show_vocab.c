#include "game.h"

void showVocab() {
    int success = 0;
    for (int i = 0; i < MAX_WORD; i++) {
        printf("%s\n", word_list[i]);
        if (i != 0) {
            if (i % 20 == 0) {
                printf("윗 방향키로 이전 페이지로, 아래 방향키로 다음 페이지로 이동하거나, 왼쪽/오른쪽 키로 이 메뉴를 종료합니다.");
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
                return 0;
                break;
        }
    } else {
        return 0;
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