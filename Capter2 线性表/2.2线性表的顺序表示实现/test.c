#include <stdio.h>
#include "MyArrayList.h"

#define SHOW_LIST ListTraverse(*list);

int main() {
    //basic test
    MyList *list = InitList();
    //test insert
    for (int i = 0; i < 6; ++i) {
        ListInsert(list, list->len, i);
    }
    SHOW_LIST
    ListInsert(list, 0, 100);
    SHOW_LIST
    ListInsert(list, 1, 299);
    SHOW_LIST
    //test delete
    ListDelete(list, 1);
    SHOW_LIST
    //test clear and empty
    ClearList(list);
    printf("is clear? %s\n", ListEmpty(*list)?"true":"false");
    SHOW_LIST
    //test ListLength
    for (int i = 0; i < 8; ++i) {
        ListInsert(list, list->len, i);
    }
    SHOW_LIST
    printf("list length is %d\n", ListLength(*list));
    //test getElem
    printf("the elem index of 4 is %d\n",*GetElem(*list,4));
    //test next and prior
    printf("the prior elem of 4 is %d\n", *PriorElem(*list, 4));
    printf("the prior elem of 0 is %s\n", PriorElem(*list, 0)==NULL?"not found":"something wrong");
    printf("the next elem of 4 is %d\n", *NextElem(*list, 4));
    printf("the next elem of 7 is %s\n", NextElem(*list, 7)==NULL?"not found":"something wrong");
    //test malloc size
    for (int i = 0; i < 999; ++i) {
        ListInsert(list, list->len, i);
    }
    SHOW_LIST
    DestroyList(list);
    //eg 2.1 at page 20
    //eg 2.2 at page 20
    //eg 2.4
    return 0;
}
