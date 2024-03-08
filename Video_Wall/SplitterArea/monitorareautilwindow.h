#ifndef			_MONITOR_MANAGER_WINDOW_H_
#define		_MONITOR_MANAGER_WINDOW_H_


#include <QWidget>
#include <memory>

#include "../ComputerInfo/computerinfo.h"

class PreviewMonitorWindow;
class MainMonitorWindow;
 
class QPushButton;
class LabelEx;
class ButtonEx;
class NavLabelEx;
class SliderEx;
  
class MonitorAreaUtilWindow 
	: public QWidget
{
	Q_OBJECT

public:
	MonitorAreaUtilWindow(QWidget *parent);
	~MonitorAreaUtilWindow();
	 
protected:
	void InitUI();
	void InitButtons();
	void InitButtons2();

	void InitLabels();
	void InitConnect();
	void InitSliders();
	void InitSystemInfo();

public Q_SLOTS:
	void OnStart(int interval);
	void OnStop();

private slots:
	void OnGetServerRunState();

public slots:
	void OnButtonLOGO1();
	void OnButtonLOGO2();
	void OnButtonClock();
	void OnButtonStreamMedia();
	void OnButtonRecord();
	void OnButtonStartNDI();
	 

	void OnBtnToTheLeft();			 
	void OnBtnToTheRight();
	void OnBtnCirrusLeaf();
	void OnBtnDrawRight();
	void OnBtnFadeInFadeOut();

	void OnBtnPushLeft();
	void OnBtnRightRub();
	void OnBtnCircularRubIn();
	void OnBtnBurn();
	void OnBtnDipToBlack();


public:
	QString GetRunTimeString();



protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent* pEvent);

 	void  LayOut720p();


private:
	std::unique_ptr<PreviewMonitorWindow>	m_ptrPreviewMonitorWindow;
	std::unique_ptr<MainMonitorWindow>			m_ptrMainMonitorWindow;

	std::unique_ptr<ButtonEx>			m_ptrButtonLOGO1;
	std::unique_ptr<ButtonEx>			m_ptrButtonLOGO2;
	std::unique_ptr<ButtonEx>			m_ptrButtonClock;
	 
	std::unique_ptr<ButtonEx>			m_ptrButtonRecord;
	std::unique_ptr<ButtonEx>			m_ptrButtonStreamMedia;
	std::unique_ptr<ButtonEx>			m_ptrButtonStartNDI;

	std::unique_ptr<ButtonEx>			m_ptrButtonScreen;

	std::unique_ptr<NavLabelEx>			m_ptrLabelOutPut;
	std::unique_ptr<NavLabelEx>			m_ptrLabelLogo;

	 
	QList<ButtonEx*>		m_listButtons;
	QList<ButtonEx*>		m_listButtons2;


	std::unique_ptr<ButtonEx>			m_ptrBtnToTheLeft;				//划向左边
	std::unique_ptr<ButtonEx>			m_ptrBtnToTheRight;			//划向右边
	std::unique_ptr<ButtonEx>			m_ptrBtnCirrusLeaf;				//卷叶
	std::unique_ptr<ButtonEx>			m_ptrBtnDrawRight;			//右边划出
	std::unique_ptr<ButtonEx>			m_ptrBtnFadeInFadeOut;	//淡入淡出

	std::unique_ptr<ButtonEx>			m_ptrBtnPushLeft;			//左推
	std::unique_ptr<ButtonEx>			m_ptrBtnRightRub;			//右擦
	std::unique_ptr<ButtonEx>			m_ptrBtnCircularRubIn;	//圆形擦入
	std::unique_ptr<ButtonEx>			m_ptrBtnBurn;					//燃烧
	std::unique_ptr<ButtonEx>			m_ptrBtnDipToBlack;		//黑色过度

	std::unique_ptr<SliderEx>			m_ptrHSliderEx;		//水平
	std::unique_ptr<SliderEx>			m_ptrVSliderEx;		//垂直
	
	std::unique_ptr<ButtonEx>			m_ptrBtnHardSwitch;		//硬切
	std::unique_ptr<ButtonEx>			m_ptrBtnAutoSwitch;		//自动

  
	QColor				m_iNormalFrameColor;
	QColor				m_iNormalBgColor;

	QColor				m_iHoverBgColor;
	QColor				m_iCheckBgColor;

	QColor				m_iNormalTextColor;
	QColor				m_iHoverTextColor;
	QColor				m_iCheckTextColor;
	 
	QString					m_strExePath;
	ComputerInfo		m_iComputerInfo;
	QTimer*				m_pServerRunState;	//定时器获取内存信息
 };



#endif//_MONITOR_MANAGER_WINDOW_H_
