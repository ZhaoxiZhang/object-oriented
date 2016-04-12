/************************************************************
  FileName:     Precede.cpp
  Author:       zzy19961112     
  Version :     1.0         
  Date:         2016.04.06
  Description:  将表达式中符号与数字分开分别存入队列     
***********************************************************/


#include<iostream>
#include<string>
#include<queue>
#include "scan.h"
using namespace std;


queue<string>Scan::ToStringQueue(string  input)
{
	int len = input.size();
	queue<string>que;
	int flag = 1; 
	
	
	for (int i = 0; i < len;)
	{
		string tmp = "";
		
		while (i < len && 
		             (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'
					                                     || input[i] == '(' ||input[i] == ')'))
		{
			if (input[i] == '-')       // 对'-'进行特判，防止出现类似"1--2"表达式中
			                           // '-2' 被拆分成'-'和'2'存入队列  
			{
				if (i == 0)
				{
					if ('0' <= input[i + 1] && input[i + 1] <= '9')
					{
						tmp += input[i++];
						break;
					}
					else
					{
						tmp = input[i++];
						que.push(tmp);
						flag = 0;
						tmp = "";
					}
				}
				else
				{
					if ((input[i - 1] < '0' || input[i - 1] > '9')
					                        && (input[i + 1] >= '0' && input[i + 1] <= '9')
											                        && (input[i - 1] != ')'))
					{
						tmp += input[i++];
						break;
					}
					else
					{
						tmp = input[i++];
						que.push(tmp);
						flag = 0;
						tmp = "";
					}
				}
			}
			else
			{
				tmp = input[i++];
				que.push(tmp);
				flag = 0;
				tmp = "";
			}
		}
		
		while ((i < len && input[i] <= '9'  && input[i] >= '0') 
		                                    || (i < len && input[i] == '.'))
		{
			tmp += input[i++];
			flag = 1;
		}
		
		if(tmp.size() > 10)     //当数值超过十位数（包括小数位），报错 
		{
			cerr << "ERROR!";
			
			while (!que.empty())
			{
				que.pop();
			}
			
			break;
		}
		
		if (flag)
		{
			if (!tmp.empty())
			{
				que.push(tmp);
			}
		}
	}
	return que;
}


/************************************************************

  Description: 从给定流中，将数据读到给定对象中

************************************************************/ 
istream &read(istream &is, Scan &expr)
{
	is >> expr.in;
	return is;
}
