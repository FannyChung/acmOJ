//Wrong Answer
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int T;
	cin >> T;
	int n, m;
	vector<int> v;
	for (int i = 0; i < T; i++)//T×é²âÊÔÊý¾Ý
	{
		v.clear();
		char ch;
		scanf_s("%c", &ch); 
		while (ch != ' ')
		{
			v.push_back(ch - '0');
			scanf_s("%c", &ch);
		}
		cin >> m;
		sort(v.begin(), v.end());
		int sz = v.size();
		for (int j = sz-1; j >m; j--)
		{
			cout << v[j];
		}
		cout << endl;
	}
	return 0;
}