#ifndef			_GRAPHICS_WIDGET_H_
#define		_GRAPHICS_WIDGET_H_

#include <QWidget>
#include <memory>
#include "../GraphicsView/graphicsviewex.h"
#include <QMainWindow>
 
class GraphicsWindow;
class GraphicsViewEx;

class QMainWindow;
class QBoxLayout;
class QMdiArea;
class QMdiSubWindow;

class GraphicsWidget
	: public   QWidget
{
	Q_OBJECT

public:
	explicit	GraphicsWidget(QWidget *parent = nullptr) ;
	~GraphicsWidget();

private:
	void 	InitConnect();
	void InitUI();

protected:
	void resizeEvent(QResizeEvent *pEvent);
	void paintEvent(QPaintEvent* pEvent);

public:
	GraphicsViewEx* CreateGraphicsViewEx();


private:
 	//std::unique_ptr<GraphicsViewEx>			m_ptrGraphicsView;
 	std::unique_ptr<GraphicsWindow>		m_ptrGraphicsWindow;

	GraphicsViewEx*			m_pViewEx;

	QMdiArea *m_pMdiArea;
 


};



#endif//_GRAPHICS_WIDGET_H_
