//
// Created by hibian on 3/22/22.
//
#include "MyBinaryTree.h"
#include "stdlib.h"
#include "stdio.h"

//构造空二叉树
MyBiTree *InitBiTree() {
    MyBiTree *T = (MyBiTree *) malloc(sizeof(MyBiTree));
    if (!T) exit(-1);
    T->left = NULL;
    T->right = NULL;
    T->elem = 0;
    return T;
}

//销毁二叉树，需要递归地释放空间
void DestroyBiTree(MyBiTree *T) {
    if(T->left!=NULL){
        DestroyBiTree(T->left);
    }
    if(T->right!=NULL){
        DestroyBiTree(T->right);
    }
    free(T);
    T = NULL;
}

//按照完全二叉树的顺序存储规则构造一棵链式存储的二叉树,definition第一位存放长度
void CreateBiTree(MyBiTree *T, int *definition, int p) {
    T->elem = definition[p];
    if (2 * p <= definition[0] && definition[2 * p] != 0) {
        T->left = InitBiTree();
        CreateBiTree(T->left, definition, 2 * p);
    } else {
        T->left = NULL;
    }
    if (2 * p + 1 <= definition[0] && definition[2 * p + 1] != 0) {
        T->right = InitBiTree();
        CreateBiTree(T->right, definition, 2 * p + 1);
    } else {
        T->right = NULL;
    }
}

void ClearBiTree(MyBiTree *T);

int BitTreeEmpty(MyBiTree T);

int BitTreeDepth(MyBiTree T);

MyBiTree *Root(MyBiTree T);

//?
int Value(MyBiTree T, Node e);

void Assign(MyBiTree T, Node *e, int value);

MyBiTree *Parent(MyBiTree T, Node e);

MyBiTree *LeftChild(MyBiTree T, Node e);

MyBiTree *RightChild(MyBiTree T, Node e);

MyBiTree *LeftSibling(MyBiTree T, Node e);

MyBiTree *RightSibling(MyBiTree T, Node e);

//?
void InsertChild(MyBiTree T, Node *p, int LR, MyBiTree *c);

void DeleteChild(MyBiTree T, Node *p, int LR);

void PreOrderTraverse(MyBiTree *T) {
    if (!T) return;
    printf("%d ", T->elem);
    PreOrderTraverse(T->left);
    PreOrderTraverse(T->right);
}

void InOrderTraverse(MyBiTree *T);

void PostOrderTraverse(MyBiTree *T);

void LevelOrderTraverse(MyBiTree *T);
