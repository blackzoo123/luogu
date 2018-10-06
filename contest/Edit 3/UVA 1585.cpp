#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
   string s;
   int n,t,i,s_len,sum;
   cin>>n;
   while(n--)
   {
       t=sum=0;
       cin>>s;
       s_len=s.size();
       for(i=0;i<s_len;i++)
       {
           if(s[i]=='O')
           {
               t++;
               sum+=t;
           }
           if(s[i]=='X')
           {
               t=0;
           }
       }
       cout<<sum<<endl;
   }
   return 0;
}
