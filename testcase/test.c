#include "start_game_prototype.h"

// How to determine word length?

int main(void) {
    for (int i = 0; i < MAX_WORD; i++) {
        if (strlen(word[i]) > 12) {
            printf("%s\n", word[i]);
        }
    }
    return 0;
}