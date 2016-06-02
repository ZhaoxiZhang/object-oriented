/************************************************************
FileName:     Precede.cpp
Author:       zzy19961112
Version :     1.0
Date:         2016.04.06
Description:  �Ӷ����ж�ȡ�ַ�����ʹ������ջ���
���ʽ�е���ֵ�Լ���������ţ�������������
***********************************************************/



#include "stdafx.h"
#include "Calculation.h"


Calculation::Calculation()
{
}


Calculation::~Calculation()
{
}

bool IsOprSign(string sign)
{
	if (sign == "+" || sign == "-" || sign == "*" || sign == "/"
		|| sign == "(" || sign == ")" || sign == "#")
	{
		return true;
	}
	else
	{
		return false;
	}
}


stack<double>Calculation::NumCalculator(queue<string>que)
{
	string tmp;
	char pri;
	stack<double>NumStk;
	stack<string>SignStk;

	que.push("#");        //�ڱ��ʽ��ͷ���ֱ��'#'���ţ���##��ԣ���ֵ��� 
	SignStk.push("#");
	NumStk.push(0);       //����-()����£���������Ĵ��� 

	tmp = que.front();
	que.pop();

	while (tmp != "#" || SignStk.top() != "#")  //��##��ԣ����ʽ��ֵ��� 
	{
		if (!IsOprSign(tmp))
		{
			NumStk.push(transform.StringToNum(tmp));
			tmp = que.front();
			que.pop();
		}
		else
		{
			pri = priority.PrecedeSign(SignStk.top(), tmp);
			if (pri == '<')       //ջ������Ȩ�� 
			{
				SignStk.push(tmp);
				tmp = que.front();
				que.pop();
			}
			else if (pri == '=')  //������ԣ�ջ�����ŵ��� 
			{
				SignStk.pop();
				tmp = que.front();
				que.pop();
			}
			else if (pri == '>')  //ջ������Ȩ�ߣ��ȵ��������㣬�����������ջ 
			{
				string TmpOfSign = SignStk.top();
				SignStk.pop();
				double num2 = NumStk.top();  //�ڶ�����������ǰ 
				NumStk.pop();
				double num1 = NumStk.top();
				NumStk.pop();
				double sum = cal.Operation(num1, TmpOfSign, num2);
				NumStk.push(sum);
			}
		}
	}
	return NumStk;
}
