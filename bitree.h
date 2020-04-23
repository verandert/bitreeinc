#ifndef _BITREE_H_
#define _BITREE_H_
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define fasle 0

typedef char Elemtype;
typedef struct BiTreeNode
{
    Elemtype data;
    struct BiTreeNode *lchild, *rchild;
}BiTreeNode;//tree节点数据类型

//布尔数据类型
typedef int boolean;

//链表节点
typedef struct StackNode
{
    void* data;
    struct StackNode *next;
}StackNode;

//链表实现栈
typedef struct
{
    StackNode *base, *top;
    int length;
}stack;

//栈相关函数的声明
void InitStack(stack *S);
void DestroyStack(stack *S);
void ClearStack(stack *S);
boolean EmptyStack(stack *S);
void Push(stack *S, void* elemtype);
void* Pop(stack *S);
void* GetTop(stack *S);

//tree相关函数声明
void CreateBiTree(BiTreeNode **T, Elemtype data[]);
void InOrderTraverse(BiTreeNode *T);
void PreOrderTraverse(BiTreeNode *T);
void PostOrderTraverse(BiTreeNode *T);
#endif