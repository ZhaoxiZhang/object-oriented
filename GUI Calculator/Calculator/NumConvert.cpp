/************************************************************
FileName:     NumConvert.cpp
Author:       zzy19961112
Version :     1.0
Date:         2016.04.06
Description:  ʹ��<sstream>ͷ�ļ�ʹ�ַ���ת��������
***********************************************************/


#include "stdafx.h"
#include "NumConvert.h"


NumConvert::NumConvert()
{
}


NumConvert::~NumConvert()
{
}


double NumConvert::StringToNum(string input)
{
	double num;

	istringstream record(input);    //����¼�󶨵��ַ��� 
	record >> num;                  //��ȡ�ַ��� 

	return num;
}
