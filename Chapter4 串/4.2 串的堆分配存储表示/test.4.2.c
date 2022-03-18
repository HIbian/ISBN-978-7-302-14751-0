//
// Created by hibian on 3/15/22.
//

#include "MyString.h"
#include "stdio.h"

int main() {
    MyString *s = StrAssgin("abc");
    show(*s);
    MyString *t = StrCopy(*s);
    show(*t);
    MyString *s3 = Conact(*s, *t);
    show(*s3);
    MyString *sub = SubString(*s3, 3, 3);
    show(*sub);

    MyString *i1 = StrAssgin("abcdefgh");
    MyString *temp = StrAssgin("gh");
    show(*i1);
    show(*temp);
    int index = Index(*i1, *temp, 1);
    printf("pos is : %d\n", index);
    printf("test replace\n");
    MyString *str1 = StrAssgin("12232278226");
    MyString *str2 = StrAssgin("22");
    MyString *str3 = StrAssgin("888");
    show(*str1);
    show(*str2);
    show(*str3);
    Replace(str1, *str2, *str3);
    show(*str1);
    printf("test replace 2\n");
    MyString *str11 = StrAssgin("ssiiadlsksiidwdnlzlxcasiisadlkwdljlasiicalsalksjdiiasdljlqwjdiilaksjdlkjxzcaii");
    MyString *str22= StrAssgin("ii");
    MyString *str33 = StrAssgin("OOOOO");
    show(*str11);
    show(*str22);
    show(*str33);
    Replace(str11, *str22, *str33);
    show(*str11);

    //insert
    MyString *insert = StrAssgin("how you");
    MyString *in = StrAssgin("are ");
    StrInsert(insert,5,*in);
    show(*insert);

    //delete
    StrDelete(insert,5,4);
    show(*insert);

    //kmp
    MyString *kmp_s = StrAssgin("abababababaaababaabcdiaadbos");
    MyString *kmp_t = StrAssgin("abaabc");
    printf("%d\n", KMPIndex(*kmp_s,*kmp_t,0));
}