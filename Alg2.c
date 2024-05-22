#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "queue.h"
#include "astar.h"

#define MAP_SIZE 100

typedef struct {
    Point point;
    int cost;
    int priority;
} Node;

typedef struct {
    Node* array[MAP_SIZE];
    int size;
} PriorityQueue;

PriorityQueue* createPriorityQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    return pq;
}

void push(PriorityQueue* pq, Node* node) {
    pq->array[pq->size++] = node;
}

Node* pop(PriorityQueue* pq) {
    int minIndex = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->array[i]->priority < pq->array[minIndex]->priority) {
            minIndex = i;
        }
    }
    Node* result = pq->array[minIndex];
    for (int i = minIndex; i < pq->size - 1; i++) {
        pq->array[i] = pq->array[i + 1];
    }
    pq->size--;
    return result;
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void aStarSearch(Point start, Point goal) {
    // Инициализация приоритетной очереди
    PriorityQueue* pq = createPriorityQueue();

    // Добавление начальной точки в очередь
    Node* startNode = (Node*)malloc(sizeof(Node));
    startNode->point = start;
    startNode->cost = 0;
    startNode->priority = heuristic(start, goal);
    push(pq, startNode);

    while (pq->size > 0) {
        Node* current = pop(pq);
        if (current->point.x == goal.x && current->point.y == goal.y) {
            printf("Маршрут найден\n");
            break;
        }
        // Добавление соседних точек в очередь
        // ...
    }
}
