//
//  Linked_List.cpp
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/17.
//  Copyright © 2020 金宸极. All rights reserved.
//

#include "List.hpp"

//MARK: 单链表
int LinkList::ListLength(){
    return length;
}

ElemType LinkList::GetElem(int i){
    if (i <= 0) {
        return DEFAULT;
    }
    LNode *p = headNode;

    for (int index = 0; index < i; index ++) {
        if (p->next == nullptr) {
            return DEFAULT;
        }
        p = p->next;
    }

    return p->data;
}

Status LinkList::Insert(int i, ElemType e){
    if (i <= 0) {
        return INFEASIBLE;
    }
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    if (!newNode) {
        return ERROR;
    }
    newNode->data = e;

    LNode *p = headNode;
    for (int index = 1; index < i; index++) {
        if (p->next == nullptr) {
            return OVERFLOW;
        }
        p = p->next;
    }
    
    newNode->next = p->next;
    p->next = newNode;
    length ++;
    
    return OK;
}

Status LinkList::Delete(int i, ElemType *e){
    if (i <= 0) {
        return INFEASIBLE;
    }

    LNode *p = headNode;
    for (int index = 1; index < i; index++) {
        if (p->next == nullptr) {
            return OVERFLOW;
        }
        p = p->next;
    }

    LNode *temp = p->next;
    p->next = temp->next;
    length--;

    (*e) = temp->data;
    free(temp);

    return OK;
}



//MARK: 双向链表
int DoubleLinkList::ListLength(){
    return length;
}

ElemType DoubleLinkList::GetElem(int i){
    if (i <= 0) {
        return DEFAULT;
    }
    DNode *p = headNode;

    for (int index = 0; index < i; index ++) {
        if (p->next == rearNode) {
            return DEFAULT;
        }
        p = p->next;
    }

    return p->data;
}

Status DoubleLinkList::Insert(int i, ElemType e){
    DNode *newNode;
    newNode = (DNode *)malloc(sizeof(DNode));
    if (!newNode) {
        return ERROR;
    }

    DNode *p = headNode;
    for (int index = 1; index < i; index++) {
        if (p->next == rearNode) {
            return OVERFLOW;
        }
        p = p->next;
    }

    newNode->data = e;
    newNode->prior = p;
    newNode->next = p->next;

    p->next->prior = newNode;
    p->next = newNode;
    
    length ++;
    
    return  OK;
}

Status DoubleLinkList::Delete(int i, ElemType *e){
    if (i <= 0) {
        return INFEASIBLE;
    }

    DNode *p = headNode;
    for (int index = 1; index < i; index++) {
        if (p->next == rearNode) {
            return OVERFLOW;
        }
        p = p->next;
    }

    p->prior->next = p->next;
    p->next->prior = p->prior;

    (*e) = p->data;
    free(p);
    length--;

    return OK;
}
