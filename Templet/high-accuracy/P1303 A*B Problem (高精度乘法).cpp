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
    BigInteger operator + (const BigInteger& b)const
    {
        BigInteger c;
        c.s.clear();
        for(int i=0,g=0; ;i++)
        {
            int t=s.size();
            int l=b.s.size();
            if(g==0&&i>=t&&i>=l)
                break;
            int x=g;
            if(i<t)
                x+=s[i];
            if(i<l)
                x+=b.s[i];
            c.s.push_back(x%BASE);
            g=x/BASE;
        }
        return c;
    }

    BigInteger operator += (const BigInteger& b)
    {
        *this = *this + b;
        return *this;
    }

    BigInteger operator - (const BigInteger& b) const
    {
        BigInteger c;
        c.s.clear();
        for(int i=0,g=0;;i++)
        {
            int t=s.size();
            int l=b.s.size();
            if(g==0&&i>=t&&i>=l)
                break;
            int x=g;
            if(i<t)
                x+=s[i];
            if(i<l)
                x-=b.s[i];
            x+=BASE;
            c.s.push_back(x%BASE);
            g=x/BASE-1;
        }
        return c;
    }

    BigInteger operator * (const BigInteger& b) const
    {
        BigInteger c,g=0;
        c.s.clear();
        for(int i=0;;i++)
        {
            int t=s.size();
            int l=b.s.size();
            int r=g.s.size();
            if(r==0&&i>=t+l-1)
                break;
            BigInteger x;
            x.s.clear();
            for(int j=0;j<r;j++)
                x.s.push_back(g.s[j]);
            if(i<t+l-1)
            {
                for(int j=max(0,i-t+1);j<=min(i,l-1);j++)
                {
                    BigInteger t=(long long)b.s[j]*s[i-j];
                    x+=t;
                }
            }
            c.s.push_back(x.s[0]);
            g.s.clear();
            int k=x.s.size();
            if(k>1)
            {
                for(int j=1;j<k;j++)
                    g.s.push_back(x.s[j]);
            }
        }
        return c;
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
        return b < *this;
    }
    bool operator >= (const BigInteger& b) const
    {
        return !(*this < b);
    }
    bool operator == (const BigInteger& b) const
    {
         return !(b < *this) && !(*this < b);
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
    BigInteger a,b;
    cin>>a>>b;
    cout<<a*b<<endl;
    return 0;
}
