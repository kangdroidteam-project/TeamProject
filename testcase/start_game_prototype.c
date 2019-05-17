#include "start_game_prototype.h"
#include <pthread.h>

#define TIME_LIMIT 5

void *retTime(void* result_lol);
void clearScreen();
void *getValue(void* value);

struct test {
    int scan_return;
    char array_input[50];
} test_struct;

int main(void) {
    //Change Seed based on time
    srand((unsigned)time(NULL));
    startGame(word);
    return 0;
}

void startGame(char word_list[][30]) {
    char user_input[60];
    int which_one, check; // Which one are you going to show?
    int result, result_test = 0, counter = 0;
    pthread_t timer_test, scan_test;

    for (int i = 0; i < 5; i++) {
        counter = 0;
        result_test = 0;
        test_struct.scan_return = 0;
        //Select which word computer is going to show 2 user.
        which_one = rand() % 9896;

        // Timer starts
        pthread_create(&timer_test, NULL, retTime, (void*)&result_test);

        // scanf starts
        pthread_create(&scan_test, NULL, getValue, (void*)&test_struct);

        while (1) {
            if (counter == 0) {
                //Show word that computer chose, and get input from user.
                printf("%s\n", word_list[which_one]);
            }

            if (result_test == 50) {
                //TIMEOUT
                // cancel scanf thread
                pthread_cancel(scan_test);
                break;
            }

            if (test_struct.scan_return == 1) {
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
        if (!strcmp(word_list[which_one], user_input)) {
            printf("You are correct!\n");
        } else {
            printf("You are wrong!\n");
        }
        printf("\n");
    }
}

void *retTime(void* result_lol) {
    struct timespec time_value;
    for ((*((int*)result_lol)) = 0; (*((int*)result_lol)) < 50; (*((int*)result_lol))++) {
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
    struct test *test_st_th = value;

    if (fgets(test_st_th -> array_input, sizeof(test_st_th -> array_input), stdin) != NULL) {
        test_st_th -> array_input[strlen(test_st_th -> array_input) - 1] = '\0';
        test_st_th -> scan_return = 1;
    }

    return NULL;
}