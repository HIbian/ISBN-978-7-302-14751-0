//
// Created by hibian on 3/15/22.
//

#include "MyString.h"
#include "stdio.h"

int main(){
    MyString *s = StrAssgin("abc");
    show(*s);
    MyString *t = StrCopy(*s);
    show(*t);
    MyString *s3 = Conact(*s,*t);
    show(*s3);
    MyString *sub = SubString(*s3,3,3);
    show(*sub);

    MyString *i1 = StrAssgin("abcdefgh");
    MyString *temp = StrAssgin("d");
    show(*i1);
    show(*temp);
    int index = Index(*i1,*temp,1);
    printf("pos is : %d\n",index);


}