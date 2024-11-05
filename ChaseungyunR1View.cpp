
// ChaseungyunR1View.cpp : CChaseungyunR1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ChaseungyunR1.h"
#endif

#include "ChaseungyunR1Doc.h"
#include "ChaseungyunR1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChaseungyunR1View

IMPLEMENT_DYNCREATE(CChaseungyunR1View, CView)

BEGIN_MESSAGE_MAP(CChaseungyunR1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CChaseungyunR1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CChaseungyunR1View 생성/소멸

CChaseungyunR1View::CChaseungyunR1View()
	: m_strOutText(_T(""))
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CChaseungyunR1View::~CChaseungyunR1View()
{
}

BOOL CChaseungyunR1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CChaseungyunR1View 그리기

void CChaseungyunR1View::OnDraw(CDC* pDC)
{
	CChaseungyunR1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CBrush *pOldBrush1,brush1,brush2, brush3, brush4, brush5, brush6, 
		brush7, brush8, brush9, brush10, brush11, brush12, brush13, brush14, 
		brush15, brush16, brush17, brush18, brush19, brush20, brush21, brush22, 
		brush23, brush24, brush25, brush26, brush27, brush28, brush29;
	
	CPen *pOldPen1, pen1, pen2, pen3, pen4, pen5, pen6;
	
	CClientDC dc(this);
	
	//펜설정
	pen1.CreatePen(PS_SOLID,2,RGB(0,0,0));

	pOldPen1 = (CPen*)dc.SelectObject(&pen1); //이전Pen저장, 새로운 Pen설정
	
	pen2.CreatePen(PS_SOLID,3,RGB(0,0,0)); //  pen2 검은색 2굵기
	pen3.CreatePen(PS_SOLID,2,RGB(0,0,0)); // pen3 검은색 1굵기
	pen4.CreatePen(PS_SOLID,2,RGB(0,100,0)); // pen4 진한갈색 2굵기
	pen6.CreatePen(PS_SOLID,1,RGB(0,0,0));//검은색 1굵기
	//브러쉬설정
	pOldBrush1 = (CBrush*)dc.SelectObject(&brush1);
	brush1.CreateSolidBrush(RGB(255,255,255)); // 흰색
	brush2.CreateSolidBrush(RGB(0,0,0)); //검은색
	brush3.CreateSolidBrush(RGB(128,255,0)); // 1층계단
	brush14.CreateSolidBrush(RGB(216,216,216)); // 벽 그늘
	brush15.CreateSolidBrush(RGB(234,234,234)); //회색벽
	brush4.CreateSolidBrush(RGB(0,255,128)); //  지붕
	brush5.CreateSolidBrush(RGB(150,165,255)); // 발코니 울타리
	brush7.CreateSolidBrush(RGB(0,255,255)); // 하늘색
	brush16.CreateSolidBrush(RGB(4,185,58)); // 옆면짙은 초록색
	brush22.CreateSolidBrush(RGB(235,254,205)); // 길바닥
	brush8.CreateSolidBrush(RGB(255,255,255)); // 바닥
	brush11.CreateSolidBrush(RGB(128,128,128)); // 문
	brush12.CreateSolidBrush(RGB(174,139,89)); // 계단
	brush26.CreateSolidBrush(RGB(164,129,79)); // 현관 땅
	brush27.CreateSolidBrush(RGB(153,217,234)); // 하늘
	brush28.CreateSolidBrush(RGB(138,249,152)); // 잔디밭
	brush29.CreateSolidBrush(RGB(0,98,98)); // 그림자
	
	// 왼쪽 잔디밭
	dc.SelectObject(pen2);
	dc.SelectObject(brush28);
	POINT pts1[] = {{0,522},{0,1000},{1000,1000},{1000,700},{610,489}};
	dc.Polygon(pts1, 5);
	
	// 오른쪽 잔디밭
	dc.SelectObject(pen2);
	dc.SelectObject(brush28);
	POINT pts2[] = {{820,489},{1000,560},{1000,489}};
	dc.Polygon(pts2, 3);
	
	// 길바닥
	dc.SelectObject(pen2);
	dc.SelectObject(brush22);
	POINT pts200[] = {{0,358},{0,523},{610,490},{1000,700},{1000,560},{821,488},{1000,488},{1000,358}};
	dc.Polygon(pts200, 8);

	//계단 1층 앞면
	dc.SelectObject(pen3);
	dc.SelectObject(brush3);
	POINT pts3[] = {{146,450},{146,470},{780,470},{780,450}};
	dc.Polygon(pts3, 4);
	
	//계단 1층 왼쪽 옆면
	dc.SelectObject(pen3);
	dc.SelectObject(brush3);
	POINT pts4[] = {{68,404},{68,428},{146,470},{146,450}};
	dc.Polygon(pts4, 4);
	
	//계단 1층 왼쪽 옆면 위
	dc.SelectObject(pen3);
	dc.SelectObject(brush3);
	POINT pts5[] = {{93,405},{68,404},{146,450},{158,433}};
	dc.Polygon(pts5, 4);
	
	//가운데 집 옆면
	dc.SelectObject(pen3);
	dc.SelectObject(brush15);
	POINT pts76[] = {{266,130},{201,206},{168,358},{305,402},{310,209},{324,224}};
	dc.Polygon(pts76, 6);

	//계단 2층 왼쪽 앞면
	dc.SelectObject(pen3);
	dc.SelectObject(brush3);
	POINT pts6[] = {{93,387},{93,405},{158,433},{158,412}};
	dc.Polygon(pts6, 4);

	//계단 1층 가운데 앞면 바닥
	dc.SelectObject(pen3);
	dc.SelectObject(brush3);
	POINT pts7[] = {{158,433},{146,450},{780,450},{753,434}};
	dc.Polygon(pts7, 4);

	//계단 2층 앞면 가운데 
	dc.SelectObject(pen3);
	dc.SelectObject(brush3);
	POINT pts8[] = {{158,412},{158,433},{753,434},{753,412}};
	dc.Polygon(pts8, 4);

	//왼쪽 계단 위 바닥
	dc.SelectObject(pen3);
	dc.SelectObject(brush3);
	POINT pts9[] = {{93,387},{158,412},{328,412},{263,387}};
	dc.Polygon(pts9, 4);

	//왼쪽 집문 앞면
	dc.SelectObject(pen3);
	dc.SelectObject(brush15);
	POINT pts10[] = {{92,264},{93,387},{263,387},{261,263}};
	dc.Polygon(pts10, 4);

	//왼쪽 집 지붕 윗면
	dc.SelectObject(pen3);
	dc.SelectObject(brush28);
	POINT pts12[] = {{52,207},{92,264},{261,263},{211,206}};
	dc.Polygon(pts12, 4);
	
	
	//왼쪽 집 
	dc.SelectObject(pen4);
	dc.MoveTo(33,270);
	dc.LineTo(40,273);
	
	//왼쪽 집 지붕 앞면
	dc.SelectObject(pen3);
	dc.SelectObject(brush28);
	POINT pts11[] = {{91,261},{85,287},{261,282},{261,263}};
	dc.Polygon(pts11, 4);

	//왼쪽 집 지붕 옆면
	dc.SelectObject(pen3);
	dc.SelectObject(brush4);
	POINT pts13[] = {{24,269},{33,273},{56,243},{86,286},{90,263},{52,210}};
	dc.Polygon(pts13, 6);

	//왼쪽 집  옆면
	dc.SelectObject(pen3);
	dc.SelectObject(brush15);
	POINT pts114[] = {{39,263},{41,413},{67,418},{68,404},{92,404},{93,286},{86,286},{86,286},{56,243}};
	dc.Polygon(pts114, 9);
	/**/
	
	

	//왼쪽 집 문
	dc.SelectObject(pen3);
	dc.SelectObject(brush11);
	POINT pts14[] = {{196,313},{196,386},{261,387},{261,313}};
	dc.Polygon(pts14, 4);

	//왼쪽 집 문 무늬1
	dc.SelectObject(pen3);
	dc.SelectObject(brush2);
	POINT pts15[] = {{212,313},{212,322},{261,322},{261,313}};
	dc.Polygon(pts15, 4);
	
	//왼쪽 집 문 무늬2
	dc.SelectObject(pen3);
	dc.SelectObject(brush2);
	POINT pts16[] = {{212,333},{212,342},{261,342},{261,333}};
	dc.Polygon(pts16, 4);

	//왼쪽 집 문 무늬3
	dc.SelectObject(pen3);
	dc.SelectObject(brush2);
	POINT pts17[] = {{212,353},{212,362},{261,362},{261,353}};
	dc.Polygon(pts17, 4);
	
	//왼쪽 집 문 무늬4
	dc.SelectObject(pen3);
	dc.SelectObject(brush2);
	POINT pts18[] = {{212,373},{212,382},{261,382},{261,373}};
	dc.Polygon(pts18, 4);
	
	//왼쪽 집 창문
	dc.SelectObject(pen3);
	dc.SelectObject(brush4);
	POINT pts19[] = {{52,308},{53,360},{81,360},{81,308}};
	dc.Polygon(pts19, 4);
	
	//왼쪽 집 안 창문 
	dc.SelectObject(pen3);
	dc.SelectObject(brush7);
	POINT pts20[] = {{58,313},{58,354},{75,354},{75,313}};
	dc.Polygon(pts20, 4);
	
	//왼쪽 집 창문 선
	dc.SelectObject(pen4);
	dc.MoveTo(65,313);
	dc.LineTo(65,354);

	//왼쪽 집 창문 선
	dc.SelectObject(pen4);
	dc.MoveTo(56,326);
	dc.LineTo(74,326);

	//왼쪽 집 창문 선
	dc.SelectObject(pen4);
	dc.MoveTo(56,339);
	dc.LineTo(74,339);
	
	//왼쪽 집문고리 
	dc.SelectObject(pen3);
	dc.SelectObject(brush7);
	dc.Ellipse(198,344,208,358);
	
	//가운데 집 지붕 
	dc.SelectObject(pen3);
	dc.SelectObject(brush4);
	POINT pts21[] = {{170,206},{183,206},{254,111},{325,226},{332,197},{254,69}};
	dc.Polygon(pts21, 6);
	

	//가운데 지붕 그림자 
	dc.SelectObject(pen3);
	dc.SelectObject(brush2);
	POINT pts23[] = {{254,111},{184,207},{200,207},{265,129}};
	dc.Polygon(pts23, 4);

	//가운데 문위 그림자
	dc.SelectObject(pen3);
	dc.SelectObject(brush29);
	POINT pts37[] = {{544,204},{544,243},{591,241},{720,204}};
	dc.Polygon(pts37, 4);

	//오른쪽 집 2층 앞면
	dc.SelectObject(pen3);
	dc.SelectObject(brush15);
	POINT pts44[] = {{532,122},{577,187},{570,202},{720,204},{912,193},{914,77},{532,82}};
	dc.Polygon(pts44, 7);

	//2층 발코니 2층 옆면
	dc.SelectObject(pen3);
	dc.SelectObject(brush14);
	POINT pts66[] = {{634,95},{634,203},{713,203},{713,80}};
	dc.Polygon(pts66, 4);

	//발코니 문
	dc.SelectObject(pen6);
	dc.SelectObject(brush11);
	POINT pts63[] = {{531,106},{533,203},{601,203},{601,106}};
	dc.Polygon(pts63, 4);

	//발코니 문선
	dc.SelectObject(pen6);
	dc.SelectObject(brush26);
	POINT pts64[] = {{559,106},{561,106},{561,203},{559,203}};
	dc.Polygon(pts64, 4);

	//2층 발코니 울타리 세로 1
	dc.SelectObject(pen6);
	dc.SelectObject(brush5);
	POINT pts47[] = {{556,141},{556,203},{560,203},{560,141}};
	dc.Polygon(pts47, 4);

	//2층 발코니 울타리 세로 2
	dc.SelectObject(pen6);
	dc.SelectObject(brush5);
	POINT pts48[] = {{566,141},{566,203},{570,203},{570,141}};
	dc.Polygon(pts48, 4);

	//2층 발코니 울타리 세로 3
	dc.SelectObject(pen6);
	dc.SelectObject(brush5);
	POINT pts49[] = {{576,141},{576,203},{580,203},{580,141}};
	dc.Polygon(pts49, 4);

	//2층 발코니 울타리 세로 4
	dc.SelectObject(pen6);
	dc.SelectObject(brush5);
	POINT pts50[] = {{586,141},{586,203},{590,203},{590,141}};
	dc.Polygon(pts50, 4);


	//2층 발코니 울타리 세로 5
	dc.SelectObject(pen6);
	dc.SelectObject(brush5);
	POINT pts51[] = {{596,141},{596,203},{600,203},{600,141}};
	dc.Polygon(pts51, 4);

	//2층 발코니 울타리 세로 6
	dc.SelectObject(pen6);
	dc.SelectObject(brush5);
	POINT pts52[] = {{606,141},{606,203},{610,203},{610,141}};
	dc.Polygon(pts52, 4);

	//2층 발코니 울타리 세로 7
	dc.SelectObject(pen6);
	dc.SelectObject(brush5);
	POINT pts53[] = {{616,141},{616,203},{620,203},{620,141}};
	dc.Polygon(pts53, 4);

	//2층 발코니 울타리 세로 8
	dc.SelectObject(pen6);
	dc.SelectObject(brush5);
	POINT pts54[] = {{626,141},{626,203},{630,203},{630,141}};
	dc.Polygon(pts54, 4);

	//2층 발코니 울타리 세로 9
	dc.SelectObject(pen6);
	dc.SelectObject(brush5);
	POINT pts55[] = {{636,141},{636,203},{640,203},{640,141}};
	dc.Polygon(pts55, 4);
	
	//2층 발코니 울타리 세로 10
	dc.SelectObject(pen6);
	dc.SelectObject(brush5);
	POINT pts56[] = {{646,141},{646,203},{650,203},{650,141}};
	dc.Polygon(pts56, 4);

	//2층 발코니 울타리 세로 11
	dc.SelectObject(pen6);
	dc.SelectObject(brush5);
	POINT pts57[] = {{656,141},{656,203},{660,203},{660,141}};
	dc.Polygon(pts57, 4);

	//2층 발코니 울타리 세로 12
	dc.SelectObject(pen6);
	dc.SelectObject(brush5);
	POINT pts58[] = {{666,141},{666,203},{670,203},{670,141}};
	dc.Polygon(pts58, 4);

	//2층 발코니 울타리 세로 13
	dc.SelectObject(pen6);
	dc.SelectObject(brush5);
	POINT pts59[] = {{676,141},{676,203},{680,203},{680,141}};
	dc.Polygon(pts59, 4);


	//2층 발코니 울타리 세로 14
	dc.SelectObject(pen6);
	dc.SelectObject(brush5);
	POINT pts60[] = {{686,141},{686,203},{690,203},{690,141}};
	dc.Polygon(pts60, 4);

	//2층 발코니 울타리 세로 15
	dc.SelectObject(pen6);
	dc.SelectObject(brush5);
	POINT pts61[] = {{696,141},{696,203},{700,203},{700,141}};
	dc.Polygon(pts61, 4);

	//2층 발코니 울타리 세로 16
	dc.SelectObject(pen6);
	dc.SelectObject(brush5);
	POINT pts62[] = {{706,141},{706,203},{710,203},{710,141}};
	dc.Polygon(pts62, 4);
	//2층 발코니 울타리 가로 1
	dc.SelectObject(pen6);
	dc.SelectObject(brush5);
	POINT pts46[] = {{533,141},{533,147},{713,147},{713,141}};
	dc.Polygon(pts46, 4);

	


	//가운데 지붕 윗면 
	dc.SelectObject(pen3);
	dc.SelectObject(brush4);
	POINT pts24[] = {{254,69},{332,197},{576,187},{496,68}};
	dc.Polygon(pts24, 4);

	//가운데 지붕 앞면 
	dc.SelectObject(pen3);
	dc.SelectObject(brush4);
	POINT pts25[] = {{332,197},{325,226},{564,216},{576,187}};
	dc.Polygon(pts25, 4);

	//가운데 집 앞면
	dc.SelectObject(pen3);
	dc.SelectObject(brush15);
	POINT pts26[] = {{309,208},{306,403},{544,390},{544,216},{325,226}};
	dc.Polygon(pts26, 5);

	//가운데 집 앞면 위 창문
	dc.SelectObject(pen3);
	dc.SelectObject(brush22);
	POINT pts27[] = {{357,246},{360,277},{508,265},{509,235}};
	dc.Polygon(pts27, 4);

	//가운데 집 앞면 위 창문
	dc.SelectObject(pen3);
	dc.SelectObject(brush7);
	POINT pts28[] = {{362,249},{364,273},{504,262},{505,238}};
	dc.Polygon(pts28, 4);

	//가운데 집 앞면 아래 창문
	dc.SelectObject(pen3);
	dc.SelectObject(brush7);
	POINT pts29[] = {{334,291},{335,379},{520,363},{526,276}};
	dc.Polygon(pts29, 4);

	//가운데 집 테이블 다리
	dc.SelectObject(pen3);
	dc.SelectObject(brush22);
	POINT pts30[] = {{391,321},{391,352},{397,352},{397,321}};
	dc.Polygon(pts30, 4);

	//가운데 집 테이블 다리2
	dc.SelectObject(pen3);
	dc.SelectObject(brush22);
	POINT pts31[] = {{462,323},{462,350},{468,350},{468,323}};
	dc.Polygon(pts31, 4);

	//가운데 집 테이블 다리3
	dc.SelectObject(pen3);
	dc.SelectObject(brush22);
	POINT pts32[] = {{402,324},{402,342},{407,342},{407,324}};
	dc.Polygon(pts32, 4);

	//가운데 집 테이블 다리4
	dc.SelectObject(pen3);
	dc.SelectObject(brush22);
	POINT pts33[] = {{449,326},{449,342},{454,342},{454,326}};
	dc.Polygon(pts33, 4);

	//집안에 테이블
	dc.SelectObject(pen3);
	dc.SelectObject(brush22);
	dc.Ellipse(386,309,473,330);

	//가운데 바닥
	dc.SelectObject(pen3);
	dc.SelectObject(brush3);
	POINT pts34[] = {{307,403},{322,410},{752,411},{591,299},{543,299},{543,390}};
	dc.Polygon(pts34, 6);

	//가운데 문 오른쪽 부분
	dc.SelectObject(pen3);
	dc.SelectObject(brush14);
	POINT pts35[] = {{591,299},{717,388},{720,204},{591,228}};
	dc.Polygon(pts35, 4);

	//가운데 문 
	dc.SelectObject(pen3);
	dc.SelectObject(brush11);
	POINT pts36[] = {{544,229},{543,299},{591,299},{591,228}};
	dc.Polygon(pts36, 4);

	//가운데 문 손잡이
	dc.SelectObject(pen3);
	dc.SelectObject(brush7);
	dc.Ellipse(548,245,555,263);

	//오른쪽 집 
	dc.SelectObject(pen3);
	dc.SelectObject(brush15);
	POINT pts38[] = {{720,204},{717,388},{751,410},{753,432},{760,438},{943,434},{941,218},{901,220},{901,204}};
	dc.Polygon(pts38, 9);

	//오른쪽 지붕 옆면
	dc.SelectObject(pen3);
	dc.SelectObject(brush4);
	POINT pts39[] = {{408,68},{423,68},{464,23},{532,82},{551,63},{463,3}};
	dc.Polygon(pts39, 6);

	//오른쪽 지붕 옆면 그림자 
	dc.SelectObject(pen3);
	dc.SelectObject(brush2);
	POINT pts40[] = {{423,68},{441,68},{478,34},{464,23}};
	dc.Polygon(pts40, 4);

	//오른쪽 지붕 옆면2 
	dc.SelectObject(pen3);
	dc.SelectObject(brush15);
	POINT pts41[] = {{441,68},{472,68},{493,102},{520,102},{533,122},{532,82},{478,34}};
	dc.Polygon(pts41, 7);

	//오른쪽 지붕 위
	dc.SelectObject(pen3);
	dc.SelectObject(brush4);
	POINT pts42[] = {{463,3},{551,63},{949,63},{824,3}};
	dc.Polygon(pts42, 4);

	//오른쪽 지붕 앞
	dc.SelectObject(pen3);
	dc.SelectObject(brush4);
	POINT pts43[] = {{551,63},{532,82},{914,77},{949,63}};
	dc.Polygon(pts43, 4);

	
	//2층 가운데 선
	dc.SelectObject(pen4);
	dc.MoveTo(713,80);
	dc.LineTo(713,203);

	//2층 발코니 위 그림자
	dc.SelectObject(pen3);
	dc.SelectObject(brush29);
	POINT pts45[] = {{533,82},{531,95},{634,95},{713,80}};
	dc.Polygon(pts45, 4);

	//2층 발코니 선
	dc.SelectObject(pen6);
	dc.MoveTo(634,95);
	dc.LineTo(634,202);

	//오른쪽 1층 지붕
	dc.SelectObject(pen3);
	dc.SelectObject(brush28);
	POINT pts67[] = {{713,187},{767,227},{968,218},{914,178}};
	dc.Polygon(pts67, 4);

	//오른쪽 1층 지붕 윗면
	dc.SelectObject(pen3);
	dc.SelectObject(brush28);
	POINT pts71[] = {{712,161},{767,227},{968,218},{913,161}};
	dc.Polygon(pts71, 4);

	//오른쪽 1층 지붕 옆면
	dc.SelectObject(pen3);
	dc.SelectObject(brush28);
	POINT pts69[] = {{712,161},{713,204},{764,243},{766,220}};
	dc.Polygon(pts69, 4);

	//오른쪽 1층 지붕 앞옆면
	dc.SelectObject(pen3);
	dc.SelectObject(brush28);
	POINT pts70[] = {{766,220},{764,243},{961,239},{968,218}};
	dc.Polygon(pts70, 4);

	//오른쪽 1층 창문겉
	dc.SelectObject(pen3);
	dc.SelectObject(brush22);
	POINT pts73[] = {{760,274},{760,356},{905,356},{905,274}};
	dc.Polygon(pts73, 4);

	//오른쪽 1층 창문
	dc.SelectObject(pen3);
	dc.SelectObject(brush7);
	POINT pts72[] = {{767,281},{767,349},{898,349},{898,281}};
	dc.Polygon(pts72, 4);


	//오른쪽 1층 창문 선
	dc.SelectObject(pen3);
	dc.MoveTo(831,281);
	dc.LineTo(831,348);

	//오른쪽 2층 창문겉
	dc.SelectObject(pen3);
	dc.SelectObject(brush22);
	POINT pts74[] = {{744,99},{744,153},{880,153},{880,99}};
	dc.Polygon(pts74, 4);

	//오른쪽 2층 창문
	dc.SelectObject(pen3);
	dc.SelectObject(brush7);
	POINT pts75[] = {{751,106},{751,146},{873,146},{873,106}};
	dc.Polygon(pts75, 4);


	//오른쪽 2층 창문 선
	dc.SelectObject(pen3);
	dc.MoveTo(814,107);
	dc.LineTo(814,147);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	if (!pDoc)
		return;
	

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CChaseungyunR1View 인쇄


void CChaseungyunR1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CChaseungyunR1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CChaseungyunR1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CChaseungyunR1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CChaseungyunR1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CChaseungyunR1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CChaseungyunR1View 진단

#ifdef _DEBUG
void CChaseungyunR1View::AssertValid() const
{
	CView::AssertValid();
}

void CChaseungyunR1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChaseungyunR1Doc* CChaseungyunR1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChaseungyunR1Doc)));
	return (CChaseungyunR1Doc*)m_pDocument;
}
#endif //_DEBUG


// CChaseungyunR1View 메시지 처리기


void CChaseungyunR1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this); 
	DrawCross(&dc,point);

	
	CView::OnLButtonDown(nFlags, point);
}

#include "MainFrm.h"	
#define SIZE 10

int CChaseungyunR1View::DrawCross(CDC* pDC, CPoint point)
{
	CMainFrame *pFrm = (CMainFrame *)AfxGetMainWnd();
	int nR,nG,nB;

	switch(pFrm->m_nColor){
			case 1: nR=0; nG=72; nB=72; break;
			case 2: nR=0; nG=255; nB=255; break;
			case 3 :nR=255; nG=255; nB=255; break;
	
			default:        nR=255; nG=255; nB=255;
		}
	CClientDC dc(this);  // 화면 출력을 위한 DC 클래스
	CBrush brush,brush1,brush2,brush3,brush4,brush5,brush22, *pOldBrush;	// 브러시 오브젝트
CPen pen,pen1,pen2,pen3,pen4, *pOldPen;      	// 펜 오브젝트

brush.CreateSolidBrush(RGB(nR,nG,nB));  	// 색설정
pOldBrush = (CBrush *)dc.SelectObject(&brush); // DC에 브러시 선택

pen.CreatePen(PS_SOLID, 1, RGB(0,0,0));   // 펜 생성
pOldPen = (CPen *)dc.SelectObject(&pen); // DC에 펜 선택

brush3.CreateSolidBrush(RGB(255,255,0)); // 형광색

brush5.CreateSolidBrush(RGB(255,255,255)); // 흰색
brush22.CreateSolidBrush(RGB(235,254,205)); // 길바닥
		pen4.CreatePen(PS_SOLID,2,RGB(0,100,0)); // pen4 진한갈색 2굵기
		pen3.CreatePen(PS_SOLID,2,RGB(0,0,0)); // pen3 검은색 2굵기
		


// dc.Rectangle(10,10,30,30);
 //배경
	dc.SelectObject(pen);
	dc.SelectObject(brush);
	POINT pts4[] = {{0,0},{0,358},{39,357},{40,273},{34,273},{24,270},{52,206},{170,205},{255,69},{408,66},{463,3},{824,3},{948,64},{914,77},{912,159},{968,218},{961,239},{942,240},{943,356},{1000,358},{1000,0}};
	dc.Polygon(pts4, 21);
//	dc.SelectObject(pOldPen);	// DC 복원
 //dc.SelectObject(pOldBrush);	// DC 복원
 
	int Shape;

	pen1.CreatePen(PS_SOLID, 1, RGB(255,255,0));// 펜 생성
	pen2.CreatePen(PS_SOLID, 3, RGB(255,0,0));
		pOldPen = (CPen *)dc.SelectObject(&pen); // DC에 펜 선택
	

	brush1.CreateSolidBrush(RGB(255,255,0));
	pOldBrush = (CBrush *)dc.SelectObject(&brush); // DC에 브러시 선택
	brush2.CreateSolidBrush(RGB(255,0,0)); 
	switch(pFrm->m_nShape){
	case 1:
		{dc.SelectObject(pen1);
		dc.SelectObject(brush1);
		POINT pts4[] ={{0,10},{5,15},{3,23},{10,17},{17,23},{15,15},{20,10},{13,10},{10,0},{7,10}};
		dc.Polygon(pts4,10);
		// x+40 y+40
		dc.SelectObject(pen1);
		dc.SelectObject(brush1);
		POINT pts5[] ={{40,50},{45,55},{43,63},{50,57},{57,63},{55,55},{60,50},{53,50},{50,40},{47,50}};
		dc.Polygon(pts5,10);
		
		//y+80
		dc.SelectObject(pen1);
		dc.SelectObject(brush1);
		POINT pts6[] ={{0,90},{5,95},{3,103},{10,97},{17,103},{15,95},{20,90},{13,90},{10,80},{7,90}};
		dc.Polygon(pts6,10);
		
		//x+80,y+120
		dc.SelectObject(pen1);
		dc.SelectObject(brush1);
		POINT pts7[] ={{80,130},{85,135},{83,143},{90,137},{97,143},{95,135},{100,130},{93,130},{90,120},{87,130}};
		dc.Polygon(pts7,10);
		
		//x+160,y+60
		dc.SelectObject(pen1);
		dc.SelectObject(brush1);
		POINT pts8[] ={{160,70},{165,75},{163,83},{170,77},{177,83},{175,75},{180,70},{173,70},{170,60},{167,70}};
		dc.Polygon(pts8,10);

		//220,20
		dc.SelectObject(pen1);
		dc.SelectObject(brush1);
		POINT pts9[] ={{220,30},{225,35},{223,43},{230,37},{237,43},{235,35},{240,30},{233,30},{230,20},{227,30}};
		dc.Polygon(pts9,10);

		//300,20
		dc.SelectObject(pen1);
		dc.SelectObject(brush1);
		POINT pts10[] ={{300,30},{305,35},{303,43},{310,37},{317,43},{315,35},{320,30},{313,30},{310,20},{307,30}};
		dc.Polygon(pts10,10);
		// 950,60
		dc.SelectObject(pen1);
		dc.SelectObject(brush1);
		POINT pts11[] ={{950,70},{955,75},{953,83},{960,77},{967,83},{965,75},{970,70},{963,70},{960,60},{957,70}};
		dc.Polygon(pts11,10);

		// 910,20
		dc.SelectObject(pen1);
		dc.SelectObject(brush1);
		POINT pts12[] ={{910,30},{915,35},{913,43},{920,37},{927,43},{925,35},{930,30},{923,30},{920,20},{917,30}};
		dc.Polygon(pts12,10);

		//140,20
		dc.SelectObject(pen1);
		dc.SelectObject(brush1);
		POINT pts13[] ={{140,30},{145,35},{143,43},{150,37},{157,43},{155,35},{160,30},{153,30},{150,20},{147,30}};
		dc.Polygon(pts13,10);
		break;}
	case 2:
		dc.SelectObject(pen1);
		dc.SelectObject(brush1);
		dc.Chord(30,10,70,60,55,5,60,50);
		break;
	case 3:
		{dc.SelectObject(pen1);
		dc.SelectObject(brush2);
		dc.Ellipse(30,30,70,70);

		dc.SelectObject(pen2);
		dc.MoveTo(50,17);
		dc.LineTo(50,27);

		dc.SelectObject(pen2);
		dc.MoveTo(35,20);
		dc.LineTo(39,29);

		dc.SelectObject(pen2);
		dc.MoveTo(21,30);
		dc.LineTo(31,37);

		dc.SelectObject(pen2);
		dc.MoveTo(17,50);
		dc.LineTo(27,50);
		
		dc.SelectObject(pen2);
		dc.MoveTo(19,65);
		dc.LineTo(29,59);

		dc.SelectObject(pen2);
		dc.MoveTo(29,76);
		dc.LineTo(35,65);

		dc.SelectObject(pen2);
		dc.MoveTo(50,80);
		dc.LineTo(50,73);

		dc.SelectObject(pen2);
		dc.MoveTo(65,69);
		dc.LineTo(72,79);

		dc.SelectObject(pen2);
		dc.MoveTo(73,58);
		dc.LineTo(84,63);

		dc.SelectObject(pen2);
		dc.MoveTo(73,50);
		dc.LineTo(85,50);

		dc.SelectObject(pen2);
		dc.MoveTo(70,39);
		dc.LineTo(84,35);

		dc.SelectObject(pen2);
		dc.MoveTo(60,29);
		dc.LineTo(68,19);
		break;}
	case 4:dc.MoveTo(0,0);
		dc.LineTo(0,0);

 }
brush4.CreateSolidBrush(RGB(0,255,255)); // 하늘색
 switch(pFrm->m_nTurn){
 case 1:
	{ dc.SelectObject(pen);
				dc.SelectObject(brush3);
				POINT pts20[] = {{58,313},{58,354},{75,354},{75,313}};
				dc.Polygon(pts20, 4);

				//왼쪽 집 창문 선
	dc.SelectObject(pen4);
	dc.MoveTo(65,313);
	dc.LineTo(65,354);

	//왼쪽 집 창문 선
	dc.SelectObject(pen4);
	dc.MoveTo(56,326);
	dc.LineTo(74,326);

	//왼쪽 집 창문 선
	dc.SelectObject(pen4);
	dc.MoveTo(56,339);
	dc.LineTo(74,339);

	//가운데 집 앞면 위 안 창문
	dc.SelectObject(pen);
	dc.SelectObject(brush3);
	POINT pts28[] = {{362,249},{364,273},{504,262},{505,238}};
	dc.Polygon(pts28, 4);

	//가운데 집 앞면 아래 창문
	dc.SelectObject(pen);
	dc.SelectObject(brush3);
	POINT pts29[] = {{334,291},{335,379},{520,363},{526,276}};
	dc.Polygon(pts29, 4);

	//가운데 집 테이블 다리
	dc.SelectObject(pen3);
	dc.SelectObject(brush22);
	POINT pts30[] = {{391,321},{391,352},{397,352},{397,321}};
	dc.Polygon(pts30, 4);

	//가운데 집 테이블 다리2
	dc.SelectObject(pen3);
	dc.SelectObject(brush22);
	POINT pts31[] = {{462,323},{462,350},{468,350},{468,323}};
	dc.Polygon(pts31, 4);

	//가운데 집 테이블 다리3
	dc.SelectObject(pen3);
	dc.SelectObject(brush22);
	POINT pts32[] = {{402,324},{402,342},{407,342},{407,324}};
	dc.Polygon(pts32, 4);

	//가운데 집 테이블 다리4
	dc.SelectObject(pen3);
	dc.SelectObject(brush22);
	POINT pts33[] = {{449,326},{449,342},{454,342},{454,326}};
	dc.Polygon(pts33, 4);

	//집안에 테이블
	dc.SelectObject(pen3);
	dc.SelectObject(brush22);
	dc.Ellipse(386,309,473,330);

	//오른쪽 1층 창문
	dc.SelectObject(pen);
	dc.SelectObject(brush3);
	POINT pts72[] = {{767,281},{767,349},{898,349},{898,281}};
	dc.Polygon(pts72, 4);

	//오른쪽 1층 창문 선
	dc.SelectObject(pen3);
	dc.MoveTo(831,281);
	dc.LineTo(831,348);

	//오른쪽 2층 창문
	dc.SelectObject(pen);
	dc.SelectObject(brush3);
	POINT pts75[] = {{751,106},{751,146},{873,146},{873,106}};
	dc.Polygon(pts75, 4);


	//오른쪽 2층 창문 선
	dc.SelectObject(pen3);
	dc.MoveTo(814,107);
	dc.LineTo(814,147);
	break;}
 case 2:
	  {dc.SelectObject(pen);
				dc.SelectObject(brush4);
				POINT pts20[] = {{58,313},{58,354},{75,354},{75,313}};
				dc.Polygon(pts20, 4);

				//왼쪽 집 창문 선
	dc.SelectObject(pen4);
	dc.MoveTo(65,313);
	dc.LineTo(65,354);

	//왼쪽 집 창문 선
	dc.SelectObject(pen4);
	dc.MoveTo(56,326);
	dc.LineTo(74,326);

	//왼쪽 집 창문 선
	dc.SelectObject(pen4);
	dc.MoveTo(56,339);
	dc.LineTo(74,339);

	//가운데 집 앞면 위 안 창문
	dc.SelectObject(pen);
	dc.SelectObject(brush4);
	POINT pts28[] = {{362,249},{364,273},{504,262},{505,238}};
	dc.Polygon(pts28, 4);

	//가운데 집 앞면 아래 창문
	dc.SelectObject(pen);
	dc.SelectObject(brush4);
	POINT pts29[] = {{334,291},{335,379},{520,363},{526,276}};
	dc.Polygon(pts29, 4);

	//가운데 집 테이블 다리
	dc.SelectObject(pen3);
	dc.SelectObject(brush22);
	POINT pts30[] = {{391,321},{391,352},{397,352},{397,321}};
	dc.Polygon(pts30, 4);

	//가운데 집 테이블 다리2
	dc.SelectObject(pen3);
	dc.SelectObject(brush22);
	POINT pts31[] = {{462,323},{462,350},{468,350},{468,323}};
	dc.Polygon(pts31, 4);

	//가운데 집 테이블 다리3
	dc.SelectObject(pen3);
	dc.SelectObject(brush22);
	POINT pts32[] = {{402,324},{402,342},{407,342},{407,324}};
	dc.Polygon(pts32, 4);

	//가운데 집 테이블 다리4
	dc.SelectObject(pen3);
	dc.SelectObject(brush22);
	POINT pts33[] = {{449,326},{449,342},{454,342},{454,326}};
	dc.Polygon(pts33, 4);

	//집안에 테이블
	dc.SelectObject(pen3);
	dc.SelectObject(brush22);
	dc.Ellipse(386,309,473,330);

	//오른쪽 1층 창문
	dc.SelectObject(pen);
	dc.SelectObject(brush4);
	POINT pts72[] = {{767,281},{767,349},{898,349},{898,281}};
	dc.Polygon(pts72, 4);

	//오른쪽 1층 창문 선
	dc.SelectObject(pen3);
	dc.MoveTo(831,281);
	dc.LineTo(831,348);

	//오른쪽 2층 창문
	dc.SelectObject(pen);
	dc.SelectObject(brush4);
	POINT pts75[] = {{751,106},{751,146},{873,146},{873,106}};
	dc.Polygon(pts75, 4);


	//오른쪽 2층 창문 선
	dc.SelectObject(pen3);
	dc.MoveTo(814,107);
	dc.LineTo(814,147);
	break;}
	return 0;
}
}