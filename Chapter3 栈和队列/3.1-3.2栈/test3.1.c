//
// Created by hibian on 12/30/21.
//
#include "MyStack.h"
#include <stdio.h>

int main() {
    MyStack *s = InitStack();
    for (int i = 0; i < 5; ++i) {
        Push(s, i * 3);
        printf("%d|", GetTop(*s));
    }
    StackTraverse(*s);
    printf("%d\n", Pop(s));
    StackTraverse(*s);
    ClearStack(s);
    StackTraverse(*s);
    for (int i = 0; i < 5; ++i) {
        Push(s, i * 3);
        printf("%d|", GetTop(*s));
    }
    StackTraverse(*s);
    printf("%d\n", StackLength(*s));
    DestroyStack(s);

}