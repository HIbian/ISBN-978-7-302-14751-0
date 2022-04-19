//
// Created by hibian on 4/19/22.
//

#ifndef C_REVIEW_SORT_H
#define C_REVIEW_SORT_H

#endif //C_REVIEW_SORT_H

#define MAXSIZE 20
typedef struct {
    //0做哨兵或者置空
    int record[MAXSIZE + 1];
    int length;
} SqList;

void Print(SqList *list);

//插入排序
void InsertSort(SqList *L);

void BInsertSort(SqList *L);

//交换排序

//选择排序

//归并排序

//记树排序