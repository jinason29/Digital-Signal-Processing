#pragma once

#include "Draw_XY.h"
#include "Fourier_Transform.h"

#include <math.h>

class Digital_Filter
{
public:
	Digital_Filter(void);
	~Digital_Filter(void);
	void Digital_Filter_LowPass();
	void Digital_Filter_Butterworth();
	void Digital_Filter_Chebyshev();
	void Digital_Filter_FilterValue(CDC* pDC);

public:
	CString N;	//���� ������ ȭ�鿡 ��Ÿ�� ����
	CString Cf;	//�������ļ��� ȭ�鿡 ��Ÿ�� ����
	Fourier_Transform fourier;
	Fourier_Transform inverse_fourier;

	int Data_No;
	int m_Filter_Order;		//���� ����
	int m_Filter_CutOff;	//�������ļ�

	//����
	double LowPass_Filter[Total_No];		//�������
	double Butterworth_Filter[Total_No];	//���Ϳ���
	double Chebyshev_Filter[Total_No];		//ü��κ�

	//���͸� �ð��� �� �Լ��� ��Ÿ�� ����
	double LowPass_TimeDomain[Total_No]; 
	double Butterworth_TimeDomain[Total_No];
	double Chebyshev_TimeDomain[Total_No];
	
};