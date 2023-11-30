#include<stdio.h>
#include<pthread.h>
void* thread(void* arg)
{
	printf("This is a thread.\n");
	return NULL;
}
int main()
{
	pthread_t tid;
	if(pthread_create(&tid,NULL,thread,NULL)!=0)
	{
		fprintf(stderr,"Error creating thread.\n");
		return 1;
	}
	printf("This is the main thread.\n");
	pthread_join(tid,NULL);
	return 0;
}
