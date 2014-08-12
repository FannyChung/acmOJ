#include <iostream>
#include <math.h>
using namespace std;

int getYue(int m){
	int result=0;
	for (int i = 0; i < sqrt(m); ++i)
	{
		if(m%i==0){
			result+=2;
		}
		if(i*i==m){
			result+=1;
		}
	}
	return result;
}

int main(){
	int N;
	cin>>N;
	while(N!=0){
		for(int i=0;i<N;i++){
			int m;
			cin>>m;
			cout<<getYue(m)<<endl;
		}
		cin>>N;
	}
	return 0; 
}

