#include "game.h"

struct minigame_score mini_score;

void mini_maze() {
    int how_many_col, x = 0, y = 0;
    int random_number[5] = {0,};
	int dest_x, dest_y, time_start, time_end, hint_count = 0;
    int** array_pointer = NULL;
    char user_input[50];

    srand((unsigned)time(NULL));

    system("cls");

    printf("�̷����� ũ�⸦ �Է��ϼ���.(n * n ����, n - ������ �Է�)  ");
    scanf("%d", &how_many_col);
    while (getchar() != '\n');
	dest_x = rand() % (how_many_col - 1) + 1;
	dest_y = rand() % (how_many_col - 1) + 1;

    system("cls");

    // 2-dimension array by dynamic memory allocation
    array_pointer = (int**)malloc(sizeof(int*) * how_many_col);
    for (int i = 0; i < how_many_col; i++) {
        array_pointer[i] = (int*)malloc(sizeof(int) * how_many_col);
    }

    // Array by dynamic memory allocation needs to be resetted on first time.
    resetArray(array_pointer, how_many_col);

    // First location = 0, 0, 5 is the where game character located in.
    array_pointer[0][0] = 5;

	// And Destination needs to be highlighted as 7

	time_start = time(0);

    while (strcmp("exit", user_input) && array_pointer[dest_y][dest_x] != 5) {
        printArray(array_pointer, how_many_col);
        // Put random numbers to int array
        for (int i = 0; i < 5; i++) {
            random_number[i] = rand() % MAX_WORD;
        }

        printf("� �������� ����?\n");
        printf("\"%s\" �� �Է��ϸ� ���� ��ĭ, \"%s\" �� �Է��ϸ� �Ʒ��� ��ĭ, \"%s\" �� �Է��ϸ� ���������� ��ĭ, \"%s\" �� �Է��ϸ� �������� ��ĭ, exit�� �Է��ϸ� �������� �ʰ� ���� ������.\nhint�� �Է��� ���� ���� �� ��Ʈ ���\n", word_list[random_number[0]], word_list[random_number[1]], word_list[random_number[2]], word_list[random_number[3]]);
        
        fgets(user_input, sizeof(user_input), stdin);
        user_input[strlen(user_input) - 1] = 0;

        if (!strcmp(word_list[random_number[0]], user_input)) {
            moveLogic(array_pointer, 1, how_many_col, &x, &y);
        } else if (!strcmp(word_list[random_number[1]], user_input)) {
            moveLogic(array_pointer, 2, how_many_col, &x, &y);
        } else if (!strcmp(word_list[random_number[2]], user_input)) {
            moveLogic(array_pointer, 3, how_many_col, &x, &y);
		} else if (!strcmp(word_list[random_number[3]], user_input)) {
			moveLogic(array_pointer, 4, how_many_col, &x, &y);
		} else if (!strcmp("hint", user_input)) {
			if (rand() % 2) {
				printf("������ ������ x�������δ� %d��ŭ, y�������δ� �۽�?\n", (dest_x)-x);
			} else {
				printf("������ ������ y�������δ� %d��ŭ x�������δ� �۽�?\n", (dest_y)-y);
			}
			Sleep(1500);
			hint_count++;
			system("cls");
        } else {
            system("cls");
        }

		time_end = time(0);
        
        if (array_pointer[dest_y][dest_x] == 5) {
			mini_score.find_road = ((time_end - time_start) - (hint_count * 10)) / how_many_col;
            printf("���ϵ帳�ϴ�! �������� �����ϼ̾��!!!\n");
			printf("�ҿ�� �ð��� �� %d��, %d��\n", (time_end - time_start)/60, (time_end - time_start) % 60);
			printf("�� ������ %d �Դϴ�.\n", mini_score.find_road);
            Sleep(3000);
        }
    }

    // Leaks of memory when we don't free it. - AT THE END OF FUNCTION
    for (int i = 0; i < how_many_col; i++) {
        free(array_pointer[i]);
    }
    free(array_pointer);
}

void moveLogic(int** input_array, int what, int col_count, int* x, int* y) {
    switch (what) {
        case 1: //up
            if (*y == 0) {
                printf("�̹� �� ����⿡ �־ ���̻� �ö��� ���մϴ�.\n");
                Sleep(SLEEP_SECOND);
            } else {
                printf("���� ���ϴ�~!\n");
                input_array[*y][*x] = 0;
                (*y)--;
                input_array[*y][*x] = 5;
            }
            system("cls");
            break;
        case 2: //down
            if (*y == col_count- 1) {
                printf("�̹� �� �Ʒ��� �־ ���̻� �������� ���մϴ�.\n");
                Sleep(SLEEP_SECOND);
            } else {
                printf("�Ʒ��� ���ϴ�~!\n");
                input_array[*y][*x] = 0;
                (*y)++;
                input_array[*y][*x] = 5;
            }
            system("cls");
            break;
        case 3: //right
            if (*x == col_count- 1) {
                printf("�̹� �� �����ʿ� �־ ���̻� ���������� ���� ���մϴ�.\n");
                Sleep(SLEEP_SECOND);
            } else {
                printf("���������� ���ϴ�~!\n");
                input_array[*y][*x] = 0;
                (*x)++;
                input_array[*y][*x] = 5;
            }
            system("cls");
            break;
        case 4: //left
            if (*x == 0) {
                printf("�̹� �� ���ʿ� �־ ���̻� �������� ���� ���մϴ�.\n");
                Sleep(SLEEP_SECOND);
            } else {
                printf("�������� ���ϴ�~!\n");
                input_array[*y][*x] = 0;
                (*x)--;
                input_array[*y][*x] = 5;
            }
            system("cls");
            break;
    }
}

void resetArray(int** input_array, int col_count) {
    for (int i = 0; i < col_count; i++) {
        for (int a = 0; a < col_count; a++) {
            input_array[i][a] = 0;
        }
    }
}

void printArray(int** input_array, int col_count) {
    for (int i = 0; i < col_count; i++) {
        for (int a = 0; a < col_count; a++) {
            printf("%d ", input_array[i][a]);
        }
        printf("\n");
    }
}