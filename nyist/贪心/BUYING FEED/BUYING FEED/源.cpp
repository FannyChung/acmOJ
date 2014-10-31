/*
JohnҪ��������ȥ��K���ķ��ϡ�����D����װ��K�����ϻ���D*K�֡�

�س���N���̵������ϣ�ÿ���̵���X���ϵ�һ���ϣ�����ΪE���̵�i�ĵ�ַ��Xi��<0Xi<E��,����������Ci��ÿ����Fi�����ϡ� һ�����Ͽ����ж���̵ꡣ
��0��ʼ��ֻ��������ʻ����󵽴�E,��������K�����ϡ�������ͣ���κη��ϵ꣬������õ���������һ�µ��κ������ķ��ϡ���������Ҫ�������������ϲ��������أ�

���룺
C����������
����������EOF����
K E N
N�У�Xi Fi Ci

�����
minimum cost to buy and transport the feed\n
*/

//AC
struct Store
{
	int x;//��ַ
	int f;//����
	int c;//����
	bool operator<(const Store & other)const{//�ۺϵ��ۺ�·�̿��ǣ���Ϊ����D����װ��K�����ϻ���D*K�֣����Կ��԰�·�̿������۵�һ����
		return x + c < other.x + other.c;
	}
};
#include<iostream>
#include<algorithm>
using namespace std;

int getMinCost(Store *s, int n,int K){//K��������
	int i = 0;
	int cost = 0;
	int remain = K;
	while(1){
		remain -= s[i].f;
		if (remain <= 0){
			remain += s[i].f;
			break;
		}
		cost += s[i].f*(s[i].x + s[i].c);
		i++;
	}
	if (remain > 0){
		cost+=remain*(s[i].x + s[i].c);
	}
	return cost;
}
int main(){
	int C;
	cin >> C;
	for (int i = 0; i < C; i++)//c����������
	{
		int K, E, N;
		cin >> K >> E >> N;
		Store *s = new Store[N];
		for (int j = 0; j < N; j++)
		{
			cin >> s[j].x >> s[j].f >> s[j].c;
			s[j].x = E-s[j].x;//��ɵ��յ�ľ���
		}
		sort(s, s + N);//���µġ���������
		cout << getMinCost(s, N, K)<<endl;
		delete[]s;
	}
	return 0;
}