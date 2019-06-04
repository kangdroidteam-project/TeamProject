#include "game.h"

struct typing_score type_score;
struct minigame_score mini_score;
struct timeattack_score timeat_score;

int showMainScoreMenu() {
    int user_input_typing;
	char dummy[10];

    printf("1. Ÿ�� ����\n");
    printf("2. �̴ϰ���\n");
    printf("3. Ÿ�Ӿ���\n");
    printf("0. �� �޴��� ���ư���\n");
    printf("���ϴ� �ܰ踦 �Է����ּ���! ");
    scanf("%d", &user_input_typing);
	while (getchar() != '\n');

    system("cls");
    switch (user_input_typing) {
        case 1:
            // Typing Score
            printf("1. �ʱ�: %d��\n", type_score.easy);
            printf("2. �߱�: %d��\n", type_score.moderate);
            printf("3. ���: %d��\n", type_score.hard);
            printf("4. ���: %d��\n", type_score.extreme);
            printf("���� �޴��� ���ư����� ����Ű�� �Է��ϼ���.. ");
			fgets(dummy, sizeof(dummy), stdin);
			break;
        case 2:
            // Minigame Score
            printf("1. ������(�����): %.2lf��\n", ((mini_score.timecalc_try) != 0) ? (double)(mini_score.timecalc_ans) / (mini_score.timecalc_try) * 100 : 0);
            printf("2. ��ã��: %d��\n", mini_score.find_road);
            printf("3. ��ǻ�Ϳ��� ���: %d��\n", mini_score.fight_computer);
            printf("4. �ܾ� ����: %d��\n", mini_score.mem_word);
			printf("���� �޴��� ���ư����� ����Ű�� �Է��ϼ���.. ");
			fgets(dummy, sizeof(dummy), stdin);
			break;
        case 3:
            // Word Time-Attack Score
			printf("1. ���ĺ� n��: %d��\n", timeat_score.alp_n1);
			printf("2. ���ĺ� n��: %d��\n", timeat_score.alp_n2);
			printf("3. ���ĺ� n��: %d��\n", timeat_score.alp_n3);

            printf("4. �ܾ� n��: %d��\n", timeat_score.word_n1);
            printf("5. �ܾ� n��: %d��\n", timeat_score.word_n2);
            printf("6. �ܾ� n��: %d��\n", timeat_score.word_n3);
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