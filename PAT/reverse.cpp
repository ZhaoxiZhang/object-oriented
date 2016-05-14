#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct Node{
	int data;
	int next;
}; 
struct Node num[100005];
int tmp[100005];

int main()
{
	int N,head,cnt,tot,i,j;
	int add,dta,nxt;
	
	scanf("%d%d%d",&head,&N,&cnt);
	
	for (i = 1;i < N + 1;i++)
	{
		scanf("%d%d%d",&add,&dta,&nxt);
		
		num[add].data = dta;
		num[add].next = nxt;
	}
	
	i = 1;
	tot = 0;
	while (head != -1)
	{
		tmp[i++] = head;
		head = num[head].next;
		tot++;
	}
	if (cnt == 0) cnt = 1;
	for (i = 1;i < (tot / cnt + 1);i++)
	{
		for (j = 1;j < cnt / 2 + 1;j++)
		{
			swap(tmp[i * cnt + 1 - j],tmp[(i - 1) * cnt + j]);
		}
	}
	for (i = 1;i < tot;i++)
	{
		printf("%05d %d %05d\n",tmp[i],num[tmp[i]].data,tmp[i + 1]);
	}
	printf("%05d %d -1\n",tmp[i],num[tmp[i]].data);
	
	return 0;
}
