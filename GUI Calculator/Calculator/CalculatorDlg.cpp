
// CalculatorDlg.cpp : ʵ���ļ�

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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CCalculatorDlg �Ի���



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


// CCalculatorDlg ��Ϣ�������

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CFont* m_font = new CFont;
	m_font->CreateFont(36,0,0,0,FW_BOLD,FALSE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_SWISS,_T("Arial"));
	mEdit.SetFont(m_font,FALSE);
	lastPress = false;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// �����һ�ΰ����ǡ�=����ť������
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
	// ���֡�1����ť
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
	// ���֡�2����ť
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("2");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClicked3()
{
	// ���֡�3����ť
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("3");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClicked4()
{
	// ���֡�4����ť
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("4");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClicked5()
{
	// ���֡�5����ť
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("5");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClicked6()
{
	// ���֡�6����ť
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("6");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClicked7()
{
	// ���֡�7����ť
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("7");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClicked8()
{
	// ���֡�8����ť
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("8");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClicked9()
{
	// ���֡�9����ť
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("9");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClicked0()
{
	// ���֡�0����ť
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
	// ����������ť
	mEdit.SetWindowText(_T(""));
}


void CCalculatorDlg::OnBnClickedBack()
{
	// �����ˡ���ť
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str.Left(str.GetLength()-1);
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedLeft()
{
	// �������š���ť
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
	// �������š���ť
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
	// "."��ť
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
	// �Ӻ�
	lastPress = false;
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("+");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedSub()
{
	// ����
	lastPress = false;
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("-");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedMul()
{
	// �˺�
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
	// ����
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
	// �Ⱥţ�������
	CString str;
	mEdit.GetWindowText(str);
	if(str.Find('+')==-1 && str.Find('-')==-1 && str.Find('*')==-1 && str.Find('/')==-1)
		return;
	else
		lastPress = true;

	CT2CA pszConvertedAnsiString(str);  // �� TCHAR ת��Ϊ LPCSTR
	string exp_str(pszConvertedAnsiString); // �� LPCSTR ���� string

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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}





void CCalculatorDlg::OnBnClickedOpenButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// ���ù�����   
	TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");
	// ������ļ��Ի���   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;

	// ��ʾ���ļ��Ի���   
	if (IDOK == fileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����  
		strFilePath = fileDlg.GetPathName();
		//tEdit.SetWindowText(strFilePath);
		SetDlgItemText(IDC_OPEN_EDIT, strFilePath);

		//SetDlgItemText(IDC_OPEN_EDIT, L" ");
	}
}


void CCalculatorDlg::OnBnClickedSaveButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// ���ù�����   
	TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|Word�ļ�(*.doc)|*.doc|�����ļ�(*.*)|*.*||");
	// ���챣���ļ��Ի���   
	CFileDialog fileDlg(FALSE, _T("doc"), _T("my"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	CString strFilePath;

	// ��ʾ�����ļ��Ի���   
	if (IDOK == fileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ����桱��ť����ѡ����ļ�·����ʾ���༭����   
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_SAVE_EDIT, strFilePath);
	}
}


void CCalculatorDlg::OnEnChangeOpenEdit()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString strFilePath;
	CString strFile;
	UpdateData(TRUE);
	tEdit.GetWindowText(strFile);
	strFilePath = strFilePath + strFile;
	UpdateData(FALSE);
	CT2CA pszConvertedAnsiString(strFilePath);  // �� TCHAR ת��Ϊ LPCSTR
	string test_str(pszConvertedAnsiString); // �� LPCSTR ���� string
	test_str_ = test_str;
}


void CCalculatorDlg::OnEnChangeSaveEdit()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString strFilePath;
	CString strFile;
	UpdateData(TRUE);
	rEdit.GetWindowText(strFile);
	strFilePath = strFilePath + strFile;
	UpdateData(FALSE);
	CT2CA pszConvertedAnsiString(strFilePath);  // �� TCHAR ת��Ϊ LPCSTR
	string results_str(pszConvertedAnsiString); // �� LPCSTR ���� string
	results_str_ = results_str;
}


void CCalculatorDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	//����ļ�����·������
	tEdit.SetWindowText(_T(""));
}


void CCalculatorDlg::OnBnClickedClear2()
{
	//����ļ����·������
	rEdit.SetWindowText(_T(""));
}


void CCalculatorDlg::OnBnClickedButtonAbout()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	INT_PTR nRes;             // ���ڱ���DoModal�����ķ���ֵ   

	CTipDlg tipDlg;           // ����Ի�����CTipDlg��ʵ��   
	nRes = tipDlg.DoModal();  // �����Ի���   
	if (IDCANCEL == nRes)     // �ж϶Ի����˳��󷵻�ֵ�Ƿ�ΪIDCANCEL���������return�������������ִ��   
		return;
}
