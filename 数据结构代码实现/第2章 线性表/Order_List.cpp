//
//  Order_List.cpp
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/17.
//  Copyright © 2020 金宸极. All rights reserved.
//

#include "List.hpp"

//MARK:- 顺序表
Status Inital_SqList(SqList *L){
    L->length = 0;
    return OK;
}

int ListLength_SqList(SqList L){
    return L.length;
}

Status GetElem_SqList(SqList L, int i, ElemType *e){
    if (!(i >= 1 && i <= L.length)) {
        return INFEASIBLE;
    }
    (*e) = L.data[i - 1];   //数组下标 = 线性表位序 - 1
    return OK;
}   //读取指定元素，O(1)


Status Insert_SqList (SqList *L, int i, ElemType e){
    if (i < 1 || i > (*L).length + 1) {
        return ERROR;
    } else if (ListLength_SqList(*L) >= MaxSize) {
        return OVERFLOW;
    }
    
    for (int index = (*L).length; index >= i; index--) {
        (*L).data[index] = (*L).data[index - 1];
    }
    
    (*L).data[i-1] = e;
    (*L).length ++;
    
    return OK;
}


Status Delete_SqList (SqList *L, int i, ElemType *e){
    if (i < 1 || i > (*L).length) {
        return ERROR;
    } else if (ListLength_SqList(*L) <= 0) {
        return INFEASIBLE;
    }
    
    (*e) = (*L).data[i-1];
    
    for (int index = i; index < (*L).length; index++) {
        (*L).data[index-1] = (*L).data[index];
    }
    
    (*L).length --;
    
    return OK;
}  //删除操作，O(n)


//MARK: 动态分配的顺序表
Status Inital_DqList (DqList *L){
    (*L).data = (ElemType *)malloc(sizeof(ElemType) * MaxSize);
    (*L).length = 0;
    (*L).MaxLength = MaxSize;
    return OK;
}


