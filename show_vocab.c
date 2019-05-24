#include "game.h"

#if defined(__APPLE__) || defined(__linux__) || defined(__unix__) || defined(__unix) || defined(unix)
int _getch(void) {
    return 0;
}
#endif

int showVocabMenu() {
    int user_input_typing;

    printf("1. 쉬운(초급) 단어\n");
    printf("2. 중급 단어\n");
    printf("3. 고급 단어\n");
    printf("4. 최상급 숙어 및 문장\n");
    printf("0. 전 메뉴로 돌아가기\n");
    printf("원하는 단계를 입력해주세요! ");
    scanf("%d", &user_input_typing);

    switch (user_input_typing) {
        case 1:
            // Easy word
            showVocab(short_word, MAX_WORD_SHORT);
        return 0;
        case 2:
            // Intermediate word
            showVocab(mid_word, MAX_WORD_MID);
        return 0;
        case 3:
            // High-End word
            showVocab(long_word, MAX_WORD_HD);
        return 0;
        case 4:
            // Real hard word
        return 0;
        case 0:
            // Return to last menu
        return 0;
        default:
            // Get another input;
        return 10;
    }
}

void showVocab(char list_word[][18], int max_word_end) {
    int success = 0, ch = 0;
    for (int i = 0; i < max_word_end; i++) {
        printf("%s\n", list_word[i]);
        if (i != 0) {
            if (i % 20 == 0) {
                printf("윗 방향키로 이전 페이지로, 아래 방향키로 다음 페이지로 이동하거나, 왼쪽/오른쪽 키로 이 메뉴를 종료합니다.");
                success = 0;
                while (success == 0) {
                    ch = _getch();
					if (ch == 224) {
						ch = _getch();
						switch (ch) {
						case 72:
							i = (i <= 40) ? 0 : i - 40;
							success = 1;
							break;
						case 80:
							success = 1;
							break;
						case 75: case 77:
							i = max_word_end + 2;
							success = 1;
							break;
						default:
							success = 0;
						}
					}
                }
                clearScreen();
            }
        }
    }
}