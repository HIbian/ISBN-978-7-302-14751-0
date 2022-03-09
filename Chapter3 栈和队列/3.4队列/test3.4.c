//
// Created by hibian on 3/9/22.
//
#include "MyQueue.h"
#include "stdio.h"

int main() {
    MyQueue *queue = InitQueue();
    EnQueue(queue, 1);
    EnQueue(queue, 2);
    EnQueue(queue, 3);
    EnQueue(queue, 4);
    EnQueue(queue, 5);
    EnQueue(queue, 6);
    EnQueue(queue, 7);
    EnQueue(queue, 8);
    EnQueue(queue, 9);
    QueueTRaverse(*queue, visit);
    printf("length is %d\n", QueueLength(*queue));
    printf("head is %d.\n",GetHead(*queue));
    DeQueue(queue);
    QueueTRaverse(*queue, visit);
    printf("length is %d\n", QueueLength(*queue));
    printf("head is %d.\n",GetHead(*queue));
    DeQueue(queue);
    QueueTRaverse(*queue, visit);
    printf("length is %d\n", QueueLength(*queue));
    printf("head is %d.\n",GetHead(*queue));
    DeQueue(queue);
    QueueTRaverse(*queue, visit);
    printf("length is %d\n", QueueLength(*queue));
    printf("head is %d.\n",GetHead(*queue));
    DeQueue(queue);
    QueueTRaverse(*queue, visit);
    printf("length is %d\n", QueueLength(*queue));
    printf("head is %d.\n",GetHead(*queue));
    DeQueue(queue);
    QueueTRaverse(*queue, visit);
    printf("length is %d\n", QueueLength(*queue));
    printf("head is %d.\n",GetHead(*queue));
    EnQueue(queue, 1);
    EnQueue(queue, 2);
    EnQueue(queue, 3);
    EnQueue(queue, 4);
    QueueTRaverse(*queue, visit);
    printf("length is %d\n", QueueLength(*queue));
    printf("head is %d.\n",GetHead(*queue));
}