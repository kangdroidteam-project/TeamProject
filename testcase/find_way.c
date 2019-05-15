#include "start_game_prototype.h"

void printArray(int** input_array, int col_count);
void resetArray(int** input_array, int col_count);

int main(void) {
    int how_many_col;
    int** array_pointer = NULL;

    printf("How many rows do you want to use?  ");
    scanf("%d", &how_many_col);

    // 2차원배열 동적 할당
    array_pointer = (int**)malloc(sizeof(int*) * how_many_col);
    for (int i = 0; i < how_many_col; i++) {
        array_pointer[i] = (int*)malloc(sizeof(int) * how_many_col);
    }

    // 동적 할당은 초기화 따로 해주어야됨
    resetArray(array_pointer, how_many_col);

    // First location = 0, 0, 5 is the where game character located in.
    array_pointer[0][0] = 5;

    printArray(array_pointer, how_many_col);
    printf("Where do you want to go?\n");
    printf("%s to go up, %s to go down, %s to go right, %s to go left.\n", );

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