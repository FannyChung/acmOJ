#include<iostream>
using namespace std;
//AC

//nλ������������������1���ܸ���


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