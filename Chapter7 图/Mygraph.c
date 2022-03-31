//
// Created by hibian on 3/30/22.
//

#include "MyGraph.h"
#include "stdio.h"
#include "stdlib.h"

int CreateDG(OLGraph *G) {
    scanf("%d %d ", &G->vexnum, &G->arcnum);
    for (int i = 0; i < G->vexnum; ++i) {
        scanf("%d", &G->vexNodes[i].data);
        G->vexNodes->firstin = NULL;
        G->vexNodes->firstout = NULL;
    }
    for (int j = 0; j < G->arcnum; ++j) {
        //弧尾，弧头顶点
        int tv, hv;
        scanf("%d %d", &tv, &hv);
        VexNode *tailVex = &G->vexNodes[tv - 1];
        VexNode *headVex = &G->vexNodes[hv - 1];
        ArcBox *arc = (ArcBox *) malloc(sizeof(ArcBox));
        arc->tailvex = tv;
        arc->headvex = hv;
        //插入尾顶点尾指针链表
        arc->tlink = tailVex->firstout;
        tailVex->firstout = arc;
        //插入头顶点头指针链表
        arc->hlink = headVex->firstin;
        headVex->firstin = arc;
    }
}

void CreateAML(AMLGraph *G) {
    scanf("%d %d", &G->arcnum, &G->vexnum);
    //初始化点
    for (int i = 0; i < G->vexnum; ++i) {
        scanf("%d", &G->vexlist[i].data);
        G->vexlist[i].firstedge = NULL;
    }
    //初始化边
    for (int j = 0; j < G->arcnum; ++j) {
        int ivex, jvex;
        scanf("%d %d", &ivex, &jvex);
        if (ivex > G->vexnum || jvex > G->vexnum) {
            printf("输入不合法\n");
            j--;
            continue;
        }
        EBox *edge = (EBox *) malloc(sizeof(EBox));
        edge->jvex = jvex - 1;
        edge->ivex = ivex - 1;
        edge->weight = 0;
        edge->ilink = G->vexlist[ivex-1].firstedge;
        edge->jlink = G->vexlist[jvex-1].firstedge;
    }

}