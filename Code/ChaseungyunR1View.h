
// ChaseungyunR1View.h : CChaseungyunR1View Ŭ������ �������̽�
//

#pragma once


class CChaseungyunR1View : public CView
{
protected: // serialization������ ��������ϴ�.
	CChaseungyunR1View();
	DECLARE_DYNCREATE(CChaseungyunR1View)

// Ư���Դϴ�.
public:
	CChaseungyunR1Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CChaseungyunR1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CString m_strOutText;
	int DrawCross(CDC* pDC, CPoint point);
};

#ifndef _DEBUG  // ChaseungyunR1View.cpp�� ����� ����
inline CChaseungyunR1Doc* CChaseungyunR1View::GetDocument() const
   { return reinterpret_cast<CChaseungyunR1Doc*>(m_pDocument); }
#endif

