//
// Created by hibian on 3/22/22.
//

#include "MyBinaryTree.h"
#include "stdio.h"

int main() {
    int def[] = {11, 1, 2, 3, 4, 5, 0, 0, 0, 0, 6, 7};
    MyBiTree *T = InitBiTree();
    CreateBiTree(T, def, 1);
    PreOrderTraverse(T);

    /*
     * 使用工具查看是否内存泄露
     * valgrind --tool=memcheck --leak-check=full ./6.2
     * 输出：
     * ==6736== HEAP SUMMARY:
     * ==6736==     in use at exit: 0 bytes in 0 blocks
     * ==6736==   total heap usage: 8 allocs, 8 frees, 1,192 bytes allocated
     * ==6736==
     * ==6736== All heap blocks were freed -- no leaks are possible
     * ==6736==
     * ==6736== For lists of detected and suppressed errors, rerun with: -s
     * ==6736== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)*
     */
    DestroyBiTree(T);
}

