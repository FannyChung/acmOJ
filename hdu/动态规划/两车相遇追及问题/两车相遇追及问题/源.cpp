//hdu 1275
//两车从两地出发，求第i次相遇时的时间和地点

//思路：用数学知识，求总长度，再分别求时间和地点

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

void calculate(double len, double a, double b, int num, double &time, double &dist){
	double totalL = len*(2*num-1);//总长度是距离长*次数
	time = totalL / (a + b);//花费时间
	dist = (a*time-floor(a*time/len)*len);//距离某端距离
	if (dist > len / 2)
		dist = len - dist;
}

int main(){
	int N;
	cin >> N;
	double length,aSpeed,bSpeed;//相距距离、a和b的速度、重合的次数
	int num;
	double time, dist;//"重合"时间以及到甲乙较近d距离
	while (N--)
	{
		cin >> length >> aSpeed >> bSpeed >> num;
		calculate(length, aSpeed, bSpeed, num, time, dist);
		cout << fixed << setprecision(3) << "Time=" << time << " Dist=" << dist<<endl;
	}
	return 0;
}