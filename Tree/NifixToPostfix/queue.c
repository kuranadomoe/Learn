/******************************************************************
***	File name:		queue.c										***
***	Description:	Queue ADT implementation					***
***	Author:			Star Cluster								***
***	Proprietor:		Star Cluster								***
*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


//Create a Queue
Queue queueCreate(void)
{
	return (struct QueueStruct *)malloc(sizeof(struct QueueStruct));
}


//Initialize this queue
Queue queueInit(Queue queue)
{
	queue->Capacity = 1024;
	queue->front = 0;
	queue->rear = 0;
	queue->Array = (QueueElement*)malloc(sizeof(QueueElement)*(queue->Capacity + 1));
	if (queue->Array == NULL)
	{
		fprintf(stderr, "No enough memory space...Press any key exit...");
		getchar();
		exit(1);
	}
	return queue;
}


//Queue empty
int queueEmpty(Queue queue)
{
	return queue->rear == queue->front;
}


//Queue full
int queueFull(Queue queue)
{
	return (queue->rear + 1) % queue->Capacity == queue->front;
}


//Queue length
int queueLength(Queue queue)
{
	return (queue->rear + queue->Capacity + 1) % queue->Capacity - queue->front;
}


//Queue enter
int queueEnter(Queue queue,QueueElement elem)
{
	if (queueFull(queue))
		return -1;
	queue->Array[++queue->rear] = elem;
	queue->rear %= queue->Capacity;
	return elem;
}


//Queue out
int queueOut(Queue queue)
{
	return queueEmpty(queue) ? -1 : queue->Array[queue->rear = (queue->rear + 1) % queue->Capacity];
}


//Get queue front element
int queueGetFront(Queue queue)
{
	return queueEmpty(queue) ? -1 : queue->Array[(queue->rear + 1) % queue->Capacity];
}


//Destroy queue
int queueDestroy(Queue queue)
{
	if (queue == NULL || queue->Array == NULL)
		return -1;
	free(queue->Array);
	free(queue);
	return 0;
}
