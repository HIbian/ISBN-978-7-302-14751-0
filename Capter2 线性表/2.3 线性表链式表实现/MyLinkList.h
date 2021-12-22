//
// Created by hibian on 12/22/21.
//

#ifndef C_REVIEW_MYLINKLIST_H
#define C_REVIEW_MYLINKLIST_H

#endif //C_REVIEW_MYLINKLIST_H
#define ERROR -1
#define True 1
#define False 0

//单链表结构定义
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

LNode *MakeNode(int e);

void FreeNode(LNode *node);

LinkList InitList();

int DestroyList(LinkList link);

int ClearList(LinkList link);

int InsFirst(LNode *head,LNode *s);

LNode *DelFirst(LNode *head);

int Append(LinkList list,LNode *node);

int RemoveLast(LinkList list);

int InsBefore(LinkList list,LNode *p,LNode *bfp);

int InsAfter(LinkList list,LNode *p,LNode *afp);

int SetCurElem(LNode *node,int e);

int GetCurElem(LNode *node);

int ListLength(LinkList list);

LNode *GetHead(LinkList list);

LNode *GetLast(LinkList list);

LNode *PriorPos(LinkList list,LNode *node);

LNode *NextPos(LinkList list,LNode *node);

int LocatePos(LinkList list,LNode *node);

LNode *LocateElem(LinkList list,int e);

void ListTraverse(LinkList list);




