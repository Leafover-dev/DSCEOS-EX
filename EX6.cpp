#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;
void *process(void *arg)
{
    int id = *(int *)arg;
    sem_wait(&mutex);	// Enter critical section
    printf("Process %d entered Critical Section\n", id);
    sleep(2);
    printf("Process %d leaving Critical Section\n", id);
    sem_post(&mutex);	// Exit critical section
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;
    sem_init(&mutex, 0, 1);
    pthread_create(&t1, NULL, process, &id1);
    pthread_create(&t2, NULL, process, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&mutex);
    return 0;
}
