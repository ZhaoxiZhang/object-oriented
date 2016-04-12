#include<stdio.h>
#include<string.h>
char arr[2000005],ans[2000005];
int main()
{
	int a,b,temp,sum,length,j,i=0;
	scanf("%d%d",&a,&b);
	sum=a+b;
	temp=sum;
	sum=(sum>0)?sum:-sum; 
	while(sum){
		if(i==3||i==7){
			arr[i]=',';
			arr[++i]=sum%10+48;
		}
		else
		   arr[i]=sum%10+48;
		sum/=10;
		i++;
	}
	length=strlen(arr);
	for(i=0,j=length-1;i<length;i++,j--){
		ans[i]=arr[j];
	}
	if(temp==0)
	   printf("0");
	else if(temp<0){
		printf("-");
		printf("%s\n",ans);
	} 
	else
	    printf("%s\n",ans);
	return 0;
}
