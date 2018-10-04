#include <iostream>
#include <cstdio>
using namespace std;

void read(int &x)                    //读入优化
{
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}

int gcd(int a,int b)                    //欧几里得算法
{
    return b==0 ? a:gcd(b,a%b);
}

int main()
{
    int i,k,r,x,y,sum=0;
    read(x);
    read(y);
    r=y/x;
    for(i=1;i<=r;i++)      //枚举
    {
       k=y/i;
       if(k*i==y&&gcd(i*x,k)==x)          //制约条件
            sum++;
    }
    printf("%d\n",sum);
    return 0;
}
