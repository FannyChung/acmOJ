#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

struct student
{
	string name;
	int age;
	int grade;
};

int cmp()
int main(int argc, char const *argv[])
{
	int N;
	std::vector<student> v;
	for (int i = 0; i < N; ++i)
	{
		student stu;
		cin>>stu.name;
		cin>>stu.age;
		cin>>stu.grade;
		v.push_back(stu);
	}

	//排序

	return 0;
}