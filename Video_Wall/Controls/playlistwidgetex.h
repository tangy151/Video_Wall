#ifndef		_PLAY_LIST_WIDGET_EX_H_
#define _PLAY_LIST_WIDGET_EX_H_

#include <QTabWidget>
#include <vector>

#include <memory>
 
class TabBarEx;
class  PlayListPageEx;
 
using namespace std;


class PlayListWidgetEx
	: public QTabWidget
{
	Q_OBJECT

public:
	PlayListWidgetEx(QWidget *parent = nullptr);
	~PlayListWidgetEx();

public:
	void InitUI();
	void InitConnects();
 
protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent* pEvent);

public:
	void AddPage(QString strPageName);
	 

	PlayListPageEx* GetCurrentPage()
	{
		return (PlayListPageEx*)currentWidget();
	}

	PlayListPageEx* GetPage(unsigned index);


	bool IsAutoHide();

	void SetAutoHide(bool state);

	void RemovePage(QString strPageName);

	int GetPageCount();


private:
	void RemovePage(PlayListPageEx* pPage);


signals:
	void PageAdded(PlayListPageEx* pPage);
	void PageRemoved(PlayListPageEx* pPage);
	void ApplicationButtonClicked();


private slots:
	void PageActivityChanged(PlayListPageEx* pPage);
	void TabClicked(int index);
	void HandleApplicationButton(bool);
	 

private:
	std::vector<PlayListPageEx*>			m_vecAllPages;
 	std::unique_ptr<TabBarEx>				m_ptrTabBarEx;
	 
	/// Whether to automatically collapse the ribbon.
	bool				m_bAutoHide		= false;
	int				m_bOldHeight		= 0;
	QString			m_strExePath		= "";
 };
#endif//_PLAY_LIST_WIDGET_EX_H_
