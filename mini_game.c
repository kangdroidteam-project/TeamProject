#include "game.h"

int showMiniGameMenu() {
    int user_input_typing;
	game_title_headline(0, "미니게임!\n");

	gotoxy(30, 12);
    printf("1. 구구단\n");

	gotoxy(30, 14);
    printf("2. 길찾기\n");

	gotoxy(30, 16);
    printf("3. 컴퓨터와의 대결!\n");

	gotoxy(30, 18);
    printf("4. 단어 기억력!\n");

	gotoxy(30, 20);
    printf("0. 전 메뉴로 돌아가기\n");

	gotoxy(30, 22);
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