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
