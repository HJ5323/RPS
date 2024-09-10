#pragma once
#include "afxdialogex.h"


// Name dialog

class Name : public CDialogEx
{
	DECLARE_DYNAMIC(Name)

public:
	Name(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Name();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Name };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_Input1, m_Input2; // 닉네임
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit2();
};
