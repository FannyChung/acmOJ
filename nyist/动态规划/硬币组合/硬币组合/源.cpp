#include <iostream>
using namespace std;
//û�����

//����n��Ӳ�ҿ������[n,2n]������һ�����ȱ���5�Ŀ��ܣ�Ȼ�����


/*
bool isComb(int n, int m, int &count){
if (m == 0&&n==0){
count++;//�����+1
return true;
}
if (m<0||n==0){
return false;
}
bool isF=false;
if (isComb(n - 1, m - 1, count) ){//����n-1����ֵ-k
isF= true;
}
if (isComb(n - 1, m - 2, count)){
isF = true;
}
if (isComb(n - 1, m - 5, count)){
isF = true;
}
return isF;
}
*/


int getMin(int n, int m){//n�Ǹ�����m����ֵ
	int **p = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		p[i] = new int[m + 1];
		for (int j = 0; j < m + 1; j++)
		{
			p[i][j] = 0;
		}
	}

	p[0][0] = 1;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = i; j < m + 1; j++)//��ֵҪ>=����
		{
			/*if (p[i - 1][j - 1] != -1){
				p[i][j] += p[i - 1][j - 1];
				}
				if (j >= 2&&p[i-1][j-2]!=-1){
				p[i][j] += p[i - 1][j - 2];
				}
				if (j >= 5){
				p[i][j] += p[i - 1][j - 5];
				}*/
			p[i][j] += p[i - 1][j - 1];
			if (j >= 2)
				p[i][j] += p[i - 1][j - 2];
			if (j >= 5)
				p[i][j] += p[i - 1][j - 5];
		}
	}
	return p[n][m];
}

int main() {
	int k;
	cin >> k;
	while (k--){
		int n, m;
		cin >> n >> m;
		int count = 0;
		//isComb(n, m, count);
		cout << getMin(n, m) << endl;
	}
	return 0;
}