#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <semaphore.h>

#define No_Threads 2

pthread_mutex_t mutex;

void* routine(void * arg){
	sleep(100);
	pthread_mutex_lock(&mutex);
	printf("\nThread %d Executed",*(int*)arg);
	pthread_mutex_unlock(&mutex);
	pthread_exit(arg);
}

int main(int argc, char const *argv[])
{
	pthread_t threads[No_Threads];

	pthread_mutex_init(&mutex,NULL);

	printf("\n %d",getpid());
	for (int i = 0; i < No_Threads; ++i)
	{
		int* a = malloc(sizeof(int));*a = i+1;
		if (pthread_create(threads+i,NULL,&routine,(void*) a) !=0)
		{
			printf("\nThread %d can't be created\n",i);return 1;
		}
		printf("\nThread %d started",i);
	}

	for (int i = 0; i < No_Threads; ++i)
	{
		int* res;	
		if (pthread_join(threads[i],(void**) &res)!=0)
		{
			printf("\nThread %d can't be joined\n",i);return 2;
		}	
		printf("\nThread %d finished",*res);
	}

	pthread_mutex_destroy(&mutex);


	printf("\nProcess Ended\n");
	return 0;
}

