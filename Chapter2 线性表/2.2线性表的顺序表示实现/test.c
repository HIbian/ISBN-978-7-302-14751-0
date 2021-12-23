#include <stdio.h>
#include "MyArrayList.h"

#define SHOW_LIST ListTraverse(*list);

int main() {
    //1 basic test
    MyList *list = InitList();
    //1.1 test insert
    for (int i = 0; i < 6; ++i) {
        ListInsert(list, list->len, i);
    }
    SHOW_LIST
    ListInsert(list, 0, 100);
    SHOW_LIST
    ListInsert(list, 1, 299);
    SHOW_LIST
    //1.2 test delete
    ListDelete(list, 1);
    SHOW_LIST
    //1.3 test clear and empty
    ClearList(list);
    printf("is clear? %s\n", ListEmpty(*list) ? "true" : "false");
    SHOW_LIST
    //1.4 test ListLength
    for (int i = 0; i < 8; ++i) {
        ListInsert(list, list->len, i);
    }
    SHOW_LIST
    printf("list length is %d\n", ListLength(*list));
    //1.5 test getElem
    printf("the elem index of 4 is %d\n", *GetElem(*list, 4));
    //1.6 test next and prior
    printf("the prior elem of 4 is %d\n", *PriorElem(*list, 4));
    printf("the prior elem of 0 is %s\n", PriorElem(*list, 0) == NULL ? "not found" : "something wrong");
    printf("the next elem of 4 is %d\n", *NextElem(*list, 4));
    printf("the next elem of 7 is %s\n", NextElem(*list, 7) == NULL ? "not found" : "something wrong");
    //1.7 test malloc size
    for (int i = 0; i < 999; ++i) {
        ListInsert(list, list->len, i);
    }
    SHOW_LIST
    DestroyList(list);

    //2 example test
    //2.1 test eg 2.1 at page 20
    MyList *listA = InitList();
    MyList *listB = InitList();
    for (int i = 0; i < 40; ++i) {
        ListInsert(listA, listA->len, 2 * i);
        ListInsert(listB, listB->len, 3 * i);
    }
    ListTraverse(*listA);
    ListTraverse(*listB);
    Union(listA, *listB);
    ListTraverse(*listA);
    //2.2 test eg 2.7 at page 26

    MyList *listC = InitList();
    MyList *listD = InitList();
    for (int i = 0; i < 40; ++i) {
        ListInsert(listC, listC->len, 2 * i);
        ListInsert(listD, listD->len, 3 * i);
    }
    ListTraverse(*listC);
    ListTraverse(*listD);
    MyList *listE = MergeList_Sq(*listC, *listD);
    ListTraverse(*listE);
    return 0;
}