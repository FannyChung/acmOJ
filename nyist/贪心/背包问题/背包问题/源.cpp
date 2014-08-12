//背包问题
//可分割

//思想：选择单位价值最大的优先

//AC
#include<iostream>
#include<algorithm>
#include <functional>
using namespace std;

struct Thing
{
	int v;//单价
	int w;//重量
	bool operator<(const Thing& other)const{
		return v < other.v;
	}
	bool operator>(const Thing& other)const{
		return v > other.v;
	}
};
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)//n组测试数据
	{
		int s, m;
		cin >> s >> m;//s个物品，背包容量m
		Thing *t = new Thing[s];
		for (int j = 0; j < s; j++)
		{
			cin >> t[j].v >> t[j].w;
		}
		sort(t, t + s, greater<Thing>());//按照单位价值由大到小排序
		int j = 0;
		int valSum = 0;//总价值
		while (1){
			int remain = m - t[j].w;
			if (remain < 0){
				break;
			}
			valSum += t[j].w*t[j].v;
			j++;
			m = remain;
		}
		//最后可能可以放一部分的当前物品
		if (m > 0){
			valSum += m*t[j].v;
		}
		cout << valSum << endl;
		delete[]t;
	}
	return 0;
}