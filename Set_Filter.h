#pragma once


// CSet_Filter ��ȭ �����Դϴ�.

class CSet_Filter : public CDialog
{
	DECLARE_DYNAMIC(CSet_Filter)

public:
	CSet_Filter(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSet_Filter();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Set_Filter };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_SetFilter_Flag;

	int m_SetFilter_Order;
	int m_SetFilter_CutOff;
	int Filter_Select_Flag;

	afx_msg void OnBnClickedOk();
};
