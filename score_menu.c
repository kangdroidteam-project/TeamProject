#include "game.h"

struct typing_score type_score;
struct minigame_score mini_score;
struct timeattack_score timeat_score;

int showMainScoreMenu() {
    int user_input_typing;
	char dummy[10];

	game_title_headline(0, "점수확인!\n");

	gotoxy(30, 12);
    printf("1. 타자 연습\n");

	gotoxy(30, 14);
    printf("2. 미니게임\n");

	gotoxy(30, 16);
    printf("3. 타임어택\n");

	gotoxy(30, 18);
    printf("0. 전 메뉴로 돌아가기\n");

	gotoxy(30, 20);
    printf("원하는 단계를 입력해주세요! ");
    scanf("%d", &user_input_typing);
	while (getchar() != '\n');

    system("cls");
    switch (user_input_typing) {
        case 1:
            // Typing Score
			game_title_headline(0, "타자게임 점수!\n");

			gotoxy(30, 12);
            printf("1. 초급: %d점\n", type_score.easy);

			gotoxy(30, 14);
            printf("2. 중급: %d점\n", type_score.moderate);

			gotoxy(30, 16);
            printf("3. 고급: %d점\n", type_score.hard);

			gotoxy(30, 18);
            printf("4. 상급: %d점\n", type_score.extreme);

			gotoxy(30, 20);
            printf("이전 메뉴로 돌아가려면 엔터키를 입력하세요.. ");
			fgets(dummy, sizeof(dummy), stdin);
			break;
        case 2:
            // Minigame Score
			game_title_headline(0, "미니게임 점수!\n");

			gotoxy(30, 12);
            printf("1. 구구단(정답률): %.2lf점\n", ((mini_score.timecalc_try) != 0) ? (double)(mini_score.timecalc_ans) / (mini_score.timecalc_try) * 100 : 0);

			gotoxy(30, 14);
            printf("2. 길찾기: %d점\n", mini_score.find_road);

			gotoxy(30, 16);
            printf("3. 컴퓨터와의 대결: %d점\n", mini_score.fight_computer);

			gotoxy(30, 18);
            printf("4. 단어 기억력: %d점\n", mini_score.mem_word);

			gotoxy(30, 20);
			printf("이전 메뉴로 돌아가려면 엔터키를 입력하세요.. ");
			fgets(dummy, sizeof(dummy), stdin);
			break;
        case 3:
            // Word Time-Attack Score
			game_title_headline(0, "타임어택 점수!\n");

			gotoxy(30, 12);
			printf("1. 알파벳 n개: %d점\n", timeat_score.alp_n1);

			gotoxy(30, 14);
			printf("2. 알파벳 n개: %d점\n", timeat_score.alp_n2);

			gotoxy(30, 16);
			printf("3. 알파벳 n개: %d점\n", timeat_score.alp_n3);

			gotoxy(30, 18);
            printf("4. 단어 n개: %d점\n", timeat_score.word_n1);

			gotoxy(30, 20);
            printf("5. 단어 n개: %d점\n", timeat_score.word_n2);

			gotoxy(30, 22);
            printf("6. 단어 n개: %d점\n", timeat_score.word_n3);

			gotoxy(30, 24);
			printf("이전 메뉴로 돌아가려면 엔터키를 입력하세요.. ");
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