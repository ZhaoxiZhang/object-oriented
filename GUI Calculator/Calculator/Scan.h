#pragma once
#include<iostream>
#include<string>
#include<queue>
#include<fstream>
using namespace std;
class Scan
{
public:
	Scan();
	~Scan();
	ifstream fin;
	string in;
	friend istream &read(istream &, Scan &);
	queue<string>ToStringQueue(string  input);
};

