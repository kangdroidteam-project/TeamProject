#include "game.h"

int showMenu();

struct typing_score type_score;
struct minigame_score mini_score;
struct timeattack_score timeat_score;

int main(void) {
    int menu_ret_value;

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
    printf("1. 타자 연습\n");
    printf("2. 미니게임\n");
    printf("3. 타임 어텍\n");
    printf("4. 게임별 점수 확인\n");
    printf("5. 게임에 사용된 단어 훑어보기!\n");
    printf("6. 저장/불러오기!\n");
    printf("7. 끝내기\n");
    printf("하고 싶은 메뉴를 선택하세요: ");
    scanf("%d", &user_choice);

    switch (user_choice) {
		// DEBUGGING MENU: DEV ONLY
		case 0:
			mini_score.fight_computer = 100;
			break;
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