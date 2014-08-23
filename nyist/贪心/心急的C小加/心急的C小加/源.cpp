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

int getMax(Wood *wood, int i,int k, int n){//i是当前 k是前一个被加入链的元素
	if (i == n - 1){
		int s1 = getMax(wood, i - 1, i, n)+1;//包括最后一个元素
		int s2 = getMax(wood, i - 1, n, n);//不包括
	}
	if (i < 0)
		return 0;
	if (wood[k].l > wood[i].l&&wood[k].w > wood[i].w){
		return 1 + getMax(wood, i - 1, i, n);
	}
	else
	{
		return getMax(wood, i - 1, k, n);
	}
}
int getMaxUp(Wood *wood,int i,int last,int n){//数组的i~n-1的最长上升个数
	if (i == n){
		return 0;
	}
	int tmp1,tmp2;
	tmp1 = getMaxUp(wood, i + 1, last, n);//不在
	if (wood[i].w < wood[last].w){//不相容
		return tmp1;
	}
	tmp2 = 1 + getMaxUp(wood, i + 1, i, n);//在
	return (tmp1 > tmp2 )? tmp1 : tmp2;
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

		cout << getMaxUp(wall, << endl;
		delete[]wall;
	}
	return 0;
}