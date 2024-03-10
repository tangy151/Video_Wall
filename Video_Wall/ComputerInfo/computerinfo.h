#ifndef	    _COMPUTER_INFO_H_
#define		_COMPUTER_INFO_H_


#if  WIN32

#include <string>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>

#include "cpuinfo.h"
#include "memoryinfo.h"
#include "systemtimeinfo.h"
 
class ComputerInfo 
{
 
public:
	ComputerInfo( );
	~ComputerInfo();

public:
	const int GetCPUInfo() const;
	const int GetMemoryInfo() const;
	void GetComputerInfo();



private:
	CPUInfo						m_iCurCPU;
	MemoryInfo				m_iCurMemory;

public:
	SystemTimeInfo	m_iCurSystemTime;
 
};
#endif

#endif//_COMPUTER_INFO_H_