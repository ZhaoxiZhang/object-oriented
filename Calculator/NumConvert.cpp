/************************************************************
  FileName:     NumConvert.cpp
  Author:       zzy19961112     
  Version :     1.0         
  Date:         2016.04.06
  Description:  使用<sstream>头文件使字符串转换成数字      
***********************************************************/


#include<iostream>
#include<sstream>
#include "numconvert.h"
using namespace std;

double NumConvert::StringToNum(string input)
{
	double num;
	
	istringstream record(input);    //将记录绑定到字符串 
	record >> num;                  //读取字符串 
	
	return num;
}
