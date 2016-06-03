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
    bool IsNotA = true;
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
            IsNotA = false;
            ipt.in = argv[2];
        }
        else
        {
            ipt.in = argv[1];
        }
        que = ipt.ToStringQueue(ipt.in);
        if (que.empty())
        {
            if (!IsNotA)
            {
            	opt.OutPutExpr(ipt.in);
            }
			opt.OutPut(que);
        }
        else
        {
            stk = cal.NumCalculator(que);
            if (!IsNotA)
            {
				que.push("= ");
				opt.OutPut(que);
            }

            opt.PutAns(stk);
        }
    }
    else
    {
        ipt.fin.open(argv[2]);
        opt.fout.open(argv[3]);
        if (!ipt.fin.is_open())
        {
            cerr << "Could not open " << argv[2] << endl;
            ipt.fin.clear();
        }
        else
        {
            while(!ipt.fin.eof())
            {
                getline(ipt.fin,ipt.in);
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

