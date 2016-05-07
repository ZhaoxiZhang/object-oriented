/************************************************************
  FileName:     Precede.cpp
  Author:       zzy19961112     
  Version :     1.0         
  Date:         2016.04.06
  Description:  运算符优先级的处理     
***********************************************************/

#include<iostream>
#include "precede.h"
using namespace std;

Precede::Precede()    //定义构造函数为数据赋值 
{                   //+-*/()#   此处代表列的优先级 
	OprRelation[0] = ">><<<>>";  // '+'
	OprRelation[1] = ">><<<>>";  // '-'
	OprRelation[2] = ">>>><>>";  // '*'
	OprRelation[3] = ">>>><>>";  // '/'
	OprRelation[4] = "<<<<<= ";  // '('
	OprRelation[5] = ">>>> >>";  // ')'
	OprRelation[6] = "<<<<< =";  // '#'
}

/************************************************************

  Description:  使用数值记录不同的运算符，方便找到运算符对应的优先级数组 

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

  Description:  返回运算符对应的优先级数组中所属的数值 

************************************************************/
char Precede::PrecedeSign(string opr1,string opr2)
{
	int index1 = ConvertToIndex(opr1);
	int index2 = ConvertToIndex(opr2);
	
	return OprRelation[index1][index2];
}
