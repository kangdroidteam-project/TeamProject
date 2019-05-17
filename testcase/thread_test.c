#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void *retTime(void* result_lol);
void *getValue(void* value);

struct test {
    int scan_return;
    char array_input[50];
};

int main(void) {
    char array[30];
    int result, result_test = 0, counter = 0;
    pthread_t timer_test, scan_test;
    struct test test_struct;

    test_struct.scan_return = 0;

    // scanf by thread 1(assigned)
    pthread_create(&scan_test, NULL, getValue, (void*)&test_struct);

    // Create thread for timer by thread 2(assigned)
    pthread_create(&timer_test, NULL, retTime, (void*)&result_test);

    while (1) {
        if (counter == 0) {
            printf("TEST\n");
        }

        if (result_test == 5) {
            break;
        }
        if (test_struct.scan_return == 1) {
            // Successfully entered scan
            // Force finish timer thread using some tricks
            result_test = 6;
            break;
        }
        counter++;
    }

    //pthread_join(timer_test, (void*)&result); // wait for timer finish? -- is it really needed?
    return 0;
}

void *retTime(void* result_lol) {
    for (int i = 0; i < 5; i++) {
        sleep(1);
        (*((int*)result_lol))++;
    }
    return NULL;
}

void *getValue(void* value) {
    struct test *test_st_th = value;
    test_st_th -> scan_return = scanf("%s", test_st_th -> array_input);
    return NULL;
}