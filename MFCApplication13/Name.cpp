// Name.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication13.h"
#include "afxdialogex.h"
#include "Name.h"
#include "Game.h"


// Name dialog

IMPLEMENT_DYNAMIC(Name, CDialogEx)

Name::Name(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Name, pParent)
{

}

Name::~Name()
{
}

void Name::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Name, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Name::OnBnClickedButton1)
END_MESSAGE_MAP()


// Name message handlers


void Name::OnBnClickedButton1()
{
	GetDlgItemText(IDC_EDIT2, m_Input1);
	GetDlgItemText(IDC_EDIT3, m_Input2);

	if (m_Input1.IsEmpty())
	{
		AfxMessageBox(_T("닉네임을 입력해주세요."), MB_OK | MB_ICONWARNING);
	}
	else
	{
		Game dlgGame;
		dlgGame.m_player1_name = m_Input1; // Game 다이얼로그로 전달
		dlgGame.m_player2_name = m_Input2;

		dlgGame.DoModal();

		CDialogEx::OnOK();
	}
}
