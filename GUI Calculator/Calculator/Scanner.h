#pragma once
#include<iostream>
#include<string>
#include<queue>
#include<fstream>
using namespace std;
class Scanner
{
private:
	ifstream fin;
public:
	Scanner();
	~Scanner();
	string in;
	void FileOpen(string FileName);
	void FileClear();
	bool IsEof();
	bool FileIsOpen();
	void FileClose();
	void Read();
	friend istream &read(istream &, Scanner &);
	queue<string>ToStringQueue(string  input);
};

