#include<iostream>
using namespace std;
//AC

//n位二进制数，所有数的1的总个数


int main(){
	int T;
	cin >> T;
	int dp[21];
	dp[1] = 1;
	int x = 1;
	for (int i = 2; i < 21; i++)
	{
		dp[i] = x + 2 * dp[i - 1];
		x *= 2;
	}
	while (T--)
	{
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}