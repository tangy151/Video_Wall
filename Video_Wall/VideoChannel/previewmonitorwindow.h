#ifndef		_PREVIEW_MONITOR_WINDOW_H_
#define _PREVIEW_MONITOR_WINDOW_H_

 
#include <memory>
#include <QWidget>

class PvwWindow;
class QLabel;
class VolumeMeter;
class QMenu;


class PreviewMonitorWindow 
	: public QWidget
{
	Q_OBJECT

public:
	PreviewMonitorWindow(QWidget *parent);
	~PreviewMonitorWindow();

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
	void mousePressEvent(QMouseEvent *pEvent);        //µ¥»÷

private:
	std::unique_ptr<PvwWindow>			m_ptrPvwWindow;
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

#endif//_PREVIEW_MONITOR_WINDOW_H_
