#include <iostream>
#include<queue>
#include"Definition.h"
using namespace std;
//authored by @Xiaohai187

void HigherPerface() {
	cout << "\n*********************************************************************\n";
	cout << "                       BiTree HigherOpreation                          \n\n";
	cout << "1���������������Ԫ��   2���������������Ԫ��   3���������������Ԫ��\n ����ѡ������0ֱ���˳���\n";
	cout << "*********************************************************************\n\n";
}

void HigherOperation(BiTree& T) {
	int chose = 0;
	while (1) {
		BasicPerface();
		cin >> chose;
		switch (chose) {
		case 1:
			cout << "\n���ѡ���ǣ�1���������������Ԫ��\n";
			MidVisit(T);
			break;
		case 2:
			cout << "\n���ѡ���ǣ�2���������������Ԫ��\n";
			FirVisit(T);
			break;
		case 3:
			cout << "\n���ѡ���ǣ�3���������������Ԫ��\n";
			LasVisit(T);
			break;
		case 0:
			exit(0);
		default:
			break;
		}
	}
}