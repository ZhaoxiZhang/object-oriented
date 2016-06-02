/************************************************************
FileName:     Precede.cpp
Author:       zzy19961112
Version :     1.0
Date:         2016.04.06
Description:  从队列中读取字符串，使用两个栈存放
表达式中的数值以及运算符符号，进行四则运算
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

	que.push("#");        //在表达式两头，分别加'#'符号，当##配对，求值完成 
	SignStk.push("#");
	NumStk.push(0);       //处理-()情况下，程序崩溃的错误 

	tmp = que.front();
	que.pop();

	while (tmp != "#" || SignStk.top() != "#")  //当##配对，表达式求值完成 
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
			if (pri == '<')       //栈顶优先权低 
			{
				SignStk.push(tmp);
				tmp = que.front();
				que.pop();
			}
			else if (pri == '=')  //括号配对，栈顶括号弹出 
			{
				SignStk.pop();
				tmp = que.front();
				que.pop();
			}
			else if (pri == '>')  //栈顶优先权高，先弹出，计算，结果操作符入栈 
			{
				string TmpOfSign = SignStk.top();
				SignStk.pop();
				double num2 = NumStk.top();  //第二个操作数在前 
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
