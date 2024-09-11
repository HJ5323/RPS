// Name.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication13.h"
#include "afxdialogex.h"
#include "Name.h"
#include "Game.h"
#include "GameRule.h"


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
	ON_EN_CHANGE(IDC_EDIT3, &Name::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT2, &Name::OnEnChangeEdit2)
END_MESSAGE_MAP()

BOOL Name::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 원하는 크기의 글꼴 설정
	font.CreatePointFont(150, _T("Arial"));

	GetDlgItem(IDC_STATIC_NAME)->SetFont(&font);


	return TRUE;
}


void Name::OnBnClickedButton1()
{
	GetDlgItemText(IDC_EDIT2, m_Input2); // Player

	if (m_Input2.IsEmpty())
	{
		AfxMessageBox(_T("이름을 입력해주세요."), MB_OK | MB_ICONWARNING);
	}
	else
	{
		// GameRule 다이얼로그 생성하고 표시
		GameRule dlgRules;

		if (dlgRules.DoModal() == IDOK)
		{
			// Name 다이얼로그 종료
			EndDialog(IDOK);

			// Game 다이얼로그로 플레이어 이름 전달
			Game dlgGame;
			dlgGame.m_player1_name = "AI";
			dlgGame.m_player2_name = m_Input2;
			dlgGame.DoModal();

		}
	}
}


void Name::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Name::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
