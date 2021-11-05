#include <iostream>
#include<queue>
#include"Definition.h"
#include "string.h"
using namespace std;
//authored by @Xiaohai187

//Huffman操作部分，Huffman树的生成使用数组的形式实现
//Select函数为在HT[0]-HT[i]的范围内选择两个权重最小并且没有双亲的两个节点
void Select(HTtree &HT,int i,int s1,int s2) {                               //在森林中选择两个最小并且双亲节点为0的节点，并返回
	s1 = HT[0].weight; s1 = HT[1].weight;                                   //初始化最小值s1为节点1的权重，次小值为节点2的权重
	for (int k = 0; k < i; k++) {                                           //在选择的范围内循环
		if (HT[k].weight <s1&& HT[k].parent == 0) {                         //如果比最小值s1小，则由s2保存s1
			s2 = s1;
			s1 = k;                                                         //s1赋值为最小
		}else if (HT[k].weight < s2 && HT[k].parent == 0) {
			s2 = k;                                                         //比最小值大，但是比次小值小，则保存在次小值内
		}
	}
	//return s1, s2;
}

void Huffman(HTtree &HT,int n) { //构造一个哈夫曼树，使用HT[100],哈夫曼的叶节点个数不能超过50
	int  s1=0, s2=0;                                                          //s1，s2为Select函数返回的节点位置
	//cout << "请输入权值节点的个数："; cin >> n;
	//int m = 2 * n;
	// HTnode *HT = new HTnode[m];
	//HTtree HT = (HTnode*)malloc(sizeof(HTnode));
	for (int i = 1; i <= 2*n; i++) {                                          //数组第一个位置不用
		HT[i].lchild = 0; HT[i].rchild = 0; HT[i].parent = 0;                 //初始化所有节点的父母
	}
	for (int j = 1; j <= n; j++) {
		cout << "请输入第" << j<< "个节点的权重：";                           //前n个位置存储n个节点，后n个位置放中间生成的节点，n-1个
		cin >> HT[j].weight;
	}
	for (int i = n + 1; i <= 2*n; i++) {                                      //开始构建哈夫曼树
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i; HT[s2].parent = i;
		HT[i].lchild = s1; HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}

}


void HuffManCode(HTtree HT,Huffmancode &HC, int n) {  //输出所有节点的哈夫曼编码
	/**HC = new char[n + 1.0];*/                                                    //存储n个字符编码的编码表空间
	char* cd = new char[n]; cd[n - 1] = '\0';                                 //分配临时存储每个字符编码的动态数组空间
	for (int i = 1; i <=n; ++i) {                                             //依次求每一个字符编码
		int start = n - 1;                                                    //start指向最后，编码开始位置
		int c = i; int f = HT[c].parent;                                      //c指向编码字符单元，f为其双亲
		while (f != 0) {                                                      //一直向上回溯
			--start;                                                          //前移
			if (HT[f].lchild == c) {
				cd[start] = '0';
			}
			else {
				cd[start] = '1';
			}
			c = f; f = HT[c].parent;                                           //向上回溯
		}
		int l = n - start;
		HC[i] = new char[l];                                          //HT[i]的编码放在HC[i]中
		strcpy (HC[i],&cd[start]);                                            //cd从start开始，复制进HC[i]中
		cout << "第" << i << "字符哈夫曼编码为：" << HC[i];
	}
	delete cd;

}

void OutHuffmanLeaves(HTtree HT,int n) {//输出哈夫曼树的所有叶节点权重
	cout << "其叶节点权重依次为：";
	for (int i = 1; i <=n; i++) {
		cout << HT[i].weight << " ";
	}
}

void HigherPerface() {
	cout << "\n*******************************************************************************\n";
	cout << "                            BiTree HigherOpreation                                \n\n";
	cout << "1、建造一个哈夫曼树  2、输出哈夫曼的所有叶节点权重  3、输出所有节点的哈夫曼编码\n";
	cout << "10、返回上一级\n 输入选择，输入0直接退出！\n";
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
			cout << "你的选择是：1、建造一个哈夫曼树\n";
			cout << "请输入权值节点的个数："; cin >> n;
			if (n > 50 || n < 0) {
				cout << "数据错误！";
				break;
			}
			else {
				int m = 2 * n;
				Huffman(HT, n);
			}
			break;
		case 2:
			cout << "你的选择是：2、输出哈夫曼的所有叶节点权重\n";
			OutHuffmanLeaves(HT, n);
			break;
		case 3:
			cout << "你的选择是：3、输出所有节点的哈夫曼编码：\n";
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
