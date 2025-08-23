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
	// 300~3000 ������ Ű�� �������� ����Ϸ��� lower_bound �� upper_bound �� ����Ѵ�.	

	// lower_bound(x) : x �̻� �������� ù ���� ã��
	auto it_lower = Container.lower_bound(300); 
	if (it_lower != Container.end())
		std::cout << "lower_bound(300): " << it_lower->first << " => " << it_lower->second << "\n";
	else
		std::cout << "not found\n";

	// upper_bound(x) : x �ʰ�(upper)�� �������� ù ���� ã��
	auto it_upper = Container.upper_bound(3000);
	if (it_upper != Container.end())
		std::cout << "upper_bound(3000): " << it_upper->first << " => " << it_upper->second << "\n";
	else
		std::cout << "not found\n";

	// equal_range(x) �� lower_bound(x) �� upper_bound(x) �� pair �� �����Ѵ�.

	// ������ �� ��� �ݺ��ڷ� ���� ����ϱ� 
	for (auto it = it_lower; it != it_upper; it++)
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

	// bucket_count : �غ�� ��Ŷ�� , max_size : �����̳ʰ� ���� �� �ִ� �ִ� ��Ҽ�( ������ ���ܹ߻�) ,  max_load_factor : �ִ�������
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
	TestMap();
	TestUnorderedMap();

}
