#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

bool isOK(){
	stack<char> st;
		//st.clear();
		//获取一行的char
	char ch=' ';
	while(ch!='\n'){
		scanf("%c",&ch);
		if(ch=='('||ch=='['){
			st.push(ch);
		}else if(ch==')'){
			if(st.empty())
				return false;
			if(st.top()=='('){
				st.pop();
			}
			else
				return false;
		}else if(ch==']'){
			if(st.empty())
				return false;
			if(st.top()=='['){
				st.pop();
			}else
				return false;
		}else
			return false;
	}
}
int main(int argc, char const *argv[])
{
	
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		if(isOK())
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
