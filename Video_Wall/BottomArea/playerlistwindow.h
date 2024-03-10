#ifndef			_PLAYER_LIST_WINDOW_H_
#define		    _PLAYER_LIST_WINDOW_H_
 
#include <QWidget>
#include <memory>

class ButtonEx;
class PlayListWidgetEx;
 
 class PlayerListWindow
	 : public QWidget
{
	Q_OBJECT

public:
	PlayerListWindow(QWidget *parent = nullptr);
	~PlayerListWindow();

public:
	void InitUI();
	void InitConnects();
	void InitTAB();
 
public:
	void AddPlayListPageNotify(QString strPageName);
	void DeletePlayListPageNotify(QString strPageName);
	 
protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent* pEvent);

protected:
	std::unique_ptr<ButtonEx>				m_ptrButton1;
	std::unique_ptr<PlayListWidgetEx>	m_ptrTabWidget;
 	 
};


#endif//_PLAYER_LIST_WINDOW_H_
