//
//  List.h
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/17.
//  Copyright © 2020 金宸极. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include "Basic.hpp"

//MARK:- 线性表的顺序存储



//MARK: 顺序表
struct SqList{
private:
    ElemType data[MaxSize];
    int length;

public:
    SqList(){
        length = 0;
    }
    /// 返回顺序表长，时间复杂度 O(1)
    int ListLength();
    
    /// 读取顺序表指定位置的元素，时间复杂度 O(1)
    /// @param i 指定位置，1 <= i <= L.length
    ElemType GetElem(int i);
    
    /// 在顺序表指定为位置插入元素，时间复杂度 O(n)
    /// @param i 指定位置，1 <= i <= L.length
    /// @param e 插入的元素
    Status Insert(int i, ElemType e);
    
    /// 删除顺序表指定位置的元素，时间复杂度 O(n)
    /// @param i 指定位置，1 <= i <= L.length
    /// @param e 用于返回删除元素的变量
    Status Delete (int i, ElemType *e);
};

//MARK: 动态分配的顺序表
#define Increas 10
struct DqList{
private:
    ElemType *data;
    int length;
    int MaxLength;
public:
    DqList(){
        data = (ElemType *)malloc(sizeof(ElemType) * MaxSize);
        length = 0;
        MaxLength = MaxSize;
    }
};



//MARK:- 线性表的链式存储



//MARK: 单链表
struct LNode{
    ElemType data;      //数据域
    LNode *next; //指针域
};

struct LinkList{
private:
    int length;
    LNode *headNode;
public:
    LinkList(){
        headNode = (LNode *)malloc(sizeof(LNode));
        if (!headNode) {
            return;
        }
        
        headNode->next = nullptr;
        length = 0;
    }
    
    /// 求单链表表长，时间复杂度 O(n)
    int ListLength();
    
    /// 读取单链表指定位置元素，时间复杂度 O(n)
    /// @param i 指定位置，1 <= i <= L.length
    ElemType GetElem(int i);
    
    /// 在单链表指定位置插入元素，时间复杂度 O(1)
    /// @param i 指定位置，1 <= i <= L.length
    /// @param e 需要插入的元素
    Status Insert(int i, ElemType e);
    
    /// 删除单链表指定位置的元素，时间复杂度 O(1)
    /// @param i 指定位置，1 <= i <= L.length
    /// @param e 返回删除元素的存储变量
    Status Delete(int i, ElemType *e);
};



   //删除操作，O(1)

//MARK: 双向链表
struct DNode{
    ElemType data;
    DNode *prior, *next;
};

struct DoubleLinkList{
private:
    int length;
    DNode *headNode;
    DNode *rearNode;
public:
    DoubleLinkList(){
        headNode = (DNode *)malloc(sizeof(DNode));
        rearNode  = (DNode *)malloc(sizeof(DNode));

        headNode->next = rearNode;
        rearNode->prior = headNode;

        headNode->prior = nullptr;
        rearNode->next = nullptr;

        length = 0;
    }
    
    /// 求双向链表表长，时间复杂度 O(n)
    int ListLength();
    
    /// 读取双向链表指定位置元素，时间复杂度 O(n)
    /// @param i 指定位置，1 <= i <= L.length
    ElemType GetElem(int i);
    
    /// 在双向链表指定位置插入元素，时间复杂度 O(1)
    /// @param i 指定位置，1 <= i <= L.length
    /// @param e 需要插入的元素
    Status Insert(int i, ElemType e);
    
    /// 删除双向链表指定位置的元素，时间复杂度 O(1)
    /// @param i 指定位置，1 <= i <= L.length
    /// @param e 返回删除元素的存储变量
    Status Delete(int i, ElemType *e);
};




#endif /* List_hpp */
