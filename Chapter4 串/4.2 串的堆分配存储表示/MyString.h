//
// Created by hibian on 3/15/22.
//

#ifndef C_REVIEW_MYSTRING_H
#define C_REVIEW_MYSTRING_H

#endif //C_REVIEW_MYSTRING_H

//参考 p71
typedef struct{
    char *ch;
    int length;
}MyString;

//生成一个其值等于chars的串
MyString* StrAssgin(char* chars);

//复制串S
MyString* StrCopy(MyString S);

//判断是否为空串
int StrEmpty(MyString S);

//返回串长度
int StrLength(MyString S);

//清空串S使其成为空串
void ClearString(MyString *S);

//链接S1,S2生成S3
MyString* Conact(MyString S1,MyString S2);

//返回S的从pos开始长为len的子串
MyString* SubString(MyString S,int pos,int len);

//返回T在pos之后第一次出现位置，否则为0
int Index(MyString S,MyString T,int pos);

//不重叠地替换S中所有子串T为V
void Replace(MyString* S,MyString T,MyString V);

//从pos个字符开始插入串T
void StrInsert(MyString* S,int pos,MyString T);

//删除从pos开始长len的子串
void StrDelete(MyString* S,int pos,int len);

//销毁S,回收资源
void DestroyString(MyString* S);

//屏幕打印字符串
void show(MyString S);

