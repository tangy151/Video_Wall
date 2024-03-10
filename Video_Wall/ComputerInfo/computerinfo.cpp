#include "computerinfo.h"


#if  WIN32

ComputerInfo::ComputerInfo( )
 {
}

ComputerInfo::~ComputerInfo()
{
}
const int ComputerInfo::GetCPUInfo() const
{
	return m_iCurCPU.GetCPUInfo();

}

const int ComputerInfo::GetMemoryInfo() const
{
	return m_iCurMemory.GetUsage();

}

void ComputerInfo::GetComputerInfo()
{
// 	m_iCurCPU.UpDateCPUInfo();
// 	m_iCurMemory.UpDateUsage();
	m_iCurSystemTime.UpDateSystemTime();
}

#endif


