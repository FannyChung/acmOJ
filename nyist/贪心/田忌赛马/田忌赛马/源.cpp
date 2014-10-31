/*
根据赛马构建二分图，找最大匹配数
如果田的马能快过王的马，则建立一条边
尽量多赢——找到最大匹配数
如果有ties，需要赋值0，1，-1给所有可能的边，然后再找最大权重匹配
输入：多个测试用例
n——两边马的数量
n个数——田的马速度（整数）
n个数——王的马
输出：赢的最大钱数量（每场200）
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