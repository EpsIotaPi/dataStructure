//
//  Traversal&Thread.cpp
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/18.
//  Copyright © 2020 金宸极. All rights reserved.
//

#include "Tree&BiTree.hpp"
#include <stack>
#include <queue>


//MARK: Traversal

void print(BiTree T){
    printf("%c", T->data);
}

void PerOrder (BiTree T, void (*visit)(BiTree)){
    if(T == NULL) {
        return;
    }
    visit(T);                    //访问结点
    PerOrder(T->lchild, visit);  //先序遍历左子树
    PerOrder(T->rchild, visit);  //最后，先序遍历右子树
}

void InOrder(BiTree T, void (*visit)(BiTree)){
    if(T == NULL) {
        return;
    }
    InOrder(T->lchild, visit);  //中序遍历左子树
    visit(T);                   //访问结点
    InOrder(T->rchild, visit);  //最后，中序遍历右子树
}

void PostOrder(BiTree T, void (*visit)(BiTree)){
    if(T == NULL) {
        return;
    }
    PostOrder(T->lchild, visit);  //后序遍历左子树
    PostOrder(T->rchild, visit);  //后序遍历右子树
    visit(T);                     //最后，访问结点
}

void InOrder_Stack(BiTree T, void (*visit)(BiTree)){
    stack<BiTree> S;
    S.push(T);
    while (!S.empty()) {
        BiTNode *P;
        P = S.top();
        S.pop();
        if (P) {
            visit(P);
            S.push(P->rchild);
            S.push(P->lchild);
        }
    }
    return;
}

void LevelOrder(BiTree T, void (*visit)(BiTree)){
    queue<BiTree> Q;

    BiTree p;
    
    Q.push(T);
    
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        visit(p);
        if (p->lchild != NULL) {
            Q.push(p->lchild);
        }
        if (p->rchild != NULL) {
            Q.push(p->rchild);
        }
    }
}
