//
//  Graph.hpp
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/18.
//  Copyright © 2020 金宸极. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include "Basic.hpp"

//MARK: 邻接矩阵表示法
struct MGraph{
private:
    ElemType vex[MaxSize];
    int arc[MaxSize][MaxSize];  //对于有向图，arc[i][j]表示从i到j的弧
    int VexNum, ArcNum;
public:
    MGraph(){
        VexNum = ArcNum = 0;
    }
    
    /// 增加一个顶点
    /// @param e 顶点保存的元素
    Status InsertVex(ElemType e);
    
    Status DeleteVex(int v);
    
    /// 增加一条有向弧 <v, w>
    /// @param v 起始顶点
    /// @param w 结束顶点
    /// @param weight 弧的权值
    Status InsertArc(int v, int w, int weight);
    
    /// 删除一条有向弧 <v, w>
    /// @param v 起始顶点
    /// @param w 结束顶点
    /// @param weight 用于返回弧权值
    Status DeleteArc(int v, int w, int *weight);
    
    void DFS(void (*visit)(int));

    void BFS(void (*visit)(int));
};

//MARK:邻接表表示法
// 弧结点
struct ArcNode{
    int adjVex;         //邻接结点的位置
    int weight;         //边的权值，无权图可以不使用
    ArcNode *next;
};

// 顶点结点
typedef struct VexNode{
    ElemType data;      //顶点信息
    ArcNode *first;     //邻接结点链表
}VexList[MaxSize];

// 顶点表
struct ALGraph{
private:
    VexList Vex;
    int VexNum, ArcNum;
public:
    ALGraph(){
        VexNum = ArcNum = 0;
    }
    
    /// 增加一个顶点
    /// @param e 顶点保存的元素
    Status InsertVex(ElemType e);
    
    /// 删除一个顶点，和所有邻接的弧
    /// @param v 删除顶点
    Status DeleteVex(int v);
    
    /// 增加一条有向弧 <v, w>
    /// @param v 起始顶点
    /// @param w 结束顶点
    /// @param weight 弧的权值
    Status InsertArc(int v, int w, int weight);
    
    /// 删除一条有向弧 <v, w>
    /// @param v 起始顶点
    /// @param w 结束顶点
    /// @param weight 用于返回弧权值
    Status DeleteArc(int v, int w, int *weight);
    
    //TODO: Add Doc
    void DFS(void (*visit)(VexNode));

    void BFS(void (*visit)(VexNode));
};


////有向图的顺序链式混合存储结构（十字链表表示法）
//// 弧结点
//typedef struct ArcNode {
//    int tailVex, headVex;           //邻接结点的位置
//    struct ArcNode *hlink, *tlink; //下一个与这条弧有相同邻接的弧的位置
//    int weight;                       //边的权值，无权图可以不使用
//} ArcNode;
//
//// 顶点结点
//typedef struct VexNode {
//    ElemType data;     //顶点信息
//    ArcNode *firstIn;  //对应弧头（head）
//    ArcNode *firstOut; //对应弧尾（tail）
//} VexNode, VexList[MaxSize];
//
//// 顶点表
//typedef struct {
//    VexList Vex;
//    int VexNum, ArcNum;
//} OLGraph;

////无向图的顺序链式混合存储结构（邻接多重表表示法）
//// 边结点
//typedef struct EdgeNode {
//    int iVex, jVex;                    //分别指示该边依附的两个顶点在线性表中的位置
//    struct EdgeNode *ilink, *jlink; //指示依附于 i/j 顶点的下一边结点
//    int mark;                        //标志域，标记遍历时是否被搜索过
//    int weight;                        //边的权值，无权图可以不使用
//} EdgeNode;
//
//// 顶点结点
//typedef struct VexNode {
//    ElemType data;   //顶点信息
//    EdgeNode *first; //邻接结点链表
//} VexNode, VexList[MaxSize];
//
//// 顶点表
//typedef struct {
//    VexList Vex;
//    int VexNum, EdgeNum; //弧数，边数
//} AMLGraph;
//
//



#endif /* Graph_hpp */
