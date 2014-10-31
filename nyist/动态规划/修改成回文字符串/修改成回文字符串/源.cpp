#include<string>
#include<iostream>
using namespace std;

int **result;
/*
int minChangeToHui(string s, int i, int j){//备忘录方法
//错误
	if (i >= j){
		return 0;
	}
	if (result[i] != -1){
		return result[i];
	}
	if (s[i] == s[j])
	{
		result[i] = minChangeToHui(s, i + 1, j - 1);
	}
	else
	{
		int a = minChangeToHui(s, i + 1, j);//这两个自问题重叠
		int b = minChangeToHui(s, i, j - 1);
		result[i] = 1 + (a > b ? b : a);
	}
	result[j] = result[i];
	return result[i];
}
*/
/*
int minChangeToHui(string s,int i,int j){//普通递归，超时
	if (i >= j){
		return 0;
	}
	if (s[i] == s[j])
		return minChangeToHui(s, i + 1, j - 1);
	
	int a = minChangeToHui(s, i + 1, j);
	int b = minChangeToHui(s, i, j - 1);
	return 1+(a > b ? b : a);
}
*/
/*
int minChangeToHui(string s, int i, int j){//备忘录方法，超时
	/*
	for (int i = 0; i < s.length(); i++)
	{
		result[i][i] = 0;
		for (int j = i+1; j < s.length(); j++)
		{
			if (s[i] == s[j]){
				result[i][j] = result[i + 1][j + 1];
			}
		}
	}
	if (i >= j){
		return 0;
	}
	if (result[i][j] != 0){
		return result[i][j];
	}

	if (s[i] == s[j]){
		result[i][j] = minChangeToHui(s, i + 1, j-1);
		return result[i][j];
	}

	int a = minChangeToHui(s, i + 1, j);
	int b = minChangeToHui(s, i, j - 1);


	if (a > b){
		result[i][j] = 1 + b;
	}
	else
	{
		result[i][j] = 1 + a;
	}
	return result[i][j];
	
}*/

int minChangeToHui(string s, int p, int q){//自底向上，动态规划
	//i是递增的，而j是递减的
	int n = s.length();
	//i<=j result=0
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			result[i][j] = 0;
		}
	}
	for (int i = n-1; i >= 0; i--)
	{
		for (int j = i+1; j < n; j++)
		{
			//if (result[i][j] != 0){
			if (1){
				if (s[i] == s[j]){
					result[i][j] = result[i + 1][j - 1];
				}
				else
				{
					int a = result[i + 1][j];
					int b = result[i][j - 1];
					result[i][j] = 1 + (a > b ? b : a);
				}
			}
		}
	}
	return result[0][n - 1];
}
int main(){
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		result = new int*[s.length()];
		for (int i = 0; i < s.length(); i++)
		{
			result[i] = new int[s.length()];
			for (int j = 0; j < s.length(); j++)
			{
				result[i][j] = 0;
			}
		}
		cout << minChangeToHui(s, 0, s.length() - 1)<<endl;
		for (int i = 0; i < s.length(); i++)
		{
			delete[]result[i];
		}
		delete[]result;
	}
	return 0;
}