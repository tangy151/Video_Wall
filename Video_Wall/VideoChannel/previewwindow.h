#ifndef			_PREVIEW_WINDOW_H_
#define		_PREVIEW_WINDOW_H_

#include <memory>
#include <QWidget>
#include "../globaldefine.h"

class QMenu;
class QLabel;

class SelectMediaSourceWindow;


class PreviewWindow : public QWidget
{
	Q_OBJECT

public:
	PreviewWindow(QWidget *parent);
	~PreviewWindow();

public:
	void InitPopMenu();
	void InitActions();
private:
	void InitConnects();

protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent* pEvent);
	void mousePressEvent(QMouseEvent *pEvent);        //µ¥»÷


public slots:
	void  OnInputMainMonitor();
	void  OnInputPrevMonitor();
	void  OnSelMediaSource();
	void  OnEditorMedia();
	void  OnReloadMedia();
	void  OnClearMedia();


public slots:

private:
 	std::unique_ptr<QLabel>					m_ptrTitleLabel;
	std::unique_ptr<QMenu>					m_ptrPopMenu;


	std::unique_ptr<QAction>				m_ptrActInputMainMonitor;
	std::unique_ptr<QAction>				m_ptrActInputPrevMonitor;
	std::unique_ptr<QAction>				m_ptrASelMediaSource;
	std::unique_ptr<QAction>				m_ptrActEditorMedia;
	std::unique_ptr<QAction>				m_ptrActReloadMedia;
	std::unique_ptr<QAction>				m_ptrActClearMedia;


	MEDIA_SELECT_TYPE				m_iMediaType;

};


#endif//_PREVIEW_WINDOW_H_
 