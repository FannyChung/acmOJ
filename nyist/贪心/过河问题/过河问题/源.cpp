//�������˶��ܹ��ӵ�����ʱ��
//˼·������
#include<iostream>
#include <algorithm>
using namespace std;
const int MAXTIME = 100;
int *s;
int getMinSum(int n){
	if (n <= 2){
		return s[n];
	}
	else//ż��
	{
		return s[n] + getMinSum(n - 2);
	}
}
int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)//T���������
	{
		int N;
		cin >> N;
		s= new int[N];
		for (int j = 0; j < N; j++)//N���˵Ļ���ʱ��
		{
			cin >> s[j];
		}
		int tmp = 0;
		int result;
		if (N % 2){//����,��һ��Ҫ�򵥣��ǵ�3��,s[2]
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