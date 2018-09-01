// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__21422160_0743_4520_AAD8_024D921C1A22__INCLUDED_)
#define AFX_STDAFX_H__21422160_0743_4520_AAD8_024D921C1A22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef struct node
{
	char num[5];    //���
	char name[10];  //����
	float price;    //����
	int count;      //������
	float sale;    //���۶�
	int next;     //��ָ��
}ElemType;
typedef struct         //˳�����
{
	ElemType *elem;     
	int length;
}SqList;


// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__21422160_0743_4520_AAD8_024D921C1A22__INCLUDED_)
