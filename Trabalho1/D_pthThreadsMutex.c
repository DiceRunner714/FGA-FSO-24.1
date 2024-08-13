#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int count;
pthread_mutex_t mut;
struct thread_arg {
    int vezes
};

void *thread_func(void *arg){
    struct thread_arg *args = (struct thread_arg *)arg;

    for(int i = 0; i < args->vezes; i++){
        int id = __sync_fetch_and_add(&count, 1);
        work(id);
    }
    return NULL;
}
