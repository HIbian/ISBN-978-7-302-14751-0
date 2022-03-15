//
// Created by hibian on 3/15/22.
//

#include "MyString.h"
#include "stdlib.h"
#include "stdio.h"

//生成一个其值等于chars的串
MyString *StrAssgin(char *chars) {
    MyString *s = (MyString *) malloc(sizeof(MyString));
    if (!s) exit(-1);
    int chars_len = 0;
    for (char *c = chars; *c != '\0'; c++, chars_len++);
    s->ch = (char *) malloc(sizeof(char) * chars_len);
    if (!s->ch) exit(-1);
    s->length = chars_len;
    for (int i = 0; i < chars_len; ++i) {
        s->ch[i] = chars[i];
    }
    return s;
}

//复制串S
MyString *StrCopy(MyString S) {
    MyString *T = (MyString *) malloc(sizeof(MyString));
    if (!T) exit(-1);
    T->length = S.length;
    T->ch = (char *) malloc(sizeof(char) * T->length);
    if (!T->ch) exit(-1);
    for (int i = 0; i < T->length; ++i) {
        T->ch[i] = S.ch[i];
    }
    return T;
}

//判断是否为空串
int StrEmpty(MyString S) {
    return S.length == 0;
}

//返回串长度
int StrLength(MyString S) {
    return S.length;
}

//清空串S使其成为空串
void ClearString(MyString *S) {
    free(S->ch);
    S->ch = (void *) 0;
    S->length = 0;
}

//链接S1,S2生成S3
MyString *Conact(MyString S1, MyString S2) {
    MyString *S3 = (MyString *) malloc(sizeof(MyString));
    if (!S3) exit(-1);
    S3->length = S1.length + S2.length;
    S3->ch = (char *) malloc(sizeof(char) * S3->length);
    if (!S3->ch) exit(-1);
    for (int i1 = 0; i1 < S1.length; ++i1) S3->ch[i1] = S1.ch[i1];
    for (int i2 = 0; i2 < S2.length; ++i2) S3->ch[i2 + S1.length] = S2.ch[i2];
    return S3;
}

//返回S的从pos开始长为len的子串
MyString *SubString(MyString S, int pos, int len) {
    MyString *sub = (MyString *) malloc(sizeof(MyString));
    if (!sub) exit(-1);
    sub->ch = (char *) malloc(sizeof(char) * len);
    if (!sub->ch) exit(-1);
    if (pos + len - 1 > S.length) return (void *) 0;
    sub->length = len;
    for (int i = 0; i < len; ++i) {
        sub->ch[i] = S.ch[pos - 1 + i];
    }
    return sub;
}

//返回T在pos之后第一次出现位置，否则为0
int Index(MyString S, MyString T, int pos) {
    for (int i = pos - 1; i < S.length - T.length + 1; ++i) {
        int count = 0;
        int j = i;
        while (S.ch[j] == T.ch[count]){
            j++;count++;
        }
        if (count == T.length) return i + 1;
    }
    return 0;
}

//不重叠地替换S中所有子串T为V
void Replace(MyString *S, MyString T, MyString V){
}

//从pos个字符开始插入串T
void StrInsert(MyString *S, int pos, MyString T);

//删除从pos开始长len的子串
void StrDelete(MyString *S, int pos, int len);

//销毁S,回收资源
void DestroyString(MyString *S);

//屏幕打印字符串
void show(MyString S) {
    printf("%s,%d\n", S.ch, S.length);
}

