#pragma once
#include <windows.h>
#include <iostream>

class Timer {
public:
	Timer()
	{
		QueryPerformanceFrequency(&frequency);
	}

	// ���� �ð��� ����ϴ� �޼���
	void Start() {
		QueryPerformanceCounter(&startTime);
	}

	// ���� �ð��� ����ϴ� �޼���
	void Stop() {
		QueryPerformanceCounter(&endTime);
	}

	// ��� �ð��� �и��� ������ ��ȯ�ϴ� �޼���
	double GetElapsedTime() const {
		return static_cast<double>(endTime.QuadPart - startTime.QuadPart) * 1000.0 / frequency.QuadPart;
	}

private:
	LARGE_INTEGER frequency;  // ���ļ�
	LARGE_INTEGER startTime;  // ���� �ð�
	LARGE_INTEGER endTime;    // ���� �ð�
};

