#include "memoryinfo.h"
#include <Windows.h>

MemoryInfo::MemoryInfo( )
	: m_iUsage(-1)
{
}

MemoryInfo::~MemoryInfo()
{
}
bool MemoryInfo::UpDateUsage()
{
	MEMORYSTATUS MemStat;
	MemStat.dwLength = sizeof(MEMORYSTATUS);
	GlobalMemoryStatus(&MemStat);
	DWORD dwUsage = MemStat.dwMemoryLoad;

	m_iUsage = (int)dwUsage;

	return true;
}

const int MemoryInfo::GetUsage(void) const
{
	return m_iUsage;
}

void MemoryInfo::SetMemory()
{
	m_iUsage = 0;
}
