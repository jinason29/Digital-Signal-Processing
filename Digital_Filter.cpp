#include "stdafx.h"
#include "Digital_Filter.h"

Digital_Filter::Digital_Filter(void)
	: N(_T(""))
	, Cf(_T(""))
	, Data_No(0)
	, m_Filter_Order(1)
	, m_Filter_CutOff(1)
{
	for(int i=0; i<Total_No; i++){
		LowPass_Filter[i] = 0;
		Butterworth_Filter[i] = 0;
		Chebyshev_Filter[i] = 0;
		LowPass_TimeDomain[i] = 0;
		Butterworth_TimeDomain[i] = 0;
		Chebyshev_TimeDomain[i] = 0;
	}
}

Digital_Filter::~Digital_Filter(void)
{
}

//acosh �Լ�
double acosh(double x){
	double y;
	y = log(x + sqrt((x*x)-1));

	return y;
}

//������� ����
void Digital_Filter::Digital_Filter_LowPass()
{
	for(int t=0; t<Data_No; t++)
			LowPass_TimeDomain[t] = 0;
	//�ð��� �󿡼� Sinc�Լ��� �̿��Ͽ� ������� ���͸� �����. 
	for(int t=m_Filter_Order; t<Data_No; t++)
		LowPass_TimeDomain[t] = abs(sin((Pi*t*m_Filter_CutOff)/Data_No)/((Pi*t)/Data_No));
	LowPass_TimeDomain[0] = LowPass_TimeDomain[1];

	//Ǫ���� Ʈ������ �Ͽ� ���ļ� �󿡼� ������� ���͸� ��Ÿ����.
	fourier.Data_No = Data_No;
	for(int t=0; t<Data_No; t++)
		fourier.Input_Signal[t] = LowPass_TimeDomain[t];
	fourier.FT_Cal();
	for(int f=0; f<Data_No; f++)
		LowPass_Filter[f] = fourier.FT_Transform[f];
}

//���Ϳ��� ����
void Digital_Filter::Digital_Filter_Butterworth()
{
	for(int f=0; f<Data_No ; f++){
		double W_Wc_2n = 0;
		Butterworth_Filter[f] = 0;

		//���ļ� �󿡼� ���Ϳ��� ���͸� �����Ѵ�.
		W_Wc_2n = pow((double)(2*Pi*f)/(2*Pi*m_Filter_CutOff), 2*m_Filter_Order);
		Butterworth_Filter[f] = 1/sqrt(1+W_Wc_2n);
	}
	//�� Ǫ���� Ʈ������ �Ͽ� �ð��� �󿡼� ���Ϳ��� ���͸� ��Ÿ����.
	inverse_fourier.Data_No = Data_No;
	for(int f=0; f<Data_No; f++)
		inverse_fourier.Input_Signal[f] = Butterworth_Filter[f];
	inverse_fourier.FT_Cal();
	for(int t=0; t<Data_No; t++)
		Butterworth_TimeDomain[t] = inverse_fourier.FT_Transform[t];
	/*
	for(int t=0; t<Data_No/2; t++)
		Butterworth_TimeDomain[t] = inverse_fourier.FT_Transform[t] + inverse_fourier.FT_Transform[(Data_No-1)-t];
	for(int t=(Data_No-1); t<Data_No; t++)
		Butterworth_TimeDomain[t] = 0;
	*/
}

//ü��κ� ����
void Digital_Filter::Digital_Filter_Chebyshev()
{
	for(int f=0; f<Data_No; f++){
		double epsilon = 0.5;
		double Cn = 0;
		double W_Wc = 0;
		Chebyshev_Filter[f] = 0;

		//���ļ� �󿡼� ü��κ� ���͸� �����Ѵ�.
		W_Wc = (double)((2*Pi*f)/(2*Pi*m_Filter_CutOff));
		if(fabs(W_Wc) <= 1)
			Cn = cos((double)m_Filter_Order*(acos(W_Wc)));
		else if(fabs(W_Wc) > 1)
			Cn = cosh((double)m_Filter_Order*(acosh(W_Wc)));
		Chebyshev_Filter[f] = fabs(1/sqrt(1+(pow(epsilon, 2)*pow(Cn, 2))));
	}
	//�� Ǫ���� Ʈ������ �Ͽ� �ð��� �󿡼� ü��κ� ���͸� ��Ÿ����.
	inverse_fourier.Data_No = Data_No;
	for(int f=0; f<Data_No; f++)
		inverse_fourier.Input_Signal[f] = Chebyshev_Filter[f];
	inverse_fourier.FT_Cal();
	for(int t=0; t<Data_No; t++)
		Chebyshev_TimeDomain[t] = inverse_fourier.FT_Transform[t];
}

//������ ������ �˷��ִ� �Լ�
void Digital_Filter::Digital_Filter_FilterValue(CDC* pDC)
{
	// �Էµ� ���������� ǥ���Ѵ�.
	N.Format(_T("��������(N) = %d"), m_Filter_Order);
	pDC->TextOut(FreqX+20, FreqY2_Start+20, N);

	// �Էµ� �������ļ��� ǥ���Ѵ�.
	Cf.Format(_T("�������ļ�(Cf) = %d"), m_Filter_CutOff);
	pDC->TextOut(FreqX+20, FreqY2_Start+50, Cf);

	// ���ļ� �� ������ ��
	for(int f=0; f<Data_No; f++){
		// �������ļ��� ȭ�鿡 ǥ���Ѵ�.(�������ļ��� 0�϶� ����)
		if((f == m_Filter_CutOff)&&(m_Filter_CutOff != 0)){
			int x = FreqX+f, y = FreqY2+10;
			Cf.Format(_T("%dHz"),f);
			pDC->TextOut(x,y,Cf);
		}
	}
}