#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
   int ans,n,k,sum;
   scanf("%d %d",&n,&k);     //直接模拟，sum为吸烟总数，ans为烟头数量
   ans=sum=n;
   while(ans>=k)   //当ans小于k时，不能换烟，退出
   {
       ans-=k;
       sum++;
       ans++;      //每换一次烟，吸烟数加一，烟头数先减k，换回的一支烟又可作为烟头，再加一
   }
   printf("%d\n",sum);
   return 0;
}
