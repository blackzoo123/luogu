void read(int &x)                             //读入优化
{
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
 
void print(int x)                      //输出优化
{
    if(x<0)//负数
    {
        putchar('-');
        x=-x;
    }
    if(x>9)//只要x还是2位数或更多就继续分解
        print(x/10);//这里递归完后栈里面x的每一位是倒过来的（关于递归，我也实在解释不清楚，各位去看看神犇们的递归解释吧）
    putchar(x%10+'0');//输出（要把int型变为char型，加'0'即可）
}
