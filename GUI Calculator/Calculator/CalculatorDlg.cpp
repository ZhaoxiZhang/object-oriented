
// CalculatorDlg.cpp : 实现文件

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include<string>
#include "TipDlg.h"

queue<string>que;
stack<double>stk;

Calculation cal;
Print opt;
Scan ipt;
string test_str_, results_str_;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculatorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, EDIT_SHOW, mEdit);
	DDX_Control(pDX, IDC_OPEN_EDIT, tEdit);
	DDX_Control(pDX, IDC_SAVE_EDIT, rEdit);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(BUTTON_1, &CCalculatorDlg::OnBnClicked1)
	ON_BN_CLICKED(BUTTON_2, &CCalculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(BUTTON_3, &CCalculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(BUTTON_4, &CCalculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(BUTTON_5, &CCalculatorDlg::OnBnClicked5)
	ON_BN_CLICKED(BUTTON_6, &CCalculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(BUTTON_7, &CCalculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(BUTTON_8, &CCalculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(BUTTON_9, &CCalculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(BUTTON_0, &CCalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(BUTTON_CLEAR, &CCalculatorDlg::OnBnClickedClear)
	ON_BN_CLICKED(BUTTON_BACK, &CCalculatorDlg::OnBnClickedBack)
	ON_BN_CLICKED(BUTTON_LEFT, &CCalculatorDlg::OnBnClickedLeft)
	ON_BN_CLICKED(BUTTON_RIGHT, &CCalculatorDlg::OnBnClickedRight)
	ON_BN_CLICKED(BUTTON_DOT, &CCalculatorDlg::OnBnClickedDot)
	ON_BN_CLICKED(BUTTON_ADD, &CCalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(BUTTON_SUB, &CCalculatorDlg::OnBnClickedSub)
	ON_BN_CLICKED(BUTTON_MUL, &CCalculatorDlg::OnBnClickedMul)
	ON_BN_CLICKED(BUTTON_DIV, &CCalculatorDlg::OnBnClickedDiv)
	ON_BN_CLICKED(BUTTON_EQL, &CCalculatorDlg::OnBnClickedEql)
	ON_EN_CHANGE(EDIT_SHOW, &CCalculatorDlg::OnEnChangeShow)
	ON_BN_CLICKED(IDC_OPEN_BUTTON, &CCalculatorDlg::OnBnClickedOpenButton)
	ON_BN_CLICKED(IIDC_SAVE_BUTTON, &CCalculatorDlg::OnBnClickedSaveButton)
	ON_EN_CHANGE(IDC_OPEN_EDIT, &CCalculatorDlg::OnEnChangeOpenEdit)
	ON_EN_CHANGE(IDC_SAVE_EDIT, &CCalculatorDlg::OnEnChangeSaveEdit)
	ON_BN_CLICKED(BUTTON_OK, &CCalculatorDlg::OnBnClickedOk)
	ON_BN_CLICKED(BUTTON_Clear1, &CCalculatorDlg::OnBnClickedClear1)
	ON_BN_CLICKED(BUTTON_CLEAR2, &CCalculatorDlg::OnBnClickedClear2)
	ON_BN_CLICKED(IDC_BUTTON_ABOUT, &CCalculatorDlg::OnBnClickedButtonAbout)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CFont* m_font = new CFont;
	m_font->CreateFont(36,0,0,0,FW_BOLD,FALSE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_SWISS,_T("Arial"));
	mEdit.SetFont(m_font,FALSE);
	lastPress = false;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 如果上一次按的是“=”按钮，清屏
void CCalculatorDlg::Clear()
{
	if (lastPress == true)
	{
		mEdit.SetWindowText(_T(""));
		lastPress = false;
	}
}

void CCalculatorDlg::OnBnClicked1()
{
	// 数字“1”按钮
	Clear();
	UpdateData(TRUE);
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("1");
	mEdit.SetWindowText(str);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClicked2()
{
	// 数字“2”按钮
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("2");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClicked3()
{
	// 数字“3”按钮
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("3");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClicked4()
{
	// 数字“4”按钮
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("4");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClicked5()
{
	// 数字“5”按钮
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("5");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClicked6()
{
	// 数字“6”按钮
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("6");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClicked7()
{
	// 数字“7”按钮
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("7");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClicked8()
{
	// 数字“8”按钮
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("8");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClicked9()
{
	// 数字“9”按钮
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("9");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClicked0()
{
	// 数字“0”按钮
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	if (str != "0")
	{
		str = str + _T("0");
		mEdit.SetWindowText(str);
	}
}


void CCalculatorDlg::OnBnClickedClear()
{
	// “清屏”按钮
	mEdit.SetWindowText(_T(""));
}


void CCalculatorDlg::OnBnClickedBack()
{
	// “后退”按钮
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str.Left(str.GetLength()-1);
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedLeft()
{
	// “左括号”按钮
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	if (str == "")
	{
		str = str + _T("(");
		mEdit.SetWindowText(str);
	}
	else
	{
		if(str.GetAt(str.GetLength()-1)<'0' || str.GetAt(str.GetLength()-1)>'9')
		{
			str = str + _T("(");
			mEdit.SetWindowText(str);
		}
	}
}


void CCalculatorDlg::OnBnClickedRight()
{
	// “右括号”按钮
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	if(str != "")
	{
		if(str.GetAt(str.GetLength()-1)>='0' && str.GetAt(str.GetLength()-1)<='9')
		{
			str = str + _T(")");
			mEdit.SetWindowText(str);
		}
	}
}


void CCalculatorDlg::OnBnClickedDot()
{
	// "."按钮
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	if(str != "")
	{
		if(str.GetAt(str.GetLength()-1)>='0' && str.GetAt(str.GetLength()-1)<='9')
		{
			str = str + _T(".");
			mEdit.SetWindowText(str);
		}
	}
}


void CCalculatorDlg::OnBnClickedAdd()
{
	// 加号
	lastPress = false;
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("+");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedSub()
{
	// 减号
	lastPress = false;
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("-");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedMul()
{
	// 乘号
	lastPress = false;
	CString str;
	mEdit.GetWindowText(str);
	if(str != "")
	{
		if(str.GetAt(str.GetLength()-1)!='+' && str.GetAt(str.GetLength()-1)!='-'
			&& str.GetAt(str.GetLength()-1)!='*' && str.GetAt(str.GetLength()-1)!='/')
		{
			str = str + _T("*");
			mEdit.SetWindowText(str);
		}
	}
}


void CCalculatorDlg::OnBnClickedDiv()
{
	// 除号
	lastPress = false;
	CString str;
	mEdit.GetWindowText(str);
	if(str != "")
	{
		if(str.GetAt(str.GetLength()-1)!='+' && str.GetAt(str.GetLength()-1)!='-'
			&& str.GetAt(str.GetLength()-1)!='*' && str.GetAt(str.GetLength()-1)!='/')
		{
			str = str + _T("/");
			mEdit.SetWindowText(str);
		}
	}
}


void CCalculatorDlg::OnBnClickedEql()
{
	// 等号，计算结果
	CString str;
	mEdit.GetWindowText(str);
	if(str.Find('+')==-1 && str.Find('-')==-1 && str.Find('*')==-1 && str.Find('/')==-1)
		return;
	else
		lastPress = true;

	CT2CA pszConvertedAnsiString(str);  // 将 TCHAR 转换为 LPCSTR
	string exp_str(pszConvertedAnsiString); // 从 LPCSTR 构造 string

	que = ipt.ToStringQueue(exp_str);
	if (que.empty())
	{
		str = "ERROR";
	}
	else
	{
		string tmp;
		stringstream ss;
		stk = cal.NumCalculator(que);
		ss << stk.top();
		ss >> tmp;
		str = tmp.c_str();
	}
	mEdit.SetWindowText(str);
}


BOOL CCalculatorDlg::PreTranslateMessage(MSG* pMsg)
{
	bool flag = true;
	CWnd *pFocusWnd = GetFocus();
	if (pFocusWnd && (pFocusWnd == GetDlgItem(IDC_OPEN_EDIT) || pFocusWnd == GetDlgItem(IDC_SAVE_EDIT)))
	{
		flag = false;
	}
	else
	{
		flag = true;
	}
	if (pMsg->message == WM_KEYDOWN && flag)
		{
			switch (pMsg->wParam)
			{
			case VK_NUMPAD0:
				OnBnClicked0(); break;
			case VK_NUMPAD1:
			case '1':
				OnBnClicked1(); break;
			case '2':
			case VK_NUMPAD2:
				OnBnClicked2(); break;
			case '3':
			case VK_NUMPAD3:
				OnBnClicked3(); break;
			case '4':
			case VK_NUMPAD4:
				OnBnClicked4(); break;
			case '5':
			case VK_NUMPAD5:
				OnBnClicked5(); break;
			case '6':
			case VK_NUMPAD6:
				OnBnClicked6(); break;
			case '7':
			case VK_NUMPAD7:
				OnBnClicked7(); break;
			case VK_NUMPAD8:
				OnBnClicked8(); break;
			case VK_NUMPAD9:
				OnBnClicked9();
				break;
			case '8':
				if (GetKeyState(VK_SHIFT) < 0)
				{
					OnBnClickedMul();
				}
				else
				{
					OnBnClicked8();
				}
				break;
			case '9':
				if (GetKeyState(VK_SHIFT) < 0)
				{
					OnBnClickedLeft();
				}
				else
				{
					OnBnClicked9();
				}
				break;
			case '0':
				if (GetKeyState(VK_SHIFT) < 0)
				{
					OnBnClickedRight();
				}
				else
				{
					OnBnClicked0();
				}
				break;
			case VK_OEM_PLUS:
				if (GetKeyState(VK_SHIFT) < 0)
				{
					OnBnClickedAdd();
				}
				else
				{
					OnBnClickedEql();
				}
				break;
			case VK_OEM_PERIOD:
			case VK_DECIMAL:
				OnBnClickedDot(); break;
			case VK_SUBTRACT:
			case VK_OEM_MINUS:
				OnBnClickedSub(); break;
			case VK_DIVIDE:
			case VK_OEM_2:
				OnBnClickedDiv(); break;
			case VK_ADD:
				OnBnClickedAdd(); break;
			case VK_MULTIPLY:
				OnBnClickedMul(); break;
			case VK_BACK:
				OnBnClickedBack(); break;
			case VK_RETURN:
				OnBnClickedEql(); return TRUE;
			case VK_ESCAPE:
				OnBnClickedClear(); return TRUE;
			default:
				break;
			}
		}

	return CDialogEx::PreTranslateMessage(pMsg);
}



void CCalculatorDlg::OnEnChangeShow()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}





void CCalculatorDlg::OnBnClickedOpenButton()
{
	// TODO: 在此添加控件通知处理程序代码
	// 设置过滤器   
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;

	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里  
		strFilePath = fileDlg.GetPathName();
		//tEdit.SetWindowText(strFilePath);
		SetDlgItemText(IDC_OPEN_EDIT, strFilePath);

		//SetDlgItemText(IDC_OPEN_EDIT, L" ");
	}
}


void CCalculatorDlg::OnBnClickedSaveButton()
{
	// TODO: 在此添加控件通知处理程序代码
	// 设置过滤器   
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|Word文件(*.doc)|*.doc|所有文件(*.*)|*.*||");
	// 构造保存文件对话框   
	CFileDialog fileDlg(FALSE, _T("doc"), _T("my"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	CString strFilePath;

	// 显示保存文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“保存”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_SAVE_EDIT, strFilePath);
	}
}


void CCalculatorDlg::OnEnChangeOpenEdit()
{
	// TODO:  在此添加控件通知处理程序代码
	CString strFilePath;
	CString strFile;
	UpdateData(TRUE);
	tEdit.GetWindowText(strFile);
	strFilePath = strFilePath + strFile;
	UpdateData(FALSE);
	CT2CA pszConvertedAnsiString(strFilePath);  // 将 TCHAR 转换为 LPCSTR
	string test_str(pszConvertedAnsiString); // 从 LPCSTR 构造 string
	test_str_ = test_str;
}


void CCalculatorDlg::OnEnChangeSaveEdit()
{
	// TODO:  在此添加控件通知处理程序代码
	CString strFilePath;
	CString strFile;
	UpdateData(TRUE);
	rEdit.GetWindowText(strFile);
	strFilePath = strFilePath + strFile;
	UpdateData(FALSE);
	CT2CA pszConvertedAnsiString(strFilePath);  // 将 TCHAR 转换为 LPCSTR
	string results_str(pszConvertedAnsiString); // 从 LPCSTR 构造 string
	results_str_ = results_str;
}


void CCalculatorDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	ipt.fin.open(test_str_);
	opt.fout.open(results_str_);
	if (!ipt.fin.is_open())
	{
		cerr << "Could not open " << results_str_ << endl;
		ipt.fin.clear();
	}
	else
	{
		while (!ipt.fin.eof())
		{
			getline(ipt.fin, ipt.in);
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


void CCalculatorDlg::OnBnClickedClear1()
{
	//清空文件输入路径内容
	tEdit.SetWindowText(_T(""));
}


void CCalculatorDlg::OnBnClickedClear2()
{
	//清空文件输出路径内容
	rEdit.SetWindowText(_T(""));
}


void CCalculatorDlg::OnBnClickedButtonAbout()
{
	// TODO: 在此添加控件通知处理程序代码
	INT_PTR nRes;             // 用于保存DoModal函数的返回值   

	CTipDlg tipDlg;           // 构造对话框类CTipDlg的实例   
	nRes = tipDlg.DoModal();  // 弹出对话框   
	if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
		return;
}
