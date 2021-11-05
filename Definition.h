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

typedef int Weight;
typedef int Parent;
typedef struct HTnode {                  //HuffmanTree�Ľṹ�嶨��
	Weight weight;
	Parent parent;
	int lchild;
	int rchild;
}HTnode, * HTtree;

typedef char** Huffmancode;

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
void HigherPerface();                                //���ײ���ѡ�����
void HigherOperation(BiTree& T);                     //���ײ���ѡ��
void Huffman(HTtree& HT, int n);                     //����һ������������ʹ��HT[100],��������Ҷ�ڵ�������ܳ���50
void OutHuffmanLeaves(HTtree HT, int n);             //�����������������Ҷ�ڵ�Ȩ��
void Select(HTtree& HT, int i, int s1, int s2);      //��ɭ����ѡ��������С����˫�׽ڵ�Ϊ0�Ľڵ㣬������
void HuffManCode(HTtree HT, Huffmancode& HC, int n);  //������нڵ�Ĺ���������