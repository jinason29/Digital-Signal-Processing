#include "stdafx.h"
#include "AdjMax.h"

AdjMax::AdjMax(void)
{
	AdMax = new double[Total_No];
	for(int i=0; i<Total_No; i++){
		AdMax[i] = 0;
	}
}

AdjMax::~AdjMax(void)
{
	delete [] AdMax;
}

//������ ����ȭ
void AdjMax::Sort_Max(void)
{
	//������ �� ���밪�� ���� ū ���� ã�´�.
	m_Max = AdMax[0];
	for(int i=1; i<m_TotalData; i++){
		if(m_Max<abs(AdMax[i]))
			m_Max = abs(AdMax[i]);
	}
	//��� �����͸� ���밪�� ���� ū ������ ������.
	//���밪�� ���� ū ���� 1�� �ȴ�.
	for(int i=0; i<m_TotalData; i++){
		AdMax[i] = AdMax[i]/m_Max;
	}
}