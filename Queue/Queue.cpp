#include <cassert>
#include <iostream>
#include <queue>

int main()
{
	std::queue<int> q;

	for (int i = 0; i < 5; ++i)
	{
		q.push(i); // back pushes 0
		std::cout << "push " << i << "\n";
		std::cout << "front()=" << q.front() << " " << "back()=" << q.back() << '\n';
	}
	

	std::cout << "큐는 front와 back 접근만 가능하므로 front부터 출력하고 pop으로 front에서 지우며 반복출력\n";
	for (; !q.empty(); q.pop())
		std::cout << q.front() << ' ';

	std::cout << '\n';
	assert(q.size() == 0);
}