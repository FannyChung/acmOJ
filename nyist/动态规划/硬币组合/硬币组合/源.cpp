#include <iostream>
using namespace std;
//没有完成

//利用n个硬币可以组成[n,2n]的任意一个，先遍历5的可能，然后计算


/*
bool isComb(int n, int m, int &count){
if (m == 0&&n==0){
count++;//组合数+1
return true;
}
if (m<0||n==0){
return false;
}
bool isF=false;
if (isComb(n - 1, m - 1, count) ){//个数n-1，面值-k
isF= true;
}
if (isComb(n - 1, m - 2, count)){
isF = true;
}
if (isComb(n - 1, m - 5, count)){
isF = true;
}
return isF;
}
*/


int getMin(int n, int m){//n是个数，m是面值
	int **p = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		p[i] = new int[m + 1];
		for (int j = 0; j < m + 1; j++)
		{
			p[i][j] = 0;
		}
	}

	p[0][0] = 1;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = i; j < m + 1; j++)//面值要>=个数
		{
			/*if (p[i - 1][j - 1] != -1){
				p[i][j] += p[i - 1][j - 1];
				}
				if (j >= 2&&p[i-1][j-2]!=-1){
				p[i][j] += p[i - 1][j - 2];
				}
				if (j >= 5){
				p[i][j] += p[i - 1][j - 5];
				}*/
			p[i][j] += p[i - 1][j - 1];
			if (j >= 2)
				p[i][j] += p[i - 1][j - 2];
			if (j >= 5)
				p[i][j] += p[i - 1][j - 5];
		}
	}
	return p[n][m];
}

int main() {
	int k;
	cin >> k;
	while (k--){
		int n, m;
		cin >> n >> m;
		int count = 0;
		//isComb(n, m, count);
		cout << getMin(n, m) << endl;
	}
	return 0;
}