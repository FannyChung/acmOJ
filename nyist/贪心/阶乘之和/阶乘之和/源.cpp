//判断一个数是否是某些正数的阶乘之和

//思路：利用递归

//完成
#include<iostream>
using namespace std;

int jie(int i){
	if (i == 1){
		return 1;
	}
	return i*jie(i - 1);
}

bool isJie(int n,int i){//判断n是否是阶乘之和
	if (n == 0){
		return true;
	}
	int tmp = n - jie(i);

	if (tmp<0){
		return false;
	}
	if (isJie(tmp,i+1)){//包含i的阶乘
		return true;
	}
	else{
		return isJie(n, i + 1);//不包含i的阶乘
	}
}

bool isJieSum(int n,int k[]){//贪心实现
	for (int i = 8; i >=0; i--)
	{
		if (n>=k[i]){
			n -= k[i];
		}
		if (n == 0){
			return true;
		}
	}
	return false;
}


int main(){
	int m;
	cin >> m;
	int tmp = 1;
	int k[9];
	for (int i = 1; i <= 9; i++)
	{
		k[i-1] = tmp;
		cout << tmp << endl;
		tmp *= (i + 1);
	}
	for (int i = 0; i < m; i++)//m组测试数据
	{
		int n;
		cin >> n;
		//if (isJie(n, 1)){
		if (isJieSum(n,k)){
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}