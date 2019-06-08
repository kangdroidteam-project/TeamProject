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

	game_title_headline(0, "Finding the way out!\n");

	gotoxy(0, 12);
    printf("미로판의 크기를 입력하세요.(n * n 형식, n - 정수만 입력)  ");
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

	time_start = time(0);

    while (strcmp("exit", user_input) && array_pointer[dest_y][dest_x] != 5) {
        printArray(array_pointer, how_many_col);
        // Put random numbers to int array
        for (int i = 0; i < 5; i++) {
            random_number[i] = rand() % MAX_WORD;
        }

        printf("어떤 방향으로 갈래?\n\n");
		printf("위로 한칸: \"%s\" \n", word_list[random_number[0]]);
		printf("아래로 한칸: \"%s\" \n", word_list[random_number[1]]);
		printf("오른쪽 한칸: \"%s\" \n", word_list[random_number[2]]);
		printf("왼쪽 한칸: \"%s\" \n", word_list[random_number[3]]);
		printf("\n힌트를 원하면 hint(단, 점수 차감!)\n");
		printf("단어를 입력하세요(끝내려면 exit): ");
        
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
				printf("목적지 까지는 x방향으로는 %d만큼, y방향으로는 글쎄?\n", (dest_x)-x);
			} else {
				printf("목적지 까지는 y방향으로는 %d만큼 x방향으로는 글쎄?\n", (dest_y)-y);
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
            printf("축하드립니다! 목적지에 도착하셨어요!!!\n");
			printf("소요된 시간은 총 %d분, %d초\n", (time_end - time_start)/60, (time_end - time_start) % 60);
			printf("총 점수는 %d 입니다.\n", mini_score.find_road);
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
                printf("이미 맨 꼭대기에 있어서 더이상 올라가질 못합니다.\n");
                Sleep(SLEEP_SECOND);
            } else {
                printf("위로 갑니다~!\n");
                input_array[*y][*x] = 0;
                (*y)--;
                input_array[*y][*x] = 5;
            }
            system("cls");
            break;
        case 2: //down
            if (*y == col_count- 1) {
                printf("이미 맨 아래에 있어서 더이상 내려가질 못합니다.\n");
                Sleep(SLEEP_SECOND);
            } else {
                printf("아래로 갑니다~!\n");
                input_array[*y][*x] = 0;
                (*y)++;
                input_array[*y][*x] = 5;
            }
            system("cls");
            break;
        case 3: //right
            if (*x == col_count- 1) {
                printf("이미 맨 오른쪽에 있어서 더이상 오른쪽으로 가지 못합니다.\n");
                Sleep(SLEEP_SECOND);
            } else {
                printf("오른쪽으로 갑니다~!\n");
                input_array[*y][*x] = 0;
                (*x)++;
                input_array[*y][*x] = 5;
            }
            system("cls");
            break;
        case 4: //left
            if (*x == 0) {
                printf("이미 맨 왼쪽에 있어서 더이상 왼쪽으로 가지 못합니다.\n");
                Sleep(SLEEP_SECOND);
            } else {
                printf("왼쪽으로 갑니다~!\n");
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