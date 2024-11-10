// Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "../StaticLib/ClassA.h"

using namespace std;

int main()
{
    std::vector<ClassA> container;
    //container.reserve(10);

    
    container.emplace_back();   
    container.emplace_back();
    container.emplace_back();
    container.emplace_back();

    std::cout << "Hello World!\n";
}
