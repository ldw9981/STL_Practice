#pragma once
#include <windows.h>
#include <iostream>

class Timer {
public:
	Timer()
	{
		QueryPerformanceFrequency(&frequency);
	}

	// 시작 시간을 기록하는 메서드
	void Start() {
		QueryPerformanceCounter(&startTime);
	}

	// 종료 시간을 기록하는 메서드
	void Stop() {
		QueryPerformanceCounter(&endTime);
	}

	// 경과 시간을 밀리초 단위로 반환하는 메서드
	double GetElapsedTime() const {
		return static_cast<double>(endTime.QuadPart - startTime.QuadPart) * 1000.0 / frequency.QuadPart;
	}

private:
	LARGE_INTEGER frequency;  // 주파수
	LARGE_INTEGER startTime;  // 시작 시간
	LARGE_INTEGER endTime;    // 종료 시간
};

