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

	// 아이콘 설정 (리소스 ID를 사용하여 아이콘 설정)
	SetIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME), TRUE);  // 큰 아이콘
	SetIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME), FALSE); // 작은 아이콘

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

// Enter 키 IDC_BUTTON1 호출
BOOL Name::PreTranslateMessage(MSG* pMsg)
{
	// Enter 키가 눌렸을 때 처리
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		// IDC_BUTTON1 버튼의 클릭 이벤트를 발생시킴
		OnBnClickedButton1();

		// 기본 동작 방지 (다이얼로그가 닫히지 않음)
		return TRUE;
	}

	// 나머지 기본 처리
	return CDialog::PreTranslateMessage(pMsg);
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
