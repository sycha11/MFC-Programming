
// ChaSeungYunR01View.cpp: CChaSeungYunR01View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ChaSeungYunR01.h"
#endif

#include "ChaSeungYunR01Doc.h"
#include "ChaSeungYunR01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChaSeungYunR01View

IMPLEMENT_DYNCREATE(CChaSeungYunR01View, CView)

BEGIN_MESSAGE_MAP(CChaSeungYunR01View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CChaSeungYunR01View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CChaSeungYunR01View 생성/소멸

CChaSeungYunR01View::CChaSeungYunR01View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_key = 0;
	m_trans = 0;
	m_key2 = 0;
	m_gun = 0;
}

CChaSeungYunR01View::~CChaSeungYunR01View()
{
}

BOOL CChaSeungYunR01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CChaSeungYunR01View 그리기

#include<math.h>
void CChaSeungYunR01View::OnDraw(CDC* /*pDC*/)
{
	CChaSeungYunR01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	CBrush brush1,* pOldBrush1, brush2,brush3,brush4,brush5,brush6,brush7,brush8,brush9;
	CPen pen1,pen2,pen3,pen4, pen5,* pOldPen1;
	CClientDC dc(this);

	//기준점 : 탱크
	int x0 = 100, y0 = 500;

	//좌표 : 자동차 차체 모든점들은 이점을 시점으로 하여서 증감시켜 제작했기에 이점만 움직이면 자동차가 움직임
	int x1 = x0 + m_trans;
	int y1 = y0 - 100 + (-1) ^ (m_trans % 4) * (m_trans % 4);

	//산 좌표
	int x2 = x0 - m_key;
	int y2 = y0;
	//펜설정
	pen1.CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	pen2.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	pen3.CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	pen4.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	pen5.CreatePen(PS_SOLID, 7, RGB(0, 128, 64));

	pOldPen1 = (CPen*)dc.SelectObject(&pen1);

	//브러쉬설정
	brush1.CreateSolidBrush(RGB(0, 128, 64)); // 차체 위
	pOldBrush1 = (CBrush*)dc.SelectObject(&brush1);
	brush2.CreateSolidBrush(RGB(0, 128, 0)); // 차체 아래
	brush3.CreateSolidBrush(RGB(0, 0, 0)); 
	brush4.CreateSolidBrush(RGB(0, 255, 64)); // 도로
	brush5.CreateSolidBrush(RGB(0, 64, 0)); // 포신
	brush6.CreateSolidBrush(RGB(64, 0, 128)); // 포신
	brush7.CreateSolidBrush(RGB(0, 255, 255)); // 하늘
	brush8.CreateSolidBrush(RGB(0, 255, 128)); // 산
	brush9.CreateSolidBrush(RGB(0, 255, 128)); // 산


	//도로
	dc.SelectObject(brush4);
	dc.SelectObject(pen2);
	POINT pts0[] ={{ 0, 500 },{ 1000,500 },{ 2000, 750},{ 0,750 }};
	dc.Polygon(pts0, 4);

	//하늘
	dc.SelectObject(brush7);
	dc.SelectObject(pen2);
	POINT pts100[] ={{ 0, 0 },{ 2000,0 },{ 2000, 500},{ 0,500 },};
	dc.Polygon(pts100, 4);

	//산1
	dc.SelectObject(brush8);
	dc.SelectObject(pen2);
	POINT pts101[] ={{ x2 -200, y2},{ x2 + 150, y2 -470 },{ x2 + 500, y2 }};
	dc.Polygon(pts101, 3);
	
	//산2
	dc.SelectObject(brush8);
	dc.SelectObject(pen2);
	POINT pts102[] ={{ x2 - 550, y2},{ x2 - 200, y2 - 470 },{ x2 +150, y2 }};
	dc.Polygon(pts102, 3);

	//산3
	dc.SelectObject(brush8);
	dc.SelectObject(pen2);
	POINT pts103[] ={{ x2 - 900, y2},{ x2 - 550, y2 - 470 },{ x2 - 200, y2 }};
	dc.Polygon(pts103, 3);

	// 차체 위
	dc.SelectObject(brush1);
	POINT pts[] ={{ x1 + 150, y1 },{ x1 + 200, y1 - 150 },{ x1 + 780, y1 - 150 },{ x1 + 780, y1 },};
	dc.Polygon(pts, 4);

	//차체아래
	dc.SelectObject(brush1);
	POINT pts1[] ={{ x1, y1 },{ x1 + 800, y1 },{ x1 + 800, y1+120 },{ x1, y1 + 120 },};
	dc.Polygon(pts1, 4);

	//창문
	dc.SelectObject(brush2);
	dc.SelectObject(pen4);

	POINT pts5[] ={{ x1 + 500, y1+ -120 },{ x1 + 700, y1-120 },{ x1 + 700, y1 -30 },{ x1+500, y1 -30 },};
	dc.Polygon(pts5, 4);

	//바퀴
	dc.SelectObject(brush2);
	dc.Ellipse(x1 - 20, y1 + 130, x1 + 90, y1 + 240);
	dc.Ellipse(x1 + 100, y1 + 130, x1 + 210, y1 + 240);
	dc.Ellipse(x1 + 220, y1 + 130, x1 + 330, y1 + 240);
	dc.Ellipse(x1 + 340, y1 + 130, x1 + 450, y1 + 240);
	dc.Ellipse(x1 + 460, y1 + 130, x1 + 570, y1 + 240);
	dc.Ellipse(x1 + 580, y1 + 130, x1 + 690, y1 + 240);
	dc.Ellipse(x1 + 700, y1 + 130, x1 + 810, y1 + 240);
	
	//안바퀴
	dc.SelectObject(brush3);
	dc.Ellipse(x1 +15, y1 + 165, x1 + 55, y1 + 205);
	dc.Ellipse(x1 + 135, y1 + 165, x1 + 175, y1 + 205);
	dc.Ellipse(x1 + 255, y1 + 165, x1 + 295, y1 + 205);
	dc.Ellipse(x1 + 375, y1 + 165, x1 + 415, y1 + 205);
	dc.Ellipse(x1 + 495, y1 + 165, x1 + 535, y1 + 205);
	dc.Ellipse(x1 + 615, y1 + 165, x1 + 655, y1 + 205);
	dc.Ellipse(x1 + 735, y1 + 165, x1 + 775, y1 + 205);
	
	//궤도
	dc.SelectObject(brush3);
	dc.SelectObject(pen2);
	POINT pts2[] ={{ x1 + 0, y1 + 120 },{ x1 + 800, y1 + 120 },{ x1 + 800, y1 + 130 },{ x1 + 0, y1 + 130 },};
	dc.Polygon(pts2, 4);

	dc.SelectObject(brush3);
	dc.SelectObject(pen2);
	POINT pts3[] ={{ x1 + 0, y1 + 240 },{ x1 + 800, y1 + 240 },{ x1 + 800, y1 + 250 },{ x1 + 0, y1 + 250 },};
	dc.Polygon(pts3, 4);		


	//포신
	dc.SelectObject(brush5);
	dc.SelectObject(pen2);
	POINT pts6[] ={{ x1 - 50, y1 - 200 },{ x1 + 194, y1 -130 },{ x1 +156, y1 -20 },{ x1 -70, y1 -150 },};
	dc.Polygon(pts6, 4);

	//총 아래
	dc.SelectObject(brush5);
	dc.SelectObject(pen2);
	POINT pts7[] ={{ x1 + 400, y1 - 200 },{ x1 + 700, y1 - 200 },{ x1 + 700, y1 - 150 },{ x1 + 400, y1 - 150 },};
	dc.Polygon(pts7, 4);

	//총몸
	dc.SelectObject(brush6);
	dc.SelectObject(pen2);
	POINT pts8[] ={{ x1 + 450, y1 - 300 },{ x1 + 650, y1 - 300 },{ x1 + 650, y1 - 250 },{ x1 + 610, y1 - 250 },
		{ x1 + 610, y1 - 200 },{ x1 + 600, y1 - 200 },{ x1 + 600, y1 - 250 },{ x1 + 450, y1 - 250 },};
	dc.Polygon(pts8, 8);

	//총열
	dc.SelectObject(brush6);
	dc.SelectObject(pen2);
	POINT pts9[] ={{ x1 + 350-m_gun , y1 - 280 },{ x1 + 450, y1 - 280 },
		{ x1 + 450, y1 - 270 },{ x1 + 350 - m_gun , y1 - 270 },};
	dc.Polygon(pts9, 4);

	//총열 손잡이
	dc.SelectObject(brush6);
	dc.SelectObject(pen2);
	POINT pts10[] ={{ x1 + 650, y1 - 280 },{ x1 + 670, y1 - 280 },{ x1 + 670, y1 - 300 },{ x1 + 690, y1 - 300 },
		{ x1 + 690, y1 - 250 },{ x1 + 670, y1 - 250 },{ x1 + 670, y1 - 270 },{ x1 + 650, y1 - 270 },
	};
	dc.Polygon(pts10, 8);


	dc.SelectObject(pen1);
	//바퀴살 회전 중심 좌표
	double wheel12[3] = { x1+35, y1 + 185, 1 };
	double wheel34[3] = { x1 + 155, y1 + 185, 1 };

	double wheel56[3] = { x1 + 275, y1 + 185, 1 };
	double wheel78[3] = { x1 + 395, y1 + 185, 1 };
	
	double wheel910[3] = { x1 + 515, y1 + 185, 1 };
	
	double wheel2122[3] = { x1 + 635, y1 + 185, 1 };
	
	double wheel1314[3] = { x1 + 755, y1 + 185, 1 };
	
	//바퀴 회전용 바퀴살 좌표 : 원형의 바퀴는 회전시켜도 동일한 모습이어서 원형의 바퀴대신 바퀴살을 회전시켜야 함
	double wheel1[3] = { x1-20 ,  y1 + 185, 1 };  //앞바퀴 바퀴살 앞점
	double wheel2[3] = { x1 + 90, y1 + 185, 1 }; //앞바퀴 바퀴살 뒷점

	double wheel3[3] = { x1 + 100, y1 + 185, 1 }; //뒷바퀴 바퀴살 앞점
	double wheel4[3] = { x1 + 210, y1 + 185, 1 }; //뒷바퀴 바퀴살 뒷점

	double wheel5[3] = { x1 + 220 ,  y1 + 185, 1 };  //앞바퀴 바퀴살 앞점
	double wheel6[3] = { x1 + 330, y1 + 185, 1 }; //앞바퀴 바퀴살 뒷점

	double wheel7[3] = { x1 + 340, y1 + 185, 1 }; //뒷바퀴 바퀴살 앞점
	double wheel8[3] = { x1 + 450, y1 + 185, 1 }; //뒷바퀴 바퀴살 뒷점
	
	double wheel9[3] = { x1 + 460 ,  y1 + 185, 1 };  //앞바퀴 바퀴살 앞점
	double wheel10[3] = { x1 + 570, y1 + 185, 1 }; //앞바퀴 바퀴살 뒷점
	
	double wheel21[3] = { x1 + 580, y1 + 185, 1 }; //뒷바퀴 바퀴살 앞점
	double wheel22[3] = { x1 + 690, y1 + 185, 1 }; //뒷바퀴 바퀴살 뒷점
	
	double wheel13[3] = { x1 + 700, y1 + 185, 1 }; //뒷바퀴 바퀴살 앞점
	double wheel14[3] = { x1 + 810, y1 + 185, 1 }; //뒷바퀴 바퀴살 뒷점
	
	//회전각
	double theta = 0, PHI = 3.1415917;
	theta = m_key * 2 * PHI / 360.0; //Degree 각을 Radian 각으로 환산

	//행렬선언
	double TP[3], RP[3], OP[3];			/* 행렬계산결과용 행렬 */
	double R[3][3] = { {cos(theta), -sin(theta), 0},   	/* 회전행렬 */
			{sin(theta), cos(theta), 0},
			{0,          0,          1}
	};
	double T[3][3] = { {1,0,0},{0,1,0},{0,0,1} };	/* 이동행렬 선언과 초기화 */

	//1바퀴 바퀴살 앞점 회전
	T[0][2] = -1 * wheel12[0]; T[1][2] = -1 * wheel12[1]; 	/* 원점이동량 입력 */
	M33M31(TP, T, wheel1);			/* 원점으로 이동 */
	M33M31(RP, R, TP);			/* 회전 */
	T[0][2] = wheel12[0]; T[1][2] = wheel12[1];	/* 제자리로 이동량 입력 */
	M33M31(OP, T, RP);			/* 제자리로 이동 */
	int gx11 = OP[0], gy11 = OP[1];		/* 회전된 좌표 */
	
	//1바퀴 바퀴살 뒷점 회전
	T[0][2] = -1 * wheel12[0]; T[1][2] = -1 * wheel12[1]; 	/* 원점이동량 입력 */
	M33M31(TP, T, wheel2);			/* 원점으로 이동 */
	M33M31(RP, R, TP);			/* 회전 */
	T[0][2] = wheel12[0]; T[1][2] = wheel12[1];	/* 제자리로 이동량 입력 */
	M33M31(OP, T, RP);			/* 제자리로 이동 */
	int gx22 = OP[0], gy22 = OP[1];		/* 회전된 좌표 */

	//2바퀴 바퀴살 앞점 회전
	T[0][2] = -1 * wheel34[0]; T[1][2] = -1 * wheel34[1]; 	/* 원점이동량 입력 */
	M33M31(TP, T, wheel3);			/* 원점으로 이동 */
	M33M31(RP, R, TP);			/* 회전 */
	T[0][2] = wheel34[0]; T[1][2] = wheel34[1];	/* 제자리로 이동량 입력 */
	M33M31(OP, T, RP);			/* 제자리로 이동 */
	int gx33 = OP[0], gy33 = OP[1];		/* 회전된 좌표 */

	//2바퀴 바퀴살 뒷점 회전
	T[0][2] = -1 * wheel34[0]; T[1][2] = -1 * wheel34[1]; 	/* 원점이동량 입력 */
	M33M31(TP, T, wheel4);			/* 원점으로 이동 */
	M33M31(RP, R, TP);			/* 회전 */
	T[0][2] = wheel34[0]; T[1][2] = wheel34[1];	/* 제자리로 이동량 입력 */
	M33M31(OP, T, RP);			/* 제자리로 이동 */
	int gx44 = OP[0], gy44 = OP[1];		/* 회전된 좌표 */


	//3바퀴 바퀴살 앞점 회전
	T[0][2] = -1 * wheel56[0]; T[1][2] = -1 * wheel56[1]; 	/* 원점이동량 입력 */
	M33M31(TP, T, wheel5);			/* 원점으로 이동 */
	M33M31(RP, R, TP);			/* 회전 */
	T[0][2] = wheel56[0]; T[1][2] = wheel56[1];	/* 제자리로 이동량 입력 */
	M33M31(OP, T, RP);			/* 제자리로 이동 */
	int gx55 = OP[0], gy55 = OP[1];		/* 회전된 좌표 */

	//3바퀴 바퀴살 뒷점 회전
	T[0][2] = -1 * wheel56[0]; T[1][2] = -1 * wheel56[1]; 	/* 원점이동량 입력 */
	M33M31(TP, T, wheel6);			/* 원점으로 이동 */
	M33M31(RP, R, TP);			/* 회전 */
	T[0][2] = wheel56[0]; T[1][2] = wheel56[1];	/* 제자리로 이동량 입력 */
	M33M31(OP, T, RP);			/* 제자리로 이동 */
	int gx66 = OP[0], gy66 = OP[1];		/* 회전된 좌표 */

	//4바퀴 바퀴살 앞점 회전
	T[0][2] = -1 * wheel78[0]; T[1][2] = -1 * wheel78[1]; 	/* 원점이동량 입력 */
	M33M31(TP, T, wheel7);			/* 원점으로 이동 */
	M33M31(RP, R, TP);			/* 회전 */
	T[0][2] = wheel78[0]; T[1][2] = wheel78[1];	/* 제자리로 이동량 입력 */
	M33M31(OP, T, RP);			/* 제자리로 이동 */
	int gx77 = OP[0], gy77 = OP[1];		/* 회전된 좌표 */

	//4바퀴 바퀴살 뒷점 회전
	T[0][2] = -1 * wheel78[0]; T[1][2] = -1 * wheel78[1]; 	/* 원점이동량 입력 */
	M33M31(TP, T, wheel8);			/* 원점으로 이동 */
	M33M31(RP, R, TP);			/* 회전 */
	T[0][2] = wheel78[0]; T[1][2] = wheel78[1];	/* 제자리로 이동량 입력 */
	M33M31(OP, T, RP);			/* 제자리로 이동 */
	int gx88 = OP[0], gy88 = OP[1];		/* 회전된 좌표 */
	
	//5바퀴 바퀴살 앞점 회전
	T[0][2] = -1 * wheel910[0]; T[1][2] = -1 * wheel910[1]; 	/* 원점이동량 입력 */
	M33M31(TP, T, wheel9);			/* 원점으로 이동 */
	M33M31(RP, R, TP);			/* 회전 */
	T[0][2] = wheel910[0]; T[1][2] = wheel910[1];	/* 제자리로 이동량 입력 */
	M33M31(OP, T, RP);			/* 제자리로 이동 */
	int gx99 = OP[0], gy99 = OP[1];		/* 회전된 좌표 */

	//5바퀴 바퀴살 뒷점 회전
	T[0][2] = -1 * wheel910[0]; T[1][2] = -1 * wheel910[1]; 	/* 원점이동량 입력 */
	M33M31(TP, T, wheel10);			/* 원점으로 이동 */
	M33M31(RP, R, TP);			/* 회전 */
	T[0][2] = wheel910[0]; T[1][2] = wheel910[1];	/* 제자리로 이동량 입력 */
	M33M31(OP, T, RP);			/* 제자리로 이동 */
	int gx1010 = OP[0], gy1010 = OP[1];		/* 회전된 좌표 */

	//6바퀴 바퀴살 앞점 회전
	T[0][2] = -1 * wheel2122[0]; T[1][2] = -1 * wheel2122[1]; 	/* 원점이동량 입력 */
	M33M31(TP, T, wheel21);			/* 원점으로 이동 */
	M33M31(RP, R, TP);			/* 회전 */
	T[0][2] = wheel2122[0]; T[1][2] = wheel2122[1];	/* 제자리로 이동량 입력 */
	M33M31(OP, T, RP);			/* 제자리로 이동 */
	int gx1111 = OP[0], gy1111 = OP[1];		/* 회전된 좌표 */

	//6바퀴 바퀴살 뒷점 회전
	T[0][2] = -1 * wheel2122[0]; T[1][2] = -1 * wheel2122[1]; 	/* 원점이동량 입력 */
	M33M31(TP, T, wheel22);			/* 원점으로 이동 */
	M33M31(RP, R, TP);			/* 회전 */
	T[0][2] = wheel2122[0]; T[1][2] = wheel2122[1];	/* 제자리로 이동량 입력 */
	M33M31(OP, T, RP);			/* 제자리로 이동 */
	int gx1212 = OP[0], gy1212 = OP[1];		/* 회전된 좌표 */

	//7바퀴 바퀴살 앞점 회전
	T[0][2] = -1 * wheel1314[0]; T[1][2] = -1 * wheel1314[1]; 	/* 원점이동량 입력 */
	M33M31(TP, T, wheel13);			/* 원점으로 이동 */
	M33M31(RP, R, TP);			/* 회전 */
	T[0][2] = wheel1314[0]; T[1][2] = wheel1314[1];	/* 제자리로 이동량 입력 */
	M33M31(OP, T, RP);			/* 제자리로 이동 */
	int gx1313 = OP[0], gy1313 = OP[1];		/* 회전된 좌표 */

	//7바퀴 바퀴살 뒷점 회전
	T[0][2] = -1 * wheel1314[0]; T[1][2] = -1 * wheel1314[1]; 	/* 원점이동량 입력 */
	M33M31(TP, T, wheel14);			/* 원점으로 이동 */
	M33M31(RP, R, TP);			/* 회전 */
	T[0][2] = wheel1314[0]; T[1][2] = wheel1314[1];	/* 제자리로 이동량 입력 */
	M33M31(OP, T, RP);			/* 제자리로 이동 */
	int gx1414 = OP[0], gy1414 = OP[1];		/* 회전된 좌표 */

	//앞뒷바퀴 바퀴살 회전 그리기
	dc.MoveTo(gx11, gy11); 	dc.LineTo(gx22, gy22);
	dc.MoveTo(gx33, gy33); 	dc.LineTo(gx44, gy44);
	dc.MoveTo(gx55, gy55); 	dc.LineTo(gx66, gy66);
	dc.MoveTo(gx77, gy77); 	dc.LineTo(gx88, gy88);
	dc.MoveTo(gx99, gy99); 	dc.LineTo(gx1010, gy1010);
	dc.MoveTo(gx1111, gy1111); 	dc.LineTo(gx1212, gy1212);
	dc.MoveTo(gx1313, gy1313); 	dc.LineTo(gx1414, gy1414);
	

	//기관총 손잡이
	dc.SelectObject(brush1);
	dc.SelectObject(pen2);

	dc.Ellipse(x1 + 600, y1 - 290, x1 + 640, y1 - 260);

	double wheel1516[3] = { x1 + 620, y1 - 275, 1 };

	dc.SelectObject(pen5);
	double wheel15[3] = { x1 + 620 ,  y1 - 290, 1 };  //앞바퀴 바퀴살 앞점
	double wheel16[3] = { x1 + 620, y1 - 330, 1 }; //앞바퀴 바퀴살 뒷점
	
	//회전각
	double theta2 = 0;
	theta2 = m_key2 * 2 * PHI / 360.0; //Degree 각을 Radian 각으로 환산

	//행렬선언
	double Y[3][3] = { {cos(theta2), -sin(theta2), 0},   	/* 회전행렬 */
			{sin(theta2), cos(theta2), 0},
			{0,          0,          1}
	};
	
	//기관총 손잡이 앞점 회전
	T[0][2] = -1 * wheel1516[0]; T[1][2] = -1 * wheel1516[1]; 	/* 원점이동량 입력 */
	M33M31(TP, T, wheel15);			/* 원점으로 이동 */
	M33M31(RP, Y, TP);			/* 회전 */
	T[0][2] = wheel1516[0]; T[1][2] = wheel1516[1];	/* 제자리로 이동량 입력 */
	M33M31(OP, T, RP);			/* 제자리로 이동 */
	int gx1515 = OP[0], gy1515 = OP[1];		/* 회전된 좌표 */

	//기관총 손잡이 뒷점 회전
	T[0][2] = -1 * wheel1516[0]; T[1][2] = -1 * wheel1516[1]; 	/* 원점이동량 입력 */
	M33M31(TP, T, wheel16);			/* 원점으로 이동 */
	M33M31(RP, Y, TP);			/* 회전 */
	T[0][2] = wheel1516[0]; T[1][2] = wheel1516[1];	/* 제자리로 이동량 입력 */
	M33M31(OP, T, RP);			/* 제자리로 이동 */
	int gx1616 = OP[0], gy1616 = OP[1];		/* 회전된 좌표 */

	//기관총 선 회전 그리기
	dc.MoveTo(gx1515, gy1515); 	dc.LineTo(gx1616, gy1616);

	//브러시와 펜 반환
	dc.SelectObject(pOldBrush1);
	dc.SelectObject(pOldPen1);
}


// CChaSeungYunR01View 인쇄


void CChaSeungYunR01View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CChaSeungYunR01View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CChaSeungYunR01View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CChaSeungYunR01View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CChaSeungYunR01View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CChaSeungYunR01View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CChaSeungYunR01View 진단

#ifdef _DEBUG
void CChaSeungYunR01View::AssertValid() const
{
	CView::AssertValid();
}

void CChaSeungYunR01View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChaSeungYunR01Doc* CChaSeungYunR01View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChaSeungYunR01Doc)));
	return (CChaSeungYunR01Doc*)m_pDocument;
}
#endif //_DEBUG


// CChaSeungYunR01View 메시지 처리기


void CChaSeungYunR01View::M33M31(double PP[], double M[][3], double P[])
{
	// TODO: 여기에 구현 코드 추가.

	for (int i = 0; i < 3; i++) {
		PP[i] = 0;
		for (int j = 0; j < 3; j++)
			PP[i] += M[i][j] * P[j];
	}

}


void CChaSeungYunR01View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar)
	{
	case VK_RIGHT: m_key += 5.0f; m_trans += 5;
		break;
	case VK_LEFT: m_key -= 5.0f;  m_trans -= 5;
		break;
	case VK_UP: 
		m_key2 += 5.0f;
		m_gun += 5.0f;
		if (m_gun == 15) {
			m_gun = 0;
		}
		break;
	case VK_DOWN: 
		m_key2 -= 5.0f;
		m_gun += 5.0f;
		if (m_gun == 15) {
			m_gun = 0;
		}
		break;
	default:
		break;
	}
	Invalidate(TRUE);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
