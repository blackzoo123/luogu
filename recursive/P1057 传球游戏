#include <iostream>
#include <cstdio>
#include <cstring>
#define N 35
using namespace std;

int f[N][N];

int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    memset(f,0,sizeof(f));
    f[1][0]=1;
    for(j=1;j<=m;j++)
    {
        f[1][j]=f[2][j-1]+f[n][j-1];                    
        f[n][j]=f[1][j-1]+f[n-1][j-1];                     //对第1个人和第n个人单独考虑
        for(i=2;i<n;i++)
            f[i][j]=f[i-1][j-1]+f[i+1][j-1];                        //递推公式（左右两种情况）
    }
    printf("%d\n",f[1][m]);
    return 0;
}
