#include "game.h"

int showTimeAttackMenu() {
    int user_input_typing;

    printf("1. 단어 n개\n");
    printf("2. 단어 n개\n");
    printf("3. 단어 n개\n");
    printf("0. 전 메뉴로 돌아가기\n");
    printf("원하는 단계를 입력해주세요! ");
    scanf("%d", &user_input_typing);

    switch (user_input_typing) {
        case 1:
            // GAME STARTS
        return 0;
        case 2:
            // GAME STARTS
        return 0;
        case 3:
            // GAME STARTS
        return 0;
        case 0:
            // Return to last menu
        return 0;
        default:
            // Get another input;
        return 10;
    }
}