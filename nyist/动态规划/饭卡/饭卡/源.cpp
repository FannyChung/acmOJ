#include<iostream>
#include<algorithm>
using namespace std;

//UNAC


//用5元买最贵的东西，然后用01背包的思想，n个物品，使他们的总价刚好为


int main(){
	int n, m;
	while (cin>>n)
	{
		int*cost = new int[n];//n种菜的价格
		for (int j = 0; j < n; j++)
		{
			cin >> cost[j];
		}

		cin >> m;//卡上余额
		if (m < 5)
			cout << m << endl;

		else
		{
			sort(cost, cost + n);
			int *p = new int[n + 1];

			m -= 5;
			int j;
			for (int i = 0; i < n; i++)
			{
				for (int j = m; j >=cost[i] ; j--)
				{
					p[j] = max(p[j], p[j - cost[i]] + cost[i]);
				}
			}
			/*

			p[n] = m;
			int minRe = m;
			for (int i = n - 1; i >= 0; i--)//从后向前遍历到第i种菜
			{
				if (p[i + 1] < 5){
					minRe = p[i + 1];
					break;
				}

			}*/
		}
		

	}

	return 0;
}