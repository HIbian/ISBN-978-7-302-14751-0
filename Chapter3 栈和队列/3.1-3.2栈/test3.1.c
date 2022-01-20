//
// Created by hibian on 12/30/21.
//
#include "MyStack.h"
#include <stdio.h>

void practice3_1(int num, int d);

int main() {
    //test
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
    //test end

    //practice 3.2.1 十进制数转换
    practice3_1(127, 2);

}

void practice3_1(int num, int d) {
    MyStack *S = InitStack();
    while (num) {
        Push(S, num % d);
        num /= d;
    }
    while (!StackEmpty(*S)){
        printf("%d ",Pop(S));
    }
}

