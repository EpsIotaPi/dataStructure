//
//  Linked_Stack.cpp
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/17.
//  Copyright © 2020 金宸极. All rights reserved.
//

#include "Stack&Queue.hpp"

//MARK: 链栈
bool LinkStack::isEmpty(){
    return (headNode->next == nullptr);
}

Status LinkStack::Push(ElemType e){
    SNode *newNode = (SNode *)malloc(sizeof(SNode));
    newNode->data = e;
    
    newNode->next = headNode->next;
    headNode->next = newNode;
    return OK;
}

Status LinkStack::Pop(ElemType *e){
    if (isEmpty()) {
        return INFEASIBLE;
    }
    SNode *p = headNode->next;
    (*e) = p->data;
        
    headNode->next = p->next;
    free(p);
    return OK;
}

Status LinkStack::GetTop(ElemType *e){
    if (isEmpty()) {
        return DEFAULT;
    }
    return headNode->next->data;
}
