#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=1e4+5;
int p[maxn];

int main()
{
    int n,m,i;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    while(next_permutation(p,p+n))             //STL中的字典序排列函数（具体参考 https://zh.cppreference.com/w/cpp/algorithm/next_permutation）
    {
        m--;
        if(m==0)
        {
            for(i=0;i<n;i++)
                printf("%d ",p[i]);
            printf("\n");
            break;                               //一旦输出序列后，立即跳出循环
        }
    }
    return 0;
}
