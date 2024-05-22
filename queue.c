#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue();
void enqueue(Queue* queue, int x, int y);
Node* dequeue(Queue* queue);
int isQueueEmpty(Queue* queue);

#endif
