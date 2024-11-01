#ifndef QUEUE_FILE_H
#define QUEUE_FILE_H

struct NodeQ
{
    double data;
    struct NodeQ *next;
};

typedef struct Queue
{
    unsigned capacity, size;
    struct NodeQ *front;
    struct NodeQ *rear;
} queue;

queue* createQueue(unsigned capacity, int *error);     //Creates an empty queue with given capacity. Returns NULL if error occurs
int isQueueFull(queue *q, int *error);      //Checks if queue is full. Outputs 1 - if full, 0 - if not full or if error occurs
int isQueueEmpty(queue *q, int *error);     //Checks if queue is empty. Outputs 1 - if empty, 0 - if not empty or if error occurs
void enqueue(queue *q, double value, int *error);     //Puts given value to a queue
double dequeue(queue *q, int *error);     //Removes first element from queue and outputs it. If error occurs then outputs 0
double getQueueFirstElement(queue *q, int *error);     //Outputs first element in queue without removing it. If error occurs then outputs 0
int getQueueSize(queue *q, int *error);    //Outputs queue's current size. If error occurs then outputs 0
int getQueueCapacity(queue *q, int *error);    //Outputs queue's capacity. If error occurs then outputs 0
void destroyQueue(queue *q, int *error);     //Frees memory of a given queue and all elements in it and makes queue to NULL

/*
Error codes:
0 - no error
1 - error with memory allocation
2 - queue is uninitialized (is NULL)
3 - queue is full
4 - queue is empty
*/

#endif