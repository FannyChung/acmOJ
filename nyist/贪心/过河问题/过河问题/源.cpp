//求所有人都能过河的最少时间
//思路：排序，
#include<iostream>
#include <algorithm>
using namespace std;
const int MAXTIME = 100;
int *s;
int getMinSum(int n){
	int result = 0;
	int i;
	for ( i = n-1; i >2; i-=2)
	{
		int s1 = s[0] + 2 * s[1] + s[i];
		int s2 = 2 * s[0] + s[i - 1] + s[i];
		result += (s1 < s2 ? s1 : s2);
	}
	if (i == 2){
		result += s[0] + s[1] + s[2];//0,2  0  0,1
	}
	else if (i == 1){
		result += s[1];//0,1 一起
	}
	else
		result += s[0];//0 一个
	return result;
}
int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)//T组测试数据
	{
		int N;
		cin >> N;
		s= new int[N];
		for (int j = 0; j < N; j++)//N个人的花费时间
		{
			cin >> s[j];
		}
		sort(s, s + N);
		cout << getMinSum(N) << endl;
		delete[]s;
	}
	return 0;
}