#ifndef			_TAB_PAGE_EX_H_
#define		_TAB_PAGE_EX_H_


#include <QAbstractButton>
#include <QBoxLayout>
#include <QIcon>
#include <QWidget>

#include <memory>
#include <vector>

#include "../globaldefine.h"

class TabSectionEx;
class QListWidget;
class MediaSelectListEx;
class MediaSelectListItemEx;
 
class TabPageEx : public QWidget
{
	Q_OBJECT

		friend class TabWidgetEx;
public:
	TabPageEx(QWidget *parent,const QString& pageTitle, MEDIA_SELECT_TYPE iMediaType);
	~TabPageEx();

public:
	void InitUI();
	void InitConnects();
 	void InsertData(QString strTitle,QString strPath);
	void DeleteData(MediaSelectListItemEx* pSelectListItem);
	void DeleteData(QString strTitle, QString strPath);


protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent* pEvent);
	 
public:
	QString GetPageLabel()
	{
		return m_strPageLabel;
	}

	void SetPageTitle(const QString& title);
	QString GetPageTitle() const
	{
		return m_strPageTitle;
	}

	bool IsActive()
	{
		return m_bActive;
	}
	void SetActive(bool state);

	MEDIA_SELECT_TYPE GetMediaType()
	{
		return m_iMediaType;
	}

signals:
	void ActiveChanged(TabPageEx* self);

public slots:

	void OnSessionListNotify(MediaSelectListItemEx* pListItem);
	void OnListSizeNotify(int iSize);

private:

	bool						m_bActive = true;
	QString				m_strPageTitle;
	TabWidgetEx*		m_pRibbon = 0x0;

	MEDIA_SELECT_TYPE		m_iMediaType;

 

protected:

	std::unique_ptr<MediaSelectListEx>			m_ptrMediaSelectListEx;
	 
	QString  m_strTitleName;

	QColor			m_iPageTabColor;

	QIcon			m_iPageIcon;
	QString		m_strPageLabel;

};


#endif//_TAB_PAGE_EX_H_
