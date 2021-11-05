#include <iostream>
#include<queue>
#include"Definition.h"
#include "string.h"
using namespace std;
//authored by @Xiaohai187

//Huffman�������֣�Huffman��������ʹ���������ʽʵ��
//Select����Ϊ��HT[0]-HT[i]�ķ�Χ��ѡ������Ȩ����С����û��˫�׵������ڵ�
void Select(HTtree &HT,int i,int s1,int s2) {                               //��ɭ����ѡ��������С����˫�׽ڵ�Ϊ0�Ľڵ㣬������
	s1 = HT[0].weight; s1 = HT[1].weight;                                   //��ʼ����Сֵs1Ϊ�ڵ�1��Ȩ�أ���СֵΪ�ڵ�2��Ȩ��
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

void Huffman(HTtree &HT,int n) { //����һ������������ʹ��HT[100],��������Ҷ�ڵ�������ܳ���50
	int  s1=0, s2=0;                                                          //s1��s2ΪSelect�������صĽڵ�λ��
	//cout << "������Ȩֵ�ڵ�ĸ�����"; cin >> n;
	//int m = 2 * n;
	// HTnode *HT = new HTnode[m];
	//HTtree HT = (HTnode*)malloc(sizeof(HTnode));
	for (int i = 1; i <= 2*n; i++) {                                          //�����һ��λ�ò���
		HT[i].lchild = 0; HT[i].rchild = 0; HT[i].parent = 0;                 //��ʼ�����нڵ�ĸ�ĸ
	}
	for (int j = 1; j <= n; j++) {
		cout << "�������" << j<< "���ڵ��Ȩ�أ�";                           //ǰn��λ�ô洢n���ڵ㣬��n��λ�÷��м����ɵĽڵ㣬n-1��
		cin >> HT[j].weight;
	}
	for (int i = n + 1; i <= 2*n; i++) {                                      //��ʼ������������
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i; HT[s2].parent = i;
		HT[i].lchild = s1; HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}

}


void HuffManCode(HTtree HT,Huffmancode &HC, int n) {  //������нڵ�Ĺ���������
	/**HC = new char[n + 1.0];*/                                                    //�洢n���ַ�����ı����ռ�
	char* cd = new char[n]; cd[n - 1] = '\0';                                 //������ʱ�洢ÿ���ַ�����Ķ�̬����ռ�
	for (int i = 1; i <=n; ++i) {                                             //������ÿһ���ַ�����
		int start = n - 1;                                                    //startָ����󣬱��뿪ʼλ��
		int c = i; int f = HT[c].parent;                                      //cָ������ַ���Ԫ��fΪ��˫��
		while (f != 0) {                                                      //һֱ���ϻ���
			--start;                                                          //ǰ��
			if (HT[f].lchild == c) {
				cd[start] = '0';
			}
			else {
				cd[start] = '1';
			}
			c = f; f = HT[c].parent;                                           //���ϻ���
		}
		int l = n - start;
		HC[i] = new char[l];                                          //HT[i]�ı������HC[i]��
		strcpy (HC[i],&cd[start]);                                            //cd��start��ʼ�����ƽ�HC[i]��
		cout << "��" << i << "�ַ�����������Ϊ��" << HC[i];
	}
	delete cd;

}

void OutHuffmanLeaves(HTtree HT,int n) {//�����������������Ҷ�ڵ�Ȩ��
	cout << "��Ҷ�ڵ�Ȩ������Ϊ��";
	for (int i = 1; i <=n; i++) {
		cout << HT[i].weight << " ";
	}
}

void HigherPerface() {
	cout << "\n*******************************************************************************\n";
	cout << "                            BiTree HigherOpreation                                \n\n";
	cout << "1������һ����������  2�����������������Ҷ�ڵ�Ȩ��  3��������нڵ�Ĺ���������\n";
	cout << "10��������һ��\n ����ѡ������0ֱ���˳���\n";
	cout << "**********************************************************************************\n";
}

void HigherOperation(BiTree& T) {
	HTtree HT = new HTnode[100]; int n; Huffmancode* HC = new Huffmancode[100];
	int chose = 0;
	while (1) {
		HigherPerface();
		cin >> chose;
		switch (chose) {
		case 1:
			cout << "���ѡ���ǣ�1������һ����������\n";
			cout << "������Ȩֵ�ڵ�ĸ�����"; cin >> n;
			if (n > 50 || n < 0) {
				cout << "���ݴ���";
				break;
			}
			else {
				int m = 2 * n;
				Huffman(HT, n);
			}
			break;
		case 2:
			cout << "���ѡ���ǣ�2�����������������Ҷ�ڵ�Ȩ��\n";
			OutHuffmanLeaves(HT, n);
			break;
		case 3:
			cout << "���ѡ���ǣ�3��������нڵ�Ĺ��������룺\n";
			HuffManCode(HT, *HC, n);
			break;
		case 4:
			break;
		case 0:
			exit(0);
		default:
			break;
		}if (chose == 10) {
			break;
		}
	}
}
