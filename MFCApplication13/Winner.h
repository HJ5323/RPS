#pragma once
#include "afxdialogex.h"


// Winner dialog

class Winner : public CDialogEx
{
	DECLARE_DYNAMIC(Winner)

public:
	Winner(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Winner();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Winner };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	CStatic m_winnerStaticCtrl;  // Static Text 컨트롤 멤버 변수
	CString m_winnerText;      // Winner 텍스트 저장 변수

	// Generated message map functions
	virtual BOOL OnInitDialog();

public:
	void SetWinnerText(CString winnerText);  // Setter 함수
};
