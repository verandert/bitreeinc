#include "./bitree.h"

//先序非递归构造二叉树
void CreateBiTree(BiTreeNode **T, Elemtype data[]){
    BiTreeNode **q = NULL;
    stack S;
    InitStack(&S);
    q = T;
    while (*data)
    {
        if(*data != 32){
            if((*q = (BiTreeNode*)malloc(sizeof(BiTreeNode)))){
                (*q)->data = *data;
                (*q)->lchild = (*q)->rchild = NULL;
                Push(&S, q);
                q = &((*q)->lchild);
            }
        }
        else
        {
            if(EmptyStack(&S)) break;//防止出现多余字符
            q = (BiTreeNode**)Pop(&S);
            q = &((*q)->rchild);
        }
        data++;
    } 
    DestroyStack(&S);
}
//中序非递归遍历二叉树
void InOrderTraverse(BiTreeNode *T){
    BiTreeNode *p;
    stack S;
    InitStack(&S);
    p = T;
    printf("中序遍历二叉树:");
    while(p || !EmptyStack(&S)){
        if(p) {
            Push(&S, p);
            p = p->lchild;
        } else
        {
            p = Pop(&S);
            printf("%c ", ((BiTreeNode*)p)->data);
            p = p->rchild;
        }
    }
    printf("\n");
    DestroyStack(&S);
}

//先序非递归遍历二叉树
void PreOrderTraverse(BiTreeNode *T){
    BiTreeNode *p;
    stack S;
    InitStack(&S);
    p = T;
    printf("先序遍历二叉树:");
    while(p || !EmptyStack(&S))
    {
        if(p) {
            Push(&S, p);
            printf("%c ", p->data);
            p = p->lchild;
        } else
        {
            p = (BiTreeNode*)Pop(&S);
            p = p->rchild;
        }
    }
    printf("\n");
    DestroyStack(&S);
}

//后序非递归遍历二叉树
void PostOrderTraverse(BiTreeNode *T){
    BiTreeNode *p, *flag = NULL;
    stack S;
    InitStack(&S);
    p = T;
    printf("后序遍历二叉树:");
    while(p || !EmptyStack(&S))
    {
        if(p) {
            Push(&S, p);
            p = p->lchild;
        } else
        {
            p = (BiTreeNode*)GetTop(&S);
            if(!p->rchild) {p = Pop(&S); printf("%c ", p->data); p = NULL;}
            else {   
                if(p->rchild == flag){
                    p = (BiTreeNode*)Pop(&S);
                    printf("%c ", p->data);
                    flag = p;
                    p = NULL;
                } else
                {
                    flag = p->rchild;
                    p = p->rchild;
                }
                
            }
        }
    }
    printf("\n");
    DestroyStack(&S);
}