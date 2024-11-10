#pragma once


class ClassA
{
public:
	int m_data;

	//���� ������
	ClassA(const ClassA& other) : m_data(other.m_data)
	{
		printf("Copy %s\n", __FUNCTION__);
	}

	// �Ű����� ������
	ClassA(int data) : m_data(data)
	{
		printf("Parameterized %s\n", __FUNCTION__);
	}

	// �⺻ ������
	ClassA() : m_data(0)
	{
		printf("Default %s\n", __FUNCTION__);
	}
	~ClassA() 
	{
		printf("%s\n", __FUNCTION__);
	}
	
};

