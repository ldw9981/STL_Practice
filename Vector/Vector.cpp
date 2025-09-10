// Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include "../StaticLib/ClassA.h"
#include "../StaticLib/Timer.h"
#include <iostream>
#include <chrono>

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
void CompareVectorPointerList()
{
	const int N = 100000;
	volatile long long sum = 0; 
	// 1) vector<int>
	{
		sum = 0;
		std::vector<int> v;
		v.reserve(N);
		for (size_t i = 0; i < N; ++i)
			v.push_back(static_cast<int>(i));
		auto start = std::chrono::high_resolution_clock::now();
		
		// �ε��� ��ȸ(���� �޸�, ĳ�� ȿ����)
		for (size_t i = 0; i < v.size(); ++i)
			sum += v[i];

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;
		std::cout << "std:: vector<int> time: " << diff.count() << " s\n";
	}

	// 2) vector<int*> : �� ���Ҹ� ���� new (����� �޸�)
	{		
		sum = 0;
		std::vector<int*> vp;
		vp.reserve(N);
		for (size_t i = 0; i < N; ++i) {
			int* p = new int(static_cast<int>(i));
			vp.push_back(p);
		}
		auto start = std::chrono::high_resolution_clock::now();
		
		for (size_t i = 0; i < vp.size(); ++i)
			sum += *vp[i]; // ���� ���� + ĳ�� �̽� ����

		auto end = std::chrono::high_resolution_clock::now();

		for (auto p : vp) delete p; // ���� ����

		std::chrono::duration<double> diff = end - start;
		std::cout << "std:: vector<int*> time: " << diff.count() << " s\n";
	}

	// ===== std::list �׽�Ʈ =====
	{
		sum = 0;
		std::list<int> lst;

		for (int i = 0; i <N; ++i)
			lst.push_back(i);

		auto start = std::chrono::high_resolution_clock::now();

		for (auto it = lst.begin(); it != lst.end(); ++it) {
			sum += *it;
		}

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;
		std::cout << "std::list time: " << diff.count() << " s\n";
	}
}



void TestPushBack()
{

}
void TestEmplaceBack()
{

}


int main()
{
	//TestReserve();
	CompareVectorPointerList();
}
