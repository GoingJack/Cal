// CDlg1.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication9.h"
#include "CDlg1.h"
#include "afxdialogex.h"


// CDlg1 对话框

IMPLEMENT_DYNAMIC(CDlg1, CDialogEx)

CDlg1::CDlg1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	,Div_Rg(1)

{

}

CDlg1::~CDlg1()
{
}

void CDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, Add_L);
	DDX_Text(pDX, IDC_EDIT3, Sub_L);
	DDX_Text(pDX, IDC_EDIT4, Add_Rg);
	DDX_Text(pDX, IDC_EDIT5, Add_Rs);
	DDX_Text(pDX, IDC_EDIT6, Sub_Rg);
	DDX_Text(pDX, IDC_EDIT7, Sub_Rs);
	DDX_Text(pDX, IDC_EDIT8, Mul_L);
	DDX_Text(pDX, IDC_EDIT9, Mul_Rg);
	DDX_Text(pDX, IDC_EDIT10, Mul_Rs);
	DDX_Text(pDX, IDC_EDIT11, Div_L);
	DDX_Text(pDX, IDC_EDIT12, Div_Rg);
	DDX_Text(pDX, IDC_EDIT13, Div_Rs);
}


BEGIN_MESSAGE_MAP(CDlg1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlg1::OnBnClickedButton1)

	ON_EN_CHANGE(IDC_EDIT12, &CDlg1::OnEnChangeEdit12)
	ON_EN_CHANGE(IDC_EDIT2, &CDlg1::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CDlg1 消息处理程序


void CDlg1::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	Add_Rs = Add_L + Add_Rg;
	Sub_Rs = Sub_L - Sub_Rg;
	Mul_Rs = Mul_L * Mul_Rg;
	Div_Rs = Div_L / Div_Rg;
	if (Div_Rg == 0)
	{
		MessageBox(TEXT("除数不能为0！"));
	}
	UpdateData(FALSE);
}


void CDlg1::OnEnChangeEdit12()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CDlg1::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
