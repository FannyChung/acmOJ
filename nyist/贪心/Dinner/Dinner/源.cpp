//��һ���������ҵ����ڵ�ָ�����ַ���������ӡ


//AC
#include<iostream>
#include<string>
using namespace std;

const string tableware[] = { "bowl", "knife", "fork", "chopsticks"};
int main(){
	int n;
	while (cin>>n)
	{
		string *str = new string[n];
		int result = 0;
		bool exist[4] = { false };
		for (int i = 0; i < n; i++)
		{
			cin>>str[i];
			for (int j = 0; j < 4; j++)
			{
				if (!exist[j]){
					if (str[i] == tableware[j]){
						cout << str[i] << " ";
					}
				}
			}
		}
		cout << endl;

		delete[] str;
	}
	return 0;
}