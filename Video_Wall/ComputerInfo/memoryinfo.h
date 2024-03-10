#ifndef			_MEMORY_INFO_H_
#define		_MEMORY_INFO_H_

#if  WIN32
class MemoryInfo 
{
 public:
	MemoryInfo( );
	~MemoryInfo();


public:
	bool UpDateUsage();
	const int GetUsage(void) const;
	void SetMemory();

private:

	int	m_iUsage;


};

#endif

#endif//_MEMORY_INFO_H_
