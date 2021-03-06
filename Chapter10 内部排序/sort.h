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

void ShellInsert(SqList *L, int dk);

void ShellSort(SqList *L, int dlta[], int t);

//交换排序

void BubbleSort(SqList *L);

int Partition(SqList *L, int low, int high);

void QuickSort(SqList *L, int low, int high);

//选择排序

void SimpleSelectSort(SqList *L);

void HeapAdjust(SqList *L, int s, int m);

void HeapSort(SqList *L);

//归并排序

//记树排序