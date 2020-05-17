//
//  Order_List.cpp
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/17.
//  Copyright © 2020 金宸极. All rights reserved.
//

#include "List.hpp"

//MARK: 顺序表

int SqList::ListLength(){
    return length;
}

ElemType SqList::GetElem(int i){
    if (!(i >= 1 && i <= length)) {
        return DEFAULT;
    }
    return data[i - 1];
}

Status SqList::Insert(int i, ElemType e){
    if (i < 1 || i > length + 1) {
        return ERROR;
    } else if (length >= MaxSize) {
        return OVERFLOW;
    }

    for (int index = length; index >= i; index--) {
        data[index] = data[index - 1];
    }

    data[i-1] = e;
    length ++;
    return OK;
}

Status SqList::Delete (int i, ElemType *e){
    if (i < 1 || i > length) {
        return ERROR;
    } else if (length <= 0) {
        return INFEASIBLE;
    }

    (*e) = data[i-1];

    for (int index = i; index < length; index++) {
        data[index-1] = data[index];
    }

    length --;

    return OK;
}


//MARK: 动态分配的顺序表


