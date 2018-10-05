#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int used[10];   //保存0~9十个数字个数

void Fuc(int n)     //求一个整数各位数字大小，并存入数组中
{
    while(n!=0)
    {
        int r=n%10;
        n=n/10;
        used[r]++;
    }
}

int main()
{
   int m,n,i;
   scanf("%d %d",&m,&n);
   memset(used,0,sizeof(used));
   for(i=m;i<=n;i++)
     Fuc(i);
   for(i=0;i<10;i++)
     printf("%d ",used[i]);
   printf("\n");
   return 0;
}
