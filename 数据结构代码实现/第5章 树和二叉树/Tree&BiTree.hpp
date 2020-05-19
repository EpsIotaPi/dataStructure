//
//  Tree&BiTree.hpp
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/17.
//  Copyright © 2020 金宸极. All rights reserved.
//

#ifndef Tree_BiTree_hpp
#define Tree_BiTree_hpp

#include "Basic.hpp"

//MARK: 二叉树

typedef struct BiTNode{
    ElemType data;
    BiTNode *lchild, *rchild;
    
}*BiTree;
void print(BiTree T);

/// 根据给定序列创建二叉树，【例】124##5##36###
/// @param T 生成的二叉树
void Create(BiTree *T);

void PerOrder(BiTree T, void (*visit)(BiTree));

void InOrder(BiTree T, void (*visit)(BiTree));

void PostOrder(BiTree T, void (*visit)(BiTree));

void InOrder_Stack(BiTree T, void (*visit)(BiTree));

/// 层次遍历二叉树，借助队列实现
/// @param T 二叉树
void LevelOrder(BiTree T, void (*visit)(BiTree));


int WPL(BiTree root, int n);

#endif /* Tree&BiTree_hpp */
