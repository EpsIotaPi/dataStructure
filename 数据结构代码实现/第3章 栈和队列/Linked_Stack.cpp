//
//  Linked_Stack.cpp
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/17.
//  Copyright © 2020 金宸极. All rights reserved.
//

#include "Stack&Queue.hpp"

//MARK:链栈

Status Inital_LinkStack(LinkStack *S){
    (*S) = (SNode *)malloc(sizeof(SNode));
    (*S)->next = NULL;
    (*S)->data = '0';     //头结点
    return OK;
}

Status isEmpty_LinkStack(LinkStack S){
    return (S->next == NULL);
}

Status Push_LinkStack(LinkStack *S, ElemType e){
    SNode *newNode = (SNode *)malloc(sizeof(SNode));
    newNode->data = e;
    
    newNode->next = (*S)->next;
    (*S)->next = newNode;
    return OK;
}

Status Pop_LinkStack(LinkStack *S, ElemType *e){
    if (isEmpty_LinkStack(*S)) {
        return INFEASIBLE;
    }
    SNode *p = (*S)->next;
    (*e) = p->data;
        
    (*S)->next = p->next;
    free(p);
    return OK;
}

Status GetTop_LinkStack(LinkStack S, ElemType *e){
    if (isEmpty_LinkStack(S)) {
        return ERROR;
    }
    (*e) = S->next->data;
    return OK;
}
