#include<iostream>
using namespace std;
//UNAC

//给定 f[n] = a * f[n-1] + b * f[n-2]中的系数a,b，并给定初值f[0]和f[1]

#define MOD 1000000007
int main(){
	unsigned int f0, f1, a, b;
	unsigned long long n;
	unsigned long long f2;
	while (cin >> f0 >> f1 >> a >> b>>n){
		if (n == 0){
			cout << f0 << endl;
		}
		else if (n == 1){
			cout << f1 << endl;
		}
		else
		{
			while (n>0)
			{
				f2 = static_cast<unsigned long long>(a)*f1 + static_cast<unsigned long long>(b)*f0;
				if (f2 >= MOD)
					f2 -= MOD;
				f0 = f1;
				f1 = f2;
				n--;
			}
			cout << f2 << endl;
		}
	}
	return 0;
}