// Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "../StaticLib/ClassA.h"
#include "../StaticLib/Timer.h"
#include <iostream>

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
