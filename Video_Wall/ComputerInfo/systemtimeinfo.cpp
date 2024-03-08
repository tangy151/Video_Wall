#include "systemtimeinfo.h"


SystemTimeInfo::SystemTimeInfo()
	: m_ulStartTime(0)
	, m_iYear(-1)
	, m_iMonth(-1)
	, m_iDay(-1)
	, m_iHour(-1)
	, m_iMinute(-1)
	, m_iSecond(-1)
	, m_iDayOfWeek(-1)
	, m_iRunTimeDay(-1)
	, m_iRunTimeHour(-1)
	, m_iRunTimeMinute(-1)
	, m_iRunTimeSecond(-1)
{
	m_ulStartTime = GetTickCount();
}

SystemTimeInfo::~SystemTimeInfo()
{
}

const int SystemTimeInfo::GetYear(void) const
{
	return m_iYear;
}

const int SystemTimeInfo::GetMonth(void) const
{
	return m_iMonth;
}

const int SystemTimeInfo::GetDay(void) const
{
	return m_iDay;
}

const int SystemTimeInfo::GetHour(void) const
{
	return m_iHour;
}

const int SystemTimeInfo::GetMinute(void) const
{
	return m_iMinute;
}

const int SystemTimeInfo::GetSecond(void) const
{
	return m_iSecond;
}

const int SystemTimeInfo::GetDayOfWeek(void) const
{
	return m_iDayOfWeek;
}

const int SystemTimeInfo::GetDayOfRunTime(void) const
{
	return m_iRunTimeDay;
}

const int SystemTimeInfo::GetHourOfRunTime(void) const
{
	return m_iRunTimeHour;
}

const int SystemTimeInfo::GetMinuteOfRunTime(void) const
{
	return m_iRunTimeMinute;
}

const int SystemTimeInfo::GetSecondOfRuntTime(void) const
{
	return m_iRunTimeSecond;
}

void SystemTimeInfo::CalculateRunTime(void)
{
	m_iYear = m_iTime.GetYear();
	m_iMonth = m_iTime.GetMonth();
	m_iDay = m_iTime.GetDay();

	m_iHour = m_iTime.GetHour();
	m_iMinute = m_iTime.GetMinute();
	m_iSecond = m_iTime.GetSecond();

	m_iDayOfWeek = m_iTime.GetDayOfWeek() - 1;

	unsigned long ulDuring = GetTickCount() - m_ulStartTime;
	unsigned long ulSecond = ulDuring / 1000;
	unsigned long ulMinute = ulSecond / 60;

	m_iRunTimeSecond = static_cast<int>(ulSecond % 60);
	m_iRunTimeMinute = static_cast<int>(ulMinute % 60);

	unsigned long ulHour = ulMinute / 60;

	m_iRunTimeHour = static_cast<int>(ulHour % 24);
	m_iRunTimeDay = static_cast<int>(ulHour / 24);

}

void SystemTimeInfo::UpDateSystemTime()
{
	unsigned long ulCurrentTime = GetTickCount();
	m_iTime = CTime::GetTickCount();
	CalculateRunTime();
}

void SystemTimeInfo::SetDateSytemTime()
{
	m_ulStartTime = 0;//系统开始运行时间

	m_iYear = 0;
	m_iMonth = 0;
	m_iDay = 0;

	m_iHour = 0;
	m_iMinute = 0;
	m_iSecond = 0;

	m_iDayOfWeek = 0;

	m_iRunTimeDay = 0;
	m_iRunTimeHour = 0;
	m_iRunTimeMinute = 0;
	m_iRunTimeSecond = 0;
}

