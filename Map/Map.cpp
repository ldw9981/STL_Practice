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

	// Load Factor(������) = �߰��� ����� ���� / ��ü ��Ŷ ��
	// Max Load Factor(�ִ�������) = ��ü ��Ŷ���� �ø��� �Ӱ谪. 
	// ���� ������(load_factor)�� max_load_factor���� ������ �������� ��Ҹ� �߰�. 
	// ���� �������� max_load_factor���� ������ ��Ŷ���� �ø��� rehashing�Ͽ� ���ġ �Ѵ�.

	std::cout << "bucket_count: " << Container.bucket_count() << " max_size: " << Container.max_size() << " max load factor " << Container.max_load_factor() << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		int key = rand();
		int value = rand();
		
		// load factor �� 1���� ũ�� rehashing �� �߻��Ѵ�. �����Ϸ��� reserve �Լ��� ����Ѵ�.
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