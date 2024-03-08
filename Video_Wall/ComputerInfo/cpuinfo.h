#ifndef			_CPU_INFO_H_
#define		_CPU_INFO_H_

#include <Windows.h>
#include <math.h>

#define SystemBasicInformation 0
#define SystemPerformanceInformation 2
#define SystemTimeInformation 3

typedef LONG(WINAPI *PROCNTQSI)(UINT, PVOID, ULONG, PULONG);

#define Li2Double(x) ((double)((x).HighPart) * 4.294967296E9 + (double)((x).LowPart))


typedef struct
{
	DWORD dwUnknown1;
	ULONG uKeMaximumIncrement;
	ULONG uPageSize;
	ULONG uMmNumberOfPhysicalPages;
	ULONG uMmLowestPhysicalPage;
	ULONG uMmHighestPhysicalPage;
	ULONG uAllocationGranularity;
	PVOID pLowestUserAddress;
	PVOID pMmHighestUserAddress;
	ULONG uKeActiveProcessors;
	BYTE bKeNumberProcessors;
	BYTE bUnknown2;
	WORD wUnknown3;
} SYSTEM_BASIC_INFORMATION;

typedef struct
{
	LARGE_INTEGER liIdleTime;
	DWORD dwSpare[76];
} SYSTEM_PERFORMANCE_INFORMATION;

typedef struct
{
	LARGE_INTEGER liKeBootTime;
	LARGE_INTEGER liKeSystemTime;
	LARGE_INTEGER liExpTimeZoneBias;
	ULONG uCurrentTimeZoneId;
	DWORD dwReserved;
} SYSTEM_TIME_INFORMATION;

class CPUInfo
{

public:
	CPUInfo();
	~CPUInfo();


public:
	bool UpDateCPUInfo(void);
	const int GetCPUInfo() const;

	void SetCpuInfo();

private:
	int																m_iCPUInfo;

	SYSTEM_PERFORMANCE_INFORMATION		m_iSysPerfInfo;
	SYSTEM_TIME_INFORMATION						m_iSysTimeInfo;
	SYSTEM_BASIC_INFORMATION						m_iSysBaseInfo;
	double															m_dbIdleTime;
	double															m_dbSystemTime;
	long																m_lStatus;

	LARGE_INTEGER											m_liOldIdleTime;
	LARGE_INTEGER											m_liOldSystemTime;

	PROCNTQSI													m_NtQuerySystemInformation;
};



#endif//_CPU_INFO_H_


