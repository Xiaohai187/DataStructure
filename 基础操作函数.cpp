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
//	std::cout << "\n请输入二叉树元素：（输入9999即终止）\n";
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

void FirCreateBiTree(BiTree &T) {					//递归的先序方式创建一个二叉树
	int ch;
	//:cout << "\n请输入二叉树元素：（输入0代表该位置没有元素）\n";
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

void MidVisit(BiTree T) {//递归的中序遍历函数
	if (T) {
		MidVisit(T->lchild);
		cout << T->data << " ";
		MidVisit(T->rchild);
	}
}

void FirVisit(BiTree T) {//递归的先序遍历函数
	if (T) {
		cout << T->data<<" ";
		FirVisit(T->lchild);
		FirVisit(T->rchild);
	}
}

void LasVisit(BiTree T) {//递归的后序遍历函数
	if (T) {
		LasVisit(T->lchild);
		LasVisit(T->rchild);
		cout << T->data << " ";
	}
}

int Depth(BiTree T) {//递归的返回二叉树的深度
	if (T == NULL) {
		return 0;
	}
	else {
		int m = Depth(T->lchild);       //左子树深度
		int n = Depth(T->rchild);       //右子树深度
		return m > n ? (m + 1): (n + 1);//返回比较长的那一个，并且加上根节点的1
	}
}
//返回树宽度的算法，先定义一个有两个数组的结构体
typedef struct Qu{
	BiTree data[1000];
	int level[1000];
	int front, rear;
}Qu;

int BTWith(BiTree T) {
	BiTnode* p;
	Qu q;                               //自定义的队列Qu
	int k, max, i, n;
	q.front = q.rear = -1;              //初始队列为空
	q.rear++;                           //队首加一
	q.data[q.rear] = T;                 //根节点入队
	q.level[q.rear] = 1;                //根节点层次记为1
	while (q.front < q.rear) {
		q.front++;                      //队头指针加一
		p = q.data[q.front];            //出队
		k = q.level[q.front];           //出队节点的层次
		if (p->lchild != NULL) {        //左孩子不空，则进队
			q.rear++;
			q.data[q.rear] = p->lchild;
			q.level[q.rear] = k + 1;
		}
		if (p->rchild != NULL) {        //左孩子不空，则进队
			q.rear++;
			q.data[q.rear] = p->rchild;
			q.level[q.rear] = k + 1;
		}
	}
	max = 0; i = 0; k = 1;               //max保存同一层最多节点个数，k表示从第一层开始扫描
	while(i<=q.rear){                    //i扫描队中所有元素
		n = 0;                           //n为第k层的节点数目
		while (i <= q.rear && q.level[i] == k) {
			n++; i++;
		}
		k = q.level[i];
		if (n > max) {
			max = n;
		}
	}return max;
}

void LevelVisit(BiTree T) {				 //使用队列，进行自上而下的层次遍历
	queue<BiTnode*>q;					 //初始化队列q，存放BiTnode型节点
	BiTnode* p = T;					   	//p指针指向根节点
	q.push(p);							 //根节点进队
	while (!q.empty()) {				 //遍历未结束
		p = q.front(); q.pop();			 //取队首元素并出队
		if (p->lchild != NULL) {		 //左孩子存在则入队
			q.push(p->lchild);
		}
		if (p->rchild != NULL) {		 //右孩子存在则入队
			q.push(p->rchild);
		}
		cout << p->data<<" ";			 //输出当前节点的数据
	}
}

int DsonNodes(BiTree T) {				 //返回二叉树中度为2的节点
	if (!T) {
		return 0;					    //递归打破条件，如果已经到最右边叶节点，则退出递归
	}
	else if (T->lchild != NULL && T->rchild != NULL) {			//左右孩子都存在的，即度为2的节点
		return DsonNodes(T->lchild) + DsonNodes(T->rchild)+1;  //递归，返回左孩子和右孩子的和加一(这个一是它自身，所以加一)
	}
	else {
		return DsonNodes(T->lchild) + DsonNodes(T->rchild);    //递归，返回左孩子和右孩子的和（自身不算一个度为2的节点，所以不用加一）
	}
}

int FindP(BiTree T) { 
	int p; int n = 0;                                         //p存储需要查找的数据，n用于记录层次
	cout << "\n请输入需要查找的节点数据："; cin >> p;
	BiTnode* r = T;
	queue<BiTnode*>l; queue<BiTnode*>s;                       //主队列，辅助队列，采用层次遍历的形式，对每一个元素进行遍历比较
	l.push(r);                                                //根节点进主队列
	if (r->data == p) {                                       //如果根节点就是需要找的节点，则直接返回1
		return 1;
	}n++;
	while (!l.empty()||!s.empty()) {                             //保持循环
		while (!l.empty()) {                                   //主队列不空时
			r = l.front(); l.pop();                            //出队队首元素
			if (r->lchild != NULL) {                           //左孩子存在时，对左孩子进行判断
				if (r->lchild->data == p) {                    //如果是，直接返回n+1
					n++;
					return n;
				}
				else {
					s.push(r->lchild);                          //如果不是，则入辅助队列
				}
			} 
			if (r->rchild != NULL) {                             //对右孩子做相同的判断
				if (r->rchild->data == p) {
					n++; 
					return n;
				}
				else {
					s.push(r->rchild);
				}
			}
		}n++;                                                    //主队列遍历结束，即这一层的节点都判断过
		while (!s.empty()) {                                     //副队列同样操作
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
	cout << "1、中序输出二叉树元素   2、先序输出二叉树元素     3、后序输出二叉树元素\n\n";
	cout << "4、初始化这个链表       5、先序遍历建立二叉链表   6、自上而下的层次遍历\n\n";
	cout << "7、返回二叉树的深度     8、返回二叉树的宽度       9、返回节点所在层次 \n\n";
	cout << "10、返回上一级          输入选择（输入0直接退出！）：\n";
	cout << "*********************************************************************\n";
}
void BasicOperation(BiTree& T) {
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
		case 4:
			cout << "\n你的选择是：4、初始化这个链表\n";
			InitBiTree(T);
			break;
		case 5:
			cout << "\n你的选择是：5、先序遍历建立二叉链表\n";
			cout << "先序方式创立二叉树，请输入二叉树元素（0代表此位置无元素）：";
			FirCreateBiTree(T);
			break;
		case 6:
			cout << "\n你的选择是：6、自上而下的层次遍历\n";
			LevelVisit(T);
			break;
		case 7:
			cout << "\n你的选择是：7、返回二叉树的深度\n";
			cout << Depth(T);
			break;
		case 8:
			cout << "\n你的选择是：8、返回二叉树的宽度\n";
			cout << BTWith(T);
			break;
		case 9:
			cout << "\n你的选择是：9、返回节点所在层次\n";
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