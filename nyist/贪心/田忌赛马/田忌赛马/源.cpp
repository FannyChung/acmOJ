/*
��������������ͼ�������ƥ����
���������ܿ������������һ����
������Ӯ�����ҵ����ƥ����
�����ties����Ҫ��ֵ0��1��-1�����п��ܵıߣ�Ȼ���������Ȩ��ƥ��
���룺�����������
n���������������
n��������������ٶȣ�������
n��������������
�����Ӯ�����Ǯ������ÿ��200��
*/
#include<iostream>
#include<algorithm>
using namespace std;


int getMaxWin(int *t, int *k, int n){
	int result = 0;
	int i = n - 1, j = n - 1;
	while (i>=0&&j>=0)
	{
		if (t[i] > k[j]){
			result++;
			j--;
			i--;
		}
		else
		{
			j--;
		}
	}
	return result;
}

int main(){
	int n;
	while (cin >> n){
		int *tian = new int[n];
		int *king = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> tian[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> king[i];
		}
		sort(tian, tian + n);
		sort(king, king + n);

		cout <<200*getMaxWin(tian, king, n)<<endl;
		delete[] tian;
		delete[] king;
	}

	return 0;
}