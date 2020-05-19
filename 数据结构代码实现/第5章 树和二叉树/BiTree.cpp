//
//  BiTree.cpp
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/17.
//  Copyright © 2020 金宸极. All rights reserved.
//

#include "Tree&BiTree.hpp"

void Create(BiTree *T){
    ElemType c;
    scanf("%c",&c);

    if (c == '#') {
        (*T) = nullptr;
        return;
    }
    
    (*T) = (BiTree)malloc(sizeof(BiTNode));
    (*T)->data = c;
    Create(&(*T)->lchild);
    Create(&(*T)->rchild);
    return;
}


int WPL(BiTree root, int n){

    if (!root->lchild && !root->rchild) {
        int y = (root->data - '0') * n;

        return y;
    }
    int x = WPL(root->lchild, n+1) + WPL(root->rchild, n+1);

    return x;
}

