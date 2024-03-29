#ifndef			_MAIN_MONITOR_WINDOW_H_
#define		    _MAIN_MONITOR_WINDOW_H_

 
#include <memory>
#include <QWidget>

class PgmWindow;
class QLabel;
class QMenu;
class VolumeMeter;

class MainMonitorWindow : public QWidget
{
	Q_OBJECT

public:
	MainMonitorWindow(QWidget *parent);
	~MainMonitorWindow();

private:
	void InitUI();
	void InitMenu();
	void InitActions();
	void InitConnects();


private slots:
 	void updateValue();

public slots:


	void	OnActPic1();
	void	OnActPic2();
	void	OnActLogo1();
	void	OnActLogo2();
	void	OnActTimer();

	void	OnActSubtitles1();
	void	OnActSubtitles2();
	void	OnActSubtitles3();
	void	OnActSubtitles4();


protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent* pEvent);
	void mousePressEvent(QMouseEvent *pEvent);        //����

private:
	std::unique_ptr<PgmWindow>			m_ptrPgmWindow;
	std::unique_ptr<QLabel>					m_ptrTitleLabel;
	std::unique_ptr<VolumeMeter>			m_ptrVolumeMeter;


	std::unique_ptr<QMenu>					m_ptrPopMenu;
	std::unique_ptr<QMenu>					m_ptrChildMenu;
	std::unique_ptr<QMenu>					m_ptrSubtitlesMenu;



	std::unique_ptr<QAction>				m_ptrActPic1;
	std::unique_ptr<QAction>				m_ptrActPic2;
	std::unique_ptr<QAction>				m_ptrActLogo1;
	std::unique_ptr<QAction>				m_ptrActLogo2;
	std::unique_ptr<QAction>				m_ptrActTimer;


	std::unique_ptr<QAction>				m_ptrActSubtitles1;
	std::unique_ptr<QAction>				m_ptrActSubtitles2;
	std::unique_ptr<QAction>				m_ptrActSubtitles3;
	std::unique_ptr<QAction>				m_ptrActSubtitles4;
};


#endif//_MAIN_MONITOR_WINDOW_H_
