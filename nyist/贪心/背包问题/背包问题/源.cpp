//��������
//�ɷָ�

//˼�룺ѡ��λ��ֵ��������

//AC
#include<iostream>
#include<algorithm>
#include <functional>
using namespace std;

struct Thing
{
	int v;//����
	int w;//����
	bool operator<(const Thing& other)const{
		return v < other.v;
	}
	bool operator>(const Thing& other)const{
		return v > other.v;
	}
};
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)//n���������
	{
		int s, m;
		cin >> s >> m;//s����Ʒ����������m
		Thing *t = new Thing[s];
		for (int j = 0; j < s; j++)
		{
			cin >> t[j].v >> t[j].w;
		}
		sort(t, t + s, greater<Thing>());//���յ�λ��ֵ�ɴ�С����
		int j = 0;
		int valSum = 0;//�ܼ�ֵ
		while (1){
			int remain = m - t[j].w;
			if (remain < 0){
				break;
			}
			valSum += t[j].w*t[j].v;
			j++;
			m = remain;
		}
		//�����ܿ��Է�һ���ֵĵ�ǰ��Ʒ
		if (m > 0){
			valSum += m*t[j].v;
		}
		cout << valSum << endl;
		delete[]t;
	}
	return 0;
}