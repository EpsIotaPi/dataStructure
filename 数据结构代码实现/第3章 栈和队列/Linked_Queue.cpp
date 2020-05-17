//
//  Linked_Queue.cpp
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/17.
//  Copyright © 2020 金宸极. All rights reserved.
//

#include "Stack&Queue.hpp"

Status LinkQueue::isEmpty(){
    return (rear == front);
}

Status LinkQueue::EnQueue(ElemType e){
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    
    newNode->data = e;
    newNode->next = rear->next;
    
    rear->next = newNode;
    rear = newNode;
    
    return OK;
}

Status LinkQueue::DeQueue(ElemType *e){
    if (isEmpty()) {
        return INFEASIBLE;
    }
    QNode *p = front->next;
    (*e) = p->data;
    
    front->next = p->next;
    
    if (rear == p) {
        rear = front;
    }   //最后一个元素出队，修改尾指针
    
    free(p);
   
    return OK;
}

Status LinkQueue::GetHead(){
    if (isEmpty()) {
        return DEFAULT;
    }
    return front->next->data;
}

Status LinkQueue::GetTail(){
    if (isEmpty()) {
        return DEFAULT;
    }
    return rear->data;
}
