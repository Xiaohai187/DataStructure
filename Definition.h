#pragma once
#include <iostream>
#include<queue>
#define MAXSIZE 10000
#define FALSE 0
//authored by @Xiaohai187


//typedef TElemTpye SqBiTree[MAXSIZE];
//SqBiTree bt;                           //˳��洢��ʽ���������


typedef struct BiTnode {                 //�������Ķ���ڵ㶨��
	int data;
	struct BiTnode* lchild, * rchild;
} BiTnode, * BiTree;

typedef struct HTnode {                  //HuffmanTree�Ľṹ�嶨��
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTnode, * HTtree;


//������������
void BasicPerface();                    //��������ѡ�����
void BasicOperation(BiTree& T);         //��������ѡ��
void InitBiTree(BiTree& T);             //�����������ʼ��
void FirCreateBiTree(BiTree& T);		//����ʽ����������
void MidVisit(BiTree T);				//���������������
void FirVisit(BiTree T);				//���������������
void LasVisit(BiTree T);				//�������ĺ������
int Depth(BiTree T);					//�ݹ鷵�ض����������
void LevelVisit(BiTree T);				//���϶��µĲ�α���
int DsonNodes(BiTree T);				//���ض������ж�Ϊ2�Ľڵ���Ŀ
int FindP(BiTree T);                    //���ؽڵ�p�ڶ������еĲ��

//���ײ�������
void HigherPerface();                    //���ײ���ѡ�����
void HigherOperation(BiTree& T);         //���ײ���ѡ��