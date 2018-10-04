#include<iostream>
#include<cstdio>
using namespace std;

const int maxn=1e5+5;
int f[maxn];

int main()
{
    int n,k,i,j;
    scanf("%d %d",&n,&k);
    f[0]=1;
    for(i=1;i<=n;i++)
    {
        f[i]=0;
        for(j=1;j<=k&&j<=i;j++)
            f[i]=(f[i]+f[i-j])%100003;
    }
    printf("%d\n",f[n]);
    return 0;
}
