#include "game.h"

int showMiniGameMenu() {
    int user_input_typing;
	game_title_headline(0, "�̴ϰ���!\n");

	gotoxy(30, 12);
    printf("1. ������\n");

	gotoxy(30, 14);
    printf("2. ��ã��\n");

	gotoxy(30, 16);
    printf("3. ��ǻ�Ϳ��� ���!\n");

	gotoxy(30, 18);
    printf("4. �ܾ� ����!\n");

	gotoxy(30, 20);
    printf("0. �� �޴��� ���ư���\n");

	gotoxy(30, 22);
    printf("���ϴ� �ܰ踦 �Է����ּ���! ");
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