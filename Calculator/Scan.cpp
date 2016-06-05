/************************************************************
  FileName:     Precede.cpp
  Author:       zzy19961112     
  Version :     1.0         
  Date:         2016.04.06
  Description:  �����ʽ�з��������ַֿ��ֱ�������     
***********************************************************/


#include<iostream>
#include<string>
#include<queue>
#include "scan.h"
using namespace std;


void Scan::FileOpen(string FileName)
{
	fin.open(FileName);
}

bool Scan::FileIsOpen()
{
	return fin.is_open();
}

void Scan::FileClear()
{
	fin.clear();
}

void Scan::Read()
{
	getline(fin, in);
}

bool Scan::IsEof()
{
	return fin.eof();
}
void Scan::FileClose()
{
	fin.close();
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
			if (input[i] == '-')       // ��'-'�������У���ֹ��������"1--2"���ʽ��
									   // '-2' ����ֳ�'-'��'2'�������  
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
			else if (input[i] == '/')  //�жϳ���Ϊ'0'�����������Ϊ0���� 
			{
				if (i + 2 < len && input[i + 1] == '0' && (input[i + 2] == '+' || input[i + 2] == '-' || input[i + 2] == '*'
					|| input[i + 2] == '/' || input[i] == '(' || input[i + 2] == ')'))
				{
					ERROR_1 = true;
					break;
				}
				else if (i ==len - 1 && input[i] == '0')
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

		if (tmp.size() > 10 || ERROR_1)     //����ֵ����ʮλ��������С��λ�������� 
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

Description: �Ӹ������У������ݶ�������������

************************************************************/
istream &read(istream &is, Scan &expr)
{
	is >> expr.in;
	return is;
}
