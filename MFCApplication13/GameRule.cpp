// GameRule.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication13.h"
#include "afxdialogex.h"
#include "GameRule.h"


// GameRule 대화 상자

IMPLEMENT_DYNAMIC(GameRule, CDialogEx)

GameRule::GameRule(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GameRule, pParent)
{

}

GameRule::~GameRule()
{
}

void GameRule::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(GameRule, CDialogEx)
	ON_BN_CLICKED(IDOK, &GameRule::OnBnClickedOk)
END_MESSAGE_MAP()

BOOL GameRule::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 원하는 크기의 글꼴 설정
	font.CreatePointFont(250, _T("Arial"));

	// Static Text 또는 다른 컨트롤에 글꼴 적용
	GetDlgItem(IDC_STATIC_RULE)->SetFont(&font);

	return TRUE;
}

void GameRule::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}
