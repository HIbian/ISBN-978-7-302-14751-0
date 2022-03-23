//
// Created by hibian on 12/30/21.
//

#ifndef C_REVIEW_MYSTACK_H
#define C_REVIEW_MYSTACK_H

#endif //C_REVIEW_MYSTACK_H
#define True 1
#define False 0
#define DefaultSize 12


typedef struct MyStack {
    int *data;
    int size;
    int len;
} MyStack;

MyStack *InitQueue();

void DestroyStack(MyStack *stack);

void ClearStack(MyStack *stack);

int StackEmpty(MyStack stack);

int StackLength(MyStack stack);

int GetTop(MyStack stack);

void Push(MyStack *stack, int push_elem);

int Pop(MyStack *stack);

void StackTraverse(MyStack stack);

