/************************************************************
  FileName:     Precede.cpp
  Author:       zzy19961112     
  Version :     1.0         
  Date:         2016.04.06
  Description:  ��������ȼ��Ĵ���     
***********************************************************/

#include<iostream>
#include "precede.h"
using namespace std;

Precede::Precede()    //���幹�캯��Ϊ���ݸ�ֵ 
{                   //+-*/()#   �˴������е����ȼ� 
	OprRelation[0] = ">><<<>>";  // '+'
	OprRelation[1] = ">><<<>>";  // '-'
	OprRelation[2] = ">>>><>>";  // '*'
	OprRelation[3] = ">>>><>>";  // '/'
	OprRelation[4] = "<<<<<= ";  // '('
	OprRelation[5] = ">>>> >>";  // ')'
	OprRelation[6] = "<<<<< =";  // '#'
}

/************************************************************

  Description:  ʹ����ֵ��¼��ͬ��������������ҵ��������Ӧ�����ȼ����� 

************************************************************/ 
int Precede::ConvertToIndex(string opr)   
{
	int index;
	
	if (opr == "+")
	{
		index = 0;
	}
	else if (opr == "-")
	{
		index = 1;
	}
	else if (opr == "*")
	{
		index = 2;
	}
	else if (opr == "/")
	{
		index = 3;
	}
	else if (opr == "(")
	{
		index = 4;
	}
	else if (opr == ")")
	{
		index = 5;
	}
	else if (opr == "#")
	{
		index = 6;
	}
	
	return index;
}


/************************************************************

  Description:  �����������Ӧ�����ȼ���������������ֵ 

************************************************************/
char Precede::PrecedeSign(string opr1,string opr2)
{
	int index1 = ConvertToIndex(opr1);
	int index2 = ConvertToIndex(opr2);
	
	return OprRelation[index1][index2];
}
