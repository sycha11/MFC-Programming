
// ChaseungyunR1.h : ChaseungyunR1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CChaseungyunR1App:
// �� Ŭ������ ������ ���ؼ��� ChaseungyunR1.cpp�� �����Ͻʽÿ�.
//

class CChaseungyunR1App : public CWinAppEx
{
public:
	CChaseungyunR1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CChaseungyunR1App theApp;
