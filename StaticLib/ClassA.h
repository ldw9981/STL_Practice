#pragma once
#include "ClassB.h"

class ClassA
{
public:
	int m_Data1;
	int* m_pData2;

	//복사 생성자: 다른 인스턴스로 초기화
	ClassA(const ClassA& other) : m_Data1(other.m_Data1)
	{		
		m_pData2 = new int;
		*m_pData2 = *other.m_pData2;
		printf("Copy %s\n", __FUNCTION__);
	}

	// 매개변수 생성자: 매개변수로 초기화
	ClassA(int data1,int data2) : m_Data1(data1)
	{
		m_pData2 = new int;
		*m_pData2 = data2;
		printf("Parameterized %s\n", __FUNCTION__);
	}
	ClassA(const ClassB& b) : m_Data1(b.m_Data1)
	{
		m_pData2 = new int;
		*m_pData2 = b.m_Data2;
		printf("Parameterized %s\n", __FUNCTION__);
	}

	// 이동 생성자: 다른 인스턴스의 리소스 소유자원(메모리, 파일 핸들 등)를 이동하여 초기화, 즉 소유 자원(리소스)을 새로생성하지않음
	ClassA(ClassA&& other) : m_Data1(other.m_Data1), m_pData2(other.m_pData2)
	{
		other.m_pData2 = nullptr;
		printf("Move %s\n", __FUNCTION__);
	}	

	// 기본 생성자 : 매개변수가 없는 초기화
	ClassA() : m_Data1(0)
	{
		m_pData2 = new int;
		*m_pData2 = 0;
		printf("Default %s\n", __FUNCTION__);
	}
	~ClassA() 
	{
		if (m_pData2 != nullptr)
			delete m_pData2;

		printf("%s\n", __FUNCTION__);
	}
	
};

