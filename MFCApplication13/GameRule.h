#pragma once
#include "afxdialogex.h"


// GameRule 대화 상자

class GameRule : public CDialogEx
{
	DECLARE_DYNAMIC(GameRule)

public:
	GameRule(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~GameRule();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GameRule };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
