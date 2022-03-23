//
// Created by hibian on 3/9/22.
//
#include "MyQueue.h"
#include <stdlib.h>
#include "stdio.h"

MyQueue* InitStack(){
    MyQueue *queue = (MyQueue*) malloc(sizeof(MyQueue));
    queue->elem = (int*) malloc(sizeof(int)*MaxSize);
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

void DestoryQueue(MyQueue *q){
    free(q->elem);
    free(q);
}

void ClearQueue(MyQueue *q){
    q->front = 0;
    q->rear = 0;
}

//预留一个存储空间用于判断队列是否满，所以判空时可以通过指针指向地址是否一样判断判断循环队列是否为空
int QueueEmpty(MyQueue q){
    return q.front == q.rear;
}

int QueueLength(MyQueue q){
    return (q.rear+MaxSize-q.front)%MaxSize;
}

int GetHead(MyQueue q){
    if(!QueueEmpty(q))
        return q.elem[q.front];
    //应返回error
    return False;
}

void EnQueue(MyQueue *q,int num){
    //判断是否队满
    if((q->rear+1)%MaxSize == q->front)
        return;
    q->elem[q->rear] = num;
    q->rear = (q->rear+1)%MaxSize;
}

int DeQueue(MyQueue *q){
    if(QueueEmpty(*q))
        //应该返回error
        return False;
    int num = q->elem[q->front];
    q->front = (q->front+1)%MaxSize;
    return num;
}

void QueueTRaverse(MyQueue q,void (*visit)(int)){
    if(QueueEmpty(q))
        return;
    int fp = q.front;
    while (fp!=q.rear){
       visit(q.elem[fp]);
       fp = (fp+1)%MaxSize;
    }
    printf("\n");
}

void visit(int elem){
    printf("%d->",elem);
}
