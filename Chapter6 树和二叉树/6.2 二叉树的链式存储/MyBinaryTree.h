//
// Created by hibian on 3/22/22.
//

#ifndef C_REVIEW_MYBINARYTREE_H
#define C_REVIEW_MYBINARYTREE_H

#endif //C_REVIEW_MYBINARYTREE_H

#define MaxSize 1000
#define True 1
#define False 0

typedef struct Node{
    int elem;
    struct Node *left;
    struct Node *right;
}MyBiTree,Node;

MyBiTree *InitBiTree(void);
void DestroyBiTree(MyBiTree *T);
void CreateBiTree(MyBiTree *T,int *definition,int p);
void ClearBiTree(MyBiTree *T);
int BitTreeEmpty(MyBiTree T);
int BitTreeDepth(MyBiTree *T);
MyBiTree *Root(MyBiTree *T);
//?
int Value(MyBiTree T,Node e);
void Assign(MyBiTree T,Node *e,int value);
MyBiTree *Parent(MyBiTree *T,Node *e);
MyBiTree *LeftChild(MyBiTree *T,Node *e);
MyBiTree *RightChild(MyBiTree *T,Node *e);
MyBiTree *LeftSibling(MyBiTree *T,Node *e);
MyBiTree *RightSibling(MyBiTree *T,Node *e);
//?
void InsertChild(MyBiTree T,Node *p,int LR,MyBiTree *c);
void DeleteChild(MyBiTree T,Node *p,int LR);

void PreOrderTraverse(MyBiTree *T);
void InOrderTraverse(MyBiTree *T);
void PostOrderTraverse(MyBiTree *T);
void LevelOrderTraverse(MyBiTree *T);


typedef struct Queue {
    MyBiTree **elem;
    int front;
    int rear;
    int maxSize;
} NodeQueue;

NodeQueue *InitQueue();
//预留一个存储空间用于判断队列是否满，所以判空时可以通过指针指向地址是否一样判断判断循环队列是否为空
int QueueEmpty(NodeQueue q);
void EnQueue(NodeQueue *q,MyBiTree *node);
MyBiTree *DeQueue(NodeQueue *q);







