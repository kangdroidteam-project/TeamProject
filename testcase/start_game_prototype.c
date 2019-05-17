#include "start_game_prototype.h"

struct scan_save_structure {
    int scan_return;
    char array_input[60];
} scanStruct;

int main(void) {
    //Change Seed based on time
    srand((unsigned)time(NULL));
    startGame(word);
    return 0;
}

void startGame(char word_list[][30]) {
    int which_one; // Which one are you going to show?
    int result_test = 0, counter = 0;
    pthread_t timer_test, scan_test; // Thread function

    for (int i = 0; i < 5; i++) {
        counter = 0;
        result_test = 0;
        scanStruct.scan_return = 0;
        //Select which word computer is going to show 2 user.
        which_one = rand() % MAX_WORD;

        // Timer starts
        pthread_create(&timer_test, NULL, retTime, (void*)&result_test);

        // scanf starts
        pthread_create(&scan_test, NULL, getValue, (void*)&scanStruct);

        while (1) {
            if (counter == 0) {
                //Show word that computer chose, and get input from user.
                printf("%s\n", word_list[which_one]);
            }

            if (result_test == TIME_LIMIT_LOOP_COUNT) {
                //TIMEOUT
                // cancel scanf thread
                pthread_cancel(scan_test);
                break;
            }

            if (scanStruct.scan_return == 1) {
                // Successfully entered scan
                // Force finish timer thread using some tricks
                result_test = 60;
                
                // Let thread finishes its work.
                pthread_join(timer_test, NULL);
                break;
            }
            counter++;
        }

        //Check whether user entered same thing with computer.
        if (!strcmp(word_list[which_one], scanStruct.array_input)) {
            printf("You are correct!\n");
        } else {
            printf("You are wrong!\n");
        }
        printf("\n");
    }
}

void *retTime(void* result_counter) {
    for ((*((int*)result_counter)) = 0; (*((int*)result_counter)) < TIME_LIMIT_LOOP_COUNT; (*((int*)result_counter))++) {
        usleep(100000);
    }
    return NULL;
}

void clearScreen() {
    #if defined(_WIN32) || defined(__CYGWIN__) || defined(_WIN64)
    // Clear Console for Windows
    system("cls");
    #else
    system("clear && printf '\e[3J'");
    #endif
}

void *getValue(void* value) {
    struct scan_save_structure *scan_structure_ptr = value;

    if (fgets(scan_structure_ptr -> array_input, sizeof(scan_structure_ptr -> array_input), stdin) != NULL) {
        scan_structure_ptr -> array_input[strlen(scan_structure_ptr -> array_input) - 1] = '\0';
        scan_structure_ptr -> scan_return = 1;
    }

    return NULL;
}