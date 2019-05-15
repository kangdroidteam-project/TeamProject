#include "game.h"

void mini_maze() {
    int how_many_col, x = 0, y = 0;
    int random_number[5] = {0,};
    int** array_pointer = NULL;
    char user_input[50];

    srand((unsigned)time(NULL));

    clearScreen();

    printf("How many rows do you want to use?  ");
    scanf("%d", &how_many_col);
    while (getchar() != '\n');

    clearScreen();

    // 2-dimension array by dynamic memory allocation
    array_pointer = (int**)malloc(sizeof(int*) * how_many_col);
    for (int i = 0; i < how_many_col; i++) {
        array_pointer[i] = (int*)malloc(sizeof(int) * how_many_col);
    }

    // Array by dynamic memory allocation needs to be resetted on first time.
    resetArray(array_pointer, how_many_col);

    // First location = 0, 0, 5 is the where game character located in.
    array_pointer[0][0] = 5;

    while (strcmp("exit", user_input) && array_pointer[how_many_col-1][how_many_col-1] != 5) {
        printArray(array_pointer, how_many_col);
        // Put random numbers to int array
        for (int i = 0; i < 5; i++) {
            random_number[i] = rand() % MAX_WORD;
        }

        printf("Where do you want to go?\n");
        printf("Enter \"%s\" to go up, \"%s\" to go down, \"%s\" to go right, \"%s\" to go left, exit to end this game(not saved!).\n", word_list[random_number[0]], word_list[random_number[1]], word_list[random_number[2]], word_list[random_number[3]]);
    
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
        } else {
            clearScreen();
        }
        
        if (array_pointer[how_many_col-1][how_many_col-1] == 5) {
            printf("Congratulations! You ended the maze!\n");
            sleepfor(3);
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
                printf("Cannot move up. We are on the top!\n");
                sleepfor(SLEEP_SECOND);
            } else {
                printf("Move up!\n");
                input_array[*y][*x] = 0;
                (*y)--;
                input_array[*y][*x] = 5;
            }
            clearScreen();
            break;
        case 2: //down
            if (*y == col_count- 1) {
                printf("Cannot move down. We are on the low-level!\n");
                sleepfor(SLEEP_SECOND);
            } else {
                printf("Move down!\n");
                input_array[*y][*x] = 0;
                (*y)++;
                input_array[*y][*x] = 5;
            }
            clearScreen();
            break;
        case 3: //right
            if (*x == col_count- 1) {
                printf("Cannot move right. We are on the most right!\n");
                sleepfor(SLEEP_SECOND);
            } else {
                printf("Move right!\n");
                input_array[*y][*x] = 0;
                (*x)++;
                input_array[*y][*x] = 5;
            }
            clearScreen();
            break;
        case 4: //left
            if (*x == 0) {
                printf("Cannot move left. We are on the most left!\n");
                sleepfor(SLEEP_SECOND);
            } else {
                printf("Move left!\n");
                input_array[*y][*x] = 0;
                (*x)--;
                input_array[*y][*x] = 5;
            }
            clearScreen();
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

void sleepfor(int sec) {
    #if defined(_WIN32) || defined(__CYGWIN__) || defined(_WIN64)
    Sleep(sec * 1000);
    #else
    sleep(sec);
    #endif
}