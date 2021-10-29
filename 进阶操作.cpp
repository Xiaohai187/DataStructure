#include <iostream>
#include<queue>
#include"Definition.h"
using namespace std;
//authored by @Xiaohai187


//Huffman�������֣�Huffman��������ʹ���������ʽʵ��
//Select����Ϊ��HT[0]-HT[i]�ķ�Χ��ѡ������Ȩ����С����û��˫�׵������ڵ�
void Select(HTtree &HT,int i,int s1,int s2) {                                //��ɭ����ѡ��������С����˫�׽ڵ�Ϊ0�Ľڵ㣬������
	s1 = HT[0].weight; s1 = HT[1].weight;                                  //��ʼ����Сֵs1Ϊ�ڵ�1��Ȩ�أ���СֵΪ�ڵ�2��Ȩ��
	for (int k = 0; k < i; k++) {                                           //��ѡ��ķ�Χ��ѭ��
		if (HT[k].weight <s1&& HT[k].parent == 0) {                         //�������Сֵs1С������s2����s1
			s2 = s1;
			s1 = k;                                                         //s1��ֵΪ��С
		}else if (HT[k].weight < s2 && HT[k].parent == 0) {
			s2 = k;                                                         //����Сֵ�󣬵��Ǳȴ�СֵС���򱣴��ڴ�Сֵ��
		}
	}
	//return s1, s2;
}

void Huffman( ) {
	int n, s1=0, s2=0;
	cout << "������Ȩֵ�ڵ�ĸ�����"; cin >> n;
	int m = 2 * n - 1;
	HTnode *HT = new HTnode[m+1];
	for (int i = 1; i <= m; i++) {
		HT[i].lchild = 0; HT[i].rchild = 0; HT[i].parent = 0;
	}
	for (int i = 1; i <= n; i++) {
		cout << "�������" << i<< "���ڵ��Ȩ�أ�"<<endl;
		cin >> HT[i].weight;
	}
	for (int i = n + 1; i <= m; i++) {
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i; HT[s2].parent = i;
		HT[i].lchild = s1; HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}

}


void HigherPerface() {
	cout << "\n*********************************************************************\n";
	cout << "                       BiTree HigherOpreation                          \n\n";
	cout << "1������һ����������    2���ݶ�   3���ݶ�  4��������һ��\n ����ѡ������0ֱ���˳���\n";
	cout << "*********************************************************************\n";
}

void HigherOperation(BiTree& T) {
	//HTtree HT;
	int chose = 0;
	while (1) {
		HigherPerface();
		cin >> chose;
		switch (chose) {
		case 1:
			cout << "\n���ѡ���ǣ�1������һ����������\n";
			Huffman();
			break;
		case 2:
			cout << "\n���ѡ���ǣ�2��\n";
			break;
		case 3:
			cout << "\n���ѡ���ǣ�3��\n";
			break;
		case 4:
			break;
		case 0:
			exit(0);
		default:
			break;
		}if (chose == 4) {
			break;
		}
	}
}
