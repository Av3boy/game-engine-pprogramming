#pragma once

#include <cstdint>

class Timer
{
public:
	Timer();
	~Timer();

	void BeginTimer();
	void EndTimer();

	inline float GetElapsedSeconds() const { return m_fElapsedSeconds; }

	static uint64_t GetTicks();

private:
	double m_dRateToSeconds;
	uint64_t m_uTickFrequency;
	uint64_t m_uStartClock;

	float m_fElapsedSeconds;
};