#pragma once


// CDlg1 对话框

class CDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg1)

public:
	CDlg1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlg1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	double Add_L;

public:
	afx_msg void OnBnClickedButton1();
private:
	double Sub_L;
private:
	double Add_Rg;
	double Add_Rs;
	double Sub_Rg;
	double Sub_Rs;
	double Mul_L;
	double Mul_Rg;
	double Mul_Rs;

private:
	double Div_L;
	double Div_Rg;
	double Div_Rs;
public:
	afx_msg void OnEnChangeEdit12();
	afx_msg void OnEnChangeEdit2();
};
