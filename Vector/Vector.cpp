// Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "../StaticLib/ClassA.h"

using namespace std;

int main()
{
    std::vector<ClassA> container;
	container.reserve(10);        // �̸� ������ Ȯ������ ������ Ȯ���� ũ�⺸�� �� ū ũ��� Ȯ���� ������ ���Ҵ��� �߻��Ͽ� ���� ���ϰ� �߻���
   
    ClassB b;

    container.push_back(b);       // �����̳ʿ� �ٸ� Ŭ������ �Ű� ���� �����ڸ� �̿��Ͽ� �ӽ� ��ü�� ���� �� ���� ��ü�� ����  	
    container.emplace_back(b);    // �Ű� ���� �����ڸ� �̿��Ͽ� ���� ��ü�� ���� (�ӽ� ��ü ���� ����)
	
    std::cout << "Hello World!\n";
}
