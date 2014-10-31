/*
1.规定哈弗曼树的左子树编码为0，右子树编码为1；

2.若两个字符权值相同，则ASCII码值小的字符为左孩子，大的为右孩子；

3.创建的新节点所代表的字符与它的左孩子的字符相同；

4.所有字符为ASCII码表上32-96之间的字符（即“ ”到“`”之间的字符）。

输入
输入包含多组数据（不超过100组）
每组数据第一行一个整数n，表示字符个数。接下来n行，每行有一个字符ch和一个整数weight，表示字符ch所对应的权值，中间用空格隔开。
输入数据保证每组测试数据的字符不会重复。
输出
对于每组测试数据，按照输入顺序输出相应的字符以及它们的哈弗曼编码结果，具体格式见样例。

样例输入
3
a 10
b 5
c 8
4
a 1
b 1
c 1
d 1
样例输出
a:0
b:10
c:11
a:00
b:01
c:10
d:11
*/
//1.使用数组
//2.使用set
//3.使用自己定义的函数
#include<iostream>
#include<algorithm>//使用set不好遍历，边插入边遍历
using namespace std;

struct Node
{
	char ch;//字符
	int val;//权值
	bool operator<(const Node& other)const{
		if (val != other.val){
			return val < other.val;
		}
		else
		{
			return ch < other.ch;
		}
	}
};

void calHuffman(Node* nds,Node* result,int n){
	int i = 0;
	//每次取两个，插进去一个

}

int main(){
	int n;
	while (cin >> n)
	{
		Node* nds = new Node[n];
		for (int i = 0; i < n; i++)
		{
			cin >> nds[i].ch >> nds[i].val;
		}
		sort(nds, nds + n);
		Node* result = new Node[2 * n - 1];

		delete[] result;
		delete[] nds;
	}
	return 0;
}