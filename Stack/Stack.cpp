// Stack.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stack>
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main() {
	// 기본: deque 사용
	std::stack<int> s1;

	// vector를 내부 컨테이너로 사용
	std::stack<int, std::vector<int>> s2;

	// list를 내부 컨테이너로 사용
	std::stack<int, std::list<int>> s3;

	// 사용 예시
	s2.push(10);
	s2.push(20);
	std::cout << s2.top() << std::endl; // 20

	s3.push(5);
	s3.push(15);
	std::cout << s3.top() << std::endl; // 15
}
