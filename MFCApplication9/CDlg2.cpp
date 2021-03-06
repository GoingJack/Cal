// CDlg2.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication9.h"
#include "CDlg2.h"
#include "afxdialogex.h"


// CDlg2 对话框

IMPLEMENT_DYNAMIC(CDlg2, CDialogEx)

CDlg2::CDlg2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, X(0)
	, Y(0)
	, Pow_Rs(0)
	, Fac(0)
	, Fac_Rs(0)
	, Ln(1)
	, Ln_Rs(0)
	, Log_A(exp(1))
	, Log_B(exp(1))
	, Log_Rs(0)
	, Log10(1)
	, Log10_Rs(0)
{

}

CDlg2::~CDlg2()
{
}

void CDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, X);
	DDX_Text(pDX, IDC_EDIT4, Y);
	DDX_Text(pDX, IDC_EDIT5, Pow_Rs);
	DDX_Text(pDX, IDC_EDIT10, Fac);
	DDX_Text(pDX, IDC_EDIT16, Fac_Rs);
	DDX_Text(pDX, IDC_EDIT20, Log_A);
	DDX_Text(pDX, IDC_EDIT22, Log_B);
	DDX_Text(pDX, IDC_EDIT21, Log_Rs);
	DDX_Text(pDX, IDC_EDIT11, Log10);
	DDX_Text(pDX, IDC_EDIT17, Log10_Rs);
	DDX_Text(pDX, IDC_EDIT18, Ln);
	DDX_Text(pDX, IDC_EDIT19, Ln_Rs);
}


BEGIN_MESSAGE_MAP(CDlg2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlg2::OnBnClickedButton2)
//	ON_EN_CHANGE(IDC_EDIT20, &CDlg2::OnEnChangeEdit20)
END_MESSAGE_MAP()


// CDlg2 消息处理程序


void CDlg2::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	Pow_Rs = pow(X, Y);
	int j = 1;
	for (int i = Fac; i >= 1; i--)
	{
		j *= i;
	}
	Log10_Rs = log10(Log10);
	Ln_Rs = log(Ln);
	Log_Rs = log(Log_B) / log(Log_A);
	Fac_Rs = j;
	
	UpdateData(FALSE);
}


void CDlg2::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}

