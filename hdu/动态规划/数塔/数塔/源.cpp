//UNAC




#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int C;
	cin >> C;//²âÊÔ×éÊý
	int N;//Ëþ¸ß
	int nums[100][100];
	int sum[100][100];
	while (C--)
	{
		cin >> N;
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cin >> nums[i][j];
			}
		}
		for (int j = 0; j < N; j++)
		{
			sum[N-1][j] = nums[N-1][j];
		}
		for (int i = N-2; i >=0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				sum[i][j] = fmax(sum[i + 1][j], sum[i + 1][j + 1]) + nums[i][j];
			}
		}
		cout << sum[0][0] << endl;
	}
	return 0;
}