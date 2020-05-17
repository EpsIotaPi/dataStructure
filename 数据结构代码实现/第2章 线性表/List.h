//
//  List.h
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/17.
//  Copyright © 2020 金宸极. All rights reserved.
//

#ifndef List_h
#define List_h

#include "Basic.h"

//MARK:- 线性表的顺序存储



//MARK: （结构）顺序表
typedef struct {
    ElemType data[MaxSize];
    int length;
}SqList;

//MARK: （操作）顺序表
/// 初始化顺序表
/// @param L 顺序表
Status Inital_SqList(SqList *L);

/// 返回顺序表长，时间复杂度 O(1)
/// @param L 顺序表
int ListLength_SqList(SqList L);

/// 读取顺序表指定位置的元素，时间复杂度 O(1)
/// @param L 顺序表
/// @param i 指定位置，1 <= i <= L.length
/// @param e 返回元素存储变量
Status GetElem_SqList(SqList L, int i, ElemType *e);

/// 在顺序表指定为位置插入元素，时间复杂度 O(n)
/// @param L 顺序表
/// @param i 指定位置，1 <= i <= L.length
/// @param e 需要插入的元素
Status Insert_SqList (SqList *L, int i, ElemType e);

/// 删除顺序表指定位置的元素，时间复杂度 O(n)
/// @param L 顺序表
/// @param i 指定位置，1 <= i <= L.length
/// @param e 返回删除元素的存储变量
Status Delete_SqList (SqList *L, int i, ElemType *e);

//MARK: （结构）动态分配的顺序表
#define Increas 10
typedef struct {
    ElemType *data;
    int length;
    int MaxLength;
}DqList;

//MARK: （操作）动态分配的顺序表
/// 初始化顺序表
/// @param L 动态分配的顺序表
Status Inital_DqList (DqList *L);


//MARK:- 线性表的链式存储



//MARK: （结构）单链表
typedef struct LNode{
    ElemType data;      //数据域
    struct LNode *next; //指针域
}LNode, *LinkList;

//MARK: （操作）单链表
/// 初始化单链表
/// @param L 单链表
Status Inital_LinkList (LinkList *L);

/// 求单链表表长，时间复杂度 O(n)
/// @param L 单链表
int ListLength_LinkList(LinkList L);      //求表长，O(n)

/// 读取单链表指定位置元素，时间复杂度 O(n)
/// @param L 单链表
/// @param i 指定位置，1 <= i <= L.length
/// @param e 返回元素存储变量
Status GetElem_LinkList(LinkList L, int i, ElemType *e);   //读取指定元素，O(n)

/// 在单链表指定位置插入元素，时间复杂度 O(1)
/// @param L 单链表
/// @param i 指定位置，1 <= i <= L.length
/// @param e 需要插入的元素
Status Insert_LinkList(LinkList *L, int i, ElemType e);    //插入操作，O(1)

/// 删除单链表指定位置的元素，时间复杂度 O(1)
/// @param L 单链表
/// @param i 指定位置，1 <= i <= L.length
/// @param e 返回删除元素的存储变量
Status Delete_LinkList(LinkList *L, int i, ElemType *e);   //删除操作，O(1)

//MARK: （结构）双向链表
typedef struct DNode{
    ElemType data;
    struct DNode *prior, *next;
}DNode, *DoubleLinkList;

//MARK: （操作）双向链表
Status Inital_DoubleLinkList(DoubleLinkList *L);

Status Insert_DoubleLinkList(DoubleLinkList *L, int i, ElemType e);

Status Delete_DoubleLinkList(DoubleLinkList *L, int i, ElemType *e);



#endif /* List_h */
