// Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "../StaticLib/ClassA.h"

using namespace std;

int main()
{
    std::vector<ClassA> container;
	container.reserve(10);        // 미리 공간을 확보하지 않으면 확보된 크기보다 더 큰 크기로 확장할 때마다 재할당이 발생하여 성능 저하가 발생함
   
    ClassB b;

    container.push_back(b);       // 컨테이너와 다른 클래스면 매개 변수 생성자를 이용하여 임시 객체를 생성 후 내부 객체를 생성  	
    container.emplace_back(b);    // 매개 변수 생성자를 이용하여 내부 객체를 생성 (임시 객체 생성 없음)
	
    std::cout << "Hello World!\n";
}
