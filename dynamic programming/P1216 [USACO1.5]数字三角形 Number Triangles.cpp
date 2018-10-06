#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1005
using namespace std;

int vis[N][N],dp[N][N];     //基础动态规划题

int main()
{
   int n,i,j,maxn=0;
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=i;j++)
        scanf("%d",&vis[i][j]);
   }
   memset(dp,0,sizeof(dp));
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=i;j++)
        dp[i][j]=max(dp[i-1][j-1]+vis[i][j],dp[i-1][j]+vis[i][j]);   //状态转移方程
   }
   for(i=1;i<=n;i++)
   {
       maxn=max(maxn,dp[n][i]);        //求最后一行所有数的最大值
   }
   printf("%d\n",maxn);
   return 0;
}
