#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
#define N 95
using namespace std;

int main()
{
   map<char,double> element;
   element['C']=12.01;
   element['O']=16.00;
   element['H']=1.008;
   element['N']=14.01;               //构造常量映射map,简化代码和运算

   int n,i,s_len,num;
   double sum;
   char str[N];
   scanf("%d",&n);
   while(n--)
   {
      sum=0.0;
      scanf("%s",str);
      s_len=strlen(str);
      for(i=0;i<s_len;i++)
      {
          num=0;
          if(isalpha(str[i])&&isdigit(str[i+1]))     //测试元素后面的数字
          {
              if(isdigit(str[i+2]))
                num=10*(str[i+1]-'0')+str[i+2]-'0';        //后面数字为两位数
              else
                num=str[i+1]-'0';                    //后面数字为一位数
          }
          else
            num=1;                                   //后面没有数字
         sum+=num*element[str[i]];          //用映射简化四种元素分子质量
      }
      printf("%.3lf\n",sum);
   }
   return 0;
}
