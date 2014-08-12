//�᳡���ţ������Ļ���������Ļ
//http://acm.nyist.net/JudgeOnline/problem.php?pid=14
#include <iostream>
#include <algorithm>
using namespace std;
struct act{
	int num;
	int s;
	int e;
};
bool lessact(const act& a1, const act &a2){
	return a1.e<a2.e;
}
int main() {
	// your code goes here
	int m;
	cin >> m;
	for (int i = 0; i<m; i++){
		int n;
		cin >> n;//n���
		act *all = new act[n];
		for (int j = 0; j<n; j++){
			(all[j]).num = j;
			cin >> all[j].s >> all[j].e;
		}
		sort(all, all+n, lessact);
		int result = 0;
		result++;
		int last = 0;//0�Żһ����������
		for (int j = 1; j<n; j++){
			if (all[j].s>all[last].e){//���ݣ�����
				last = j;
				result++;
			}
		}
		cout << result << endl;
		delete[]all;
	}
	return 0;
}