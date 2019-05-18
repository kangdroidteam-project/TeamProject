#include "start_game_prototype.h"

void save(char* wtf);
void makeArray(int value, char* wtf);
void load();

struct test {
    int a;
    int b;
    int c;
    int d;
} TEST;

int main(void) {
    char test[30];
    TEST.a = 1;
    TEST.b = 2;
    TEST.c = 3;
    TEST.d = 0;
    makeArray(TEST.a, test);
    makeArray(TEST.b, test);
    makeArray(TEST.c, test);
    save(test);
    load();
    return 0;
}

void makeArray(int value, char* wtf) {
    char temp[20] = {0};
    int temp_counter = 0, wtf_counter = strlen(wtf);

    if (value == 0) {
        temp[temp_counter] = '0';
    } else {
        while (value != 0) {
            temp[temp_counter] = (value % 10) + '0';
            value = value / 10;
            temp_counter++;
        }
    }

    // Roll back to positive way.
    for (int i = strlen(temp); i >= 0; i--) {
        //printf("COUNTER: %d, I: %d, temp[i]: %d\n", counter, i, temp[i-1]);
        wtf[wtf_counter] = temp[i-1];
        wtf_counter++;
    }

    // Put blan on last bits
    wtf[strlen(wtf)] = ' ';
}

void save(char* wtf) {
    //int temp_counter = 0, wtf_counter = 0;
    FILE *test_file = fopen("/Users/kangdroid/Desktop/TeamProject/testcase/test_io_write.txt", "w");
    // Trail last bits
    wtf[strlen(wtf) - 1] = 0;
    fputs(wtf, test_file);
    fclose(test_file);
}

void load() {
    FILE *test_file = fopen("/Users/kangdroid/Desktop/TeamProject/testcase/test_io_write.txt", "r");
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
}