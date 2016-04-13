/************************************************************
  FileName:     Operate.cpp
  Author:       zzy19961112     
  Version :     1.0         
  Date:         2016.04.06
  Description:  进行四则运算，并返回结果      
***********************************************************/

#include<iostream>
#include<string>
#include "operate.h"
using namespace std;

double Operate::Operation(double opr1,string op,double opr2)
{
	double sum; 
	if (op == "+")
	{
		sum = opr1 + opr2;
	}
	else if (op == "-")
	{
		sum = opr1 - opr2;
	}
	else if (op == "*")
	{
		sum = opr1 * opr2;
	}
	else if (op == "/")
	{
		sum = opr1 / opr2;
	}
	return sum;
}
