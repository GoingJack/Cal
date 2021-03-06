#pragma once
#include "string"

// CDlg3 对话框

class CDlg3 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg3)

public:
	CDlg3(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlg3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
private:
	CEdit N_L;
	CEdit N_R;
public:
	afx_msg void OnBnClickedButton2();
private:
	long B_L;
	long B_R;
private:
	CEdit N_OL;
	long O_L;
	CEdit N_OR;
	long O_R;
public:
	long H_R;
	/* 十六进制数转换为十进制数 */
	long hexToDec(char *source);

	/* 返回ch字符在sign数组中的序号 */
	int getIndexOfSigns(char ch);
	std::string DecIntToHexStr(long num);
	std::string DecStrToHexStr(std::string str);
private:
	CEdit N_HL;
	CEdit N_HR;
	CString H_L;
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};
