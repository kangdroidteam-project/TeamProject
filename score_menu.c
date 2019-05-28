#include "game.h"

struct typing_score type_score;
struct minigame_score mini_score;
struct timeattack_score timeat_score;

int showMainScoreMenu() {
    int user_input_typing, dummy;

    printf("1. 타자 연습\n");
    printf("2. 미니게임\n");
    printf("3. 타임어택\n");
    printf("0. 전 메뉴로 돌아가기\n");
    printf("원하는 단계를 입력해주세요! ");
    scanf("%d", &user_input_typing);

    clearScreen();
    switch (user_input_typing) {
        case 1:
            // Typing Score
            printf("1. 초급: %d점\n", type_score.easy);
            printf("2. 중급: %d점\n", type_score.moderate);
            printf("3. 고급: %d점\n", type_score.hard);
            printf("4. 상급: %d점\n", type_score.extreme);
            printf("이전 메뉴로 돌아가려면 1을 입력하세요. ");
            scanf("%d", &dummy);
        return 0;
        case 2:
            // Minigame Score
            printf("1. 구구단: %d점\n", mini_score.timecalc);
            printf("2. 길찾기: %d점\n", mini_score.find_road);
            printf("3. 컴퓨터와의 대결: %d점\n", mini_score.fight_computer);
            printf("4. 단어 기억력: %d점\n", mini_score.mem_word);
            printf("이전 메뉴로 돌아가려면 1을 입력하세요. ");
            scanf("%d", &dummy);
        return 0;
        case 3:
            // Word Time-Attack Score
            printf("1. 단어 n개: %d점\n", timeat_score.word_n1);
            printf("2. 단어 n개: %d점\n", timeat_score.word_n2);
            printf("3. 단어 n개: %d점\n", timeat_score.word_n3);
            printf("이전 메뉴로 돌아가려면 1을 입력하세요. ");
            scanf("%d", &dummy);
        return 0;
        case 0:
            // Return to last menu
        return 0;
        default:
            // Get another input;
        return 10;
    }
}