#include "game.h"

int showMiniGameMenu() {
    int user_input_typing;

    printf("1. 구구단\n");
    printf("2. 길찾기\n");
    printf("3. 컴퓨터와의 대결!\n");
    printf("4. 단어 기억력!\n");
    printf("0. 전 메뉴로 돌아가기\n");
    printf("원하는 단계를 입력해주세요! ");
    scanf("%d", &user_input_typing);

    switch (user_input_typing) {
        case 1:
            // GAME STARTS
			times_table();
        return 0;
        case 2:
            // GAME STARTS
            mini_maze();
        return 0;
        case 3:
            // GAME STARTS
			fight_computer();
        return 0;
        case 4:
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