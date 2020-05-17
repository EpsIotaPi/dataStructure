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
struct SqStack{
private:
    ElemType data[MaxSize];
    int top;
public:
    SqStack(){
        top = -1;
    }
    /// 顺序栈判空
    bool isEmpty();
    
    /// 顺序栈判满
    bool isFull();
    
    /// 入栈（插入元素），时间复杂度 O(1)
    /// @param e 需要入栈的元素
    Status Push(ElemType e);
    
    /// 出栈（删除元素），时间复杂度 O(1)
    /// @param e 出栈元素存储变量
    Status Pop(ElemType *e);
    
    /// 获取栈顶元素，时间复杂度 O(1)
    ElemType GetTop();
};

//MARK: 共享栈
struct ShareStack{
private:
    ElemType data[MaxSize];
    int Top0;
    int Top1;
public:
    ShareStack(){
        Top0 = -1;
        Top1 = MaxSize;
    }
    /// 共享栈判空
    /// @param Stack 操作的栈（置 0 为 Top0 对应的栈，置 1 为 Top1 对应的栈）
    bool isEmpty(int Stack);

    /// 共享栈判满，满足条件时两栈均满
    bool isFull();
        
    /// 入栈，插入元素
    /// @param Stack 操作的栈（置 0 为 Top0 对应的栈，置 1 为 Top1 对应的栈）
    /// @param e 入栈元素
    Status Push(int Stack, ElemType e);

    /// 出栈，删除元素
    /// @param Stack 操作的栈（置 0 为 Top0 对应的栈，置 1 为 Top1 对应的栈）
    /// @param e 出栈元素存储变量
    Status Pop(int Stack, ElemType *e);

    /// 获取栈顶元素
    /// @param Stack 操作的栈（置 0 为 Top0 对应的栈，置 1 为 Top1 对应的栈）
    ElemType GetTop(int Stack);
};

//MARK: 链栈
struct SNode{
    SNode *next;
    ElemType data;
};

struct LinkStack{
private:
    int length;
    SNode *headNode;
public:
    LinkStack(){
        headNode = (SNode *)malloc(sizeof(SNode));
        headNode->next = nullptr;
        length = '0';   
    }
    
    /// 链栈判空
    bool isEmpty();
    
    /// 入栈（插入元素），时间复杂度 O(1)
    /// @param e 需要入栈的元素
    Status Push(ElemType e);
    
    /// 出栈（删除元素），时间复杂度 O(1)
    /// @param e 出栈元素存储变量
    Status Pop(ElemType *e);
    
    /// 获取栈顶元素，时间复杂度 O(1)
    /// @param e 栈顶元素存储变量
    Status GetTop(ElemType *e);
};




//MARK:- 队列

//MARK: 循环队列
struct SqQueue{
private:
    ElemType data[MaxSize];
    int front, rear;
public:
    SqQueue(){
        front = rear = 0;
    }

    /// 循环队列判空
    bool isEmpty();

    /// 循环队列判满
    bool isFull();

    /// 入队（插入元素），时间复杂度 O(1)
    /// @param e 需要入队的元素
    Status EnQueue(ElemType e);

    /// 出队（删除元素），时间复杂度 O(1)
    /// @param e 出队元素存储变量
    Status DeQueue(ElemType *e);

    /// 获取队头元素，时间复杂度 O(1)
    ElemType GetHead();
    
    /// 获取队尾元素，时间复杂度 O(1)
    ElemType GetTail();
};





//MARK: （结构）单链队列
struct QNode{
    ElemType data;
    struct QNode *next;
};

struct LinkQueue{
private:
    QNode *front;
    QNode *rear;
public:
    LinkQueue(){
        QNode *Head = (QNode *)malloc(sizeof(QNode));
        Head->next = nullptr;
        Head->data = DEFAULT;     //头结点
        
        front = Head;
        rear = Head;
    }
    
    /// 单链队列判空
    Status isEmpty();

    /// 入队（插入元素），时间复杂度，O(1)
    /// @param e 需要入队的元素
    Status EnQueue(ElemType e);

    /// 出队（删除元素），时间复杂度，O(1)
    /// @param e 出队元素存储变量
    Status DeQueue(ElemType *e);

    /// 获取队头元素，时间复杂度，O(1)
    Status GetHead();

    /// 获取队尾元素，时间复杂度，O(1)
    Status GetTail();
};





#endif /* Stack_hpp */
