//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
//----------------------------------------------------------------------------
// Timer 
//    v.2.1.0
//    v.2.5
//    v.2.6   - Baseline
//    v.2.6.1 - fixed warning TestRegistry
//    v.2.7   - Baseline
//    v.2.8   - warning 5039 windows.h
//    v.2.9   - fence
//    v.2.10  - msc_ver 1914, win 10.0.17
//    v.2.11  - warning fixes 
//    v.2.12  - mutex on all trace::out
//    v.2.13  - fixed warnings on mutex and default copy const / assignment
//    v.2.14  - FileIO remove new... so you can overload new/delete
//    v.2.15  - number tests pass reformat
//    v.2.16  - fixing static analysis issues
//    v.2.17  - missing deleted copy constructor and assignment operator in macro
//    v.2.18  - teardown issue
//    v.2.19  - WinSDK, Compiler, Framework version reporting
//    v.2.20  - WinSDK, Compiler, Framework version reporting in Release mode
//    v.2.21  - x64 info header
//    v.2.22  - Timer renamed to PerformanceTimer 
//    v.2.23  - Mem Tracking now works with placement and alignment new
//    v.2.24  - new tracking with file names and line numbers
//    v.2.25  - fixing collision with unused_var() macros in align16
//    v.2.26  - any order for the link, removed FileIO.cpp and PerformanceTimer.cpp
//    v.2.27  - atomics in Timer 
//    v.2.28  - remove dynamic cast, warnings on atomic
//---------------------------------------------------------------------------- 

#ifndef PERFORMANCE_TIMER_H
#define PERFORMANCE_TIMER_H

#pragma warning( push )
	#pragma warning( disable : 4365 )
	#include <atomic>
#pragma warning( pop ) 

// --------------------------------------------------
// Windows.h include
// many warnings - need to wrap for Wall warnings
// --------------------------------------------------

#pragma warning( push )
	#pragma warning( disable : 4820 )
	#pragma warning( disable : 4668 )
	#pragma warning( disable : 5039 )
	#include <Windows.h>
#pragma warning( pop ) 

class PerformanceTimer
{
public:

	// ------------------------------------------
	// big four
	// ------------------------------------------

	PerformanceTimer(const PerformanceTimer &) = delete;
	PerformanceTimer & operator= (const PerformanceTimer &) = delete;
	~PerformanceTimer() = default;

	PerformanceTimer() noexcept
		:
		ticTime(),
		tocTime(),
		deltaTime(),
		SecondsPerCycle(0.0f),
		timeSeconds(0.0f)
	{
		this->privInitTimer();
		this->Reset();
	}

	void Tic() noexcept
	{
		// Forces a Fence... 
		atomic_thread_fence(std::memory_order_acq_rel);

		this->ticTime = this->privGetTimer();

		// Forces a Fence...
		atomic_thread_fence(std::memory_order_acq_rel);
	}

	void Toc() noexcept
	{
		// Forces a Fence... 
		atomic_thread_fence(std::memory_order_acq_rel);

		this->tocTime = this->privGetTimer();
		assert(this->tocTime.QuadPart >= this->ticTime.QuadPart);
		this->deltaTime.QuadPart = this->tocTime.QuadPart - this->ticTime.QuadPart;

		// Forces a Fence... 
		atomic_thread_fence(std::memory_order_acq_rel);
	}

	void Reset() noexcept
	{
		this->ticTime.QuadPart = 0;
		this->tocTime.QuadPart = 0;
		this->deltaTime.QuadPart = 0;
	}

	float TimeInSeconds() noexcept
	{
		float floatTime;
		floatTime = static_cast<float>(this->deltaTime.QuadPart);
		floatTime *= this->SecondsPerCycle;
		return floatTime;
	}

private:

	void privInitTimer() noexcept
	{
		LARGE_INTEGER Frequency;
		QueryPerformanceFrequency(&Frequency);
		this->SecondsPerCycle = 1.0f / Frequency.QuadPart;
	}

	LARGE_INTEGER privGetTimer() noexcept
	{
		LARGE_INTEGER time;
		QueryPerformanceCounter(&time);
		return time;
	}

	// ------------------------------------------
	// data
	// ------------------------------------------

	LARGE_INTEGER	ticTime;
	LARGE_INTEGER	tocTime;
	LARGE_INTEGER	deltaTime;
	float			SecondsPerCycle;
	float			timeSeconds;

};


#endif TIMER_H

// ---  End of File ---------------