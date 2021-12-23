//
// Created by hibian on 12/22/21.
//

#include <stdio.h>
#include "MyLinkList.h"

#define SHOW(_list) ListTraverse(_list)

#include <unistd.h>

void progress() {
    char meta = '#';
    char str[300];
    for (int i = 0; i < 100; ++i) {
        char *s = str;
        int j = i;
        while (j-- > 0)
            *s++ = meta;
        j = 100 - i;
        while (j-- > 0)
            *s++ = ' ';
        *s = '\0';
        printf("\033[34m[%s]\r", str);
        fflush(stdout);
        sleep(1);
    }

}

int main() {
    //1. test create a link list and nodes and append;
    LinkList list = InitList();
    for (int j = 0; j < 20; ++j) {
        Append(list, MakeNode(j));
    }
    SHOW(list);
    //2. test clear;
    ClearList(list);
    SHOW(list);
    //3. test insert first;
    for (int i = 0; i < 20; ++i) {
        Append(list, MakeNode(i));
        InsFirst(list, MakeNode(i));
    }
    SHOW(list);
    //4. test remove last;
    for (int j = 0; j < 30; ++j) {
        RemoveLast(list);
    }
    SHOW(list);
    //5. test locate elem
    LNode *anode = LocateElem(list, 15);
    SetCurElem(anode, 999);
    SHOW(list);
    int anodeDate = GetCurElem(anode);
    printf("%d\n",anodeDate);
    printf("%d\n", LocatePos(list,anode));
    printf("%d\n",ListLength(list));
    //6. test insert before.after
    InsAfter(list, anode, MakeNode(1010));
    InsBefore(list, anode, MakeNode(883));
    SHOW(list);
    //7. test delete first
    DestroyList(DelFirst(list));
    SHOW(list);
    //8. test get head,last,prior,next
    printf("%d\n", GetHead(list)->data);
    printf("%d\n", GetLast(list)->data);
    printf("%d\n", PriorPos(list,anode)->data);
    printf("%d\n", NextPos(list,anode)->data);

    //9. test merge 2.21 at page 39
    LinkList La = InitList();
    LinkList Lb = InitList();
    for (int i = 0; i < 10; ++i) {
        Append(La, MakeNode(2*i));
        Append(Lb, MakeNode(3*i));
    }
    SHOW(La);
    SHOW(Lb);
    LinkList Lc = MergeList_L(La,Lb);
    SHOW(Lc);

    //10. test reverse
    ReverseLinkList(Lc);
    SHOW(Lc);

    //just play;
    progress();


}
