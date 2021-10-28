#include <iostream>
#include<queue>
#include"Definition.h"
using namespace std;
//authored by @Xiaohai187

void HigherPerface() {
	cout << "\n*********************************************************************\n";
	cout << "                       BiTree HigherOpreation                          \n\n";
	cout << "1、中序输出二叉树元素   2、先序输出二叉树元素   3、后序输出二叉树元素\n 输入选择，输入0直接退出！\n";
	cout << "*********************************************************************\n\n";
}

void HigherOperation(BiTree& T) {
	int chose = 0;
	while (1) {
		BasicPerface();
		cin >> chose;
		switch (chose) {
		case 1:
			cout << "\n你的选择是：1、中序输出二叉树元素\n";
			MidVisit(T);
			break;
		case 2:
			cout << "\n你的选择是：2、先序输出二叉树元素\n";
			FirVisit(T);
			break;
		case 3:
			cout << "\n你的选择是：3、后序输出二叉树元素\n";
			LasVisit(T);
			break;
		case 0:
			exit(0);
		default:
			break;
		}
	}
}