//
//  Order_Stack.cpp
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/17.
//  Copyright © 2020 金宸极. All rights reserved.
//

#include "Stack&Queue.hpp"

//MARK:- 顺序栈

Status Inital_SqStack(SqStack *S){
    (*S).top = -1;
    return OK;
}

bool isEmpty_SqStack(SqStack S){
    return (S.top == -1);
}

bool isFull_SqStack(SqStack S){
    return (S.top == MaxSize - 1);
}

Status Push_SqStack(SqStack *S, ElemType e){
    if (isFull_SqStack(*S)) {
        return OVERFLOW;
    }
    (*S).top ++;
    (*S).data[(*S).top] = e;
    return OK;
}

Status Pop_SqStack(SqStack *S, ElemType *e){
    if (isEmpty_SqStack(*S)) {
        return INFEASIBLE;
    }
    (*e) = (*S).data[(*S).top];
    (*S).top --;
    return OK;
}

Status GetTop_SqStack(SqStack S, ElemType *e){
    if (isEmpty_SqStack(S)) {
        //TODO: 是否考虑修改返回值
        return ERROR;
    }
    (*e) = S.data[S.top];
    return OK;
}


//MARK:- 共享栈

Status Inital_ShareStack(ShareStack *S){
    S->Top0 = -1;
    S->Top1 = MaxSize;
    
    return OK;
}

bool isEmpty_ShareStack(ShareStack S, int Stack){
    if (Stack == 0) {
        return (S.Top0 == -1);      //0号栈的判空条件
    }
    return (S.Top1 == MaxSize);     //1号栈的判空条件
}

bool isFull_ShareStack(ShareStack S){
    return (S.Top0 + 1 == S.Top1);
}

Status Push_ShareStack(ShareStack *S, int Stack, ElemType e){
    if (isFull_ShareStack(*S)) {
        return OVERFLOW;
    }
    
    if (Stack == 0) {
        S->Top0 ++;
        S->data[S->Top0] = e;
    } else {
        S->Top1 --;
        S->data[S->Top1] = e;
    }
    
    return OK;
}

Status Pop_ShareStack(ShareStack *S, int Stack, ElemType *e){
    if (isEmpty_ShareStack(*S, Stack)) {
        return INFEASIBLE;
    }
    
    if (Stack == 0) {
        (*e) = S->data[S->Top0];
        S->Top0 --;
    } else {
        (*e) = S->data[S->Top1];
        S->Top1 ++;
    }
    
    return OK;
}

Status GetTop_ShareStack(ShareStack *S, int Stack, ElemType *e){
    if (isEmpty_ShareStack(*S, Stack)) {
        return INFEASIBLE;
    }
    
    if (Stack == 0) {
        (*e) = S->data[S->Top0];
    } else {
        (*e) = S->data[S->Top1];
    }
    
    return OK;
}
