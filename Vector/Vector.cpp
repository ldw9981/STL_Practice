// Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "../StaticLib/ClassA.h"
#include "../StaticLib/Timer.h"
#include <iostream>

using namespace std;

Timer g_timer;

/* reserve �Լ��� vector, map, unordered_map ���� �ִ�. �Ҵ�� �����Ǽ� (Capacity)�� ������ ����(Size)�� �ٸ� �����̴�.
   �����̳ʿ� �Ҵ�� ũ�⸦ �Ѿ ���Ҹ� �߰��Ҷ� ����� �߻��ϴ��� ã�ƺ���.
*/
void TestReserve()
{
	std::vector<ClassA> container;
	// �̸� ������ Ȯ������ ������ Ȯ���� ũ�⺸�� �� ū ũ��� Ȯ���� ������ ���Ҵ��� �߻��Ͽ� ���� ���ϰ� �߻���
	//container.reserve(10);      
	ClassA a;	

	// �Ҵ�� ������ ���� ���� ����
	std::cout << "Capacity" << container.capacity() << ", Size" << container.size() << "\n"; 

	//�Ҵ�� �������ٰ� ���ο� ������ �Ҵ���.
	container.push_back(a);    // �Ҵ�� ��� �����ּ� ��) 00000172F03E4780 [copy]

	std::cout << "Capacity" << container.capacity() << ", Size" << container.size() << "\n";


	//������ ���������� ���ο� ������ �Ҵ��ϰ� ���� �ν��Ͻ��� ������(���������ȣ��). ���� ������ ������(�ı���ȣ��).
	container.push_back(a);    // �Ҵ�� ��� �����ּ� ��) 00000172F03E2A20 [copy] [copy] , delete 00000172F03E4780
	container.push_back(a);	   // �Ҵ�� ��� �����ּ� ��) 00000172F03E2B40 [copy] [copy] [copy] , delete 00000172F03E2A20
	container.push_back(a);    // �Ҵ�� ��� �����ּ� ��) 00000172F03EFA40 [copy] [copy] [copy] [copy] , delete 00000172F03E2B40
}

/*
	�迭�� �Ҵ���� �޸𸮸� �����Ҷ��� ���� ����. 
	ĳ����Ʈ�� ĳ���̽��� ���Ͽ� �˾ƺ���.
*/
void CompareArrayAndPointer()
{
	size_t size = 1000000; 
	std::vector<int> containerValue;
	std::vector<int*> containerPointer;
	containerPointer.reserve(size);
	containerValue.reserve(size);

	for (int i = 0; i < size; i++)	//0~999999 
	{
		containerValue.push_back(i);
		containerPointer.push_back( new int);
		*containerPointer[i] = i;
	}
	
	int sum = 0;
	g_timer.Start();
	for (size_t i = 0; i < size; i++)
	{
		sum += containerValue[i];
	}	
	g_timer.Stop();
	cout << "Vector<int> : " << g_timer.GetElapsedTime() << "ms" << endl;

	sum = 0;
	g_timer.Start();
	for (size_t i = 0; i < size; i++)
	{
		sum += *containerPointer[i];
	}
	g_timer.Stop();
	cout << "Vector<int*> : " << g_timer.GetElapsedTime() << "ms" << endl;
}


void TestPushBack()
{

}
void TestEmplaceBack()
{

}


int main()
{
	TestReserve();
	//CompareArrayAndPointer();
}
