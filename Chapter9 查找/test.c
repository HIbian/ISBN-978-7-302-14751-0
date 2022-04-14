//
// Created by hibian on 4/14/22.
//

#include "stdio.h"
#include "search.h"
#define LIST_LEN 10

int main() {
    int list[LIST_LEN] = {1,14,26,43,50,53,59,74,88,100};
    int re = binary_search(list,LIST_LEN,50);
    printf("%d\n",re);

}

