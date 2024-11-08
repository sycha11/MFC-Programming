﻿
// ChaSeungYunR01View.h: CChaSeungYunR01View 클래스의 인터페이스
//

#pragma once


class CChaSeungYunR01View : public CView
{
protected: // serialization에서만 만들어집니다.
	CChaSeungYunR01View() noexcept;
	DECLARE_DYNCREATE(CChaSeungYunR01View)

// 특성입니다.
public:
	CChaSeungYunR01Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CChaSeungYunR01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	int m_trans;
	int m_key;
	int m_key2;
	int m_gun;
	void M33M31(double PP[], double M[][3], double P[]);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // ChaSeungYunR01View.cpp의 디버그 버전
inline CChaSeungYunR01Doc* CChaSeungYunR01View::GetDocument() const
   { return reinterpret_cast<CChaSeungYunR01Doc*>(m_pDocument); }
#endif

