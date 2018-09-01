#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 10005
#define N 105
using namespace std;

int dp[M],v[N];

int main()
{
    int m,n,i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
    memset(dp,0,sizeof(0));
    dp[0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=m;j>=v[i];j--)
            dp[j]+=dp[j-v[i]];
    }
    printf("%d\n",dp[m]);
    return 0;
}
