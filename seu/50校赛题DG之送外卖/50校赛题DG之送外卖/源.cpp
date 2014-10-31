#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<algorithm>
using namespace std;

//UN
int main(){
	unsigned int n;
	cin >> n;
	while (n!=0)
	{
		unsigned int *t = new unsigned int[n];
		for (unsigned int i = 0; i < n; i++)
		{
			cin >> t[i];
		}
		sort(t, t + n);
		unsigned int sum = 0;
		unsigned int k = 0;
		for (unsigned int i = 0; i < n; i++)
		{
			k += t[i];
			sum += k;
		}
		double avg = static_cast<double>(sum) / n;
		//cout << fixed(3) << avg << endl;
		printf("%.3f\n", avg);
		delete[]t;
		cin >> n;
	}
	return 0;
}