// 子串匹配.cpp : 定义控制台应用程序的入口点。
//找到最接近指定串的长串部分在长串中的位置
//

#include "stdafx.h"

#include<iostream>
#include<string>
using namespace std;

#define MAXLEN 100
#define MATCH 0
#define INSERT 1
#define DELETE 2


struct cell
{
	int cost;
	int parent;
};

cell m[MAXLEN + 1][MAXLEN + 1];


int match(char s, char t){
	if (s == t){
		return 0;
	}
	else
		return 1;
}

int indel(char s){
	return 1;
}

void row_init(int i){
/*	m[0][i].cost = i;
	if (i == 0)//------------------------------------×¢Òâm[0][0]µÄparentÊÇ01
		m[0][i].parent = -1;
	else
		m[0][i].parent = INSERT;
		*/
	m[0][i].cost = 0;
	m[0][i].parent = -1;
}

void column_init(int i){
	m[i][0].cost = i;
	if (i == 0)
		m[i][0].parent = -1;
	else
		m[i][0].parent = DELETE;
}
void goal_cell(string a, string b, int *i, int *j){
	*i = a.length() - 1;
	//*j = b.length() - 1;
	*j = 1;
	int min =0;
	for (; *j < b.length(); (*j)++)
	{
		if (m[*i][*j].cost < m[*i][min].cost){
			min = *j;
		}
	}
}


void match_out(string a, string b, int i, int j){
	if (a[i - 1] == b[j - 1]){
		cout << "M";
	}
	else
		cout << "S";
}

void insert_out(string s, int i){
	cout << "I";
}

void delete_out(string s, int i){
	cout << "D";
}

void reconstruct_path(string a, string b, int i, int j){
	if (m[i][j].parent == -1){
		return;
	}
	if (m[i][j].parent == MATCH){
		reconstruct_path(a, b, i - 1, j - 1);
		match_out(a, b, i, j);
		return;
	}
	if (m[i][j].parent == INSERT){
		reconstruct_path(a, b, i - 1, j - 1);
		insert_out(b, j - 1);
		return;
	}
	if (m[i][j].parent == DELETE){
		reconstruct_path(a, b, i - 1, j - 1);
		delete_out(a, i - 1);
		return;
	}
}
int getEDmin(string a, string b){
	int i, j, k;
	int opt[3];

	for (int i = 0; i < MAXLEN; i++)
	{
		row_init(i);
		column_init(i);
	}

	for (i = 1; i <a.length() + 1; i++)
	{
		for (j = 1; j < b.length() + 1; j++)
		{
			opt[MATCH] = m[i - 1][j - 1].cost + match(a[i - 1], b[j - 1]);
			opt[INSERT] = m[i][j - 1].cost + indel(b[j - 1]);//INSERT
			opt[DELETE] = m[i - 1][j].cost + indel(a[i - 1]);//DELETE
			m[i][j].cost = opt[MATCH];
			m[i][j].parent = MATCH;
			for (k = 1; k <= DELETE; k++)//---------------------Ã»ÓÐÖ´ÐÐµ½delete???----opt[INSERT] = m[i][j - 1].cost +1+ indel(b[j - 1]);//INSERT---------------´ÖÐÄ!!!

			{
				if (m[i][j].cost > opt[k]){
					m[i][j].cost = opt[k];
					m[i][j].parent = k;
				}
			}
		}
	}
	goal_cell(a, b, &i, &j);
	//reconstruct_path(a, b, i, j);
	return (m[i][j].cost);
}

int _tmain(int argc, _TCHAR* argv[])
{
	string a = "thou shalt not";
	string b = " not";
	cout << getEDmin(a, b) << endl;
	return 0;
}

