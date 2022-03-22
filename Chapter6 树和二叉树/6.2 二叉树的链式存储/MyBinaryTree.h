//
// Created by hibian on 3/22/22.
//

#ifndef C_REVIEW_MYBINARYTREE_H
#define C_REVIEW_MYBINARYTREE_H

#endif //C_REVIEW_MYBINARYTREE_H

typedef struct Node{
    int elem;
    struct Node *left;
    struct Node *right;
}MyBiTree,Node;

MyBiTree *InitBiTree(void);
void DestroyBiTree(MyBiTree *T);
void CreateBiTree(MyBiTree *T,int *definition,int p);
void ClearBiTree(MyBiTree *T);
int BitTreeEmpty(MyBiTree T);
int BitTreeDepth(MyBiTree T);
MyBiTree *Root(MyBiTree T);
//?
int Value(MyBiTree T,Node e);
void Assign(MyBiTree T,Node *e,int value);
MyBiTree *Parent(MyBiTree T,Node e);
MyBiTree *LeftChild(MyBiTree T,Node e);
MyBiTree *RightChild(MyBiTree T,Node e);
MyBiTree *LeftSibling(MyBiTree T,Node e);
MyBiTree *RightSibling(MyBiTree T,Node e);
//?
void InsertChild(MyBiTree T,Node *p,int LR,MyBiTree *c);
void DeleteChild(MyBiTree T,Node *p,int LR);

void PreOrderTraverse(MyBiTree *T);
void InOrderTraverse(MyBiTree *T);
void PostOrderTraverse(MyBiTree *T);
void LevelOrderTraverse(MyBiTree *T);








