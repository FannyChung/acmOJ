#include<iostream>
#include<algorithm>
using namespace std;

int getMaxVal(int *a1, int *a2, int N, int M){
	int i = N - 1, j = M - 1;
	int val = 0;
	while (i>0&&j>0)
	{
		val += a1[i];
		val += a2[j];
		i--;
		j--;
	}
	return val;
}

int main(){
	int N, M;
	cin >> N >> M;//N个广告，M个广告位
	int *b1 = new int[N];
	int *b2 = new int[M];
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		b1[i] = tmp*(i + 1);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> tmp;
		b2[i] = tmp*(i + 1);
	}
	sort(a1, a1 + N);
	sort(a2, a2 + M);



	delete[]a1;
	delete[]a2;
	return 0;
}