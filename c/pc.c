#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<time.h>

sem_t mutex,empty,full;
int buffer[5],get = 0,item,gitem,put = 0,pro[10],con[10];
void *producer(void *arg)
{
    do
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[put%5] = item;
        item++;
        printf("Producer %d produced %d ,item buffered[%d]:%d \n",(*(int *)arg),buffer[put%5],put%5,item); 
        put ++;
        sem_post(&mutex);
        sem_post(&full);
        sleep(3);

    } while (1);
    
}
void *consumer(void *arg)
{
    do
    {
        sem_wait(&full);
        sem_wait(&mutex);
        gitem = buffer[get%5];  
        printf("Consumer %d Consumes %d ,item buffered[%d]:%d \n",(*(int *)arg),gitem,get%5,gitem); 
        get ++;
        sem_post(&mutex);
        sem_post(&empty);
        sleep(2);

    } while (1);
    
}

void main()
{  
    int p,c,j,k;
    pthread_t a[10],b[10];
    sem_init(&mutex,0,1);
    sem_init(&full,0,0);
    sem_init(&empty,0,5);
    printf("Enter number of process");
    scanf("%d",&p);
    printf("\n Enter number of consumers:");
    scanf("%d",&c);
    for(int j = 0;j<p;j++)
    {
        pro[j] = j;
        pthread_create(&a[j],NULL,producer,&pro[j]);
    }
    for(k=0;k<c;k++)
    {
        con[k] = k;
        pthread_create(&b[k],NULL,consumer,&con[k]);
        
    }
    for(j = 0;j<p;j++)
    {
        pthread_join(a[j],NULL); // used for joining producer and consumer or else it exits from main much faster
    }
    for(k=0;k<c;k++)
    {
        pthread_join(b[k],NULL);
    }
}
