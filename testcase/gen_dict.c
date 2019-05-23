#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generateDict(char word[][30]);
int main(void) {
    char long_word[2244][30] = {""};
    //Change Seed based on time
    srand((unsigned)time(NULL));
    generateDict(long_word);
    printf("char long_word[2244][10] = {\n");
    for (int i = 0; i < 2243; i++) {
        printf("    {\"%s\"},\n", long_word[i]);
    }
    printf("};");

    return 0;
}

// TODO: EXCEPTION MAINTANCE
void generateDict(char word[][30]) {
    char ch;
    int lines = 0, x = 0;
    FILE * fp = fopen("/Users/kangdroid/Desktop/google-10000-english/google-10000-english-usa-no-swears-long.txt", "r");
    while (!feof(fp)) {
        ch = fgetc(fp);
        if (ch == '\n') {
            lines++;
            x = 0;
        } else {
            word[lines][x] = ch;
            x++;
        }
    }
    if (word[lines][strlen(word[lines]) - 1] == -1) {
        word[lines][strlen(word[lines]) - 1] = '\0';
    }
    fclose(fp);
}