#include<iostream>
#include<string>
using namespace std;
/*
int getMaxLCSLen(string s1, string s2,int i,int j){//普通递归，超时
	if (i < 0 || j < 0){
		return 0;
	}
	if (s1[i] == s2[j]){
		return 1 + getMaxLCSLen(s1, s2, i - 1, j - 1);
	}
	int a = getMaxLCSLen(s1, s2, i - 1, j);
	int b = getMaxLCSLen(s1, s2, i, j - 1);
	return a>b ? a : b;
}
*/
/*
int getMaxLCSLen(string s1, string s2, int i, int j){//动态规划，备忘录，超时
	if (i < 0 || j < 0){
		return 0;
	}
	if (k[i][j] != 0)
		return k[i][j];
	
	if (s1[i] == s2[j]){
		k[i][j]=1 + getMaxLCSLen(s1, s2, i - 1, j - 1);
		return k[i][j];
	}
	int a = getMaxLCSLen(s1, s2, i - 1, j);
	int b = getMaxLCSLen(s1, s2, i, j - 1);
	k[i][j] = a > b ? a : b;
	return a>b ? a : b;
}
*/
int getMaxLCSLen(string s1, string s2, int i, int j){//动态规划，迭代，
	int **k = new int*[i+1];
	for (int x = 0; x < i+1; x++)
	{
		k[x] = new int[j+1];
		/*for (int b = 0; b < j+1; b++)
		{
			k[j][b] = 0;
		}*/
	}
	for (int m = 0; m < i+1; m++)
	{
		k[m][0] = 0;
	}
	for (int m = 0; m < j+1; m++)
	{
		k[0][m] = 0;
	}


	for (int m = 1; m < i+1; m++)
	{
		for (int n = 1; n < j+1; n++)
		{
			if (s1[m-1] == s2[n-1]){
				k[m][n] = 1 + k[m - 1][n - 1];
			}
			else
			{
				int a = k[m - 1][n];
				int b = k[m][n - 1];
				k[m][n] = (a > b ? a : b);
			}
		}
	}
	int result = k[i][j];
	for (int m = 0; m < i+1; m++)
	{
		delete[] k[m];
	}
	delete[]k;
	return result;
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)//n组测试数据
	{
		string s1,s2;
		cin >> s1>>s2;
		int n1 = s1.length();
		int n2 = s2.length();
		cout << getMaxLCSLen(s1, s2,n1,n2) << endl;
	}
	return 0;
}