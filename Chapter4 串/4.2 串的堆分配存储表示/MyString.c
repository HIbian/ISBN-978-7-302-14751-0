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
        while (S.ch[j] == T.ch[count] && S.ch[j] != '\0') {
            j++;
            count++;
        }
        if (count == T.length) return i + 1;
    }
    return 0;
}

//不重叠地替换S中所有子串T为V
typedef struct array {
    int pos;
    int number;
    struct array *next;
} LinkedArrary;

void Replace(MyString *S, MyString T, MyString V) {
    //找到有几处需要替换，确定最终字符串长度
    LinkedArrary *head = (LinkedArrary *) malloc(sizeof(LinkedArrary));
    head->pos = 0;
    head->number = 0;
    head->next = NULL;
    LinkedArrary *p = head;
    int pos = 1;
    int count = 0;
    while (pos = Index(*S, T, pos)) {
        p->next = (LinkedArrary *) malloc(sizeof(LinkedArrary));
        p = p->next;
        p->pos = pos;
        pos += T.length;
        p->number = ++count;
    }
    int offset = V.length - T.length;
    int length = S->length + offset * count;
    char *chars = (char *) malloc(sizeof(char) * length);
    p = head->next;
    int end = 0;
    for (int i = 0; i < length; ++i) {
        if (i < (p->number - 1) * offset + p->pos - 1 || i >= (p->number - 1) * offset + p->pos - 1 + V.length) {
            chars[i] = S->ch[i - offset * (p->number - 1)];
        } else if (end) {
            chars[i] = S->ch[i - offset * end];
        } else {
            chars[i] = V.ch[i - ((p->number - 1) * offset + p->pos - 1)];
            if (i - ((p->number - 1) * offset + p->pos - 1) == V.length - 1) {
                if (p->next) p = p->next;
                else {
                    end = p->number++;
                }
            }
        }
    }
    free(S->ch);
    S->ch = chars;
    S->length = length;
}

//从pos个字符开始插入串T
void StrInsert(MyString *S, int pos, MyString T) {
    char *chs = (char *) malloc(sizeof(char) * (S->length + T.length));
    if (!chs) exit(-1);
    int i = 0;
    while (i < pos - 1) {
        chs[i] = S->ch[i];
        i++;
    }
    while (i - pos + 1 < T.length) {
        chs[i] = T.ch[i - pos + 1];
        i++;
    }
    while (i < S->length + T.length) {
        chs[i] = S->ch[i - T.length];
        i++;
    }
    free(S->ch);
    S->ch = chs;
    S->length = S->length + T.length;
}

//删除从pos开始长len的子串
void StrDelete(MyString *S, int pos, int len) {
    if (S->length - len < 0) exit(-1);
    char *chs = (char *) malloc(sizeof(char) * (S->length - len));
    if (!chs) exit(-1);
    int i = 0;
    while (i < pos - 1) {
        chs[i] = S->ch[i];
        i++;
    }
    while (i < S->length - len) {
        chs[i] = S->ch[i + len];
        i++;
    }
    S->length = S->length - len;
    free(S->ch);
    S->ch = chs;
}

//销毁S,回收资源
void DestroyString(MyString *S) {
    free(S->ch);
    free(S);
}

//屏幕打印字符串
void show(MyString S) {
    printf("%s,%d\n", S.ch, S.length);
}

int *getNext(MyString S) {
    int *next = (int *) malloc(sizeof(int) * S.length);
    int i = 0;
    next[0] = -1;
    int j = -1;
    while (i < S.length) {
        if (j == -1 || S.ch[i] == S.ch[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    return next;
}

int KMPIndex(MyString S, MyString T, int pos) {
    //pos>=1,but MyString index begins at zero.
    int *next = getNext(T);
    int j = 0;
    int i = pos - 1;
    while (i<S.length && j<T.length){
        if(j == -1 || S.ch[i] == T.ch[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(j == T.length){
        return i - j +1;
    }
    return 0;
}