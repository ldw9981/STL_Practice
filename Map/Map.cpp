// Map.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <string>
#include <map>
#include <unordered_map>

void TestMap()
{
	std::cout << __FUNCDNAME__ << std::endl;
    std::map<int,int>  Container;
    
    for (size_t i = 0; i < 100; i++)
    {
        int key = rand();
		int value = rand();
        Container.insert(std::make_pair(key,value));
    }

	// 
	for (auto it = Container.begin(); it != Container.end(); it++)
	{
		std::cout << "Key: " << (*it).first << " Value: " << (*it).second << std::endl;
	}

}

void TestUnorderedMap()
{
	std::cout << __FUNCDNAME__ << std::endl;
	std::unordered_map<int, int>  Container;

	// Load Factor(적재율) = 추가된 요소의 개수 / 전체 버킷 수
	// Max Load Factor(최대적재율) = 전체 버킷수를 늘리는 임계값. 
	// 현재 적재율(load_factor)이 max_load_factor보다 낮으면 문제없이 요소를 추가. 
	// 현재 적재율이 max_load_factor보다 높으면 버킷수를 늘리고 rehashing하여 재배치 한다.

	std::cout << "bucket_count: " << Container.bucket_count() << " max_size: " << Container.max_size() << " max load factor " << Container.max_load_factor() << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		int key = rand();
		int value = rand();
		
		// load factor 가 1보다 크면 rehashing 이 발생한다. 방지하려면 reserve 함수를 사용한다.
		Container.insert(std::make_pair(key, value));
		
		std::cout << "bucket_count: " << Container.bucket_count() << " size: " << Container.size() << " load factor " << Container.load_factor() << std::endl; 
		
	}

	for (auto it = Container.begin(); it != Container.end(); it++)
	{
		std::cout << "Key: " << (*it).first << " Value: " << (*it).second << std::endl;
	}
	
}

int main()
{
	//TestMap();
	TestUnorderedMap();

}
