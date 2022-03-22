//
// Created by hibian on 3/22/22.
//

#include "MyBinaryTree.h"
#include "stdio.h"

int main(){
    int def[] = {11,1,2,3,4,5,6,7,8,9,10,11};
    MyBiTree *T = InitBiTree();
    CreateBiTree(T,def,1);
    PreOrderTraverse(T);
}

