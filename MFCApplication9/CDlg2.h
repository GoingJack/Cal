#pragma once


// CDlg2 对话框

class CDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg2)

public:
	CDlg2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlg2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	double X;
	double Y;
	double Pow_Rs;
public:
	afx_msg void OnBnClickedButton2();
	virtual void OnOK();
private:
	int Fac;
	int Fac_Rs;
public:
	//afx_msg void OnEnChangeEdit20();
private:
	double Log_A;
	double Log_B;
	double Log_Rs;
	double Log10;
public:
	double Log10_Rs;
private:
	double Ln;
	double Ln_Rs;
};
