// ConvInput.cpp : ���� �����Դϴ�.

#include "stdafx.h"
#include "Input_Signal.h"

// CInput_Signal ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CInput_Signal, CDialog)

CInput_Signal::CInput_Signal(CWnd* pParent /*=NULL*/)
	: CDialog(CInput_Signal::IDD, pParent)
	, m_InputSignal_Freq(1)
	, m_InputSignal_Flag(_T("Sin"))
	, InputSignal_Select_Flag(0)
{

}

CInput_Signal::~CInput_Signal()
{
}

void CInput_Signal::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_InputSignal_Freq, m_InputSignal_Freq);
	DDX_Radio(pDX, IDC_InputSignal_Sin, InputSignal_Select_Flag);
}


BEGIN_MESSAGE_MAP(CInput_Signal, CDialog)

	ON_BN_CLICKED(IDOK, &CInput_Signal::OnBnClickedOk)
END_MESSAGE_MAP()


// CConvInput �޽��� ó�����Դϴ�.


//Ȯ�� ��ư�� ������ �Է½�ȣ�� ȭ�鿡 ��Ÿ����. 
void CInput_Signal::OnBnClickedOk()
{
	UpdateData(TRUE);
	CString message;

	switch(InputSignal_Select_Flag){

	case 0:
		m_InputSignal_Flag = "Sin";
		message.Format(_T(" Sin, ���ļ� %dHz�� �����Ǿ����ϴ�.\n"), m_InputSignal_Freq);
		AfxMessageBox(message);
		break;
	case 1:
		m_InputSignal_Flag = "Cos";
		message.Format(_T(" Cos, ���ļ� %dHz�� �����Ǿ����ϴ�.\n"), m_InputSignal_Freq);
		AfxMessageBox(message);
		break;
	case 2:
		m_InputSignal_Flag = "Sinc";
		message.Format(_T(" Sinc, ���ļ� %dHz�� �����Ǿ����ϴ�.\n"), m_InputSignal_Freq);
		AfxMessageBox(message);
		break;
	case 3:
		m_InputSignal_Flag = "White Noise";
		message.Format(_T(" White Noise�� �����Ǿ����ϴ�."));
		AfxMessageBox(message);
		break;
	}

	CDialog::OnOK();
}
