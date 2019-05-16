#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void *retTime(void* result_lol);

int main(void) {
    int result, result_test = 0;;
    pthread_t timer_test;
    pthread_create(&timer_test, NULL, retTime, (void*)&result_test);
    while (result_test != 5) {
        printf("a\n");
    }
    pthread_join(timer_test, (void*)&result);
    //printf("%d\n", result);
    return 0;
}

void *retTime(void* result_lol) {
    for (int i = 0; i < 5; i++) {
        sleep(1);
        (*((int*)result_lol))++;
    }
}