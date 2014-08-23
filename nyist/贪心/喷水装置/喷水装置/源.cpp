#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
#define Lenth 20
#define Width 2

int getNum(double R[],int n){
	double remain = Lenth;
	int count = 0;
	for (int i = n-1; i >=0; i--)
	{
		double a = sqrt(R[i] * R[i] - Width/2);
		if (remain > 0){
			remain -= (a*2);
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}
int main(){
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)//m组测试数据
	{
		int n;
		cin >> n;//n个喷水装置
		double *R=new double[n];
		for (int j = 0; j < n; j++)
		{
			cin >> R[j];
		}
		sort(R, R + n);
		cout << getNum(R, n) << endl;
		delete[]R;
	}
	return 0;
}