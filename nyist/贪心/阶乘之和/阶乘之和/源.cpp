//�ж�һ�����Ƿ���ĳЩ�����Ľ׳�֮��

//˼·�����õݹ�

//���
#include<iostream>
using namespace std;

int jie(int i){
	if (i == 1){
		return 1;
	}
	return i*jie(i - 1);
}

bool isJie(int n,int i){//�ж�n�Ƿ��ǽ׳�֮��
	if (n == 0){
		return true;
	}
	int tmp = n - jie(i);

	if (tmp<0){
		return false;
	}
	if (isJie(tmp,i+1)){//����i�Ľ׳�
		return true;
	}
	else{
		return isJie(n, i + 1);//������i�Ľ׳�
	}
}
int main(){
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)//m���������
	{
		int n;
		cin >> n;
		if (isJie(n, 1)){
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}