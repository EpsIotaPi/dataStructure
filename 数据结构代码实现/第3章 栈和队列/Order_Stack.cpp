//
//  Order_Stack.cpp
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/17.
//  Copyright © 2020 金宸极. All rights reserved.
//

#include "Stack&Queue.hpp"

//MARK: 顺序栈

bool SqStack::isEmpty(){
    return (top == -1);
}

bool SqStack::isFull(){
    return (top == MaxSize - 1);
}

Status SqStack::Push(ElemType e){
    if (isFull()) {
        return OVERFLOW;
    }
    top ++;
    data[top] = e;
    return OK;
}

Status SqStack::Pop(ElemType *e){
    if (isEmpty()) {
        return INFEASIBLE;
    }
    (*e) = data[top];
    top --;
    return OK;
}

ElemType SqStack::GetTop(){
    if (isEmpty()) {
        return DEFAULT;
    }
    return data[top];
}


//MARK: 共享栈

bool ShareStack::isEmpty(int Stack){
    if (Stack == 0) {
        return (Top0 == -1);      //0号栈的判空条件
    }
    return (Top1 == MaxSize);     //1号栈的判空条件
}

bool ShareStack::isFull(){
    return (Top0 + 1 == Top1);
}

Status ShareStack::Push( int Stack, ElemType e){
    if (isFull()) {
        return OVERFLOW;
    }
    
    if (Stack == 0) {
        Top0 ++;
        data[Top0] = e;
    } else {
        Top1 --;
        data[Top1] = e;
    }
    
    return OK;
}

Status ShareStack::Pop(int Stack, ElemType *e){
    if (isEmpty(Stack)) {
        return INFEASIBLE;
    }
    
    if (Stack == 0) {
        (*e) = data[Top0];
        Top0 --;
    } else {
        (*e) = data[Top1];
        Top1 ++;
    }
    
    return OK;
}

ElemType ShareStack::GetTop(int Stack){
    if (isEmpty(Stack)) {
        return DEFAULT;
    }
    
    return (Stack == 0) ? data[Top0] : data[Top1];
}
