#include<iostream>
#include<cstdio>
using namespace std;

const int maxn=5e5+5;
int f[maxn],T[maxn];
long long cnt=0;

void Fuc(int *A,int x,int y)
{
    if(y-x>1)
    {
        int m=x+(y-x)/2;
        int p=x,q=m,i=x;
        Fuc(A,x,m);
        Fuc(A,m,y);
        while(p<m||q<y)
        {
            if(q>=y||(p<m&&A[p]<=A[q]))
                T[i++]=A[p++];
            else
            {
                T[i++]=A[q++];
                cnt+=m-p;
            }
        }
        for(i=x;i<y;i++)
            A[i]=T[i];
    }
}

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        cin>>f[i];
    Fuc(f,0,n);
    cout<<cnt<<endl;
    return 0;
}
