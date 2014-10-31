#include<iostream>
#include<algorithm>
using namespace std;

//unAC

int main(){
	int n, q;
	cin >> n >> q;
	while (1){
		int* a = new int[n];
		int **num = new int*[n];
		for (int i = 0; i < n; i++)
		{
			num[i] = new int[n];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		//sort(a, a + n);
		for (int j = 0; j < q; j++)
		{
			int count = 0;
			int l, r, x, y;
			cin >> l >> r >> x >> y;
			cout << num[l][r] << endl;
		}
		delete[]a;
		cin >> n >> q;
		if (cin.eof())
		{
			break;
		}
	}
	return 0;
}