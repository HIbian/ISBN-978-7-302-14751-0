//
// Created by hibian on 3/23/22.
//
#include "MyBinaryTree.h"
#include "stdlib.h"

NodeQueue *InitQueue() {
    NodeQueue *nodeQueue = (NodeQueue *) malloc(sizeof(NodeQueue));
    nodeQueue->front = 0;
    nodeQueue->rear = 0;
    nodeQueue->maxSize = MaxSize;
    nodeQueue->elem = (MyBiTree **) malloc(sizeof(NodeQueue *) * nodeQueue->maxSize);
}

//预留一个存储空间用于判断队列是否满，所以判空时可以通过指针指向地址是否一样判断判断循环队列是否为空
int QueueEmpty(NodeQueue q){
    return q.front == q.rear;
}
void EnQueue(NodeQueue *q,MyBiTree *node){
    //判断是否队满
    if((q->rear+1)%MaxSize == q->front)
        return;
    q->elem[q->rear] = node;
    q->rear = (q->rear+1)%MaxSize;
}

MyBiTree *DeQueue(NodeQueue *q){
    if(QueueEmpty(*q))
        return False;
    MyBiTree *node = q->elem[q->front];
    q->front = (q->front+1)%MaxSize;
    return node;
}
