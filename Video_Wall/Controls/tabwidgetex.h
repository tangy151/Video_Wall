#ifndef			_TAB_WIDGET_EX_H_
#define		_TAB_WIDGET_EX_H_

#include <QTabWidget>
#include <vector>
#include <memory>
 
#include "../globaldefine.h"

class ButtonEx;
class TabBarEx;

class  MediaSelectListItemEx;

class AddIPStreamWindow;
class AddPlayListWindow;

class LocalMediaStreamWindow;


using namespace std;

class TabPageEx;

class TabWidgetEx
	: public QTabWidget
{
	Q_OBJECT

public:
	TabWidgetEx(QWidget *parent = nullptr);
	~TabWidgetEx();

public:
	void InitUI();
	void InitConnects();
 	void InitButtons();
	void InitWindow();
	 
	void ShowAudioEditor(bool bShow);
	void SetMediaButtonEnable(bool bEnable);

	void SetCurrentSelectItem(MediaSelectListItemEx*  pSelectListItem);

	void MediaListHasData(int iSize);


protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent* pEvent);

public:
 	void AddPage(QString strName, MEDIA_SELECT_TYPE iMediaType);
	 
	TabPageEx* GetCurrentPage()
	{
		return (TabPageEx*)currentWidget();
	}

	TabPageEx* GetPage(unsigned index);
	void RemovePage(TabPageEx* pPage);

	bool IsAutoHide();

	void SetAutoHide(bool state);

	MEDIA_SELECT_TYPE OnGetMediaSelectType()
	{
		return m_iMediaType;
	}

  signals:
	void PageAdded(TabPageEx* pPage);
	void PageRemoved(TabPageEx* pPage);
	void ApplicationButtonClicked();

signals:
	void AddPlayListPage(QString);
	void DeletePlayListPage(QString);
	 
signals: //回调到主窗口
	void AddPageDataNotify(QString strName, QString strPath);
	void DeletePageDataNotify(QString strName, QString strPath);
	 

public  slots:
 	void OnDeviceNameNotify(QString strDeviceName);
	void OnAddPlayListNotify(QString strListName);
	void OnAddIPStreamNotify(QString strName, QString strAddr);


private slots:
	void PageActivityChanged(TabPageEx* pPage);
	void TabClicked(int index);
	void HandleApplicationButton(bool);

public  slots :
	 
	void OnBtnAdd();
	void OnBtnEdit();
	void OnBtnReName();
	void OnBtnDelete();

public://外部添加删除数据
	void AddPageData(MEDIA_SELECT_TYPE iMediaType, QString strName, QString strPath);
	void DeletePageData(MEDIA_SELECT_TYPE iMediaType, QString strName, QString strPath);
	 
private:
	void ButtonAddEvent();
	void ButtonEditEvent();
	void ButtonDeleteEvent();
  
private:
	std::vector<TabPageEx*>			m_vecAllPages;
	 
 	std::unique_ptr<ButtonEx>			m_ptrBtnAdd;
	std::unique_ptr<ButtonEx>			m_ptrBtnEdit;
 	std::unique_ptr<ButtonEx>			m_ptrBtnReName;
	std::unique_ptr<ButtonEx>			m_ptrBtnDelete;

	std::unique_ptr<ButtonEx>			m_ptrBtnclone;
	std::unique_ptr<ButtonEx>			m_ptrBtnReName2;
	std::unique_ptr<ButtonEx>			m_ptrBtnDelete2;

	std::unique_ptr<TabBarEx>			m_ptrTabBarEx;
	   

	TabPageEx* 	m_ptrCurrentPageEx;

	QList<ButtonEx*>		m_listButtons;
	
	/// Whether to automatically collapse the ribbon.
	bool				m_bAutoHide		= false;
	int				m_bOldHeight		= 0;
	QString		m_strExePath		= "";

	QString		m_strCurPictureDir;
	QString		m_strCurVideoDir;

	MEDIA_SELECT_TYPE			m_iMediaType;
 
	MediaSelectListItemEx*		m_pSelectListItem;
};


#endif//_TAB_WIDGET_EX_H_
