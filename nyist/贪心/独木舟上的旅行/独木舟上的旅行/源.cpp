//最少的船只
//限定只能装2人，且有体重限制
//思路：先排序，两个指针分别指向头尾，体重和满足条件，则同时向中间移动，否则，只有后面的指针移动
//http://acm.nyist.net/JudgeOnline/problem.php?pid=71

//完成
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int s;
	cin >> s;
	for (int i = 0; i < s; i++)
	{
		int w, n;
		cin >> w >> n;
		int *wi = new int[n];//n人重量
		for (int j = 0; j < n; j++)
		{
			cin >> wi[j];
		}
		sort(wi, wi + n);
		int p = 0, q = n - 1;
		int result = 0;
		while (p <= q){
			if (wi[p] + wi[q] <= w){
				p++;
			}
			q--;
			result++;
		}
		cout << result <<endl;
		delete[]wi;
	}
	return 0;
}