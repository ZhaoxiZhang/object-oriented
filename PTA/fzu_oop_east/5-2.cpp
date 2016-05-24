#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include <iomanip>
using namespace std;

class Student
{
	private:
		int height;
		int weight;
		string name;
	public:
		void memset();
		void set(int h,int w,string ne);
		void cmp(int h,int w,string ne);
		void print();
};

void Student::set(int h,int w,string ne)
{
	height = h;
	weight = w;
	name = ne;
}

void Student::memset()
{
	height = -1;
	weight = -1;
}
void Student::cmp(int h,int w,string ne)
{
	if (h > height)
	{
		set(h,w,ne);
	}
}

void Student::print()
{
	cout << name << " " << height << " " << weight << endl;
}

Student stu[1000005];
int cnt[1000005];

int main()
{
	int N;
	for (int i = 0;i < 1000000;i++)
	{
		stu[i].memset();
	}
	scanf("%d",&N);
	int h,w,roomnum;
	string ne;
	for (int i = 0;i < N;i++)
	{
		cin >> roomnum >> ne >> h >> w;
		stu[roomnum].cmp(h,w,ne);
		cnt[i] = roomnum; 
	}
	
	sort(cnt,cnt + N);
	
	for (int i = 0;i < N;)
	{
		while (cnt[i] == cnt[i + 1])
		{
			i++;
		}
		cout << setfill('0') << setw(6) << cnt[i] << " ";
		stu[cnt[i++]].print();
	}
}
