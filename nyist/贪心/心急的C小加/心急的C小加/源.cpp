#include<iostream>
using namespace std;
struct Wood
{
	int l;
	int w;
	bool operator>(const Wood &other)const{
		return (l > other.l) && (w > other.w);
	}
};

int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)//T×é²âÊÔ
	{
		int N;
		cin >> N;//N¸öÄ¾°ô
		Wood *wall = new Wood[N];
		for (int j = 0; j < N; j++)
		{
			cin >> wall[j].l >> wall[j].w;
		}

	}
	return 0;
}