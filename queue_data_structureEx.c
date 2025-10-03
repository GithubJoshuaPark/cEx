#include <stdio.h>
#include <stdbool.h>
#include "queue_data_structureEx.h"
#include "hello.h" // For printLine

#define QUEUE_SIZE 5

// A structure to represent a circular queue
typedef struct {
    int items[QUEUE_SIZE];
    int front;
    int rear;
    int count;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Check if the queue is full
bool isQueueFull(Queue *q) {
    return q->count == QUEUE_SIZE;
}

// Check if the queue is empty
bool isQueueEmpty(Queue *q) {
    return q->count == 0;
}

// Add an element to the queue (enqueue)
void enqueue(Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
    } else {
        q->rear = (q->rear + 1) % QUEUE_SIZE; // Wrap around
        q->items[q->rear] = value;
        q->count++;
        printf("Enqueued %d into the queue. Now c->count: %d, c->front: %d, c->rear: %d.\n"
                , value
                , q->count
                , q->front
                , q->rear);
    }
}

// Remove an element from the queue (dequeue)
int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Return an error value
    } else {
        int item = q->items[q->front];
        q->front = (q->front + 1) % QUEUE_SIZE; // Wrap around
        q->count--;
        return item;
    }
}

void queue_data_structureEx(void) {
    printLine("Demonstrating Queue Data Structure (FIFO)");

    Queue myQueue;
    initQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    // Dequeue 10
    printf("Dequeued %d from the queue. Now c->count: %d, c->front: %d, c->rear: %d.\n"
               , dequeue(&myQueue)
               , myQueue.count
               , myQueue.front
               , myQueue.rear
            );

    enqueue(&myQueue, 40);
    enqueue(&myQueue, 50);
    enqueue(&myQueue, 60); // This should be full

    printf("\nDequeuing remaining items:\n");
    while (!isQueueEmpty(&myQueue)) {
        printf("Dequeued %d from the queue. Now c->count: %d, c->front: %d, c->rear: %d.\n"
               , dequeue(&myQueue)
               , myQueue.count
               , myQueue.front
               , myQueue.rear
            );
    }
}