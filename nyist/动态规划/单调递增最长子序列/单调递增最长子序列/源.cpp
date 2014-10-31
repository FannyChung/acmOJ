#include<iostream>
#include<string>
using namespace std;

int getMax(string s){
	int b = 1;
	int result = 0;
	for (int j = 0; j <s.length() - 1; j++)
	{
		if (s[j] < s[j + 1]){
			b++;
		}
		else
		{
			result = (result>b ? result : b);
			b = 1;
		}
	}

	result = (result>b ? result : b);
	if (s.length() == 1){
		result = 0;
	}
	return result;
}

int getRecersiveMax(string s, int i, int res[]){//备忘录，动态规划
	
	//没完成
	if (i == s.length())
		return 0;
	if (res[i] != 0)
		return res[i];

	int p;
	int max=0;
	for (int j = i + 1; j < s.length(); j++)
	{
		p = getRecersiveMax(s, j, res);
		if (max < p)
			max = p;
	}
	res[i] = 1+max;
	return res[i];
}
int getMaxLCSLen(string s1, string s2, int i, int j){//动态规划，迭代，
	int **k = new int*[i + 1];
	for (int x = 0; x < i + 1; x++)
	{
		k[x] = new int[j + 1];
		/*for (int b = 0; b < j+1; b++)
		{
		k[j][b] = 0;
		}*/
	}
	for (int m = 0; m < i + 1; m++)
	{
		k[m][0] = 0;
	}
	for (int m = 0; m < j + 1; m++)
	{
		k[0][m] = 0;
	}


	for (int m = 1; m < i + 1; m++)
	{
		for (int n = 1; n < j + 1; n++)
		{
			if (s1[m - 1] == s2[n - 1]){
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
	for (int m = 0; m < i + 1; m++)
	{
		delete[] k[m];
	}
	delete[]k;
	return result;
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s1;
		cin >> s1;
		/*string s2 = "abcdefghijklmnopqrstuvwxyz";
		int n1 = s1.length();
		int n2 = s2.length();
		cout << getMaxLCSLen(s1, s2, n1, n2) << endl;*/

		int *res = new int[s1.length()];
		for (int j = 0; j < s1.length(); j++)
		{
			res[j] = 0;
		}
		cout << res[0] << endl;
	}

	return 0;
}