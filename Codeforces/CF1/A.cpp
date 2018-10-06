#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,m,a;
    long long i,j,sum;
    cin>>n>>m>>a;
    if(n%a==0)
        i=n/a;
    else
        i=n/a+1;
    if(m%a==0)
        j=m/a;
    else
        j=m/a+1;
    sum=i*j;
    cout<<sum<<endl;
    return 0;
}
