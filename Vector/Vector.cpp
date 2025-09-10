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

/* reserve 함수는 vector, map, unordered_map 에만 있다. 할당된 공간의수 (Capacity)와 원소의 개수(Size)는 다른 개념이다.
   컨테이너에 할당된 크기를 넘어서 원소를 추가할때 어떤일이 발생하는지 찾아본다.
*/
void TestReserve()
{
	std::vector<ClassA> container;
	// 미리 공간을 확보하지 않으면 확보된 크기보다 더 큰 크기로 확장할 때마다 재할당이 발생하여 성능 저하가 발생함
	//container.reserve(10);      
	ClassA a;	

	// 할당된 공간과 실제 원소 개수
	std::cout << "Capacity" << container.capacity() << ", Size" << container.size() << "\n"; 

	//할당된 공간없다가 새로운 공간을 할당함.
	container.push_back(a);    // 할당된 노드 시작주소 예) 00000172F03E4780 [copy]

	std::cout << "Capacity" << container.capacity() << ", Size" << container.size() << "\n";


	//공간이 부족해지면 새로운 공간을 할당하고 기존 인스턴스를 복사함(복사생성자호출). 이전 공간은 삭제됨(파괴자호출).
	container.push_back(a);    // 할당된 노드 시작주소 예) 00000172F03E2A20 [copy] [copy] , delete 00000172F03E4780
	container.push_back(a);	   // 할당된 노드 시작주소 예) 00000172F03E2B40 [copy] [copy] [copy] , delete 00000172F03E2A20
	container.push_back(a);    // 할당된 노드 시작주소 예) 00000172F03EFA40 [copy] [copy] [copy] [copy] , delete 00000172F03E2B40
}

/*
	배열과 할당받은 메모리를 접근할때의 성능 차이. 
	캐쉬히트와 캐쉬미스에 대하여 알아본다.
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
		
		// 인덱스 순회(연속 메모리, 캐시 효율↑)
		for (size_t i = 0; i < v.size(); ++i)
			sum += v[i];

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;
		std::cout << "std:: vector<int> time: " << diff.count() << " s\n";
	}

	// 2) vector<int*> : 각 원소를 개별 new (흩어진 메모리)
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
			sum += *vp[i]; // 간접 참조 + 캐시 미스 가능

		auto end = std::chrono::high_resolution_clock::now();

		for (auto p : vp) delete p; // 누수 방지

		std::chrono::duration<double> diff = end - start;
		std::cout << "std:: vector<int*> time: " << diff.count() << " s\n";
	}

	// ===== std::list 테스트 =====
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
