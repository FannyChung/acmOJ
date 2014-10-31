/*
假设海岸线是无限长的直线，土地是海岸线的一边，海在另一边。每个小岛是海这边的一个点，每个雷达安装在海岸线，只能包含d的距离，所以如果它们的距离<=d,一个岛能被一个雷达站覆盖.
我们使用笛卡尔坐标系，定义海岸线是x轴，海在x上方，给定岛的地址，和雷达的覆盖范围，写出找到最少的雷达站数量来覆盖这些小岛，注意岛的地址是用x-y坐标代替

输入是：
n(岛的数量) d(雷达半径)
n行坐标
一个空行

以0 0结尾

输出：
Case 1:2
Case 2:-1(不能覆盖)
实例：
3 2
1 2
-3 1
2 1

1 2
0 2

0 0

输出：
Case 1: 2
Case 2: 1
*/
#include<iostream>
#include<algorithm>
using namespace std;
struct Point
{
	int x;
	int y;
	bool operator<(const Point &other)const{
		return y < other.y;
	}
};

int getMinCount(Point *ps, int n, int d){
	if (ps[n-1].y > d)
		return -1;


}

int main(){
	int n, d;
	int cs = 1;
	while (cin>>n>>d)
	{
		Point *ps = new Point[n];
		for (int i = 0; i < n; i++)
		{
			cin >> ps[i].x >> ps[i].y;
		}
		sort(ps, ps + n);
		cout << "Case " << cs << ":";
		delete[] ps;
	}
	return 0;
}