#include<iostream>
#include<string>
#include<queue>
#include<cstring>
#include<fstream>
#include "calculation.h"
#include "numconvert.h"
#include "precede.h"
#include "operate.h"
#include "print.h"
#include "scan.h"

int main(int argc,char* argv[])
{
    int flag = 1;
    queue<string>que;
    stack<double>stk;
    string input;

    Calculation cal;
    Print opt;
    Scan  ipt;

    if (strcmp(argv[1],"-f") != 0)
    {
        if (strcmp(argv[1],"-a") == 0)
        {
            flag = 0;
            ipt.in = argv[2];
        }
        else
        {
            ipt.in = argv[1];
        }
        que = ipt.ToStringQueue(ipt.in);
        if (que.empty())
        {
            if (!flag)
            {
            	opt.outputexpr(ipt.in);
            }
			opt.output(que);
        }
        else
        {
            stk = cal.NumCalculator(que);
            if (!flag)
            {
				que.push("= ");
				opt.output(que);
            }

            opt.putans(stk);
        }
    }
    else
    {
        opt.fin.open(argv[2]);
        opt.fout.open(argv[3]);
        if (!opt.fin.is_open())
        {
            cerr << "Could not open " << argv[2] << endl;
            opt.fin.clear();
        }
        else
        {
            while(!opt.fin.eof())
            {
                getline(opt.fin,ipt.in);
                if (ipt.in == "")
                {
                	continue;
                }
				que = ipt.ToStringQueue(ipt.in);
                if (que.empty())
                {
					opt.OutputToFile(que);
                }
                else
                {
                    stk = cal.NumCalculator(que);
                    opt.PutAnsTofile(stk);
                }
            }
        }
    }

    return 0;
}

