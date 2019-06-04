#include "game.h"

struct typing_score type_score;

int showTypingMenu() {
    int user_input_typing;
	char input[5];

    printf("1. �ʱ�\n");
    printf("2. �߱�\n");
    printf("3. ���\n");
    printf("4. �ֻ��\n");
	printf("5. �ܰ� ����\n");
	printf("6. ��Ģ(���� ���� ����)\n");
	printf("7. �����غ���\n");
    printf("0. �� �޴��� ���ư���\n");
    printf("���ϴ� �ܰ踦 �Է����ּ���! ");
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
				printf("��� �ܰ踦 Ŭ���� �Ͻ� �е鸸 �ֻ�� �ܰ踦 �÷��� �� �� �ֽ��ϴ�!\n");
				Sleep(3000);
			}
			break;
		case 5:
			// Explanation of Steps, Level
			printf("�����ܰ�� ����ڰ� �ϳ��� ��Ÿ���� �� 5������ �־��� ���ڸ� �Է��ؾ� �Ѵ�,\n");
			printf("easy mode�� ����ڰ� �ϳ��� ��Ÿ���� ��20������ �־��� ���ڸ� �Է��ؾ� �Ѵ�,\n");
			printf("����Ű�� ������ �� �޴��� ���ư��ϴ�..");
			fgets(input, sizeof(input), stdin);
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			//Sleep(5000);
			break;
		case 6:
			// Explanation of Rule with Score agenda.
			printf("������ ���ڸ� ���� ��쿡 1���� ��´�.\n");
			printf("����Ű�� ������ �� �޴��� ���ư��ϴ�..");
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