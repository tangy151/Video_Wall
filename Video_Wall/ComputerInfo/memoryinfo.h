#ifndef			_MEMORY_INFO_H_
#define		_MEMORY_INFO_H_
 
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

#endif//_MEMORY_INFO_H_
