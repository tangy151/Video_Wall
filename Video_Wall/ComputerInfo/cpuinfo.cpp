#include "cpuinfo.h"


#if  WIN32
CPUInfo::CPUInfo()
	: m_iCPUInfo(-1)
	, m_dbIdleTime(0.0)
	, m_dbSystemTime(0.0)
	, m_lStatus(0)
	, m_NtQuerySystemInformation(NULL)
{
	memset(&m_iSysPerfInfo, 0, sizeof(SYSTEM_PERFORMANCE_INFORMATION));
	memset(&m_iSysTimeInfo, 0, sizeof(SYSTEM_TIME_INFORMATION));
	memset(&m_iSysBaseInfo, 0, sizeof(SYSTEM_BASIC_INFORMATION));
	memset(&m_liOldIdleTime, 0, sizeof(LARGE_INTEGER));
	memset(&m_liOldSystemTime, 0, sizeof(LARGE_INTEGER));
}

CPUInfo::~CPUInfo()
{
}


bool CPUInfo::UpDateCPUInfo(void)
{
	m_NtQuerySystemInformation = (PROCNTQSI)GetProcAddress(
		GetModuleHandle("ntdll.dll"),
		"NtQuerySystemInformation"
	);

	if (!m_NtQuerySystemInformation)
	{
		return false;
	}


	// get number of processors in the system
	m_lStatus = m_NtQuerySystemInformation(SystemBasicInformation,
		&m_iSysBaseInfo, sizeof(m_iSysBaseInfo), NULL);
	if (m_lStatus != NO_ERROR)
	{
		return false;
	}
	m_lStatus = m_NtQuerySystemInformation(SystemTimeInformation,
		&m_iSysTimeInfo, sizeof(m_iSysTimeInfo), 0);
	if (m_lStatus != NO_ERROR)
	{
		return false;
	}

	// get new CPUInfo''s idle time
	m_lStatus = m_NtQuerySystemInformation(SystemPerformanceInformation,
		&m_iSysPerfInfo, sizeof(m_iSysPerfInfo), NULL);
	if (m_lStatus != NO_ERROR)
	{
		return false;
	}
	// if it''s a first call - skip it
	if (m_liOldIdleTime.QuadPart/* != 0*/)
	{

		// CurrentValue = NewValue - OldValue
		m_dbIdleTime = Li2Double(m_iSysPerfInfo.liIdleTime) - Li2Double(m_liOldIdleTime);
		m_dbSystemTime = Li2Double(m_iSysTimeInfo.liKeSystemTime) - Li2Double(m_liOldSystemTime);


		// CurrentCpuIdle = IdleTime / SystemTime
		m_dbIdleTime = m_dbIdleTime / m_dbSystemTime;

		// CurrentCpuUsage% = 100 - (CurrentCpuIdle * 100) / NumberOfProcessors
		m_dbIdleTime = 100.0 - m_dbIdleTime * 100.0 / (double)m_iSysBaseInfo.bKeNumberProcessors + 0.5;
	}

	m_liOldIdleTime = m_iSysPerfInfo.liIdleTime;
	m_liOldSystemTime = m_iSysTimeInfo.liKeSystemTime;

	m_iCPUInfo = (int)m_dbIdleTime;

	return true;
}

const int CPUInfo::GetCPUInfo() const
{
	return -1 < m_iCPUInfo ? m_iCPUInfo : 0;
}

void CPUInfo::SetCpuInfo()
{
	m_iCPUInfo = 0;
}

#endif