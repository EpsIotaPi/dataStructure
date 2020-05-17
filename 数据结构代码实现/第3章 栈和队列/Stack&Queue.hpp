//
//  Stack&Queue
//  数据结构代码实现
//
//  Created by 金宸极 on 2020/5/17.
//  Copyright © 2020 金宸极. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include "Basic.hpp"

//MARK:- 栈



//MARK: （结构）顺序栈
typedef struct {
    ElemType data[MaxSize];
    int top;
}SqStack;

//MARK: （操作）顺序栈

/// 初始化顺序栈
/// @param S 顺序栈
Status Inital_SqStack(SqStack *S);

/// 顺序栈判空
/// @param S 顺序栈
bool isEmpty_SqStack(SqStack S);

/// 顺序栈判满
/// @param S 顺序栈
bool isFull_SqStack(SqStack S);

/// 入栈（插入元素），时间复杂度 O(1)
/// @param S 顺序栈
/// @param e 需要入栈的元素
Status Push_SqStack(SqStack *S, ElemType e);

/// 出栈（删除元素），时间复杂度 O(1)
/// @param S 顺序栈
/// @param e 出栈元素存储变量
Status Pop_SqStack(SqStack *S, ElemType *e);

/// 获取栈顶元素，时间复杂度 O(1)
/// @param S 顺序栈
/// @param e 栈顶元素存储变量
Status GetTop_SqStack(SqStack S, ElemType *e);

//MARK: （结构）共享栈
typedef struct{
    ElemType data[MaxSize];
    int Top0;
    int Top1;
} ShareStack;

//MARK: （操作）共享栈
/// 初始化共享栈
/// @param S 共享栈
Status Inital_ShareStack(ShareStack *S);

/// 共享栈判空
/// @param S 共享栈
/// @param Stack 操作的栈（置 0 为 Top0 对应的栈，置 1 为 Top1 对应的栈）
bool isEmpty_ShareStack(ShareStack S, int Stack);

/// 共享栈判满，满足条件时两栈均满
/// @param S 共享栈
bool isFull_ShareStack(ShareStack S);
    
/// 入栈，插入元素
/// @param S 共享栈
/// @param Stack 操作的栈（置 0 为 Top0 对应的栈，置 1 为 Top1 对应的栈）
/// @param e 入栈元素
Status Push_ShareStack(ShareStack *S, int Stack, ElemType e);

/// 出栈，删除元素
/// @param S 共享栈
/// @param Stack 操作的栈（置 0 为 Top0 对应的栈，置 1 为 Top1 对应的栈）
/// @param e 出栈元素存储变量
Status Pop_ShareStack(ShareStack *S, int Stack, ElemType *e);

/// 获取栈顶元素
/// @param S 共享栈
/// @param Stack 操作的栈（置 0 为 Top0 对应的栈，置 1 为 Top1 对应的栈）
/// @param e 栈顶元素存储变量
Status GetTop_ShareStack(ShareStack *S, int Stack, ElemType *e);
    
//MARK: （结构）链栈
typedef struct SNode{
    struct SNode *next;
    ElemType data;
} *LinkStack, SNode;

//MARK: （操作）链栈
/// 初始化链栈
/// @param S 链栈
Status Inital_LinkStack(LinkStack *S);

/// 链栈判空
/// @param S 链栈
Status isEmpty_LinkStack(LinkStack S);

/// 入栈（插入元素），时间复杂度O(1)
/// @param S 链栈
/// @param e 需要入栈的元素
Status Push_LinkStack(LinkStack *S, ElemType e);

/// 出栈（删除元素），时间复杂度O(1)
/// @param S 链栈
/// @param e 出栈元素存储变量
Status Pop_LinkStack(LinkStack *S, ElemType *e);

/// 获取栈顶元素，时间复杂度O(1)
/// @param S 链栈
/// @param e 栈顶元素存储变量
Status GetTop_LinkStack(LinkStack S, ElemType *e);



//MARK:- 队列



//MARK: （结构）循环队列
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
}SqQueue;


//MARK: （操作）循环队列
/// 初始化循环队列
/// @param Q 循环队列
Status Inital_SqQueue(SqQueue *Q);

/// 循环队列判空
/// @param Q 循环队列
bool isEmpty_SqQueue(SqQueue Q);

/// 循环队列判满
/// @param Q 循环队列
bool isFull_SqQueue(SqQueue Q);

/// 入队（插入元素），时间复杂度，O(1)
/// @param Q 循环队列
/// @param e 需要入队的元素
Status EnQueue_SqQueue(SqQueue *Q, ElemType e);

/// 出队（删除元素），时间复杂度，O(1)
/// @param Q 循环队列
/// @param e 出队元素存储变量
Status DeQueue_SqQueue(SqQueue *Q, ElemType *e);

/// 获取队头元素，时间复杂度，O(1)
/// @param Q 循环队列
/// @param e 队头元素存储变量
Status GetHead_SqQueue(SqQueue Q, ElemType *e);

//MARK: （结构）单链队列
typedef struct QNode{
    ElemType data;
    struct QNode *next;
} QNode;
typedef struct{
    QNode *front;
    QNode *rear;
} LinkQueue;

//MARK: （操作）单链队列
/// 初始化单链队列
/// @param Q 单链队列
Status Inital_LinkQueue(LinkQueue *Q);

/// 单链队列判空
/// @param Q 单链队列
Status isEmpty_LinkQueue(LinkQueue Q);

/// 入队（插入元素），时间复杂度，O(1)
/// @param Q 单链队列
/// @param e 需要入队的元素
Status EnQueue_LinkQueue(LinkQueue *Q, ElemType e);

/// 出队（删除元素），时间复杂度，O(1)
/// @param Q 单链队列
/// @param e 出队元素存储变量
Status DeQueue_LinkQueue(LinkQueue *Q, ElemType *e);

/// 获取队头元素，时间复杂度，O(1)
/// @param Q 单链队列
/// @param e 队头元素存储变量
Status GetHead_LinkQueue(LinkQueue Q, ElemType *e);

/// 获取队尾元素，时间复杂度，O(1)
/// @param Q 单链队列
/// @param e 队尾元素存储变量
Status GetTail_LinkQueue(LinkQueue Q, ElemType *e);

#endif /* Stack_hpp */
