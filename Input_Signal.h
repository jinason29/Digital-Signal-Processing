#pragma once

#include "JungSangE_DSP.h"
#include "afxdialogex.h"

// CInput_Signal ��ȭ �����Դϴ�.

class CInput_Signal : public CDialog
{
	DECLARE_DYNAMIC(CInput_Signal)

public:
	CInput_Signal(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CInput_Signal();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Input_Signal };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_InputSignal_Flag;

	int m_InputSignal_Freq;
	int InputSignal_Select_Flag;
	
	afx_msg void OnBnClickedOk();
};
