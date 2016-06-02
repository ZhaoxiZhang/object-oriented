#include "stdafx.h"
#include "Scan.h"


Scan::Scan()
{
}


Scan::~Scan()
{
}

queue<string>Scan::ToStringQueue(string  input)
{
	int len = input.size();
	queue<string>que;
	int flag = 1;
	bool ERROR_1 = false;


	for (int i = 0; i < len;)
	{
		string tmp = "";

		while (i < len &&
			(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'
				|| input[i] == '=' || input[i] == '(' || input[i] == ')'))
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
			else if (input[i] == '/')  //判断除数为'0'的情况，除数为0报错 
			{
				if (i + 2 < len && input[i + 1] == '0' && (input[i + 2] == '+' || input[i + 2] == '-' || input[i + 2] == '*'
					|| input[i + 2] == '/' || input[i] == '(' || input[i + 2] == ')'))
				{
					ERROR_1 = true;
					break;
				}
				else if (i + 1 < len && input[i + 1] == '0')
				{
					ERROR_1 = true;
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
			else if (input[i] == '=')
			{
				i++;
				continue;
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

		if (tmp.size() > 10 || ERROR_1)     //当数值超过十位数（包括小数位），报错 
		{
			//cerr << "ERROR!";

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