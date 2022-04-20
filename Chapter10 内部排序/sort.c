//
// Created by hibian on 4/19/22.
//

#include "sort.h"
#include "stdio.h"

void Print(SqList *list) {
    for (int i = 1; i <= list->length; ++i) {
        printf("%d,", list->record[i]);
    }
    printf("\n");
}

//插入排序
void InsertSort(SqList *L) {
    for (int i = 2; i <= L->length; ++i) {
        L->record[0] = L->record[i];
        int j = i - 1;
        for (; j > 0; --j) {
            if (L->record[0] < L->record[j]) {
                L->record[j + 1] = L->record[j];
            } else {
                break;
            }
        }
        L->record[j + 1] = L->record[0];
    }
}

void BInsertSort(SqList *L) {
    int i, j;
    int low, mid, high;
    for (i = 2; i <= L->length; ++i) {
        L->record[0] = L->record[i];
        low = 1;
        high = i - 1;
        //二分查找
        while (low <= high) {
            mid = (low + high) / 2;
            if (L->record[0] > L->record[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
//            printf("%d %d %d\n", low, mid, high);
        }
//        printf("\n===========\n");
        for (j = i; j >= high + 1; --j) {
            L->record[j] = L->record[j - 1];
        }
        L->record[high + 1] = L->record[0];
    }
}

void ShellInsert(SqList *L, int dk) {
    for (int i = dk + 1; i <= L->length; i++) {
        if (L->record[i] < L->record[i - dk]) {
            L->record[0] = L->record[i];
            int j = i - dk;
            for (; j >= 1; j -= dk) {
                if (L->record[0] < L->record[j]) {
                    L->record[j + dk] = L->record[j];
                    continue;
                }
                break;
            }
            L->record[j + dk] = L->record[0];
        }
    }
}

void ShellSort(SqList *L, int dlta[], int t) {
    for (int i = 0; i < t; ++i) {
        ShellInsert(L, dlta[i]);
    }
}

//交换排序

void BubbleSort(SqList *L) {
    for (int i = 1; i <= L->length - 1; ++i) {
        for (int j = 1; j <= L->length - i; ++j) {
            if (L->record[j] > L->record[j + 1]) {
                L->record[0] = L->record[j + 1];
                L->record[j + 1] = L->record[j];
                L->record[j] = L->record[0];
            }
        }
    }
}

int Partition(SqList *L, int low, int high) {
    L->record[0] = L->record[low];
    while (low < high) {
        while (low < high && L->record[high] >= L->record[0]) high--;
        L->record[low] = L->record[high]; //关于这里直接赋值,low在这之前已经把值给了0或者high,所以可以直接赋值
        while (low < high && L->record[low] <= L->record[0]) low++;
        L->record[high] = L->record[low];
    }
    L->record[low] = L->record[0];
    return low;
}

void QuickSort(SqList *L, int low, int high) {
    if (low < high) {
        int pivotloc = Partition(L, low, high);
        printf("low=%d high=%d p=%d\n", low, high, pivotloc);
        QuickSort(L, pivotloc + 1, high);
        QuickSort(L, low, pivotloc - 1);
    }
}
