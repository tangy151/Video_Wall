#ifndef			_PLAY_LIST_PAGE_EX_H_
#define		_PLAY_LIST_PAGE_EX_H_

#include <QAbstractButton>
#include <QBoxLayout>
#include <QIcon>
#include <QWidget>

#include <memory>
#include <vector>

class PlayListEx;
class PlayListItemEx;
class PlayControlWindow;
 
class PlayListPageEx 
	: public QWidget
{
	Q_OBJECT

		friend class PlayListWidgetEx;

public:
	PlayListPageEx(QWidget *parent , const QString& pageTitle);
	~PlayListPageEx();


public:
	void InitUI();
	void InitConnects();

	void InsertData(QString strTitle, QString strPath,QString strTime);
	void DeleteData(PlayListItemEx* pSelectListItem);
	 

public slots:

	void OnPlayListNotify(PlayListItemEx* pListItem);

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

signals:
	void ActiveChanged(PlayListPageEx* self);

private:

	bool								m_bActive = true;
	QString						m_strPageTitle;
	PlayListWidgetEx*		m_pRibbon = 0x0;

	std::unique_ptr<PlayListEx>	m_ptrPlayListEx;

	std::unique_ptr<PlayControlWindow>			m_ptrPlayControlWindow;

	QColor			m_iPageTabColor;

	QIcon			m_iPageIcon;
	QString		m_strPageLabel;



};


#endif//_PLAY_LIST_PAGE_EX_H_

