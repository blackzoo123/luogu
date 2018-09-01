// medicine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void InitList(SqList &L,int n)      //顺序表的初始化
{
	L.elem=new ElemType[n];   //为顺序表分配一个大小为MAXSIZE的数组空间
	if(!L.elem)
		exit(OVERFLOW);       //存储分配失败退出
	L.length=n;               
}

void read(SqList &L)     //将药品信息读入drug.txt文件中，并输出
{
	int i,n;
    FILE *fp;
    if((fp=fopen("drug.txt","r"))==NULL)
	{
        printf("打开文件失败!!!\n");
        exit(0);
	}
	fscanf(fp,"%d",&n);
	InitList(L,n);
	for(i=1;i<=L.length;i++)
	{
		fscanf(fp,"%s",&L.elem[i].num);
		fscanf(fp,"%s",&L.elem[i].name);
		fscanf(fp,"%f",&L.elem[i].price);
		fscanf(fp,"%d",&L.elem[i].count);
		fscanf(fp,"%f",&L.elem[i].sale);
	}
	printf("药品信息导入已经完成!\n\n");
	printf("开始输出药品信息:\n");
	printf("请输出药品数量:");
	printf("%d\n",n);
	printf("编号\t药名\t单价\t数量\t销售额\n");
	for(i=1;i<=L.length;i++)
	{
		printf("%s\t%s\t%.2f\t%d\t%.2f\n",L.elem[i].num,L.elem[i].name,L.elem[i].price,L.elem[i].count,L.elem[i].sale);
	}
	fclose(fp);
}

void Distribute(ElemType *r,int i,int *f,int *e)   //建立字表，开始分配
{
	int j,p;
	for(j=0;j<=26;j++)
		f[j]=0;
	for (p=r[0].next;p;p=r[p].next)
	{	
		if(i>0)
		{
			j=r[p].num[i]-'0';
			if(!f[j])
				f[j]=p;
			else
				r[e[j]].next=p;
			e[j]=p;
		}
		else
		{
			j=r[p].num[i]-'A';
			if(!f[j])
				f[j]=p;
			else
				r[e[j]].next=p;
			e[j]=p;
		}
	}
}
void Collect(ElemType *r,int i,int *f,int *e)     //子表链接成单链表，收集
{
	int j,t;
	for(j=0;!f[j];j++);
	r[0].next=f[j];
	t=e[j];
	while (j<26)
	{
		for(j=j+1;j<25&&!f[j];++j);
		if (f[j])
		{
			r[t].next=f[j];
			t=e[j];
		}
	}
	r[t].next=0;
}
void RadixSort(SqList &L)   //对编号进行基数排序
{
	int f[27],e[26];
	int i;
	for(i=0;i<L.length;i++)
		L.elem[i].next=i+1;
	L.elem[L.length].next=0;
	for(i=3;i>=0;i--)
	{
		Distribute(L.elem,i,f,e);   //第i趟分配
		Collect(L.elem,i,f,e);      //第i趟收集
	}
	i=L.elem[0].next;
	while(i)
	{
		printf("%s\t%s\t%.2f\t%d\t%.2f\n",L.elem[i].num,L.elem[i].name,L.elem[i].price,L.elem[i].count,L.elem[i].sale);   //链式输出排序后信息
		i=L.elem[i].next;
	}
}

void BubbleSort(SqList &L)   //对单价进行冒泡排序
{
	int i,m,flag,j;
	m=L.length-1;flag=1;
	while((m>0)&&(flag==1))
	{
		flag=0;
		for(j=1;j<=m;j++)
		{
			if(L.elem[j].price>L.elem[j+1].price)
			{
				flag=1;
				ElemType t=L.elem[j];
				L.elem[j]=L.elem[j+1];
				L.elem[j+1]=t;
			}
		}
		--m;
	}
	printf("使用冒泡排序对药品单价进行排序:\n");
	printf("编号\t药名\t单价\t数量\t销售额\n");
	for(i=1;i<=L.length;i++)
	{
		printf("%s\t%s\t%.2f\t%d\t%.2f\n",L.elem[i].num,L.elem[i].name,L.elem[i].price,L.elem[i].count,L.elem[i].sale);
	}
}


int Partition(SqList &L,int low,int high)    //对顺序表L的子表elem[low..high]进行一趟排序，返回枢轴位置
{
	int en;
	L.elem[0]=L.elem[low];
	en=L.elem[low].count;
	while(low<high)
	{
		while(low<high&&L.elem[high].count>=en)
			--high;
		L.elem[low]=L.elem[high];
		while(low<high&&L.elem[low].count<=en)
			++low;
		L.elem[high]=L.elem[low];
	}
	L.elem[low]=L.elem[0];
	return low;
}

void Qsort(SqList &L,int low,int high)     //对顺序表L中的子序列L.elem[low..high]做快速排序
{
	if(low<high)
	{
		int t=Partition(L,low,high);
		Qsort(L,low,t-1);
		Qsort(L,t+1,high);
	}
}

void QuickSort(SqList &L)     //对销售量进行快速排序
{
	printf("使用快速排序对销售量排序:\n");
	Qsort(L,1,L.length);
	printf("编号\t药名\t单价\t数量\t销售额\n");
	for(int i=1;i<=L.length;i++)
	{
		printf("%s\t%s\t%.2f\t%d\t%.2f\n",L.elem[i].num,L.elem[i].name,L.elem[i].price,L.elem[i].count,L.elem[i].sale);
	}
}

void HeapAdjust(SqList &L,int s,int m)   //筛选法将堆调整为大根堆
{
	ElemType rc=L.elem[s];
	for(int j=2*s;j<=m;j*=2)
	{
		if(j<m&&L.elem[j].sale<L.elem[j+1].sale)
			++j;
		if(rc.sale>=L.elem[j].sale)
			break;
		L.elem[s]=L.elem[j];
		s=j;
	}
	L.elem[s]=rc;
}

void CreatHeap(SqList &L)   //将无序序列建立成大根堆
{
	int n=L.length;
	for(int i=n/2;i>0;--i)
	{
		HeapAdjust(L,i,n);
	}
}

void HeapSort(SqList &L)   //对销售额进行堆排序
{
	int i;
	CreatHeap(L);
	for(i=L.length;i>1;--i)
	{
		ElemType x=L.elem[1];
		L.elem[1]=L.elem[i];
		L.elem[i]=x;
		HeapAdjust(L,1,i-1);
	}
	printf("使用堆排序对药品销售额进行排序:\n");
	printf("编号\t药名\t单价\t数量\t销售额\n");
	for(i=1;i<=L.length;i++)
	{
		printf("%s\t%s\t%.2f\t%d\t%.2f\n",L.elem[i].num,L.elem[i].name,L.elem[i].price,L.elem[i].count,L.elem[i].sale);
	}
}

void Menu()
{//菜单
	printf("\n");
	printf("**************************************************\n");
    printf("*******            实验七:药品信息管理系统   *****\n");
	printf("*******            1、导入药品信息并输出     *****\n");
	printf("*******            2、编号排序               *****\n");
	printf("*******            3、单价排序               *****\n");
	printf("*******            4、销售量排序             *****\n");
	printf("*******            5、销售额排序             *****\n");
	printf("*******            6、退出管理系统           *****\n");
	printf("**************************************************\n");
}



int main()
{
	int ch;
	SqList L;
	while(1)
	{
		Menu();
		printf("请输入您的选择:");
 		scanf("%d",&ch);
		while(ch<1||ch>6)
		{
		    printf("输入有误，请重新输入");
			scanf("%d",&ch);
		}
		switch(ch)
		{
		case 1:
			read(L);
			break;
		case 2:
			RadixSort(L);
			break;
		case 3:
			BubbleSort(L);
			break;
		case 4:
			QuickSort(L);
			break;
		case 5:
			HeapSort(L);
			break;
		case 6:
			printf("程序已退出\n");
			exit(0);
		}
	}
	return 0;
}