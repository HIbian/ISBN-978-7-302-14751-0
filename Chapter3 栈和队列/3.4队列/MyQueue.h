#define True 1
#define False 0
#define MaxSize 10

typedef struct{
    int *elem;
    int front;
    int rear;
}MyQueue;

MyQueue* InitQueue();

void DestoryQueue(MyQueue *q);

void ClearQueue(MyQueue *q);

int QueueEmpty(MyQueue q);

int QueueLength(MyQueue q);

int GetHead(MyQueue q);

void EnQueue(MyQueue *q,int num);

int DeQueue(MyQueue *q);

void QueueTRaverse(MyQueue q,void (*visit)(int));

void visit(int elem);

