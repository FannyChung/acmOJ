#include<iostream>
using namespace std;



int main(){
	int f[20];
	f[1] = 1;
	f[2] = 2;
	int kill;
	for (int i = 3; i < 20; i++)
	{
		kill = f[i - 1] - f[i - 2];
		f[i] = 2 * f[i - 1] - kill;
	}

	int n,T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		cout << f[n] << endl;
	}
	
	return 0;
}