//
// Created by hibian on 12/30/21.
//
#include "MyStack.h"
#include <stdio.h>

void practice3_2_1(int num, int d);

void practice3_2_2(char *str);

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
    practice3_2_1(127, 2);

    //3.2.2 括号匹配检测
    practice3_2_2("(de({ow}ow32)");

}

void practice3_2_1(int num, int d) {
    MyStack *S = InitStack();
    while (num) {
        Push(S, num % d);
        num /= d;
    }
    while (!StackEmpty(*S)) {
        printf("%d ", Pop(S));
    }
    putchar('\n');
}

void practice3_2_2(char *str) {
    char *p = str;
    MyStack *s = InitStack();
    while (*p != '\0') {
        if (*p == '(' || *p == '{' || *p == '[') {
            Push(s, *p);
        } else if (*p == ')' || *p == '}' || *p == ']') {
            char p_want = ' ';
            if (*p == ')') p_want = '(';
            else if (*p == '}') p_want = '{';
            else if (*p == ']') p_want = '[';
            if (p_want != Pop(s)) {
                printf("括号不匹配");
                return;
            }
        }
        p++;
    }
    if(StackEmpty(*s)){
        printf("括号匹配");
    } else{
        printf("括号不匹配");
    }
}