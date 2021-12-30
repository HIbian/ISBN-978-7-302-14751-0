//
// Created by hibian on 12/30/21.
//
#include "MyStack.h"
#include <stdio.h>
#include <stdlib.h>

MyStack *InitStack() {
    MyStack *stack = (MyStack *) malloc(sizeof(MyStack));
    stack->data = (int *) malloc(DefaultSize*sizeof(int));
    stack->len =0;
    stack->size = DefaultSize;
    return stack;
}

void DestroyStack(MyStack *stack){
    free(stack->data);
    free(stack);
}

void ClearStack(MyStack *stack){
    stack->len = 0;
}

int StackEmpty(MyStack stack){
    return stack.len == 0;
}

int StackLength(MyStack stack){
    return stack.len;
}

int GetTop(MyStack stack){
    //or return other when len == 0
    if (stack.len == 0)
        exit(-1);
    return stack.data[stack.len-1];
}

void Push(MyStack *stack, int push_elem){
    if (stack->len == stack->size)
        return;
    *(stack->data + stack->len) = push_elem;
    stack->len++;
}

int Pop(MyStack *stack){
    if (StackEmpty(*stack))
        exit(-1);
    return stack->data[--stack->len];
}


void StackTraverse(MyStack stack){
    for (int i = 0; i < stack.len; ++i) {
        printf("%d ",*(stack.data+i));
    }
    printf("<-top\n");
}
