//��һ����С�� 2 x n ������������Ҫ��2�ֹ��Ĺ������������ƹ��ֱ��� 2 x 1 �� 2 x 2�������һ���ж���������ķ�����

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