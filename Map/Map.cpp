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

	for (auto it = Container.begin(); it != Container.end(); it++)
	{
		std::cout << "Key: " << (*it).first << " Value: " << (*it).second << std::endl;
	}
	
	// 85, 561, 600, 1247, 1354, 1408, 1456, 1673, 2795, 2799, 2811, 3467, 3594
	// 300~3000 사이의 키를 기준으로 출력하려면 lower_bound 와 upper_bound 를 사용한다.	

	// lower_bound(x) : x 이상 기준으로 첫 원소 찾기
	auto it_lower = Container.lower_bound(300); 
	if (it_lower != Container.end())
		std::cout << "lower_bound(300): " << it_lower->first << " => " << it_lower->second << "\n";
	else
		std::cout << "not found\n";

	// upper_bound(x) : x 초과(upper)의 기준으로 첫 원소 찾기
	auto it_upper = Container.upper_bound(3000);
	if (it_upper != Container.end())
		std::cout << "upper_bound(3000): " << it_upper->first << " => " << it_upper->second << "\n";
	else
		std::cout << "not found\n";

	// equal_range(x) 는 lower_bound(x) 와 upper_bound(x) 를 pair 로 리턴한다.

	// 구간의 각 경계 반복자로 구간 출력하기 
	for (auto it = it_lower; it != it_upper; it++)
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

	// bucket_count : 준비된 버킷수 , max_size : 컨테이너가 담을 수 있는 최대 요소수( 넘으면 예외발생) ,  max_load_factor : 최대적재율
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
	TestMap();
	TestUnorderedMap();

}
