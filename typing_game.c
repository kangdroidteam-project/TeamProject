#include "game.h"

struct typing_score type_score;

int showTypingMenu() {
    int user_input_typing;
	char input[5];

    printf("1. 초급\n");
    printf("2. 중급\n");
    printf("3. 고급\n");
    printf("4. 최상급\n");
	printf("5. 단계 설명\n");
	printf("6. 규칙(점수 산정 기준)\n");
	printf("7. 연습해보기\n");
    printf("0. 전 메뉴로 돌아가기\n");
    printf("원하는 단계를 입력해주세요! ");
    scanf("%d", &user_input_typing);
	while (getchar() != '\n');

    switch (user_input_typing) {
        case 1:
            // Beginner
			word_game(1);
			break;
        case 2:
            // Intermediates
			word_game(2);
			break;
        case 3:
            // Expert
			word_game(3);
			break;
        case 4:
            // Extremely-hard
			if (type_score.extreme_unlock == 4) {
				word_game(4);
			}
			else {
				printf("고급 단계를 클리어 하신 분들만 최상급 단계를 플레이 할 수 있습니다!\n");
				Sleep(3000);
			}
			break;
		case 5:
			// Explanation of Steps, Level
			printf("연습단계는 영어문자가 하나씩 나타나고 총 5문제의 주어진 문자를 입력해야 한다,\n");
			printf("easy mode는 영어문자가 하나씩 나타나고 총20문제의 주어진 문자를 입력해야 한다,\n");
			printf("엔터키를 누르면 전 메뉴로 돌아갑니다..");
			fgets(input, sizeof(input), stdin);
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			//Sleep(5000);
			break;
		case 6:
			// Explanation of Rule with Score agenda.
			printf("점수는 문자를 맞은 경우에 1점씩 얻는다.\n");
			printf("엔터키를 누르면 전 메뉴로 돌아갑니다..");
			fgets(input, sizeof(input), stdin);
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			//Sleep(5000);
			break;
		case 7:
			// Practice mode(beginner)
			word_game(0);
			break;
        case 0:
            // Return to last menu
        return 0;
        default:
            // Get another input;
        return 10;
    }
}