//
// Created by hibian on 12/21/21.
//

#ifndef C_REVIEW_MYARRAYLIST_H
#define C_REVIEW_MYARRAYLIST_H

#endif //C_REVIEW_MYARRAYLIST_H

#define INIT_SIZE 10

typedef struct {
    int *elem;
    int len;
    int size;
    int malloc_factor;
} MyList;

MyList *InitList();

void DestroyList(MyList *list);

void ClearList(MyList *list);

int ListEmpty(MyList list);

int ListLength(MyList list);

int *GetElem(MyList list, int n);

int Locate(MyList list, int elem);

int *PriorElem(MyList list, int cur_e);

int *NextElem(MyList list, int cur_e);

void ListInsert(MyList *list, int i, int e);

int *ListDelete(MyList *list, int i);

void ListTraverse(MyList list);

//eg 2.1 at page 20
void Union(MyList *listA, MyList listB);

//eg 2.7 at page 26
MyList *MergeList_Sq(MyList La, MyList Lb);
