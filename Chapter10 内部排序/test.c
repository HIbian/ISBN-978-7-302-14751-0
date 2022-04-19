//
// Created by hibian on 4/19/22.
//

#include "sort.h"
#include "stdlib.h"
#include "stdio.h"

void InsertSortTest();

void BInsertSortTest();

void ShellSortTest();

int main() {
//    InsertSortTest();
//    BInsertSortTest();
    ShellSortTest();
}

void ShellSortTest() {
    SqList *list = (SqList *) malloc(sizeof(SqList));
    list->record[0] = 0;
    list->record[1] = 22;
    list->record[2] = 19;
    list->record[3] = 93;
    list->record[4] = 87;
    list->record[5] = 73;
    list->record[6] = 33;
    list->record[7] = 23;
    list->record[8] = 46;
    list->record[9] = 45;
    list->record[10] = 99;
    list->record[11] = 78;
    list->length = 11;
    Print(list);
    int dlta[3] = {5, 2, 1};
    ShellSort(list, dlta, 3);
    Print(list);
}

void BInsertSortTest() {
    SqList *list = (SqList *) malloc(sizeof(SqList));
    list->record[0] = 0;
    list->record[1] = 22;
    list->record[2] = 19;
    list->record[3] = 93;
    list->record[4] = 87;
    list->record[5] = 73;
    list->record[6] = 33;
    list->record[7] = 23;
    list->record[8] = 46;
    list->record[9] = 45;
    list->record[10] = 99;
    list->record[11] = 78;
    list->length = 11;
    Print(list);
    BInsertSort(list);
    Print(list);
}

void InsertSortTest() {
    SqList *list = (SqList *) malloc(sizeof(SqList));
    list->record[0] = 0;
    list->record[1] = 22;
    list->record[2] = 19;
    list->record[3] = 93;
    list->record[4] = 87;
    list->record[5] = 73;
    list->record[6] = 33;
    list->record[7] = 23;
    list->record[8] = 46;
    list->record[9] = 45;
    list->record[10] = 99;
    list->record[11] = 78;
    list->length = 11;
    Print(list);
    InsertSort(list);
    Print(list);
}
