#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    printf("Thread is running\n");
    printf("Hello from the thread\n");
    return NULL;
}
int main()
{
    pthread_t thread_id;
    printf("Main program started\n");
    pthread_create(&thread_id, NULL,
    thread_function, NULL);
    pthread_join(thread_id, NULL);
    printf("Thread execution completed\n");

    return 0;
}
