#include<iostream>
#include<set>
#include<map>
#include<cstdio>
#include<cmath>
using namespace std;

int Factor(int N)
{
	set<int>all;
	int max = sqrt(N);
	for (int i = 1;i <= max;i++)
	{
		if (N % i == 0)
		{
			all.insert(i);
			all.insert(N/i);
		}
	}
	int len = all.size();
	return len;
}

int main()
{
    int F,T,num,max = 0;
    set<int>all;
    set<int>::iterator it;
    scanf("%d%d",&F,&T);
    for (int i = F;i <= T;i++)
    {
        int len = Factor(i);
        if (max < len)
        {
            num = i;
            max = len;
        }
        else if (max == len && i < num)
        {
            num = i;
            max = len;
        }
    }
    max = sqrt(num);
    for (int i = 1;i <= max;i++)
    {
        if (num % i == 0)
        {
            all.insert(i);
            all.insert(num/i);
        }
    }
    printf("[%d,%d] %d %d\n",F,T,num,all.size());
    bool first = true;
    for (it = all.begin();it != all.end();it++)
    {
        first?printf("%d",*it):printf(" %d",*it);
        first = false;
    }
    return 0;
}

