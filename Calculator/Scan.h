#ifndef SCAN_H_
#define SCAN_H_ 
#include<string>
#include<queue>
#include<fstream>
using namespace std;


class Scan
{
	private:
		ifstream fin;
	public:
		string in;
		void FileOpen(string FileName);
		void FileClear();
		bool IsEof();
		bool FileIsOpen();
		void Read();
		friend istream &read(istream &, Scan &);
		queue<string>ToStringQueue(string  input);
};


istream &read(istream &, Scan &);


#endif
