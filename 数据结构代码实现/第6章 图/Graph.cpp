//
//  Graph.cpp
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/18.
//  Copyright © 2020 金宸极. All rights reserved.
//

#include "Graph.hpp"

// MARK: 邻接矩阵表示法
Status MGraph::InsertVex(ElemType e){
    if (VexNum >= MaxSize) {
        return OVERFLOW;
    }
    vex[VexNum] = e;
    for (int i = 0; i <= VexNum; i++) {
        arc[VexNum][i] = arc[i][VexNum] = 0;
    }
    VexNum ++;
    return OK;
}

//FIXME: 没有处理后续的弧
//Status MGraph::DeleteVex(int v){
//    if (VexNum < v || v <= 0) {
//        return INFEASIBLE;
//    }
//    for (int i = v; i < VexNum - 2; i++) {
//        vex[i] = vex[i + 1];
//    }
//    for (int i = 0; i <= VexNum; i++) {
//        arc[VexNum][i] = arc[i][VexNum] = 0;
//    }
//
//    return OK;
//}


Status MGraph::InsertArc(int v, int w, int weight){
    if (max(v, w) + 1 > VexNum) {
        return INFEASIBLE;
    }
    
    arc[v][w] = weight;
    ArcNum ++;
    return OK;
}


Status MGraph::DeleteArc(int v, int w, int *weight){
    if (max(v, w) + 1 > VexNum || arc[v][w] == 0) {
        return INFEASIBLE;
    }
    (*weight) = arc[v][w];
    arc[v][w] = 0;
    ArcNum --;
    return OK;
}


// MARK: 邻接表表示法


Status ALGraph::InsertVex(ElemType e){
    if (VexNum >= MaxSize) {
        return OVERFLOW;
    }
    Vex[VexNum].data = e;
    Vex[VexNum].first = nullptr;

    VexNum ++;
    return OK;
}

//FIXME: 没有删除以此为弧尾的弧
Status ALGraph::DeleteVex(int v){
    if (VexNum < v || v <= 0) {
        return INFEASIBLE;
    }
    ArcNode *P = Vex[v].first;
    while (P) {
        ArcNode *temp = P->next;
        free(P);
        P = temp;
    }
    while (v < VexNum) {
        Vex[v] = Vex[v + 1];
        v++;
    }
    VexNum --;
    return OK;
}


Status ALGraph::InsertArc(int v, int w, int weight){
    if (max(v, w) + 1 > VexNum) {
        return INFEASIBLE;
    }

    ArcNode *newArc = (ArcNode *)malloc(sizeof(ArcNode));
    newArc->adjVex = w;
    newArc->next = Vex[w].first;
    Vex[w].first = newArc;
    
    ArcNum ++;
    return OK;
}


Status ALGraph::DeleteArc(int v, int w, int *weight){
    if (max(v, w) + 1 > VexNum) {
        return INFEASIBLE;
    }
    ArcNode *P = Vex[v].first;
    while (P && P->adjVex != w) {
        P = P->next;
    }
    if (!P) {
        return INFEASIBLE;
    }
    (* weight) = P->weight;
    if (P->next) {
        P->adjVex = P->next->adjVex;
        P->weight = P->next->weight;
    }
    ArcNode *temp = P->next;
    P->next = temp->next;
    free(temp);
    
    ArcNum --;
    return OK;
}
