/******************************************************************
***	File name:		queue.c										***
***	Description:	Queue ADT Statement							***
***	Author:			Star Cluster								***
***	Proprietor:		Star Cluster								***
*******************************************************************/
#pragma once
#ifndef QUEUE_H
#define QUEUE_H


typedef char QueueElement;
typedef struct QueueStruct
{
	int Capacity;//capacity of queue
	int front;//front of queue
	int rear;//rear of queue
	QueueElement *Array;//stack array
}*Queue;


Queue queueCreate(void);//Create a Queue
Queue queueInit(Queue queue);//Initialize this queue
int queueEmpty(Queue queue);//Queue empty
int queueFull(Queue queue);//Queue full
int queueLength(Queue queue);//Queue length
int queueEnter(Queue queue, QueueElement elem);//Queue enter
int queueOut(Queue queue);//Queue out
int queueGetFront(Queue queue);//Get queue front element





#endif
