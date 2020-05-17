//
//  Order_Queue.cpp
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/17.
//  Copyright © 2020 金宸极. All rights reserved.
//

#include "Stack&Queue.hpp"

//MARK: 循环队列

bool SqQueue::isEmpty(){
    return (rear == front);
}

bool SqQueue::isFull(){
    return (front == (rear + 1) % MaxSize);
}

Status SqQueue::EnQueue(ElemType e){
    if (isFull()) {
        return OVERFLOW;
    }
    data[rear] = e;
    rear = (rear + 1) % MaxSize;
    return OK;
}

Status SqQueue::DeQueue(ElemType *e){
    if (isEmpty()) {
        return INFEASIBLE;
    }
    (*e) = data[front];
    front = (front + 1) % MaxSize;
    return OK;
}

ElemType SqQueue::GetHead(){
    if (isEmpty()) {
        return DEFAULT;
    }
    return data[front];
}

ElemType SqQueue::GetTail(){
    if (isEmpty()) {
        return DEFAULT;
    }
    return data[(rear - 1 + MaxSize) % MaxSize];
}
