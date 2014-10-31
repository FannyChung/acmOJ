//有一个大小是 2 x n 的网格，现在需要用2种规格的骨牌铺满，骨牌规格分别是 2 x 1 和 2 x 2，请计算一共有多少种铺设的方法。

#include<iostream>
using namespace std;




int main(){
	int T;
	cin >> T;
	int dp[31];
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i < 31; i++)
	{
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
	}
	while (T--)
	{
		int N;
		cin >> N;
		cout << dp[N] << endl;
	}
	return 0;
}