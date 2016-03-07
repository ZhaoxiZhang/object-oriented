#include<stdio.h>  
int main()  
{
    int a,b,sum;
    scanf("%d%d",&a,&b);
    sum=a+b;
    if(sum<0){
        printf("-");
        sum=-sum;
    }
    if(sum>=1000000){
        printf("%d,%03d,%03d\n",sum/1000000, (sum/1000)%1000, sum%1000);
    }
    else if(sum >= 1000){
        printf("%d,%03d\n",sum/1000,sum%1000);
    }
    else  
        printf("%d\n", sum);
    return 0;
}
