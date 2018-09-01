#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

string s="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int Fun(char ch)
{
    if(ch<='9'&&ch>='0')
        return ch-'0';
    else
        return ch-'A'+10;
}

int main()
{
    int n,i,x,g,rl,wl,strl;
    int r[2005],w[2005];
    string sr,sw,str;
    cin>>n>>sr>>sw;
    rl=sr.size();
    wl=sw.size();
    for(i=0;i<rl;i++)
        r[i]=Fun(sr[rl-i-1]);
    for(i=0;i<wl;i++)
        w[i]=Fun(sw[wl-i-1]);
    for(i=0,g=0; ;i++)
    {
        if(g==0&&i>=rl&&i>=wl)
            break;
        x=g;
        if(i<rl)
            x+=r[i];
        if(i<wl)
            x+=w[i];
        g=x/n;
        if(x>=n)
            x-=n;
        str[i]=s[x];
    }
    strl=i;
    for(i=strl-1;i>=0;i--)
        cout<<str[i];
    cout<<endl;
    return 0;
}
