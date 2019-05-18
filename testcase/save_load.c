#include "start_game_prototype.h"

int main(void) {
    FILE *test_file = fopen("/Users/kangdroid/Desktop/TeamProject/testcase/test_io.txt", "r");
    char test[40];

    fgets(test, sizeof(test), test_file);

    printf("%s\n", test);
    printf("%d\n", strlen(test));

    fclose(test_file);
    return 0;
}