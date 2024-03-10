#ifndef			_PLAY_LIST_SECTON_EX_H_
#define		_PLAY_LIST_SECTON_EX_H_


#include <QWidget>
#include <memory>
 
class PlayListEx;
class QListWidget;
class PlayListItemEx;

class PlayListSectionEx
	: public QWidget
{
	Q_OBJECT

public:
	PlayListSectionEx(QWidget *parent, QString  strTitleName);
	~PlayListSectionEx();

public:

	void InitUI();
	void InitConnects();

	void InitData();

public slots:
	 
	void OnSessionListNotify(PlayListItemEx* pListItem);


protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent* pEvent);

protected:
	QString						m_strTitleName;


	std::unique_ptr<PlayListEx>	m_ptrPlayListEx;
		//std::unique_ptr<QListWidget>	m_ptrPlayListEx;

	
};

#endif//_PLAY_LIST_SECTON_EX_H_
