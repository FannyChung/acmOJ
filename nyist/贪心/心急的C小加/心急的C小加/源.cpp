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

int getMax(Wood *wood, int i,int k, int n){//i�ǵ�ǰ k��ǰһ������������Ԫ��
	if (i == n - 1){
		int s1 = getMax(wood, i - 1, i, n)+1;//�������һ��Ԫ��
		int s2 = getMax(wood, i - 1, n, n);//������
	}
	if (i < 0)
		return 0;
	if (wood[k].l > wood[i].l&&wood[k].w > wood[i].w){
		return 1 + getMax(wood, i - 1, i, n);
	}
	else
	{
		return getMax(wood, i - 1, k, n);
	}
}
int getMaxUp(Wood *wood,int i,int last,int n){//�����i~n-1�����������
	if (i == n){
		return 0;
	}
	int tmp1,tmp2;
	tmp1 = getMaxUp(wood, i + 1, last, n);//����
	if (wood[i].w < wood[last].w){//������
		return tmp1;
	}
	tmp2 = 1 + getMaxUp(wood, i + 1, i, n);//��
	return (tmp1 > tmp2 )? tmp1 : tmp2;
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

		cout << getMaxUp(wall, << endl;
		delete[]wall;
	}
	return 0;
}