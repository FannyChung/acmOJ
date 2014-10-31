/*
John要到镇子上去拿K磅的肥料。开车D公里装载K磅肥料花费D*K分。

县城有N个商店卖肥料，每个商店在X轴上的一段上，长度为E。商店i的地址在Xi（<0Xi<E）,可以卖给他Ci分每磅，Fi磅肥料。 一个点上可以有多个商店。
从0开始，只能正向行驶，最后到达E,带着最少K磅肥料。他可以停在任何肥料店，并且买该店限制数量一下的任何数量的肥料。他最少需要付款多少来买肥料并且运输呢？

输入：
C个测试用例
测试用例以EOF结束
K E N
N行：Xi Fi Ci

输出：
minimum cost to buy and transport the feed\n
*/

//AC
struct Store
{
	int x;//地址
	int f;//上限
	int c;//单价
	bool operator<(const Store & other)const{//综合单价和路程考虑，因为开车D公里装载K磅肥料花费D*K分，所以可以把路程看作单价的一部分
		return x + c < other.x + other.c;
	}
};
#include<iostream>
#include<algorithm>
using namespace std;

int getMinCost(Store *s, int n,int K){//K是需求量
	int i = 0;
	int cost = 0;
	int remain = K;
	while(1){
		remain -= s[i].f;
		if (remain <= 0){
			remain += s[i].f;
			break;
		}
		cost += s[i].f*(s[i].x + s[i].c);
		i++;
	}
	if (remain > 0){
		cost+=remain*(s[i].x + s[i].c);
	}
	return cost;
}
int main(){
	int C;
	cin >> C;
	for (int i = 0; i < C; i++)//c个测试用例
	{
		int K, E, N;
		cin >> K >> E >> N;
		Store *s = new Store[N];
		for (int j = 0; j < N; j++)
		{
			cin >> s[j].x >> s[j].f >> s[j].c;
			s[j].x = E-s[j].x;//变成到终点的距离
		}
		sort(s, s + N);//按新的“单价排序”
		cout << getMinCost(s, N, K)<<endl;
		delete[]s;
	}
	return 0;
}