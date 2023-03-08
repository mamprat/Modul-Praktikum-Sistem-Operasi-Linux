#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int counter = 0;
pthread_t tid[4];
pthread_mutex_t lock;

void* doSomeThing(void *arg) {

pthread_mutex_lock(&lock);
        printf("\n Thread %d started, please wait...\n", counter);
    counter++;
 
    unsigned long i = 0;
    for(i=0; i<(0xFFFFFFFF);i++);
        printf("\n Thread %d finished\n", counter);
 
 pthread_mutex_unlock(&lock);
 return NULL;
}

int main(void){
    int i = 0;
    int err;
    if (pthread_mutex_init(&lock, NULL) != 0){
        printf("\n mutex init failed\n");
    //return 1;
    }
 
    while(i < 4){
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);

    if (err != 0)
        printf("\ncan't create thread :[%s]", strerror(err));
    i++;
    }
    while(i < 3){
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);

    if (err != 0)
        printf("\ncan't create thread :[%s]", strerror(err));
    i++;
    }

    while(i < 2){
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);

    if (err != 0)
        printf("\ncan't create thread :[%s]", strerror(err));
    i++;
    }

    while(i < 1){
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);

    if (err != 0)
        printf("\ncan't create thread :[%s]", strerror(err));
    i++;
    }

    while(i < 0){
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);

    if (err != 0)
        printf("\ncan't create thread :[%s]", strerror(err));
    i++;
    }
 
 pthread_join(tid[0], NULL);
 pthread_join(tid[1], NULL);
 pthread_join(tid[2], NULL);
 pthread_join(tid[3], NULL);
 pthread_join(tid[4], NULL);
 pthread_mutex_destroy(&lock);
 return 0;
}
