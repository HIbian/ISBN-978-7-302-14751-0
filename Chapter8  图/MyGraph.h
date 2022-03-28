#include <stdlib.h>

#define MAX_VERTEX 20
//邻接表
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
    int weight;
}ArcNode;

typedef struct VNode {
    int data;
    ArcNode *firstarc;
}VNode;

typedef struct {
    VNode vertices[MAX_VERTEX];
    int vexnum,arcnum;
    int kind;
}ALGraph;

//十字链表


//邻接多重表
