//
//  Linked_Queue.cpp
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/17.
//  Copyright © 2020 金宸极. All rights reserved.
//

#include "Stack&Queue.hpp"

//MARK: 单链队列

Status Inital_LinkQueue(LinkQueue *Q){
    QNode *Head = (QNode *)malloc(sizeof(QNode));
    Head->next = NULL;
    Head->data = '\0';     //头结点
    
    (*Q).front = Head;
    (*Q).rear = Head;
    
    return OK;
}

Status isEmpty_LinkQueue(LinkQueue Q){
    return (Q.rear == Q.front);
}

Status EnQueue_LinkQueue(LinkQueue *Q, ElemType e){
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    
    newNode->data = e;
    newNode->next = Q->rear->next;
    
    Q->rear->next = newNode;
    Q->rear = newNode;
    
    return OK;
}

Status DeQueue_LinkQueue(LinkQueue *Q, ElemType *e){
    if (isEmpty_LinkQueue(*Q)) {
        return INFEASIBLE;
    }
    QNode *p = Q->front->next;
    (*e) = p->data;
    
    Q->front->next = p->next;
    
    if (Q->rear == p) {
        Q->rear = Q->front;
    }   //最后一个元素出队，修改尾指针
    
    free(p);
   
    return OK;
}

Status GetHead_LinkQueue(LinkQueue Q, ElemType *e){
    if (isEmpty_LinkQueue(Q)) {
        return ERROR;
    }
    (*e) = Q.front->next->data;
    
    return OK;
}

Status GetTail_LinkQueue(LinkQueue Q, ElemType *e){
    if (isEmpty_LinkQueue(Q)) {
        return ERROR;
    }
    (*e) = Q.rear->data;
    
    return OK;
}
