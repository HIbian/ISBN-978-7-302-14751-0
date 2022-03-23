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
    if (T->left != NULL) {
        DestroyBiTree(T->left);
    }
    if (T->right != NULL) {
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

void ClearBiTree(MyBiTree *T) {
    if (T->left != NULL) {
        DestroyBiTree(T->left);
    }
    if (T->right != NULL) {
        DestroyBiTree(T->right);
    }
    T->left = NULL;
    T->right = NULL;
    T->elem = 0;
}

int BitTreeEmpty(MyBiTree T) {
    return T.elem == 0 && T.right == NULL && T.left == NULL;
}

int BitTreeDepth(MyBiTree *T) {
    if (T == NULL) return 0;
    int left_depth = BitTreeDepth(T->left);
    int right_depth = BitTreeDepth(T->right);
    return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
}

MyBiTree *Root(MyBiTree *T) {
    return T;
}

//?
int Value(MyBiTree T, Node e) {
    return e.elem;
}

void Assign(MyBiTree T, Node *e, int value) {
    e->elem = value;
}

MyBiTree *Parent(MyBiTree *T, Node *e) {
    if (T == NULL) return NULL;
    if (T->right == e || T->left == e) {
        return T;
    }
    MyBiTree *p_r = Parent(T->left, e);
    MyBiTree *p_l = Parent(T->right, e);
    return p_r == NULL ? p_l : p_r;
}

MyBiTree *LeftChild(MyBiTree *T, Node *e) {
    return e->left;
}

MyBiTree *RightChild(MyBiTree *T, Node *e) {
    return e->right;
}

MyBiTree *LeftSibling(MyBiTree *T, Node *e) {
    return Parent(T, e)->left;
}

MyBiTree *RightSibling(MyBiTree *T, Node *e) {
    return Parent(T, e)->right;
}

void InsertChild(MyBiTree T, Node *p, int LR, MyBiTree *c) {
    //0,left,1,right
    if (LR) {
        p->right = c;
    } else {
        p->left = c;
    }
}

void DeleteChild(MyBiTree T, Node *p, int LR) {
    if (LR) {
        DestroyBiTree(p->right);
    } else {
        DestroyBiTree(p->left);
    }
}

void PreOrderTraverse(MyBiTree *T) {
    if (!T) return;
    printf("%d ", T->elem);
    PreOrderTraverse(T->left);
    PreOrderTraverse(T->right);
}

void InOrderTraverse(MyBiTree *T) {
    if (!T)return;
    InOrderTraverse(T->left);
    printf("%d", T->elem);
    InOrderTraverse(T->right);
}

void PostOrderTraverse(MyBiTree *T) {
    if (!T)return;
    PostOrderTraverse(T->left);
    PostOrderTraverse(T->right);
    printf("%d", T->elem);
}

void LevelOrderTraverse(MyBiTree *T) {
    NodeQueue *q = InitQueue();
    EnQueue(q, T);
    while (!QueueEmpty(*q)) {
        MyBiTree *node = DeQueue(q);
        if (node->left != NULL) EnQueue(q,node->left);
        if (node->right != NULL) EnQueue(q,node->right);
        printf("%d",node->elem);
    }
}
