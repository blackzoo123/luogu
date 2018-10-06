#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void Reverse(string s);     //字符串的倒置函数

int main()
{
    int i,k=0,t,length;
    string s,sb1,sb2;
    cin>>s;
    length=s.size();
    for(i=0;i<length;i++)
    {
        if(s[i]=='.')
        {
            t=i;
            k=1;
        }
        if(s[i]=='/')
        {
            t=i;
            k=2;
        }
        if(s[i]=='%')
        {
            t=i;
            k=3;
        }
    }
    if(k==0)      //整数情况
    {
        Reverse(s);
    }
    if(k==1)
    {
        sb1=s.substr(0,t);    //截取整数位
        Reverse(sb1);        //逆序输出
        cout<<".";
        sb2=s.substr(t+1,s.size());    //截取小数位
        int w=-1;
        int r=sb2.size();
        for(i=0;i<r;i++)
        {
            if(sb2[i]!='0')     //顺序扫描，删除逆序后的后置0
            {
                w=i;
                break;
            }
        }
        if(w<0)               //小数部分全为0，只输出一个0
            cout<<"0";
        else
        {
            for(i=r-1;i>=w;i--)
            cout<<sb2[i];
        }
    }
    if(k==2)
    {
        sb1=s.substr(0,t);     //截取分子部分
        Reverse(sb1);                         
        cout<<"/";
        sb2=s.substr(t+1,s.size());     //截取分母部分
        Reverse(sb2);                                       //依次输出逆序后子字符串
    }
    if(k==3)
    {
       sb1=s.substr(0,t);             //截取百分号之前部分
       Reverse(sb1);
       cout<<"%";
    }
    cout<<endl;
    return 0;
}

void Reverse(string s)
{
    int i,t,l;
    l=s.size();
    for(i=l-1;i>=0;i--)
    {
        if(s[i]!='0')            //逆序扫描字符串，删除逆序后的前置0
        {
            t=i;
            break;
        }
    }
    for(i=t;i>=0;i--)     //从不为‘0’的字符开始，逆序输出
        cout<<s[i];
}
