#ifndef			_SYSTEM_TIME_INFO_H_
#define		_SYSTEM_TIME_INFO_H_

#include <atltime.h>

class SystemTimeInfo 
{
 
public:
	SystemTimeInfo();
	~SystemTimeInfo();


public:
	const int GetYear(void) const;
	const int GetMonth(void) const;
	const int GetDay(void) const;

	const int GetHour(void) const;
	const int GetMinute(void) const;
	const int GetSecond(void) const;

	const int GetDayOfWeek(void) const;
	const int GetDayOfRunTime(void) const;
	const int GetHourOfRunTime(void) const;
	const int GetMinuteOfRunTime(void) const;
	const int GetSecondOfRuntTime(void) const;


public:
	void UpDateSystemTime();
	void SetDateSytemTime();

private:
	//计算运行时间
	void CalculateRunTime(void);



private:
	unsigned long	m_ulStartTime;//系统开始运行时间
	CTime	m_iTime;

	int	m_iYear;
	int	m_iMonth;
	int	m_iDay;

	int	m_iHour;
	int	m_iMinute;
	int	m_iSecond;

	int	m_iDayOfWeek;

	int	m_iRunTimeDay;
	int	m_iRunTimeHour;
	int	m_iRunTimeMinute;
	int	m_iRunTimeSecond;

};


#endif//_SYSTEM_TIME_INFO_H_
