// Set_Filter.cpp : ���� �����Դϴ�.

#include "stdafx.h"
#include "JungSangE_DSP.h"
#include "Set_Filter.h"
#include "afxdialogex.h"


// CSet_Filter ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CSet_Filter, CDialog)

CSet_Filter::CSet_Filter(CWnd* pParent /*=NULL*/)
	: CDialog(CSet_Filter::IDD, pParent)
	, m_SetFilter_Flag(_T(""))
	, m_SetFilter_Order(1)
	, m_SetFilter_CutOff(1)
	, Filter_Select_Flag(0)
{

}

CSet_Filter::~CSet_Filter()
{
}

void CSet_Filter::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SetFilter_Order, m_SetFilter_Order);
	DDX_Text(pDX, IDC_SetFilter_CutOff, m_SetFilter_CutOff);
	DDX_Radio(pDX, IDC_SetFilter_LowPass, Filter_Select_Flag);
}


BEGIN_MESSAGE_MAP(CSet_Filter, CDialog)
	ON_BN_CLICKED(IDOK, &CSet_Filter::OnBnClickedOk)
END_MESSAGE_MAP()


// CSet_Filter �޽��� ó�����Դϴ�.

//Ȯ�� ��ư�� ������ ������ ���͸� ȭ�鿡 ��Ÿ����.
void CSet_Filter::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	UpdateData(TRUE);
	CString message;

	switch(Filter_Select_Flag){

	case 0:
		m_SetFilter_Flag = "Low Pass";
		message.Format(_T(" Low Pass, �������� %d �������ļ� %dHz�� �����Ǿ����ϴ�."), m_SetFilter_Order, m_SetFilter_CutOff);
		AfxMessageBox(message);
		break;
	case 1:
		m_SetFilter_Flag = "Butterworth";
		message.Format(_T(" Butterworth, �������� %d �������ļ� %dHz�� �����Ǿ����ϴ�."), m_SetFilter_Order, m_SetFilter_CutOff);
		AfxMessageBox(message);
		break;
	case 2:
		m_SetFilter_Flag = "Chebyshev";
		message.Format(_T(" Chebyshev, �������� %d �������ļ� %dHz�� �����Ǿ����ϴ�."), m_SetFilter_Order, m_SetFilter_CutOff);
		AfxMessageBox(message);
		break;
	}

	CDialog::OnOK();
}
