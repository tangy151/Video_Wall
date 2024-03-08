#ifndef		_MEDIA_SETTING_WINDOW_H_
#define		_MEDIA_SETTING_WINDOW_H_

#include <memory>
#include <QWidget>
  
#include "../globaldefine.h"
 
class ButtonEx;
class TabWidgetEx;
class TabBarEx;
class QButtonGroup;

class MediaSettingWindow 
	: public QWidget
{
	Q_OBJECT

public:
	MediaSettingWindow(QWidget *parent = nullptr);
	~MediaSettingWindow();

public:
	void InitButtons();
	void InitTAB();
  	void InitConnects();

public://外部添加删除数据
	void AddPageData(MEDIA_SELECT_TYPE iMediaType, QString strName, QString strPath);
	void DeletePageData(MEDIA_SELECT_TYPE iMediaType,  QString strName, QString strPath);
	 
signals:
	void AddPlayListPageNotify(QString strPageName);
	void DeletePlayListPageNotify(QString strPageName);
	

public slots:
	void AddPlayListPage(QString strPageName);
	void DeletePlayListPage(QString strPageName);

public slots:
	void AddPageDataNotify(QString strName, QString strPath);
	void DeletePageDataNotify(QString strName, QString strPath);



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

 	std::unique_ptr<TabWidgetEx>			m_ptrTabWidget;
	std::unique_ptr<TabBarEx>					m_ptrTabBarEx;


	std::unique_ptr<QButtonGroup>	m_ptrSwitchGroup;


	MEDIA_SELECT_TYPE			m_iMediaType;
};

#endif//_MEDIA_SETTING_WINDOW_H_
