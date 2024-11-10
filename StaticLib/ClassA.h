#pragma once


class ClassA
{
public:
	int m_data;

	//복사 생성자
	ClassA(const ClassA& other) : m_data(other.m_data)
	{
		printf("Copy %s\n", __FUNCTION__);
	}

	// 매개변수 생성자
	ClassA(int data) : m_data(data)
	{
		printf("Parameterized %s\n", __FUNCTION__);
	}

	// 기본 생성자
	ClassA() : m_data(0)
	{
		printf("Default %s\n", __FUNCTION__);
	}
	~ClassA() 
	{
		printf("%s\n", __FUNCTION__);
	}
	
};

