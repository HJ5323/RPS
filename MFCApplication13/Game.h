#pragma once
#include "afxdialogex.h"
#include "afxwin.h" 
#include <atlimage.h>

// Game dialog

class Game : public CDialogEx
{
	DECLARE_DYNAMIC(Game)

public:
	Game(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Game();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Game };
#endif

protected:
	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void OnBnClickedButton1();
	afx_msg void OnTimer(UINT_PTR nIDEvent);  // 타이머 이벤트 처리

	CFont font1, font2, font3;

	DECLARE_MESSAGE_MAP()
public:
	int m_round;  // 현재 라운드
	int m_player1_score;  // Player1의 스코어 (Computer)
	int m_player2_score;  // Player2의 스코어 (User)
	CString m_player1_name;  // Player1의 이름
	CString	m_player2_name;  // Player2의 이름
	CButton m_start;  // 게임시작 버튼
	CStatic m_round_ctrl;  // 현재 라운드 표시
	CStatic m_timer_ctrl;  // 타이머 컨트롤
	CStatic m_player1_score_ctrl;  // Player1의 점수 표시
	CStatic m_player2_score_ctrl;  // Player2의 점수 표시
	CStatic m_round_result;  // 각 라운드의 결과 표시
	CStatic m_player1_result;  // Player1의 결과 표시
	CStatic m_player2_result;  // Player2의 결과 표시
	CString m_winnerText;  // winner 저장할 멤버 변수
	UINT_PTR m_nTimerID;  // 타이머 ID

	void ResetGame(); // 게임 초기화

	void CheckWinner();
	HBITMAP LoadBitmapResource(UINT resourceID);  // 비트맵 로드
	void ScaleAndSetBitmap(CStatic& control, HBITMAP hBitmap);  // 비트맵 컨트롤 크기에 맞추는 함수
	afx_msg void OnStnClickedRound();
	afx_msg void OnStnClickedplayer2();
	afx_msg void OnStnClickedPlayer2Score();
	afx_msg void OnStnClickedRoundScore();
	afx_msg void OnStnClickedStaticTime();
	afx_msg void OnStnClickedTimer();
	afx_msg void OnStnClickedPlayer1Score1();
};
