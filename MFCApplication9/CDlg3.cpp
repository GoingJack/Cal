// CDlg3.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication9.h"
#include "CDlg3.h"
#include "afxdialogex.h"
#include "string"
bool flag=FALSE;

// CDlg3 对话框

IMPLEMENT_DYNAMIC(CDlg3, CDialogEx)

CDlg3::CDlg3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, B_L(0)
	, B_R(0)
	, O_L(0)
	, O_R(0)
	, H_R(0)
	, H_L(_T(""))
{

}

CDlg3::~CDlg3()
{
}

void CDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, N_L);
	DDX_Control(pDX, IDC_EDIT15, N_R);
	DDX_Text(pDX, IDC_EDIT1, B_L);
	DDX_Text(pDX, IDC_EDIT15, B_R);
	DDX_Control(pDX, IDC_EDIT19, N_OL);
	DDX_Text(pDX, IDC_EDIT19, O_L);
	DDX_Control(pDX, IDC_EDIT23, N_OR);
	DDX_Text(pDX, IDC_EDIT23, O_R);
	DDX_Text(pDX, IDC_EDIT25, H_R);
	DDX_Control(pDX, IDC_EDIT24, N_HL);
	DDX_Control(pDX, IDC_EDIT25, N_HR);
	DDX_Text(pDX, IDC_EDIT24, H_L);
}


BEGIN_MESSAGE_MAP(CDlg3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlg3::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlg3::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlg3::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlg3::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDlg3::OnBnClickedButton5)
END_MESSAGE_MAP()


// CDlg3 消息处理程序


void CDlg3::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
		CDlg3::OnBnClickedButton3();
		CDlg3::OnBnClickedButton4();
		CDlg3::OnBnClickedButton5();
}


void CDlg3::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	B_L = 0;
	B_R = 0;
	O_L = 0;
	O_R = 0;
	H_L = CString("0");
	H_R = 0;
	UpdateData(FALSE);
}
 
 int CDlg3::getIndexOfSigns(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}
	else if (ch >= 'A' && ch <= 'F')
	{
		return ch - 'A' + 10;
	}
	else if (ch >= 'a' && ch <= 'f')
	{
		return ch - 'a' + 10;
	}
	else
	{
		return -1;
	}
	
}
 long CDlg3::hexToDec(char *source)
 {
	 long sum = 0;
	 long t = 1;
	 int i, len;

	 len = strlen(source);
	 for (i = len - 1; i >= 0; i--)
	 {
		 sum += t * getIndexOfSigns(*(source + i));
		 t *= 16;
	 }

	 return sum;
 }
 std::string CDlg3::DecIntToHexStr(long num)
 {
	 std::string str;
	 long Temp = num / 16;
	 int left = num % 16;
	 if (Temp > 0)
		 str += DecIntToHexStr(Temp);
	 if (left < 10)
		 str += (left + '0');
	 else
		 str += ('A' + left - 10);
	 return str;
 }
 std::string CDlg3::DecStrToHexStr(std::string str)
 {
	 long Dec = 0;
	 for (int i = 0; i < str.size(); ++i)
		 Dec = Dec * 10 + str[i] - '0';
	 return DecIntToHexStr(Dec);
 }




 void CDlg3::OnBnClickedButton3()
 {
	 // TODO: 在此添加控件通知处理程序代码
	 CString str_NL, str_NR;
	 N_L.GetWindowTextW(str_NL);
	 N_R.GetWindowTextW(str_NR);
	 int i = _ttoi(str_NL);
	 int j = _ttoi(str_NR);
	 if (i)
	 {
		 UpdateData(TRUE);
		 long tmp = B_L;
		 int m;
		 int k = 0;
		 while (B_L != 0)
		 {
			 m = B_L % 10;
			 if (m != 0 && m != 1 && m != -1)
			 {
				 MessageBox(TEXT("输入的二进制数值错误！"));
				 B_L = 0;
				 N_HL.SetWindowTextW(TEXT("0"));
				 break;
			 }
			 B_L /= 10;
			 B_R += m * (int)pow(2, k++);
		 }


		 B_L= tmp;
		 UpdateData(FALSE);



	 }
	 else if (j)
	 {
		 UpdateData(TRUE);
		 long tmp_B = B_R;
		 int tmp = 0, c[100], rl = 0;
		 B_L = 0;
		 while (B_R > 0)
		 {
			 //m 这里是每一次循环都会执行到的
			 c[tmp++] = B_R % 2;
			 B_R /= 2;
		 }
		 while (tmp > 0)
		 {
			 B_L += (long)c[tmp - 1] * pow(10, tmp - 1);
			 tmp--;
		 }
		 B_R = tmp_B;
		 UpdateData(FALSE);

	 }
	 else
	 {
		 MessageBox(TEXT("输入了非法字符！"));
		 B_L = 0;
		 B_R = 0;
		 UpdateData(FALSE);
	 }

 }


 void CDlg3::OnBnClickedButton4()
 {
	 // TODO: 在此添加控件通知处理程序代码
	 CString str_OL, str_OR;
	 N_OL.GetWindowTextW(str_OL);
	 N_OR.GetWindowTextW(str_OR);
	 int a = _ttoi(str_OL);
	 int b = _ttoi(str_OR);
	 if (a)
	 {
		 UpdateData(TRUE);
		 long tmp = O_L;
		 int m;
		 int k = 0;
		 while (O_L != 0)
		 {
			 m = O_L % 10;
			 if (m == 9 || m == -9|| m==8 || m == -8)
			 {
				 MessageBox(TEXT("输入的八进制数值错误！"));
				 break;
			 }
			 O_L /= 10;
			 O_R += m * (int)pow(8, k++);
		 }
		 O_L = tmp;
		 UpdateData(FALSE);
	 }
	 else if (b)
	 {
		 UpdateData(TRUE);
		 long tmp_O = O_R;
		 int tmp = 0, c[100], rl = 0;
		 O_L = 0;
		 while (O_R > 0)
		 {
			 //m 这里是每一次循环都会执行到的
			 c[tmp++] = O_R % 8;
			 O_R /= 8;
		 }
		 while (tmp > 0)
		 {
			 O_L += (long)c[tmp - 1] * pow(10, tmp - 1);
			 tmp--;
		 }
		 O_R = tmp_O;
		 UpdateData(FALSE);
	 }
	 else
	 {
		 MessageBox(TEXT("输入了非法字符！"));
		 O_L = 0;
		 O_R = 0;
		 UpdateData(FALSE);
	 }

 }


 void CDlg3::OnBnClickedButton5()
 {
	 // TODO: 在此添加控件通知处理程序代码
	 CString str_HL, str_HR;
	 N_HL.GetWindowTextW(str_HL);
	 N_HR.GetWindowTextW(str_HR);
	 int c = _ttoi(str_HL);
	 int d = _ttoi(str_HR);
	 if (d)
	 {
		 UpdateData(TRUE);
		 std::string DecStr;

		 DecStr = DecStrToHexStr(std::to_string(H_R));
		 H_L = DecStr.data();
		 UpdateData(FALSE);
	 }
	 else if (1)
	 {
		 UpdateData(TRUE);
		 CStringA tmp;
		 tmp = H_L;
		 int count = 0;
		 char *pp = tmp.GetBuffer();
		 int len = strlen(pp);
		 for (int i = len - 1; i >= 0; i--)
			 if (!(*(pp + i) >= '0' && *(pp + i) <= '9' || *(pp + i) >= 'A' && *(pp + i) <= 'F' || *(pp + i) >= 'a' && *(pp + i) <= 'f'))
			 {
				 MessageBox(TEXT("你输入了非法16进制字符！"));
				 H_L = CString("0");
				 UpdateData(FALSE);
				 break;
			 }
			 else
			 {
				 count++;
			 }
		 if (count == len)
		 {
			 H_R = CDlg3::hexToDec(pp);
			 UpdateData(FALSE);
		 }
	 }
 }
