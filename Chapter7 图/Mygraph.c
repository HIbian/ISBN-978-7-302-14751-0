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
    scanf("%d %d", &G->vexnum, &G->arcnum);
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
        //插入链表
        edge->ilink = G->vexlist[ivex - 1].firstedge;
        edge->jlink = G->vexlist[jvex - 1].firstedge;
        G->vexlist[ivex - 1].firstedge = G->vexlist[jvex - 1].firstedge = edge;
    }
}

void CreateAMLByData(AMLGraph *G, int vexnum, int arcnum, const int *data, int edge_vex[][3]) {
    G->vexnum = vexnum;
    G->arcnum = arcnum;
    //初始化点
    for (int i = 0; i < G->vexnum; ++i) {
        G->vexlist[i].data = data[i];
        G->vexlist[i].firstedge = NULL;
    }
    //初始化边
    for (int j = 0; j < G->arcnum; ++j) {
        int ivex = edge_vex[j][0];
        int jvex = edge_vex[j][1];
        EBox *edge = (EBox *) malloc(sizeof(EBox));
        edge->jvex = jvex - 1;
        edge->ivex = ivex - 1;
        edge->weight = edge_vex[j][2];
        //插入链表
        edge->ilink = G->vexlist[ivex - 1].firstedge;
        edge->jlink = G->vexlist[jvex - 1].firstedge;
        G->vexlist[ivex - 1].firstedge = G->vexlist[jvex - 1].firstedge = edge;
    }
}

//第一个相邻顶点下标 -1表示没有
int FirstAdjVex(AMLGraph *G, int v) {
    EBox *edge = G->vexlist[v].firstedge;
    if (edge == NULL) {
        return -1;
    }
    //ps:包含了回环情况：若i=v且j=v.返回的值也是v.若不相等返回的是和v不相同的另一个顶点
    return edge->ivex == v ? edge->jvex : edge->ivex;
}

//下一个相邻顶点下标 -1表示没有
int NextAdjVex(AMLGraph *G, int v, int w) {
    EBox *edge = G->vexlist[v].firstedge;
    int i_or_j = 0;//确定v位置0 i 1 j
    while (edge) {
        i_or_j = edge->jvex == v;
        if (i_or_j) {
            //v在j的情况
            if (edge->ivex == w) {
                edge = edge->jlink;
                break;
            }
            edge = edge->jlink;
        } else {
            if (edge->jvex == w) {
                edge = edge->ilink;
                break;
            }
            edge = edge->ilink;
        }
    }
    if (!edge) return -1;
    i_or_j = edge->jvex == v;
    if (i_or_j) return edge->ivex;
    else return edge->jvex;
}

void DFSTraverse(AMLGraph *G) {
    int visited[MAX_VERTEX] = {0};
    for (int v = 0; v < G->vexnum; ++v) {
        if (!visited[v]) DFS(G, v, visited);
    }
}

void DFS(AMLGraph *G, int v, int visited[]) {
    visited[v] = 1;
    printf("%d->", G->vexlist[v].data);
    for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)) {
        if (!visited[w]) DFS(G, w, visited);
    }
}