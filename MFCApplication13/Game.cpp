// Game.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication13.h"
#include "afxdialogex.h"
#include "Game.h"
#include "Winner.h"


// Game dialog

IMPLEMENT_DYNAMIC(Game, CDialogEx)

Game::Game(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Game, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

Game::~Game()
{
}

void Game::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BUTTON1, m_start);
    DDX_Control(pDX, IDC_ROUND, m_round_ctrl);
    DDX_Control(pDX, IDC_TIMER, m_timer_ctrl);
    DDX_Control(pDX, IDC_PLAYER1_SCORE, m_player1_score_ctrl);
    DDX_Control(pDX, IDC_PLAYER2_SCORE, m_player2_score_ctrl);
    DDX_Control(pDX, IDC_ROUND_SCORE, m_round_result);
    DDX_Control(pDX, IDC_PLAYER1_RESULT, m_player1_result);
    DDX_Control(pDX, IDC_PLAYER2_RESULT, m_player2_result);
}



BEGIN_MESSAGE_MAP(Game, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Game::OnBnClickedButton1)
    ON_WM_TIMER()
END_MESSAGE_MAP()


// Game message handlers

BOOL Game::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // 초기 글자 지움
    m_round_ctrl.SetWindowText(L"");
    m_timer_ctrl.SetWindowText(L"");
    m_player1_score_ctrl.SetWindowText(L"");
    m_player2_score_ctrl.SetWindowText(L"");
    m_round_result.SetWindowText(L"");

    // 전달받은 텍스트를 static text에 표시
    SetDlgItemText(IDC_player1, m_player1_name);
    SetDlgItemText(IDC_player2, m_player2_name);

    // 초기 값 설정
    m_round = 1;
    m_player1_score = 0;
    m_player2_score = 0;

    // 타이머는 설정하지 않은 상태
    m_nTimerID = 0;

    srand(static_cast<unsigned int>(time(nullptr)));

    return TRUE;  // return TRUE unless you set the focus to a control
}

// start 버튼 클릭 시 실행
void Game::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	m_round = 1;  // 첫 번째 라운드 시작
	m_player1_score = 0;
	m_player2_score = 0;

	// UI 업데이트
	CString roundText;
	roundText.Format(_T("%d"), m_round);
	m_round_ctrl.SetWindowTextW(roundText);

	// 타이머 시작 (5초 간격)
	m_nTimerID = SetTimer(1, 1000, nullptr);  // 1초 간격으로 타이머 작동

    GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);
}

// 타이머가 호출될 때마다 실행
void Game::OnTimer(UINT_PTR nIDEvent)
{
    static int timeRemaining = 5;  // 5초 카운트다운

    if (nIDEvent == m_nTimerID)
    {
        // 남은 시간 UI 업데이트
        CString timerText;
        timerText.Format(_T("%d"), timeRemaining);
        m_timer_ctrl.SetWindowTextW(timerText);

        // 시간이 0이 되면 가위바위보 결과 확인
        if (timeRemaining == 0)
        {
            KillTimer(m_nTimerID);  // 타이머 종료
            timeRemaining = 5;  // 타이머 초기화

            // OpenCV로 인식한 결과 가져오기 (지금은 가상 결과 사용)
            int player1_result = rand() % 3;  // 0: 가위, 1: 바위, 2: 보
            int player2_result = rand() % 3;

            // Player 1과 Player 2의 이미지 설정
            HBITMAP hPlayer1Image = LoadBitmapResource(player1_result == 0 ? IDB_SCISSORS : player1_result == 1 ? IDB_ROCK : IDB_PAPER);
            HBITMAP hPlayer2Image = LoadBitmapResource(player2_result == 0 ? IDB_SCISSORS : player2_result == 1 ? IDB_ROCK : IDB_PAPER);

            if (hPlayer1Image && hPlayer2Image)
            {
                // Player 1
                ScaleAndSetBitmap(m_player1_result, hPlayer1Image);

                // Player 2
                ScaleAndSetBitmap(m_player2_result, hPlayer2Image);
            }

            // 승자 판단
            if ((player1_result == 0 && player2_result == 2) ||  // 가위 vs 보
                (player1_result == 1 && player2_result == 0) ||  // 바위 vs 가위
                (player1_result == 2 && player2_result == 1))    // 보 vs 바위
            {
                m_player1_score++;
                m_round_result.SetWindowTextW(m_player1_name + _T(" Wins!"));
            }
            else if (player1_result == player2_result)
            {
                m_round_result.SetWindowTextW(_T("Draw!"));
            }
            else
            {
                m_player2_score++;
                m_round_result.SetWindowTextW(m_player2_name + _T(" Wins!"));
            }

            // 점수 업데이트
            CString player1ScoreText, player2ScoreText;
            player1ScoreText.Format(_T("%d"), m_player1_score);
            player2ScoreText.Format(_T("%d"), m_player2_score);
            m_player1_score_ctrl.SetWindowTextW(player1ScoreText);
            m_player2_score_ctrl.SetWindowTextW(player2ScoreText);

            // 다음 라운드 설정
            if (m_round < 3)
            {
                m_round++;
                CString roundText;
                roundText.Format(_T("%d"), m_round);
                m_round_ctrl.SetWindowTextW(roundText);

                // 타이머 재시작
                m_nTimerID = SetTimer(1, 1000, nullptr);
            }
            else
            {
                // 게임 종료 후 최종 승자 확인
                CheckWinner();
            }
        }
        else
        {
            timeRemaining--;  // 시간 감소
        }
    }

    // 2초 후에 Winner 다이얼로그 표시
    if (nIDEvent == 2)  
    {
        KillTimer(2);  // 타이머 종료

        Winner dlgWinner;
        dlgWinner.SetWinnerText(m_winnerText); // Winner 다이얼로그에 결과 전달
        dlgWinner.DoModal();
    }

    CDialogEx::OnTimer(nIDEvent);
}

HBITMAP Game::LoadBitmapResource(UINT resourceID)
{
    HBITMAP hBitmap = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(resourceID));
    if (hBitmap == NULL)
    {
        AfxMessageBox(_T("이미지 로드 실패!"));
    }
    return hBitmap;
}

void Game::ScaleAndSetBitmap(CStatic& control, HBITMAP hBitmap)
{
    // 컨트롤의 크기 얻기
    CRect rect;
    control.GetClientRect(&rect);

    // 메모리 DC 생성
    CDC dcMemory;
    dcMemory.CreateCompatibleDC(NULL);

    // 비트맵 선택
    HBITMAP hOldBitmap = (HBITMAP)dcMemory.SelectObject(hBitmap);

    // 비트맵 정보 얻기
    BITMAP bitmap;
    ::GetObject(hBitmap, sizeof(BITMAP), &bitmap);

    // 실제 스케일링을 위해 DC 생성
    CDC* pDC = control.GetDC();

    // StretchBlt로 이미지를 스케일링하여 컨트롤에 맞춤
    pDC->StretchBlt(0, 0, rect.Width(), rect.Height(),
        &dcMemory, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);

    // Release DC 및 이전 비트맵으로 복구
    dcMemory.SelectObject(hOldBitmap);
    control.ReleaseDC(pDC);

    // 비트맵 핸들 해제
    DeleteObject(hBitmap);
}

// 최종 승자를 확인
void Game::CheckWinner()
{
    CString winnerText;
    if (m_player1_score > m_player2_score)
    {
        winnerText.Format(_T("Winner: %s"), m_player1_name);
    }
    else if (m_player1_score < m_player2_score)
    {
        winnerText.Format(_T("Winner: %s"), m_player2_name);
    }
    else
    {
        winnerText = _T("It's a Draw!");
    }

    m_winnerText = winnerText;

    // 2초 타이머 설정
    SetTimer(2, 2000, nullptr);
}

