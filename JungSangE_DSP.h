
// JungSangE_DSP.h : JungSangE_DSP ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CJungSangE_DSPApp:
// �� Ŭ������ ������ ���ؼ��� JungSangE_DSP.cpp�� �����Ͻʽÿ�.
//

class CJungSangE_DSPApp : public CWinAppEx
{
public:
	CJungSangE_DSPApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CJungSangE_DSPApp theApp;
