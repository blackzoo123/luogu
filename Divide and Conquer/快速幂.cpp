#include <iostream>
#include <cstdio>

using namespace std;
long long pow_mod(long long a,long long n,long long m);

int main()
{
    long long b,q,k,t;
    cin>>b>>q>>k;
    if(k!=1)
       t=pow_mod(b,q,k);
    else
        t=0;
    cout<<b<<"^"<<q<<" mod "<<k<<"="<<t<<endl;
    return 0;
}

long long pow_mod(long long a,long long n,long long m)
{
    if(n==0)
        return 1;
    long long x=pow_mod(a,n/2,m);
    long long ans=x*x%m;
    if(n%2==1)
        ans=ans*a%m;
    return ans;
}
