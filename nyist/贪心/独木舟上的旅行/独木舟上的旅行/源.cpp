//���ٵĴ�ֻ
//�޶�ֻ��װ2�ˣ�������������
//˼·������������ָ��ֱ�ָ��ͷβ�����غ�������������ͬʱ���м��ƶ�������ֻ�к����ָ���ƶ�
//http://acm.nyist.net/JudgeOnline/problem.php?pid=71

//���
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
		int *wi = new int[n];//n������
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