#include<iostream>
#include<algorithm>
using namespace std;
struct Duan
{
	int x;//Æðµã
	int y;//ÖÕµã
	/*bool operator<(const Duan& other)const{
		if (x == other.x){

		}
		return (x < other.y);
	}*/
};

bool cmp(const Duan& m,const Duan& other){
	return other.y - m.x;
}
int main(){
	int N;
	cin >> N;
	Duan *ds = new Duan[N];
	for (int i = 0; i < N; i++)
	{
		cin >> ds[i].x >> ds[i].y;
	}
	sort(ds, ds + N,less<Duan>());
	int result = 0;
	for (int i = 1; i < N; i++)
	{
		int len = ds[i].y - ds[i - 1].x+1;
		if (len > result)
			result = len;
	}
	cout << result << endl;
	delete[]ds;
	return 0;
}