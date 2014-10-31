//�����ʱ�䴦��������ľ��
//˼·��������������г���

#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
struct Wood
{
	int l;
	int w;
	bool operator<(const Wood &other)const{
		return (l < other.l);
	}
};
int getMaxRevLen(Wood *wood, int i,int last,int n){
	if (i == n)
		return 0;
	if (last == -1){
		int max=0;
		while (wood[i].w<=wood[i + 1].w)//�ܹ��Ƚϣ������������
		{
			i++;
		}
		int k1 = getMaxRevLen(wood, i+1, last,n);//����
		int k2 = 1 + getMaxRevLen(wood, i + 1, i,n);//�ڣ�i��Ϊlast
		return (k1>k2 ? k1 : k2);//ȡ����
	}
	if (wood[i].w >= wood[last].w){//�ɱȣ�����
		return getMaxRevLen(wood, i + 1, last,n);
	}
	else
	{
		return 1+getMaxRevLen(wood, i + 1, i,n);
	}
}
int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)//T�����
	{
		int N;
		cin >> N;//N��ľ��
		Wood *wall = new Wood[N];
		for (int j = 0; j < N; j++)
		{
			cin >> wall[j].l >> wall[j].w;
		}
		sort(wall, wall + N);//����l����

		cout << "result"<<getMaxRevLen(wall, 0, -1,N) << endl;
		delete[]wall;
	}
	return 0;
}