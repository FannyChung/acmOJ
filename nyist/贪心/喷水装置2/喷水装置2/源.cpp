//��ˮװ��2��������ˮ��λ�úͰ뾶������С�������������串��

//̰�ģ���˵��С���������ҵ�����left<start�������Ҷ˵㣬�޸�startΪ�����Ҷ˵�,�����ٴα�����ʱ��i����ԭ����
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
using namespace std;
#define NUNOK -10000000
struct Point
{
	double l;
	double r;
	bool operator<(const Point& other)const{//����˵��С��������
		return l < other.l;
	}
};

int getNum(Point p[], int n,int w,int h){
	double start = 0;
	int count = 0;
	int i = 0;
	double a;
	double b;
	while (p[i].l == NUNOK)//�����뾶̫С  ������ û��h/2���
	{
		i++;
	}
	while (start<w)
	{
		int maxR = start;
		while (p[i].l <= start)//ѭ���ҵ�������˵�������  �����Ҷ˵�
		{
			if (p[i].r > maxR){
				maxR = p[i].r;
			}
			i++;
			if (i >= n)
				break;
		}
		if (i >= n&&maxR < w){
			return 0; 
		}
		if (maxR == start){//û������l<start�ģ���С����˵�Ҳ�����㣩
			return 0;
		}
		start = maxR;
		count++;
	}
	return count;
}

int main(){
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)//n���������
	{
		int n,w,h;
		cin >> n;
		cin >> w >> h;//������
		Point *p = new Point[n];
		int x, r;
		for (int j = 0; j < n; j++)//n��װ��
		{
			cin >> x >> r;
			if (r<=(h/2)){
				p[j].l = NUNOK;
				p[j].r = NUNOK;
			}
			else
			{
				double p2 = static_cast<double>(r*r) -( h / 2)*(h/2);
				double a = sqrt(p2);
				p[j].l = x - a;//�������Ҷ˵�
				p[j].r = x + a;
			}
		}
		sort(p, p + n);//����˵��С��������
		cout << getNum(p, n, w, h)<<endl;
		delete[]p;
	}
	return 0;
}