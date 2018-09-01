// medicine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void InitList(SqList &L,int n)      //˳���ĳ�ʼ��
{
	L.elem=new ElemType[n];   //Ϊ˳������һ����СΪMAXSIZE������ռ�
	if(!L.elem)
		exit(OVERFLOW);       //�洢����ʧ���˳�
	L.length=n;               
}

void read(SqList &L)     //��ҩƷ��Ϣ����drug.txt�ļ��У������
{
	int i,n;
    FILE *fp;
    if((fp=fopen("drug.txt","r"))==NULL)
	{
        printf("���ļ�ʧ��!!!\n");
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
	printf("ҩƷ��Ϣ�����Ѿ����!\n\n");
	printf("��ʼ���ҩƷ��Ϣ:\n");
	printf("�����ҩƷ����:");
	printf("%d\n",n);
	printf("���\tҩ��\t����\t����\t���۶�\n");
	for(i=1;i<=L.length;i++)
	{
		printf("%s\t%s\t%.2f\t%d\t%.2f\n",L.elem[i].num,L.elem[i].name,L.elem[i].price,L.elem[i].count,L.elem[i].sale);
	}
	fclose(fp);
}

void Distribute(ElemType *r,int i,int *f,int *e)   //�����ֱ���ʼ����
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
void Collect(ElemType *r,int i,int *f,int *e)     //�ӱ����ӳɵ������ռ�
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
void RadixSort(SqList &L)   //�Ա�Ž��л�������
{
	int f[27],e[26];
	int i;
	for(i=0;i<L.length;i++)
		L.elem[i].next=i+1;
	L.elem[L.length].next=0;
	for(i=3;i>=0;i--)
	{
		Distribute(L.elem,i,f,e);   //��i�˷���
		Collect(L.elem,i,f,e);      //��i���ռ�
	}
	i=L.elem[0].next;
	while(i)
	{
		printf("%s\t%s\t%.2f\t%d\t%.2f\n",L.elem[i].num,L.elem[i].name,L.elem[i].price,L.elem[i].count,L.elem[i].sale);   //��ʽ����������Ϣ
		i=L.elem[i].next;
	}
}

void BubbleSort(SqList &L)   //�Ե��۽���ð������
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
	printf("ʹ��ð�������ҩƷ���۽�������:\n");
	printf("���\tҩ��\t����\t����\t���۶�\n");
	for(i=1;i<=L.length;i++)
	{
		printf("%s\t%s\t%.2f\t%d\t%.2f\n",L.elem[i].num,L.elem[i].name,L.elem[i].price,L.elem[i].count,L.elem[i].sale);
	}
}


int Partition(SqList &L,int low,int high)    //��˳���L���ӱ�elem[low..high]����һ�����򣬷�������λ��
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

void Qsort(SqList &L,int low,int high)     //��˳���L�е�������L.elem[low..high]����������
{
	if(low<high)
	{
		int t=Partition(L,low,high);
		Qsort(L,low,t-1);
		Qsort(L,t+1,high);
	}
}

void QuickSort(SqList &L)     //�����������п�������
{
	printf("ʹ�ÿ������������������:\n");
	Qsort(L,1,L.length);
	printf("���\tҩ��\t����\t����\t���۶�\n");
	for(int i=1;i<=L.length;i++)
	{
		printf("%s\t%s\t%.2f\t%d\t%.2f\n",L.elem[i].num,L.elem[i].name,L.elem[i].price,L.elem[i].count,L.elem[i].sale);
	}
}

void HeapAdjust(SqList &L,int s,int m)   //ɸѡ�����ѵ���Ϊ�����
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

void CreatHeap(SqList &L)   //���������н����ɴ����
{
	int n=L.length;
	for(int i=n/2;i>0;--i)
	{
		HeapAdjust(L,i,n);
	}
}

void HeapSort(SqList &L)   //�����۶���ж�����
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
	printf("ʹ�ö������ҩƷ���۶��������:\n");
	printf("���\tҩ��\t����\t����\t���۶�\n");
	for(i=1;i<=L.length;i++)
	{
		printf("%s\t%s\t%.2f\t%d\t%.2f\n",L.elem[i].num,L.elem[i].name,L.elem[i].price,L.elem[i].count,L.elem[i].sale);
	}
}

void Menu()
{//�˵�
	printf("\n");
	printf("**************************************************\n");
    printf("*******            ʵ����:ҩƷ��Ϣ����ϵͳ   *****\n");
	printf("*******            1������ҩƷ��Ϣ�����     *****\n");
	printf("*******            2���������               *****\n");
	printf("*******            3����������               *****\n");
	printf("*******            4������������             *****\n");
	printf("*******            5�����۶�����             *****\n");
	printf("*******            6���˳�����ϵͳ           *****\n");
	printf("**************************************************\n");
}



int main()
{
	int ch;
	SqList L;
	while(1)
	{
		Menu();
		printf("����������ѡ��:");
 		scanf("%d",&ch);
		while(ch<1||ch>6)
		{
		    printf("������������������");
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
			printf("�������˳�\n");
			exit(0);
		}
	}
	return 0;
}