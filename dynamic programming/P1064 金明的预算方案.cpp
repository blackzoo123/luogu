#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 32005
#define N 65
using namespace std;

int f[M],dp[M],v[N],p[N],q[N];

int main()
{
    int m,n,i,j,k;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&v[i],&p[i],&q[i]);
        p[i]=v[i]*p[i];
    }
    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++)
    {
        if(!q[i])
        {
            for(j=0;j<v[i];j++)
                f[j]=0;
            for(j=v[i];j<=m;j++)
                f[j]=dp[j-v[i]]+p[i];     //对01背包包括主件后的状态
            for(j=1;j<=n;j++)
            {
                if(q[j]==i)
                {
                    for(k=m;k>=v[i]+v[j];k--)
                        f[k]=max(f[k],f[k-v[j]]+p[j]);   //对01背包进行附件的挑选后的状态构成一个背包组
                }
            }
            for(j=v[i];j<=m;j++)
                dp[j]=max(dp[j],f[j]);    //对背包组（只含主件或主件与附件的集合）进行分组背包,将f[j]用dp[j]代替可得分组背包一般形式
        }
    }
    printf("%d\n",dp[m]);
    return 0;
}
