//
//  Travelsal.cpp
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/19.
//  Copyright © 2020 金宸极. All rights reserved.
//

#include "Graph.hpp"
#include <stack>
#include <queue>

//MARK: 邻接矩阵的遍历



//MARK: 邻接表的遍历

void ALGraph::DFS(void (*visit)(VexNode)){
    bool visited[MaxSize];
    fill(visited, visited + VexNum, false);
    
    stack<int> S;
    for (int i = 0; i < VexNum; i++) {
        S.push(i);
        while (!S.empty()) {
            int k = S.top();
            S.pop();
            if (!visited[k]) {
                visit(Vex[k]);
                visited[k] = true;
                ArcNode *P = Vex[k].first;
                while (P) {
                    S.push(P->adjVex);
                    P = P->next;
                }
            }
        }
    }

    return;
}

void ALGraph::BFS(void (*visit)(VexNode)){
    bool visited[MaxSize];
    fill(visited, visited + VexNum, false);
    
    queue<int> Q;
    for (int i = 0; i < VexNum; i++) {
        Q.push(i);
        while (!Q.empty()) {
            int k = Q.front();
            Q.pop();
            if (!visited[k]) {
                visit(Vex[k]);
                visited[k] = true;
                ArcNode *P = Vex[k].first;
                while (P) {
                    Q.push(P->adjVex);
                    P = P->next;
                }
            }
        }
    }
    return;
}

