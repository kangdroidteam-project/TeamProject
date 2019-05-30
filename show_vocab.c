#include "game.h"

int showVocabMenu() {
    int user_input_typing;

    printf("1. ����(�ʱ�) �ܾ�\n");
    printf("2. �߱� �ܾ�\n");
    printf("3. ��� �ܾ�\n");
    printf("4. �ֻ�� ���� �� ����\n");
    printf("0. �� �޴��� ���ư���\n");
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

void showVocab(char list_word[][18], int max_word_end) {
    int success = 0, ch = 0;
    for (int i = 0; i < max_word_end; i++) {
        printf("%s\n", list_word[i]);
        if (i == max_word_end - 1) {
            printf("�̰� ���Դϴ�! �޴��� ���ư��ϴ�..\n");
            sleepfor(2);
        }
        if ((i != 0) && (i % 20 == 0)) {
            printf("�� ����Ű�� ���� ��������, �Ʒ� ����Ű�� ���� �������� �̵��ϰų�, ����/������ Ű�� �� �޴��� �����մϴ�.");
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
            system("cls");
        }
    }
}