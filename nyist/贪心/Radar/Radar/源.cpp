/*
���躣���������޳���ֱ�ߣ������Ǻ����ߵ�һ�ߣ�������һ�ߡ�ÿ��С���Ǻ���ߵ�һ���㣬ÿ���״ﰲװ�ں����ߣ�ֻ�ܰ���d�ľ��룬����������ǵľ���<=d,һ�����ܱ�һ���״�վ����.
����ʹ�õѿ�������ϵ�����庣������x�ᣬ����x�Ϸ����������ĵ�ַ�����״�ĸ��Ƿ�Χ��д���ҵ����ٵ��״�վ������������ЩС����ע�⵺�ĵ�ַ����x-y�������

�����ǣ�
n(��������) d(�״�뾶)
n������
һ������

��0 0��β

�����
Case 1:2
Case 2:-1(���ܸ���)
ʵ����
3 2
1 2
-3 1
2 1

1 2
0 2

0 0

�����
Case 1: 2
Case 2: 1
*/
#include<iostream>
#include<algorithm>
using namespace std;
struct Point
{
	int x;
	int y;
	bool operator<(const Point &other)const{
		return y < other.y;
	}
};

int getMinCount(Point *ps, int n, int d){
	if (ps[n-1].y > d)
		return -1;


}

int main(){
	int n, d;
	int cs = 1;
	while (cin>>n>>d)
	{
		Point *ps = new Point[n];
		for (int i = 0; i < n; i++)
		{
			cin >> ps[i].x >> ps[i].y;
		}
		sort(ps, ps + n);
		cout << "Case " << cs << ":";
		delete[] ps;
	}
	return 0;
}