//求最短时间处理完所有木棒
//思路：即最长的上升序列长度

#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
struct Wood
{
	int l;
	int w;
	bool operator<(const Wood &other)const{
		return (l < other.l);
	}
};
int getMaxRevLen(Wood *wood, int i,int last,int n){
	if (i == n)
		return 0;
	if (last == -1){
		int max=0;
		while (wood[i].w<=wood[i + 1].w)//能够比较，则不在最长反链中
		{
			i++;
		}
		int k1 = getMaxRevLen(wood, i+1, last,n);//不在
		int k2 = 1 + getMaxRevLen(wood, i + 1, i,n);//在，i变为last
		return (k1>k2 ? k1 : k2);//取大者
	}
	if (wood[i].w >= wood[last].w){//可比，不在
		return getMaxRevLen(wood, i + 1, last,n);
	}
	else
	{
		return 1+getMaxRevLen(wood, i + 1, i,n);
	}
}
int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)//T组测试
	{
		int N;
		cin >> N;//N个木棒
		Wood *wall = new Wood[N];
		for (int j = 0; j < N; j++)
		{
			cin >> wall[j].l >> wall[j].w;
		}
		sort(wall, wall + N);//按照l排序

		cout << "result"<<getMaxRevLen(wall, 0, -1,N) << endl;
		delete[]wall;
	}
	return 0;
}