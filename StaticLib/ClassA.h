#pragma once
#include "ClassB.h"

class ClassA
{
public:
	int m_Data1;
	int* m_pData2;

	//���� ������: �ٸ� �ν��Ͻ��� �ʱ�ȭ
	ClassA(const ClassA& other) : m_Data1(other.m_Data1)
	{		
		m_pData2 = new int;
		*m_pData2 = *other.m_pData2;
		printf("Instance %p, Copy %s \n",this, __FUNCTION__);
	}

	// �Ű����� ������: �Ű������� �ʱ�ȭ
	ClassA(int data1,int data2) : m_Data1(data1)
	{
		m_pData2 = new int;
		*m_pData2 = data2;
		printf("Instance %p, Parameterized %s \n", this, __FUNCTION__);
	}
	ClassA(const ClassB& b) : m_Data1(b.m_Data1)
	{
		m_pData2 = new int;
		*m_pData2 = b.m_Data2;
		printf("Instance %p, Parameterized %s \n", this, __FUNCTION__);
	}

	// �̵� ������: �ٸ� �ν��Ͻ��� ���ҽ� �����ڿ�(�޸�, ���� �ڵ� ��)�� �̵��Ͽ� �ʱ�ȭ, �� ���� �ڿ�(���ҽ�)�� ���λ�����������
	ClassA(ClassA&& other) : m_Data1(other.m_Data1), m_pData2(other.m_pData2)
	{
		other.m_pData2 = nullptr;
		printf("Instance %p, Move %s \n", this, __FUNCTION__);
	}	

	// �⺻ ������ : �Ű������� ���� �ʱ�ȭ
	ClassA() : m_Data1(0)
	{
		m_pData2 = new int;
		*m_pData2 = 0;
		printf("Instance %p, Default %s \n", this, __FUNCTION__);
	}
	~ClassA() 
	{
		if (m_pData2 != nullptr)
			delete m_pData2;

		printf("Instance %p, %s \n", this, __FUNCTION__);
	}
	
};

