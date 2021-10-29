// 树和二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//authored by @Xiaohai187

#include <iostream>
#include<queue>
#include"Definition.h"
using namespace std;



int main() {
	int a;
	BiTree T;
	/*cout << "先序方式创立二叉树，请输入二叉树元素（0代表此位置无元素）：";
	FirCreateBiTree(T);*/
	while (1) {
		cout << "\n*********************************************************************\n";
		cout << "                       BiTree  Opreation                               \n\n";
		cout << "          选择对二叉树相关的基础或者进阶操作，输入0则退出！\n";
		cout << "                 1、基础操作            2、进阶操作\n";
		cout << "\n*********************************************************************\n";
		cin >> a;
		switch (a){
		case 1:
			BasicOperation(T);
			break;
		case 2:
			HigherOperation(T);
			break;
		case 3:
			break;
		case 0:
			exit(0);
		default:
			break;
		}
	}
}

//ABC##D##EF##G##   1 2 3 0 0 4 0 0 5 6 0 0 7 0 0 
//          A
//      B       E
//    C   D   F   G
//   # # # # # # # #

//ABC##DHJ####EFI#K#L###G##  1 2 3 0 0 4 5 6 0 0 0 0 7 8 9 0 10 0 11 0 0 0 12 0 0 
//             A                                 1
//        B          E                      2         7   
//     C    D     F     G                3    4    8     12
//   #  # H  #  I  #  #  #              # #  5 #  9 #   # #
//       J #   # K                         6 #  # 10       
//      # #     # L                       #  #    # 11
//               # #                               #  #