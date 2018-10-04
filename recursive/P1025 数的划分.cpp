#include <iostream>
#include <cstdio>
#include <cstring>
#define M 205
#define N 6
using namespace std;

int f[M][N];      //f[i][j]表示大小为n的数分成j份的个数

int main()
{
    int i,j,n,k;
    scanf("%d%d",&n,&k);
    memset(f,0,sizeof(f));
    for(i=1;i<=n;i++)
    {
        f[i][1]=f[i][i]=1;                //边界条件
        for(j=2;j<=k&&j<i;j++)
            f[i][j]=f[i-1][j-1]+f[i-j][j];             //递推公式          
    }
    printf("%d\n",f[n][k]);
    return 0;
}
