#include <stdio.h>

int main(void) {
    char test[50];

    for (int i = 0; i < 5; i++) {
        scanf("%s", test);
        printf("%s", test);
    }
    return 0;
}