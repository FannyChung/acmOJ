//喷水装置2：给定喷水的位置和半径，求最小的数量——区间覆盖

//贪心：左端点从小到大排序，找到满足left<start的最大的右端点，修改start为他的右端点,后面再次遍历的时候，i保持原来的
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
using namespace std;
#define NUNOK -10000000
struct Point
{
	double l;
	double r;
	bool operator<(const Point& other)const{//按左端点从小到大排序
		return l < other.l;
	}
};

int getNum(Point p[], int n,int w,int h){
	double start = 0;
	int count = 0;
	int i = 0;
	double a;
	double b;
	while (p[i].l == NUNOK)//跳过半径太小  以至于 没有h/2大的
	{
		i++;
	}
	while (start<w)
	{
		int maxR = start;
		while (p[i].l <= start)//循环找到满足左端点条件的  最大的右端点
		{
			if (p[i].r > maxR){
				maxR = p[i].r;
			}
			i++;
			if (i >= n)
				break;
		}
		if (i >= n&&maxR < w){
			return 0; 
		}
		if (maxR == start){//没有满足l<start的（最小的左端点也不满足）
			return 0;
		}
		start = maxR;
		count++;
	}
	return count;
}

int main(){
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)//n组测试数据
	{
		int n,w,h;
		cin >> n;
		cin >> w >> h;//长、宽
		Point *p = new Point[n];
		int x, r;
		for (int j = 0; j < n; j++)//n个装置
		{
			cin >> x >> r;
			if (r<=(h/2)){
				p[j].l = NUNOK;
				p[j].r = NUNOK;
			}
			else
			{
				double p2 = static_cast<double>(r*r) -( h / 2)*(h/2);
				double a = sqrt(p2);
				p[j].l = x - a;//计算左右端点
				p[j].r = x + a;
			}
		}
		sort(p, p + n);//按左端点从小到大排序
		cout << getNum(p, n, w, h)<<endl;
		delete[]p;
	}
	return 0;
}