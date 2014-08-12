#include<iostream>
using namespace std;


int **place;
int **result;

int getMaxLen(int r,int c){
	int maxLen = 0;
	int move[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			result[i][j] = 0;//indicate that we have met (i,j)
			int maxNext = 0;
			for (int k = 0; k < 4; k++)
			{
				int p = i + move[k][0];
				int q = j + move[k][1];
				if (p < 0 || p >= r || q < 0 || q >= c){// ignore it when next move can be out of matrix
					continue;
				}
				if (place[i][j]>place[p][q]){//we can go to this position when value goes down
					if (result[p][q]>maxNext){
						maxNext = result[p][q];
					}
				}
			}
			result[i][j] = maxNext;//update this point's max routelen

			for (int k = 0; k < 4; k++)
			{
				int p = i + move[k][0];
				int q = j + move[k][1];
				if (p < 0 || p >= r || q < 0 || q >= c){// ignore it when next move can be out of matrix
					continue;
				}
				if (place[i][j]>place[p][q]){//update the maxLen when neibghers can goto it

				}
			}


		}
	}
	return maxLen;
}
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int r, c;
		cin >> r >> c;
		place = new int*[r];
		result = new int*[r];
		for (int j = 0; j < r; j++)
		{
			place[j] = new int[c];
			result = new int*[c];
			for (int k = 0; k < c; k++)
			{
				cin >> place[j][k];
				result[j][k] = -1;
			}
		}


		for (int j = 0; j < r; j++)
		{
			delete[] place[j];
		}
		delete[]place;

	}

	return 0;
}