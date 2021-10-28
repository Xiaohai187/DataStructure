#pragma once
#include <iostream>
#include<queue>
#define MAXSIZE 10000
#define FALSE 0
//authored by @Xiaohai187


//typedef TElemTpye SqBiTree[MAXSIZE];
//SqBiTree bt;                           //顺序存储方式定义二叉树


typedef struct BiTnode {
	int data;
	struct BiTnode* lchild, * rchild;
} BiTnode, * BiTree;


//基础操作部分
void BasicPerface();                    //基础操作选择界面
void BasicOperation(BiTree& T);         //基础操作选择
void InitBiTree(BiTree& T);             //二叉树链表初始化
void FirCreateBiTree(BiTree& T);		//先序方式创建二叉树
void MidVisit(BiTree T);				//二叉树的中序遍历
void FirVisit(BiTree T);				//二叉树的先序遍历
void LasVisit(BiTree T);				//二叉树的后序遍历
int Depth(BiTree T);					//递归返回二叉树的深度
void LevelVisit(BiTree T);				//自上而下的层次遍历
int DsonNodes(BiTree T);				//返回二叉树中度为2的节点数目
int FindP(BiTree T);                    //返回节点p在二叉树中的层次

//进阶操作部分
void HigherPerface();                    //进阶操作选择界面
void HigherOperation(BiTree& T);         //进阶操作选择