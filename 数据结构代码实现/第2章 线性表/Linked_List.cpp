//
//  Linked_List.cpp
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/17.
//  Copyright © 2020 金宸极. All rights reserved.
//

#include "List.h"

//MARK: 单链表
Status Inital_LinkList (LinkList *L){
    (*L) = (LNode *)malloc(sizeof(LNode));
    if (!L) {
        return ERROR;
    }
    
    (*L)->next = nullptr;
    (*L)->data = '0';     //头结点可以存储线性表长度
    
    return OK;
}

int ListLength_LinkList(LinkList L){
    //可以直接读取头结点的数据，此处示例一般化情况
    LNode *p = L;
    int Length = 0;
    
    while (p->next != nullptr) {
        Length ++;
        p = p->next;
    }
    
    return Length;
}

Status GetElem_LinkList(LinkList L, int i, ElemType *e){
    if (i <= 0) {
        return INFEASIBLE;
    }
    LNode *p = L;
    
    for (int index = 0; index < i; index ++) {
        if (p->next == nullptr) {
            return OVERFLOW;
        }
        p = p->next;
    }
    
    (*e) = p->data;
    return OK;
}

Status Insert_LinkList(LinkList *L, int i, ElemType e){
    if (i <= 0) {
        return INFEASIBLE;
    }
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    if (!newNode) {
        return ERROR;
    }
    newNode->data = e;
    
    LNode *p = *L;
    for (int index = 1; index < i; index++) {
        if (p->next == nullptr) {
            return OVERFLOW;
        }
        p = p->next;
    }
    
    newNode->next = p->next;
    p->next = newNode;
    (*L)->data++ ; //头结点用于存储线性表长度
    
    return OK;
}

Status Delete_LinkList(LinkList *L, int i, ElemType *e){
    if (i <= 0) {
        return INFEASIBLE;
    }
    
    LNode *p = *L;
    for (int index = 1; index < i; index++) {
        if (p->next == nullptr) {
            return OVERFLOW;
        }
        p = p->next;
    }
    
    LNode *temp = p->next;
    p->next = temp->next;
    (*L)->data--;   //头结点用于存储线性表长度
    
    (*e) = temp->data;
    free(temp);
    
    return OK;
}



//MARK: 双向链表
Status Inital_DoubleLinkList(DoubleLinkList *L){
    DoubleLinkList head = (DoubleLinkList)malloc(sizeof(DNode));
    DoubleLinkList rear  = (DoubleLinkList)malloc(sizeof(DNode));
    if (!head || !rear) {
        return ERROR;
    }
    head->next = rear;
    rear->prior = head;
    
    head->prior = nullptr;
    rear->next = nullptr;
    
    head->data = 0;
    
    *L = head;
    return OK;
}

Status Insert_DoubleLinkList(DoubleLinkList *L, int i, ElemType e){
    DNode *newNode;
    newNode = (DNode *)malloc(sizeof(DNode));
    if (!newNode) {
        return ERROR;
    }
    
    DNode *p = *L;
    for (int index = 1; index < i; index++) {
        if (p->next == nullptr) {
            return OVERFLOW;
        }
        p = p->next;
    }
    
    newNode->data = e;
    newNode->prior = p;
    newNode->next = p->next;
    
    p->next->prior = newNode;
    p->next = newNode;
    (*L)->data ++;

    return  OK;
}

Status Delete_DoubleLinkList(DoubleLinkList *L, int i, ElemType *e){
    if (i <= 0) {
        return INFEASIBLE;
    }
    
    DNode *p = *L;
    for (int index = 1; index < i; index++) {
        if (p->next == nullptr) {
            return OVERFLOW;
        }
        p = p->next;
    }
    
    p->prior->next = p->next;
    p->next->prior = p->prior;
    
    (*e) = p->data;
    free(p);
    (*L)->data --;
    
    return OK;
}




