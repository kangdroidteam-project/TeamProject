#include "start_game_prototype.h"

int main(void) {
    FILE *test_file = fopen("/Users/kangdroid/Desktop/TeamProject/testcase/test_io.txt", "r");
    char test[40];
    int score_saved[40] = {0,}, counter = 0, res = 0, intcounter = 0;

    fgets(test, sizeof(test), test_file);

    while (counter != strlen(test)) {
        if (test[counter] == ' ') {
            score_saved[intcounter] = res;
            res = 0;
            counter++;
            intcounter++;
            continue;
        }
        res = res * 10 + (test[counter] - '0');
        counter++;
    }

    //last bit calculated
    score_saved[intcounter] = res;
    for (int i = 0; i < intcounter + 1; i++) {
        printf("array: %d\n", score_saved[i]);
    }
    fclose(test_file);
    return 0;
}