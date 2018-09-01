#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct BigInteger
{
    static const int BASE=100000000;
    static const int WIDTH=8;
    vector<int> s;

    BigInteger(long long num=0)
    {
        *this=num;
    }
    BigInteger operator=(long long num)
    {
        s.clear();
        do{
            s.push_back(num%BASE);
            num/=BASE;
        }while(num>0);
        return *this;
    }
    BigInteger operator=(const string& str)
    {
        s.clear();
        int x,len=(str.length()-1)/WIDTH+1;
        for(int i=0;i<len;i++)
        {
            int end=str.length()-i*WIDTH;
            int start=max(0,end-WIDTH);
            sscanf(str.substr(start,end-start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }
    bool operator < (const BigInteger& b)const
    {
        if(s.size()!=b.s.size())
            return s.size()<b.s.size();
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!=b.s[i])
                return s[i]<b.s[i];
        }
        return false;
    }
    bool operator > (const BigInteger& b) const
    {
        return b<*this;
    }
};

ostream& operator<<(ostream &out,const BigInteger& x)
{
    out<<x.s.back();
    for(int i=x.s.size()-2;i>=0;i--)
    {
        char buf[20];
        sprintf(buf,"%08d",x.s[i]);
        int l=strlen(buf);
        for(int j=0;j<l;j++)
            out<<buf[j];
    }
    return out;
}

istream& operator>>(istream &in,BigInteger& x)
{
    string s;
    if(!(in>>s))
        return in;
    x=s;
    return in;
}
int main()
{
    int n,i,t;
    BigInteger f[22],maxn=0;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>f[i];
    for(i=1;i<=n;i++)
    {
        if(maxn<f[i])
        {
            maxn=f[i];
            t=i;
        }
    }
    cout<<t<<endl<<maxn<<endl;
    return 0;
}
