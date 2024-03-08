#ifndef		_CHANNEL_AREA_UTIL_WINDOW_H_
#define	 _CHANNEL_AREA_UTIL_WINDOW_H_
 
#include <memory>
#include <QWidget>

#include <vector>
 
#include "../Public/selectmediasourcewindow.h"
class ChannelWindow;
class QGridLayout;

class ChannelAreaUtilWindow : public QWidget
{
	Q_OBJECT

public:
	ChannelAreaUtilWindow(QWidget *parent = nullptr);
	~ChannelAreaUtilWindow();
	

public:
	void InitUI();

	void SetChannelIndex(int iChannelIndex);

protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent *pEvent);

private:

protected:	
 	std::vector< ChannelWindow*>				m_vecChannelWindows;
	std::unique_ptr<QGridLayout>				m_ptGridLayout;


	std::unique_ptr<SelectMediaSourceWindow>				m_ptrSelectMediaSourceWindow;

	int			m_iChannelIndex;
	 
};


#endif//_CHANNEL_MANAGER_WINDOW_H_
