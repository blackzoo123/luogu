#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int used[10];            //保存0~9这10个数字

void Fuc(int n)    //核心算法，求各个数位数字，并保存在数组里
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
   int t,n,i;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d",&n);
       memset(used,0,sizeof(used));
       for(i=1;i<=n;i++)
          Fuc(i);
       for(i=0;i<9;i++)
          printf("%d ",used[i]);
       printf("%d\n",used[9]);            //注意输出格式
   }
   return 0;
}
