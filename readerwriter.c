#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
sem_t mutex,wrt;
pthread_t tid;
int sharedvar=99;
pthread_t writers[5],readers[5];
int readercount=0;

void reader()
{
sem_wait(&mutex);
readercount++;
if(readercount==1)
sem_wait(&wrt);
sem_post(&mutex);
printf("\n %d Reader is reading sharedvar= %d",readercount,sharedvar);
printf("\n Reader is done");
sem_wait(&mutex);
readercount--;
if(readercount==0);
sem_post(&wrt);
sem_post(&mutex);
}
void writer()
{
printf("\n Writer is trying to enter");
sem_wait(&wrt);
printf("\n Writer has entered CS");
sharedvar++;
printf("\n Writer changed the value of sharedvar to %d",sharedvar);
sem_post(&wrt);
printf("\n Writer is out of CS");
}
int main()
{
int n2,i;
printf("Enter the numbers of readers and writers:");
scanf("%d",&n2);
sem_init(&mutex,0,1);
sem_init(&wrt,0,1);
for(i=0;i<n2;i++)
{
pthread_create(&writers[i],NULL,(void*)writer,NULL);
pthread_create(&readers[i],NULL,(void*)reader,NULL);
}
for(i=0;i<n2;i++)
{
pthread_join(writers[i],NULL);
pthread_join(readers[i],NULL);
}
}	
