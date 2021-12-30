//
// Created by hibian on 12/30/21.
//
# include "MyStack.h"
int main(){
   MyStack *s = InitStack();
    for (int i = 0; i < 5; ++i) {
        Push(s,i);
    }
    StackTraverse(*s);

}