//
//  Order_Queue.cpp
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/17.
//  Copyright © 2020 金宸极. All rights reserved.
//

#include "Stack&Queue.hpp"

//MARK: 循环队列


Status Inital_SqQueue(SqQueue *Q){
    (*Q).front = (*Q).rear = 0;
    return OK;
}

bool isEmpty_SqQueue(SqQueue Q){
    return (Q.rear == Q.front);
}

bool isFull_SqQueue(SqQueue Q){
    return (Q.front == (Q.rear + 1) % MaxSize);
}

Status EnQueue_SqQueue(SqQueue *Q, ElemType e){
    if (isFull_SqQueue(*Q)) {
        return OVERFLOW;
    }
    (*Q).data[(*Q).rear] = e;
    (*Q).rear = ((*Q).rear + 1) % MaxSize;
    return OK;
}

Status DeQueue_SqQueue(SqQueue *Q, ElemType *e){
    if (isEmpty_SqQueue(*Q)) {
        return INFEASIBLE;
    }
    (*e) = (*Q).data[(*Q).front];
    (*Q).front = ((*Q).front + 1) % MaxSize;
    return OK;
}

Status GetHead_SqQueue(SqQueue Q, ElemType *e){
    if (isEmpty_SqQueue(Q)) {
        return ERROR;
    }
    (*e) = (Q).data[(Q).front];
    return OK;
}
