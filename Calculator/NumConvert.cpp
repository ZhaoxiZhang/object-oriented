/************************************************************
  FileName:     NumConvert.cpp
  Author:       zzy19961112     
  Version :     1.0         
  Date:         2016.04.06
  Description:  ʹ��<sstream>ͷ�ļ�ʹ�ַ���ת��������      
***********************************************************/


#include<iostream>
#include<sstream>
#include "numconvert.h"
using namespace std;

double NumConvert::StringToNum(string input)
{
	double num;
	
	istringstream record(input);    //����¼�󶨵��ַ��� 
	record >> num;                  //��ȡ�ַ��� 
	
	return num;
}
