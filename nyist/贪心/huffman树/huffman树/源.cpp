/*
1.�涨��������������������Ϊ0������������Ϊ1��

2.�������ַ�Ȩֵ��ͬ����ASCII��ֵС���ַ�Ϊ���ӣ����Ϊ�Һ��ӣ�

3.�������½ڵ���������ַ����������ӵ��ַ���ͬ��

4.�����ַ�ΪASCII�����32-96֮����ַ������� ������`��֮����ַ�����

����
��������������ݣ�������100�飩
ÿ�����ݵ�һ��һ������n����ʾ�ַ�������������n�У�ÿ����һ���ַ�ch��һ������weight����ʾ�ַ�ch����Ӧ��Ȩֵ���м��ÿո������
�������ݱ�֤ÿ��������ݵ��ַ������ظ���
���
����ÿ��������ݣ���������˳�������Ӧ���ַ��Լ����ǵĹ������������������ʽ��������

��������
3
a 10
b 5
c 8
4
a 1
b 1
c 1
d 1
�������
a:0
b:10
c:11
a:00
b:01
c:10
d:11
*/
//1.ʹ������
//2.ʹ��set
//3.ʹ���Լ�����ĺ���
#include<iostream>
#include<algorithm>//ʹ��set���ñ������߲���߱���
using namespace std;

struct Node
{
	char ch;//�ַ�
	int val;//Ȩֵ
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
	//ÿ��ȡ���������ȥһ��

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