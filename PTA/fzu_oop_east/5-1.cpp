#include<iostream>
#include<cstdio>
using namespace std;

class Data{
	private:
		int year,month,day;
	public:
		bool IsLeap(int year);
		void set(int x,int y,int z);
		int TheDay(int Year,int Month,int Day);
		void Print(int Day);
}; 

Data::Data(int = 0,int = 0,int = 0);
bool Data::IsLeap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void Data::set(int x,int y,int z)
{
	year = x;
	month = y;
	day = z;
}

int Data::TheDay(int Year,int Month,int Day)
{
	int ans[13] = {0,0,31,59,90,120,151,181,212,243,273,304,334};
	Day += ans[Month];
	if (IsLeap(Year))
	{
		if (Month > 2)
		{
			Day++;
		}
	}
	return Day;
}

void Data::Print(int Day)
{
	printf("%d\n",Day);
}

int main()
{
	int Year,Month,Day;
	Data Calender;
	while (~scanf("%d %d %d",&Year,&Month,&Day) && Year && Month && Day)
	{
		Calender.set(Year,Month,Day);
		Day = Calender.TheDay(Year,Month,Day);
		Calender.Print(Day);
	}
	return 0;
}
