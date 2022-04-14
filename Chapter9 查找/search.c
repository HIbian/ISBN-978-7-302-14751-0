//
// Created by hibian on 4/14/22.
//

#include "search.h"

//返回下标 -1表示未找到
int binary_search(const int list[], int len, int num) {
    int low = 0;
    int high = len - 1;
    int mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (num > list[mid]) {
            low = mid + 1;
        } else if (num < list[mid]) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}
