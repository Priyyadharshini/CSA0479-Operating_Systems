#include <stdio.h>
#include <pthread.h>
void* threadFunction(void* arg)
{
    int threadNumber=*(int*)arg;
    printf("Thread %d is running.\n",threadNumber);
    for(int i=0;i<5;++i)
	{
        printf("Thread %d is working...\n",threadNumber);
        exit(1);
    }
    printf("Thread %d is exiting.\n",threadNumber);
    pthread_exit(NULL);
}
int main()
{
    pthread_t thread1,thread2;
    int threadNumber1=1,threadNumber2=2;
    pthread_create(&thread1, NULL, threadFunction, (void*)&threadNumber1);
    pthread_create(&thread2, NULL, threadFunction, (void*)&threadNumber2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    if (pthread_equal(thread1, thread2))
	{
        printf("Threads are equal.\n");
    }
	else
	{
        printf("Threads are not equal.\n");
    }
    printf("Main thread is exiting.\n");
    pthread_exit(NULL);
}
