#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	int **num = new int*[n];
	int **s = new int*[n];
	for (int i = 0; i < n; i++)
	{
		num[i] = new int[n];
		s[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			cin >> num[i][j];
		}
	}

	for (int i = 0; i < n; i++)//初始化倒数第一行
	{
		s[n - 1][i] = num[n - 1][i];
	}

	for (int i = n-2; i >=0; i--)//从倒数第二行开始
	{
		for (int j = 0; j <= i; j++)
		{
			s[i][j] = num[i][j] + (s[i + 1][j] > s[i + 1][j + 1] ? s[i + 1][j] : s[i + 1][j + 1]);
		}
	}
	cout << s[0][0] << endl;
	for (int i = 0; i < n; i++)
	{
		delete[]num[i];
	}
	delete[]num;
	return 0;
}