#include <iostream>
#include<queue>
#include"Definition.h"
using namespace std;
//authored by @Xiaohai187


//Huffman操作部分，Huffman树的生成使用数组的形式实现
//Select函数为在HT[0]-HT[i]的范围内选择两个权重最小并且没有双亲的两个节点
void Select(HTtree &HT,int i,int s1,int s2) {                                //在森林中选择两个最小并且双亲节点为0的节点，并返回
	s1 = HT[0].weight; s1 = HT[1].weight;                                  //初始化最小值s1为节点1的权重，次小值为节点2的权重
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

void Huffman( ) {
	int n, s1=0, s2=0;
	cout << "请输入权值节点的个数："; cin >> n;
	int m = 2 * n - 1;
	HTnode *HT = new HTnode[m+1];
	for (int i = 1; i <= m; i++) {
		HT[i].lchild = 0; HT[i].rchild = 0; HT[i].parent = 0;
	}
	for (int i = 1; i <= n; i++) {
		cout << "请输入第" << i<< "个节点的权重："<<endl;
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
	cout << "1、建造一个哈夫曼树    2、暂定   3、暂定  4、返回上一级\n 输入选择，输入0直接退出！\n";
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
			cout << "\n你的选择是：1、建造一个哈夫曼树\n";
			Huffman();
			break;
		case 2:
			cout << "\n你的选择是：2、\n";
			break;
		case 3:
			cout << "\n你的选择是：3、\n";
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
