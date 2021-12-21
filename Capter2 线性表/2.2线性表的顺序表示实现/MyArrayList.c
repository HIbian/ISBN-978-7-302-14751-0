//
// Created by hibian on 12/21/21.
//

#include "MyArrayList.h"
#include "stdlib.h"
#include "stdio.h"

MyList *InitList() {
    MyList *list = (MyList *) malloc(sizeof(MyList));
    list->elem = (int *) malloc(INIT_SIZE * sizeof(int));
    list->len = 0;
    list->size = INIT_SIZE;
    list->malloc_factor = 2;
    return list;
}

void DestroyList(MyList *list) {
    free(list);
}

void ClearList(MyList *list) {
    free(list->elem);
    list->elem = (int *) malloc(list->size * sizeof(int));
    list->len = 0;
}

int ListEmpty(MyList list) {
    return list.len == 0;
}

int ListLength(MyList list) {
    return list.len;
}

int *GetElem(MyList list, int n) {
    if (n > list.len - 1 || n < 0) {
        return NULL;
    }
    return &list.elem[n];
}

int Locate(MyList list, int elem) {
    int i = 0;
    while (i < list.len && elem != list.elem[i]) {
        i++;
    }
    if (i == list.len)
        return -1;
    return i;
}

int *PriorElem(MyList list, int cur_e) {
    int index;
    if ((index = Locate(list, cur_e)) != -1 && index != 0) {
        return list.elem + index - 1;
    }
    return NULL;
}

int *NextElem(MyList list, int cur_e) {
    int index;
    if ((index = Locate(list, cur_e)) != -1 && index != list.len - 1) {
        return list.elem + index + 1;
    }
    return NULL;
}

void ListInsert(MyList *list, int i, int e) {
    if (list->size == list->len) {
        //situation of full : add space
        list->size *= list->malloc_factor;
        int *new_space = (int *) malloc(list->size * sizeof(int));
        for (int j = 0; j < list->len; ++j) {
            *(new_space + j) = *(list->elem + j);
        }
        free(list->elem);
        list->elem = new_space;
        printf("malloced , size is %d\n", list->size);
    }
    int *p = list->elem + list->len;
    int mc = list->len - i;
    while (mc-- > 0) {
        *p = *(p - 1);
        p--;
    }
    *p = e;
    list->len++;
}

int *ListDelete(MyList *list, int i) {
    if (list->len == 0)
        return NULL;
    int *p = list->elem + i;
    //save int value by ptr.
    int *ret = (int *) malloc(sizeof(int));
    *ret = *p;
    while (i++ < list->len) {
        *p = *(p + 1);
        p++;
    }
    list->len--;
    return ret;
}

void ListTraverse(MyList list) {
    putchar('[');
    while (list.len-- > 0) {
        if (list.len == 0) {
            printf("%d", *(list.elem++));
            break;
        }
        printf("%d,", *(list.elem++));
    }
    putchar(']');
    putchar('\n');
}

void Union(MyList *listA, MyList listB) {
    int len_b = ListLength(listB);
    for (int i = 0; i < len_b; ++i) {
        if (Locate(*listA, *(listB.elem + i)) == -1) {
            ListInsert(listA, listA->len, *(listB.elem + i));
        }
    }
}

MyList *MergeList_Sq(MyList La, MyList Lb) {
    MyList *Lc = InitList();
    int ia = 0;
    int ib = 0;
    while (ia < La.len && ib < Lb.len) {
        if (*(La.elem + ia) < *(Lb.elem + ib)) {
            ListInsert(Lc, Lc->len, *(La.elem + ia));
            ia++;
        } else {
            ListInsert(Lc, Lc->len, *(Lb.elem + ib));
            ib++;
        }
    }
    while(ia<La.len){
        ListInsert(Lc, Lc->len, *(La.elem + ia));
        ia++;
    }
    while (ib<Lb.len){
        ListInsert(Lc,Lc->len,*(Lb.elem+ib));
        ib++;
    }
    return Lc;
}
