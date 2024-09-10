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


// GameRule 메시지 처리기


void GameRule::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}
