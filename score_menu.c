#include "game.h"

struct typing_score type_score;
struct minigame_score mini_score;
struct timeattack_score timeat_score;

int showMainScoreMenu() {
    int user_input_typing;
	char dummy[10];

	game_title_headline(0, "����Ȯ��!\n");

	gotoxy(30, 12);
    printf("1. Ÿ�� ����\n");

	gotoxy(30, 14);
    printf("2. �̴ϰ���\n");

	gotoxy(30, 16);
    printf("3. Ÿ�Ӿ���\n");

	gotoxy(30, 18);
    printf("0. �� �޴��� ���ư���\n");

	gotoxy(30, 20);
    printf("���ϴ� �ܰ踦 �Է����ּ���! ");
    scanf("%d", &user_input_typing);
	while (getchar() != '\n');

    system("cls");
    switch (user_input_typing) {
        case 1:
            // Typing Score
			game_title_headline(0, "Ÿ�ڰ��� ����!\n");

			gotoxy(30, 12);
            printf("1. �ʱ�: %d��\n", type_score.easy);

			gotoxy(30, 14);
            printf("2. �߱�: %d��\n", type_score.moderate);

			gotoxy(30, 16);
            printf("3. ���: %d��\n", type_score.hard);

			gotoxy(30, 18);
            printf("4. ���: %d��\n", type_score.extreme);

			gotoxy(30, 20);
            printf("���� �޴��� ���ư����� ����Ű�� �Է��ϼ���.. ");
			fgets(dummy, sizeof(dummy), stdin);
			break;
        case 2:
            // Minigame Score
			game_title_headline(0, "�̴ϰ��� ����!\n");

			gotoxy(30, 12);
            printf("1. ������(�����): %.2lf��\n", ((mini_score.timecalc_try) != 0) ? (double)(mini_score.timecalc_ans) / (mini_score.timecalc_try) * 100 : 0);

			gotoxy(30, 14);
            printf("2. ��ã��: %d��\n", mini_score.find_road);

			gotoxy(30, 16);
            printf("3. ��ǻ�Ϳ��� ���: %d��\n", mini_score.fight_computer);

			gotoxy(30, 18);
            printf("4. �ܾ� ����: %d��\n", mini_score.mem_word);

			gotoxy(30, 20);
			printf("���� �޴��� ���ư����� ����Ű�� �Է��ϼ���.. ");
			fgets(dummy, sizeof(dummy), stdin);
			break;
        case 3:
            // Word Time-Attack Score
			game_title_headline(0, "Ÿ�Ӿ��� ����!\n");

			gotoxy(30, 12);
			printf("1. ���ĺ� n��: %d��\n", timeat_score.alp_n1);

			gotoxy(30, 14);
			printf("2. ���ĺ� n��: %d��\n", timeat_score.alp_n2);

			gotoxy(30, 16);
			printf("3. ���ĺ� n��: %d��\n", timeat_score.alp_n3);

			gotoxy(30, 18);
            printf("4. �ܾ� n��: %d��\n", timeat_score.word_n1);

			gotoxy(30, 20);
            printf("5. �ܾ� n��: %d��\n", timeat_score.word_n2);

			gotoxy(30, 22);
            printf("6. �ܾ� n��: %d��\n", timeat_score.word_n3);

			gotoxy(30, 24);
			printf("���� �޴��� ���ư����� ����Ű�� �Է��ϼ���.. ");
			fgets(dummy, sizeof(dummy), stdin);
			break;
        case 0:
            // Return to last menu
        return 0;
        default:
            // Get another input;
        return 10;
    }
}