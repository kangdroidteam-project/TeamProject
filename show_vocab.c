#include "game.h"

/*
  Each menu shows value of structure variable.
  Use enter key to escape current functions.
  (Menu functions are same as main functions)
*/
int showVocabMenu() {
    int user_input_typing;

	game_title_headline(0, "�ܾ� ����Ʈ!\n");

	gotoxy(30, 12);
    printf("1. ����(�ʱ�) �ܾ�\n");

	gotoxy(30, 14);
    printf("2. �߱� �ܾ�\n");

	gotoxy(30, 16);
    printf("3. ��� �ܾ�\n");

	gotoxy(30, 18);
    printf("4. �ֻ�� ���� �� ����\n");

	gotoxy(30, 20);
    printf("0. �� �޴��� ���ư���\n");

	gotoxy(30, 22);
    printf("���ϴ� �ܰ踦 �Է����ּ���! ");
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

/*
  Get list_word, max_word_end from call, show it to user.
  We are basically using arrow key to control i value(in user's view, vocab list page)
  Basically if i(iteration counter variable) exceeds max_word_end, then we show warning sign and automatically return to menu.
  if i is 0, we show list_word[0] value. again and again.
*/
void showVocab(char *list_word[], int max_word_end) {
    int success = 0, ch = 0;
	system("cls");
    for (int i = 0; i < max_word_end; i++) {
        printf("%s\n", list_word[i]);
        if (i == max_word_end - 1) {
            printf("�̰� ���Դϴ�! �޴��� ���ư��ϴ�..\n");
            Sleep(2000);
        }
        if ((i != 0) && (i % 20 == 0)) {
            printf("�� ����Ű�� ���� ��������, �Ʒ� ����Ű�� ���� �������� �̵��ϰų�, ����/������ Ű�� �� �޴��� �����մϴ�.");
            success = 0;
			// Those are key - core functions fore controling i(iteration variable) value.
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
            system("cls");
        }
    }
}