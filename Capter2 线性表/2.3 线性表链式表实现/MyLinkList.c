//
// Created by hibian on 12/22/21.
//
#include "MyLinkList.h"
#include <stdlib.h>
#include <stdio.h>

LNode *MakeNode(int e) {
    LNode *newNode = (LNode *) malloc(sizeof(LNode));
    if (!newNode)
        return NULL;
    newNode->data = e;
    newNode->next = NULL;
    return newNode;
}

void FreeNode(LNode *node) {
    //I'm not sure is this implement satisfies the meaning of the book;
    free(node);
}

LinkList InitList() {
    LinkList link = (LinkList) malloc(sizeof(LNode));
    if (!link) {
        return NULL;
    }
    //head node doesn't need data;
    link->data = 0;
    link->next = NULL;
    return link;
}

int DestroyList(LinkList link) {
    if (link != NULL) {
        DestroyList(link->next);
        FreeNode(link);
    }
    return True;
}

int ClearList(LinkList link) {
    DestroyList(link->next);
    link->next = NULL;
    return True;
}

int InsFirst(LNode *head, LNode *s) {
    s->next = head->next;
    head->next = s;
    return True;
}

LNode *DelFirst(LNode *head) {
    LNode *first = head->next;
    if (!first)
        return NULL;
    head->next = first->next;
    first->next = NULL;
    return first;
}

int Append(LinkList list, LNode *node) {
    LNode *p = list;
    while (p->next)
        p = p->next;
    //node -> next should be NULL or other custom definition;
    node->next = p->next;
    p->next = node;
    return True;
}

int RemoveLast(LinkList list) {
    LNode *toBeLast = list;
    if (!toBeLast->next) {
        return False;
    }
    while (toBeLast->next->next) {
        toBeLast = toBeLast->next;
    }
    DestroyList(toBeLast->next);
    toBeLast->next = NULL;
    return True;
}

int InsBefore(LinkList list, LNode *p, LNode *bfp) {
    LNode *ptr = list;
    while (ptr->next != p && ptr->next)
        ptr = ptr->next;
    if (!ptr->next)
        return False;
    ptr->next = bfp;
    bfp->next = p;
    return True;
}

int InsAfter(LinkList list, LNode *p, LNode *afp) {
    LNode *ptr = list;
    while (ptr != p && ptr)
        ptr = ptr->next;
    if (ptr == NULL)
        return False;
    afp->next = ptr->next;
    ptr->next = afp;
    return True;
}

int SetCurElem(LNode *node, int e) {
    node->data = e;
    return True;
}

int GetCurElem(LNode *node) {
    return node->data;
}

int ListLength(LinkList list) {
    int len = 0;
    LNode *p = list;
    while (p->next != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

LNode *GetHead(LinkList list) {
    //I'm not sure...,too simple?
    return list;
}

LNode *GetLast(LinkList list) {
    LNode *p = list;
    while (p->next != NULL)
        p = p->next;
    return p;
}

LNode *PriorPos(LinkList list, LNode *node) {
    LNode *p = list;
    while (p->next != node && p->next)
        p = p->next;
    if (!p->next)
        return NULL;
    return p;
}

LNode *NextPos(LinkList list, LNode *node) {
    //interesting;
    return node->next;
}

int LocatePos(LinkList list, LNode *node) {
    //start from 0;
    int pos = 0;
    LNode *p = list;
    while (p->next != node && p->next) {
        pos++;
        p = p->next;
    }
    if (!p->next)
        return ERROR;
    return pos;
}

LNode *LocateElem(LinkList list, int e) {
    LNode *p = list;
    while ((p = p->next)) {
        if (p->data == e)
            return p;
    }
    return NULL;
}

void ListTraverse(LinkList list) {
    LNode *p = list;
    printf("*->");
    while ((p = p->next)) {
        printf("%d->", p->data);
    }
    printf("NULL\n");
}

LinkList MergeList_L(LinkList La, LinkList Lb) {
    LinkList Lc = InitList();
    LNode *pc = Lc, *pa = La->next, *pb = Lb->next;
    while (pa&&pb){
        if (pa->data < pb->data) {
            pc->next = pa;
            pa = pa->next;
        } else{
            pc->next = pb;
            pb = pb ->next;
        }
        pc = pc ->next;
    }
    if (!pa)
        pc->next = pb;
    if (!pb)
        pc->next = pa;
    FreeNode(La);
    FreeNode(Lb);
    return Lc;
}