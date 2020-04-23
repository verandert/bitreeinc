#include "./bitree.h"

int main(){
    Elemtype data[] = "AB  CD  EF   ";//先序二叉树列表,以此构造二叉树;
    BiTreeNode *T;
    CreateBiTree(&T, data);
    // InOrderTraverse(T);
    // PreOrderTraverse(T);
    // PostOrderTraverse(T);
    printf("后序递归遍历二叉树:");
    PostOrderTraverseV1(T);
    printf("\n");
    return 0;
}