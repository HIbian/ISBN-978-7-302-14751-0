//
// Created by hibian on 3/30/22.
//

#include "MyGraph.h"
#include "stdio.h"

int main(){
    OLGraph *G = (OLGraph *) malloc(sizeof(OLGraph));
    /*
     * 测试为五个顶点八条边的有向图
     * 5 8
     * 1 2 3 4 5
     * 1 2
     * 1 4
     * 1 5
     * 2 3
     * 2 5
     * 3 1
     * 3 4
     * 5 3
     * 通过debug和画图验证数据正确性
     * https://cdn.jsdelivr.net/gh/HIbian/MyStaticResources/202203301641025.jpg
     */
    CreateDG(G);
    printf("%d %d",G->vexnum,G->arcnum);
}