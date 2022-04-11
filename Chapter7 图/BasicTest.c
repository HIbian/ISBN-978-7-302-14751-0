//
// Created by hibian on 3/30/22.
//

#include "MyGraph.h"
#include "stdio.h"

void testCreateAMLByData();

void testCreateAML();

void testCreateDG();

void testPrimeMST();

int main() {
    //测试十字链表创建
//    testCreateDG();

    //测试邻接多重标创建(手动输入)
//    testCreateAML();

    //测试邻接多重标创建(通过参数)
//    testCreateAMLByData();

    //测试Prim算法生成MST
    testPrimeMST();
}

void testPrimeMST() {
    //构造教材p174中图7.16的无向图
    AMLGraph *aml = (AMLGraph *) malloc(sizeof(AMLGraph));
    int vex_data[6] = {1, 2, 3, 4, 5, 6};
    int edge_vex[10][3] = {
            {1, 2, 6},
            {1, 3, 1},
            {1, 4, 5},
            {2, 3, 5},
            {2, 5, 3},
            {3, 4, 5},
            {3, 5, 6},
            {3, 6, 4},
            {4, 6, 2},
            {5, 6, 6},
    };
    CreateAMLByData(aml, 6, 10, vex_data, edge_vex);
    printf("%d %d\n", aml->vexnum, aml->arcnum);
    MST_Prim(aml);
}

void testCreateDG() {
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
    printf("%d %d", G->vexnum, G->arcnum);
}

void testCreateAML() {/*
 * 测试输入数据
 * https://cdn.jsdelivr.net/gh/HIbian/MyStaticResources/202203311506913.jpeg
 */
    AMLGraph *amlGraph = (AMLGraph *) malloc(sizeof(AMLGraph));
    CreateAML(amlGraph);
    printf("%d %d", amlGraph->vexnum, amlGraph->arcnum);
}

void testCreateAMLByData() {
    AMLGraph *aml = (AMLGraph *) malloc(sizeof(AMLGraph));
    int data[5] = {1, 2, 3, 4, 5};
    int edge_vex[6][3] = {
            {1, 2, 0},
            {1, 4, 0},
            {2, 3, 0},
            {3, 4, 0},
            {2, 5, 0},
            {3, 5, 0}
    };
    CreateAMLByData(aml, 5, 6, data, edge_vex);
    printf("%d %d\n", aml->vexnum, aml->arcnum);

    //深度优先遍历
    DFSTraverse(aml);
}
