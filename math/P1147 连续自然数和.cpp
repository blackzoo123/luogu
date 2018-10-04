#include <iostream>
#include <cstdio>
#include <cmath>
#define eps 1e-8           //精度确定值
using namespace std;

int m;

void read(int &x)        //读入优化
{
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}

double equation(double n)        //求解一元二次方程
{
    double k=m;
    double r=4*n*n-4*n+1+8*k;
    double s=(-1+sqrt(r))/2;
    return s;
}

bool ok(double x)             //精度判断：x是否为正整数
{
    return fabs(x-(int)(x+0.05))<eps;
}

int main()
{
    int i,j;
    double ans,t;
    read(m);
    for(i=1;i<m;i++)
    {
        t=i;           //用doule型保存i，避免i*i爆内存
        ans=equation(t);
        if(ans>t&&ok(ans))
        {
            j=(int)(ans);
            printf("%d %d\n",i,j);             
        }
    }
    return 0;
}
