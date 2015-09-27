/*
 * ProducerConsumer.cpp
 *
 *  Created on: 16-Sep-2011
 *      Author: Alok
 */

#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <map>

#define NUM_CON     3
#define NUM_PROD    1
#define MAXNUMOFPRODUCT         20
#define MINNUMOFPRODUCT         5

int produserRunning = 0;
int consumerRunning[2] = {0};
std::map<int, int> threaidConsumeridMap;
static unsigned int counter;
int queue[MAXNUMOFPRODUCT];
int prodTStarted = 0;
int conTStarted[2] = {0};

pthread_t producerThread[NUM_PROD], consumerThread[NUM_CON];
pthread_mutex_t mutexqueue;

void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;

   printf("Hello World! It's me, thread #%ld!\n", tid);
   pthread_exit(NULL);
}

void Produce(int signal)
{
   printf("[Produce]: Received signal: %d\n",signal);
   printf("Started: Production\n");
   while (counter < MAXNUMOFPRODUCT)
   {
       produserRunning = 1;
       printf ("\t\tWaiting to acquired Lock by: %d\n",pthread_self());
       pthread_mutex_lock(&mutexqueue);
       printf ("\t\tLock accquired by: %d\n",pthread_self());
       queue[counter] = counter;
       printf("Produced: %d\n", counter);
       counter++;
       pthread_mutex_unlock(&mutexqueue);
       printf ("\t\tLock released by: %d\n",pthread_self());

       //raise the signal to start all consumer
       for (int i = 0; i < NUM_CON; i++)
       {
           if (!consumerRunning[i])
           {
               while(!conTStarted[i]) {}
               pthread_kill(consumerThread[i], SIGUSR2);
               printf("Consumer signal raised for: %d\n", i);
           }
       }
       //sleep(2);
       system("sleep 1");
   }
   produserRunning = 0;
   printf("Stoped: Production\n");
}

void Consume(int signal)
{
    printf("[Consume: %d] Received signal: %d\n", threaidConsumeridMap[(int)pthread_self()], signal);
    printf("Started: Consumption\n");
    while (counter > 0)
    {
        consumerRunning[threaidConsumeridMap[(int)pthread_self()]] = 1;
        printf ("\t\tWaiting to acquired Lock by: %d\n",pthread_self());
        pthread_mutex_lock(&mutexqueue);
        printf ("\t\tLock accquired by: %d\n",pthread_self());

        //Verify the counter again, may be it was modified by other thread (we had verified before locking)
        if (counter)
        {
        	queue[counter] = 0;
        	printf("Consumed[%d]: %d\n", threaidConsumeridMap[(int)pthread_self()], counter);
        	counter--;
        }
        else
        {
        	printf("Consumed[%d]: The conter was modified by other thread!!!\n", threaidConsumeridMap[(int)pthread_self()]);
        }
        pthread_mutex_unlock(&mutexqueue);
        printf ("\t\tLock rileased by: %d\n",pthread_self());
        if (!produserRunning && counter <= MINNUMOFPRODUCT)
        {
            //raise a signal to the producer to start production
            //raise(SIGUSR1);
            pthread_kill(producerThread[0], SIGUSR1);
            printf ("Producer siganl raised\n");
        }
       //sleep(2);
       system("sleep 6");
    }
    //consumerRunning = 0;
    consumerRunning[threaidConsumeridMap[(int)pthread_self()]] = 0;
    printf("Stoped: Consumption\n");
}

void *StartConsumption(void * con)
{
	if(!conTStarted[*((int *)con)])
	{
		printf("Starting Consumptor: %d\n",*((int*)con));
    	threaidConsumeridMap[(int)pthread_self()] = *((int*)con);
    	conTStarted[*((int *)con)] = 1;
	}
    //Consume(31);
    signal(SIGUSR2, Consume);
    while(1) {};
}

void *StartProduction(void *)
{
    Produce(30);
    prodTStarted = 1;
    signal(SIGUSR1, Produce);
    while(1) {};
}

void CreateProducer()
{
    static unsigned int producerCounter;
    printf("Creating producer thread: %d\n", producerCounter);
    int rc;
    if (producerCounter != NUM_PROD)
    {
        rc = pthread_create(&producerThread[producerCounter], NULL, StartProduction, NULL);
        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
        printf("Created producer thread: %d\n", producerCounter);
        producerCounter++;
    }
    else
    {
        printf("MAX Producer thread reached\n");
    }
}

void CreateConsumer(int i)
{
    static unsigned int consumerCounter;
    printf("Creating consumer thread: %d\n", consumerCounter);
    int rc;
    if (consumerCounter != NUM_CON)
    {
        rc = pthread_create(&consumerThread[consumerCounter], NULL, StartConsumption, (void *)&i);
        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
        printf("Created consumer thread: %d\n", consumerCounter);
        consumerCounter++;
    }
    else
    {
        printf("MAX Consumer thread reached\n");
    }
}

int main (int argc, char *argv[])
{

   /*pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   for(t=0; t<NUM_THREADS; t++){
      printf("In main: creating thread %ld\n", t);
      rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }
   */

    CreateProducer();
    for (int i = 0; i < NUM_CON; i++)
    {
    	system("sleep 1");
    	CreateConsumer(i);
    }

    pthread_join(producerThread[0], NULL);
    for (int i = 0; i < NUM_CON; i++)
        pthread_join(consumerThread[i], NULL);

    /* Last thing that main() should do */
    pthread_exit(NULL);
}
