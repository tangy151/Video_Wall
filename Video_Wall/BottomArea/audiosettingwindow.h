#ifndef			_AUDIO_SETTING_WINDOW_H_
#define		_AUDIO_SETTING_WINDOW_H_
 
#include <memory>
#include <QWidget>
#include <vector>
using namespace std;

class ButtonEx;
class TabWidgetEx;
class QButtonGroup;
class  VolumeControlWindow;
 

class AudioSettingWindow 
	: public QWidget
{
	Q_OBJECT

public:
	AudioSettingWindow(QWidget *parent = nullptr);
	~AudioSettingWindow();

public:
	void InitUI();
	void InitConnects();
	void InitVolumeControlWindow();

	void SetVolumeControlWindowState(bool bShow);

public slots:
	void  OnButton1();
	void  OnButton3();
	  
protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent* pEvent);

 

protected:
	std::unique_ptr<ButtonEx>			m_ptrButton1;
	std::unique_ptr<ButtonEx>			m_ptrButton2;
	std::unique_ptr<ButtonEx>			m_ptrButton3;

	QList<ButtonEx*>		m_listButtons;

	std::vector<VolumeControlWindow*>				m_vecVolumeControlWindow;

	std::unique_ptr<VolumeControlWindow>			m_ptrVolumeControlWindow;

	// 设备操作模式组
 
	std::unique_ptr<QButtonGroup>	m_ptrSwitchGroup;
	 
	std::unique_ptr<TabWidgetEx>		m_ptrTabWidget;
};

#endif//_AUDIO_SETTING_WINDOW_H_
