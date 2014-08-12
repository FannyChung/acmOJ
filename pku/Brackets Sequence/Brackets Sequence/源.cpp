#include<iostream>
#include<vector>
using namespace std;

void calcu(int a[],int n){
	vector<bool> b(n);
	b[0]=true;
	for (int i = 1; i < n; i++)
	{
		bool tag = true;
		for (int j = 0; j < i; j++)
		{
			if (b[j]){
				if (a[j]>a[i]){
					tag = false;
					break;
				}
			}
		}
		if (tag){//大于存在递增序列的每一个元素
			a[i] = true;
		}
		else
		{

		}
	}
}

int main(){
	int N;
	int *s = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
	}
	calcu(s,N);
	return 0;
}