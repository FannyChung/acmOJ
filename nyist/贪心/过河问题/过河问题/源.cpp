//求所有人都能过河的最少时间
//思路：排序，
#include<iostream>
#include <algorithm>
using namespace std;
const int MAXTIME = 100;
int *s;
int getMinSum(int n){
	if (n <= 2){
		return s[n];
	}
	else//偶数
	{
		return s[n] + getMinSum(n - 2);
	}
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
		int tmp = 0;
		int result;
		if (N % 2){//奇数,有一个要打单，是第3个,s[2]
			tmp = s[2];
			s[2] = MAXTIME;
			sort(s, s + N);
			result = getMinSum(N - 1);
		}
		else
		{
			sort(s, s + N);
			result=getMinSum(N);
		}
		cout << result<< endl;
		delete[]s;
	}
	return 0;
}