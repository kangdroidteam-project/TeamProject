#include "game.h"

int showMenu();

int main(void) {
    int menu_ret_value;
	system("mode con cols=80 lines=30"); // Resize Console to 80(x) * 30(y)

	// if showMenu returns any other value than 7,  we show the menu again and again.
    do {
        menu_ret_value = showMenu();
    } while (menu_ret_value != 7);

    // Clear screen before exit!
    system("cls");
    return 0;
}

int showMenu() {
    int user_choice, typ_menu_ret;

    // Clear screen before we start anything;
    system("cls");
	game_title_headline(0, "���� ��ſ� Ÿ�ڰ���!\n");

	gotoxy(30, 12);
    printf("1. Ÿ�� ����\n");

	gotoxy(30, 14);
    printf("2. �̴ϰ���\n");

	gotoxy(30, 16);
    printf("3. Ÿ�� ����\n");

	gotoxy(30, 18);
    printf("4. ���Ӻ� ���� Ȯ��\n");

	gotoxy(30, 20);
    printf("5. ���ӿ� ���� �ܾ� �Ⱦ��!\n");

	gotoxy(30, 22);
    printf("6. ����/�ҷ�����!\n");

	gotoxy(30, 24);
    printf("7. ������\n");

	gotoxy(30, 26);
    printf("�ϰ� ���� �޴��� �����ϼ���: ");
    scanf("%d", &user_choice);

	// Same Algorithm applied in main funciton. Each function returns some value.
    switch (user_choice) {
        case 1:
            // Typing practice MENU Function
            do {
                system("cls");
                typ_menu_ret = showTypingMenu();
            } while (typ_menu_ret != 0);
        return user_choice;

        case 2:
            // Mini game MENU Function
            do {
                system("cls");
                typ_menu_ret = showMiniGameMenu();
            } while (typ_menu_ret != 0);
        return user_choice;

        case 3:
            // Time Attack MENU Function
			system("cls");
			showDefMenu();
            /*do {
                system("cls");
                typ_menu_ret = showTimeAttackMenu();
            } while (typ_menu_ret != 0);*/
        return user_choice;

        case 4:
            // Score - per - Game MENU Function
            do {
                system("cls");
                typ_menu_ret = showMainScoreMenu();
            } while (typ_menu_ret != 0);
        return user_choice;

        case 5:
            // Show Vocab list
            do {
                system("cls");
                typ_menu_ret = showVocabMenu();
            } while (typ_menu_ret != 0);
        return user_choice;

        case 6:
            // Save-Load Menu
            do {
                system("cls");
                typ_menu_ret = slMenu();
            } while (typ_menu_ret != 0);
        return user_choice;
        
        case 7:
            // END
        return user_choice;

        default:
        return 0;
    }
}