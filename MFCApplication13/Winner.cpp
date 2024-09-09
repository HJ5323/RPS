// Winner.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication13.h"
#include "afxdialogex.h"
#include "Winner.h"


// Winner dialog

IMPLEMENT_DYNAMIC(Winner, CDialogEx)

Winner::Winner(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Winner, pParent)
{

}

Winner::~Winner()
{
}

void Winner::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_WINNER_STATIC, m_winnerStaticCtrl);
}


BEGIN_MESSAGE_MAP(Winner, CDialogEx)
END_MESSAGE_MAP()


// Winner message handlers

BOOL Winner::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // Edit Control에 텍스트 설정
    m_winnerStaticCtrl.SetWindowTextW(m_winnerText);

    return TRUE;  // 포커스를 컨트롤에 두지 않음
}

void Winner::SetWinnerText(CString winnerText)
{
	m_winnerText = winnerText;
}
