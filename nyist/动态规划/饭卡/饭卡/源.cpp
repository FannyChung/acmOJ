#include<iostream>
#include<algorithm>
using namespace std;

//UNAC


//��5Ԫ�����Ķ�����Ȼ����01������˼�룬n����Ʒ��ʹ���ǵ��ܼ۸պ�Ϊ


int main(){
	int n, m;
	while (cin>>n)
	{
		int*cost = new int[n];//n�ֲ˵ļ۸�
		for (int j = 0; j < n; j++)
		{
			cin >> cost[j];
		}

		cin >> m;//�������
		if (m < 5)
			cout << m << endl;

		else
		{
			sort(cost, cost + n);
			int *p = new int[n + 1];

			m -= 5;
			int j;
			for (int i = 0; i < n; i++)
			{
				for (int j = m; j >=cost[i] ; j--)
				{
					p[j] = max(p[j], p[j - cost[i]] + cost[i]);
				}
			}
			/*

			p[n] = m;
			int minRe = m;
			for (int i = n - 1; i >= 0; i--)//�Ӻ���ǰ��������i�ֲ�
			{
				if (p[i + 1] < 5){
					minRe = p[i + 1];
					break;
				}

			}*/
		}
		

	}

	return 0;
}