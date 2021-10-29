#include <iostream>
#include<queue>
#include"Definition.h"
using namespace std;
//authored by @Xiaohai187

void InitBiTree(BiTree &T) {
	T->data=0;
	T->lchild = NULL;
	T->rchild = NULL;
}

//BiTree CreateNormallBiTree() {
//	int elem=0;
//    BiTnode *T = (BiTree)malloc(sizeof(BiTnode));
//	std::cout << "\n�����������Ԫ�أ�������9999����ֹ��\n";
//	std::cin >> elem;
//	if (elem == 9999) {
//		return NULL;
//	}
//	else {
//		T->data = elem; 
//		T->lchild=CreateNormallBiTree();
//		T->rchild=CreateNormallBiTree();
//	}
//	return T;
//}

void FirCreateBiTree(BiTree &T) {					//�ݹ������ʽ����һ��������
	int ch;
	//:cout << "\n�����������Ԫ�أ�������0�����λ��û��Ԫ�أ�\n";
	cin >> ch;
	if (ch == 0) {
		T = NULL;
	}
	else {
		T = new BiTnode;
		T->data = ch;
		FirCreateBiTree(T->lchild);
		FirCreateBiTree(T->rchild);
	}
}

void MidVisit(BiTree T) {//�ݹ�������������
	if (T) {
		MidVisit(T->lchild);
		cout << T->data << " ";
		MidVisit(T->rchild);
	}
}

void FirVisit(BiTree T) {//�ݹ�������������
	if (T) {
		cout << T->data<<" ";
		FirVisit(T->lchild);
		FirVisit(T->rchild);
	}
}

void LasVisit(BiTree T) {//�ݹ�ĺ����������
	if (T) {
		LasVisit(T->lchild);
		LasVisit(T->rchild);
		cout << T->data << " ";
	}
}

int Depth(BiTree T) {//�ݹ�ķ��ض����������
	if (T == NULL) {
		return 0;
	}
	else {
		int m = Depth(T->lchild);       //���������
		int n = Depth(T->rchild);       //���������
		return m > n ? (m + 1): (n + 1);//���رȽϳ�����һ�������Ҽ��ϸ��ڵ��1
	}
}
//��������ȵ��㷨���ȶ���һ������������Ľṹ��
typedef struct Qu{
	BiTree data[1000];
	int level[1000];
	int front, rear;
}Qu;

int BTWith(BiTree T) {
	BiTnode* p;
	Qu q;                               //�Զ���Ķ���Qu
	int k, max, i, n;
	q.front = q.rear = -1;              //��ʼ����Ϊ��
	q.rear++;                           //���׼�һ
	q.data[q.rear] = T;                 //���ڵ����
	q.level[q.rear] = 1;                //���ڵ��μ�Ϊ1
	while (q.front < q.rear) {
		q.front++;                      //��ͷָ���һ
		p = q.data[q.front];            //����
		k = q.level[q.front];           //���ӽڵ�Ĳ��
		if (p->lchild != NULL) {        //���Ӳ��գ������
			q.rear++;
			q.data[q.rear] = p->lchild;
			q.level[q.rear] = k + 1;
		}
		if (p->rchild != NULL) {        //���Ӳ��գ������
			q.rear++;
			q.data[q.rear] = p->rchild;
			q.level[q.rear] = k + 1;
		}
	}
	max = 0; i = 0; k = 1;               //max����ͬһ�����ڵ������k��ʾ�ӵ�һ�㿪ʼɨ��
	while(i<=q.rear){                    //iɨ���������Ԫ��
		n = 0;                           //nΪ��k��Ľڵ���Ŀ
		while (i <= q.rear && q.level[i] == k) {
			n++; i++;
		}
		k = q.level[i];
		if (n > max) {
			max = n;
		}
	}return max;
}

void LevelVisit(BiTree T) {				 //ʹ�ö��У��������϶��µĲ�α���
	queue<BiTnode*>q;					 //��ʼ������q�����BiTnode�ͽڵ�
	BiTnode* p = T;					   	//pָ��ָ����ڵ�
	q.push(p);							 //���ڵ����
	while (!q.empty()) {				 //����δ����
		p = q.front(); q.pop();			 //ȡ����Ԫ�ز�����
		if (p->lchild != NULL) {		 //���Ӵ��������
			q.push(p->lchild);
		}
		if (p->rchild != NULL) {		 //�Һ��Ӵ��������
			q.push(p->rchild);
		}
		cout << p->data<<" ";			 //�����ǰ�ڵ������
	}
}

int DsonNodes(BiTree T) {				 //���ض������ж�Ϊ2�Ľڵ�
	if (!T) {
		return 0;					    //�ݹ��������������Ѿ������ұ�Ҷ�ڵ㣬���˳��ݹ�
	}
	else if (T->lchild != NULL && T->rchild != NULL) {			//���Һ��Ӷ����ڵģ�����Ϊ2�Ľڵ�
		return DsonNodes(T->lchild) + DsonNodes(T->rchild)+1;  //�ݹ飬�������Ӻ��Һ��ӵĺͼ�һ(���һ�����������Լ�һ)
	}
	else {
		return DsonNodes(T->lchild) + DsonNodes(T->rchild);    //�ݹ飬�������Ӻ��Һ��ӵĺͣ�������һ����Ϊ2�Ľڵ㣬���Բ��ü�һ��
	}
}

int FindP(BiTree T) { 
	int p; int n = 0;                                         //p�洢��Ҫ���ҵ����ݣ�n���ڼ�¼���
	cout << "\n��������Ҫ���ҵĽڵ����ݣ�"; cin >> p;
	BiTnode* r = T;
	queue<BiTnode*>l; queue<BiTnode*>s;                       //�����У��������У����ò�α�������ʽ����ÿһ��Ԫ�ؽ��б����Ƚ�
	l.push(r);                                                //���ڵ��������
	if (r->data == p) {                                       //������ڵ������Ҫ�ҵĽڵ㣬��ֱ�ӷ���1
		return 1;
	}n++;
	while (!l.empty()||!s.empty()) {                             //����ѭ��
		while (!l.empty()) {                                   //�����в���ʱ
			r = l.front(); l.pop();                            //���Ӷ���Ԫ��
			if (r->lchild != NULL) {                           //���Ӵ���ʱ�������ӽ����ж�
				if (r->lchild->data == p) {                    //����ǣ�ֱ�ӷ���n+1
					n++;
					return n;
				}
				else {
					s.push(r->lchild);                          //������ǣ����븨������
				}
			} 
			if (r->rchild != NULL) {                             //���Һ�������ͬ���ж�
				if (r->rchild->data == p) {
					n++; 
					return n;
				}
				else {
					s.push(r->rchild);
				}
			}
		}n++;                                                    //�����б�������������һ��Ľڵ㶼�жϹ�
		while (!s.empty()) {                                     //������ͬ������
			r = s.front(); s.pop();
			if (r->lchild != NULL) {
				if (r->lchild->data == p) {
					n++; return n;
				}
				else {
					l.push(r->lchild);
				}
			}
			if (r->rchild != NULL) {
				if (r->rchild->data == p) {
					n++; return n;
				}
				else {
					l.push(r->rchild);
				}
			}
		}n++;
	}return n;
}

void BasicPerface() {
	cout << "\n*********************************************************************\n";
	cout << "                       BiTree Basic Opreation                          \n\n";
	cout << "1���������������Ԫ��   2���������������Ԫ��     3���������������Ԫ��\n\n";
	cout << "4����ʼ���������       5���������������������   6�����϶��µĲ�α���\n\n";
	cout << "7�����ض����������     8�����ض������Ŀ��       9�����ؽڵ����ڲ�� \n\n";
	cout << "10��������һ��          ����ѡ������0ֱ���˳�������\n";
	cout << "*********************************************************************\n";
}
void BasicOperation(BiTree& T) {
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
		case 4:
			cout << "\n���ѡ���ǣ�4����ʼ���������\n";
			InitBiTree(T);
			break;
		case 5:
			cout << "\n���ѡ���ǣ�5���������������������\n";
			cout << "����ʽ�����������������������Ԫ�أ�0�����λ����Ԫ�أ���";
			FirCreateBiTree(T);
			break;
		case 6:
			cout << "\n���ѡ���ǣ�6�����϶��µĲ�α���\n";
			LevelVisit(T);
			break;
		case 7:
			cout << "\n���ѡ���ǣ�7�����ض����������\n";
			cout << Depth(T);
			break;
		case 8:
			cout << "\n���ѡ���ǣ�8�����ض������Ŀ��\n";
			cout << BTWith(T);
			break;
		case 9:
			cout << "\n���ѡ���ǣ�9�����ؽڵ����ڲ��\n";
			cout << FindP(T);
			break;
		case 10:
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