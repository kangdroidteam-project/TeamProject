#include "start_game_prototype.h"

void printArray(int** input_array, int col_count);
void resetArray(int** input_array, int col_count);

int main(void) {
    int how_many_col;
    int random_number[5] = {0,};
    int** array_pointer = NULL;
    char user_input[50];

    srand((unsigned)time(NULL));

    printf("How many rows do you want to use?  ");
    scanf("%d", &how_many_col);
    while (getchar() != '\n');

    // 2-dimension array by dynamic memory allocation
    array_pointer = (int**)malloc(sizeof(int*) * how_many_col);
    for (int i = 0; i < how_many_col; i++) {
        array_pointer[i] = (int*)malloc(sizeof(int) * how_many_col);
    }

    // Array by dynamic memory allocation needs to be resetted on first time.
    resetArray(array_pointer, how_many_col);

    // First location = 0, 0, 5 is the where game character located in.
    array_pointer[0][0] = 5;

    // Put random numbers to int array
    for (int i = 0; i < 5; i++) {
        random_number[i] = rand() % 9896;
    }

    printArray(array_pointer, how_many_col);
    printf("Where do you want to go?\n");
    printf("Enter \"%s\" to go up, \"%s\" to go down, \"%s\" to go right, \"%s\" to go left.\n", word[random_number[0]], word[random_number[1]], word[random_number[2]], word[random_number[3]]);
    
    fgets(user_input, sizeof(user_input), stdin);
    user_input[strlen(user_input) - 1] = 0;

    if (!strcmp(word[random_number[0]], user_input)) {
        printf("Move up!\n");
    } else if (!strcmp(word[random_number[1]], user_input)) {

    } else if (!strcmp(word[random_number[2]], user_input)) {

    } else if (!strcmp(word[random_number[3]], user_input)) {

    }

    // Leaks of memory when we don't free it. - AT THE END OF FUNCTION
    for (int i = 0; i < how_many_col; i++) {
        free(array_pointer[i]);
    }
    free(array_pointer);

    return 0;
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