//hdu 1275
//���������س��������i������ʱ��ʱ��͵ص�

//˼·������ѧ֪ʶ�����ܳ��ȣ��ٷֱ���ʱ��͵ص�

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

void calculate(double len, double a, double b, int num, double &time, double &dist){
	double totalL = len*(2*num-1);//�ܳ����Ǿ��볤*����
	time = totalL / (a + b);//����ʱ��
	dist = (a*time-floor(a*time/len)*len);//����ĳ�˾���
	if (dist > len / 2)
		dist = len - dist;
}

int main(){
	int N;
	cin >> N;
	double length,aSpeed,bSpeed;//�����롢a��b���ٶȡ��غϵĴ���
	int num;
	double time, dist;//"�غ�"ʱ���Լ������ҽϽ�d����
	while (N--)
	{
		cin >> length >> aSpeed >> bSpeed >> num;
		calculate(length, aSpeed, bSpeed, num, time, dist);
		cout << fixed << setprecision(3) << "Time=" << time << " Dist=" << dist<<endl;
	}
	return 0;
}