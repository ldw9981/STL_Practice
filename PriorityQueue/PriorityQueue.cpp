#include <functional>
#include <iostream>
#include <queue>
#include <string_view>	// C++17 읽기 전용	문자열 뷰. 상수 메모리 사용. 문자열의 복사본을 메모리에 올리지 않기
#include <vector>

template<typename T>
void pop_println(std::string_view rem, T& pq)
{
	std::cout << rem << ": ";
	for (; !pq.empty(); pq.pop())
		std::cout << pq.top() << ' ';
	std::cout << '\n';
}

template<typename T>
void println(std::string_view rem, const T& v)
{
	std::cout << rem << ": ";
	for (const auto& e : v)
		std::cout << e << ' ';
	std::cout << '\n';
}

int main()
{
	const auto data = { 1, 8, 5, 6, 3, 4, 0, 9, 7, 2 };
	println("data", data);

	std::priority_queue<int> max_priority_queue;

	//  직접 요소를 넣어 우선순위 큐를 구성하는 방법
	for (int n : data)
		max_priority_queue.push(n);

	pop_println("max_priority_queue", max_priority_queue);

	// 템플릿 타입정보 타입, 컨테이너, 비교자를 명시적으로 지정하여 우선순위 큐를 정의하는 방법
	std::priority_queue<int, std::vector<int>, std::greater<int>>
		min_priority_queue1(data.begin(), data.end());

	pop_println("min_priority_queue1", min_priority_queue1);

	//생성자에 비교자 객체를 전달하는 방법
	std::priority_queue min_priority_queue2(data.begin(), data.end(), std::greater<int>());

	pop_println("min_priority_queue2", min_priority_queue2);

	// 사용자 비교함수 사용하기
	struct
	{
		bool operator()(const int l, const int r) const 
		{ 
			return l > r; 
		}
	} customLess;

	std::priority_queue custom_priority_queue(data.begin(), data.end(), customLess);

	pop_println("custom_priority_queue", custom_priority_queue);

	// 원소비교에 함다 함수 사용하기
	auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
	std::priority_queue<int, std::vector<int>, decltype(cmp)> lambda_priority_queue(cmp);

	for (int n : data)
		lambda_priority_queue.push(n);

	pop_println("lambda_priority_queue", lambda_priority_queue);
}