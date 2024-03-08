#ifndef		_GRAPHICS_VIEW_EX_H_
#define	_GRAPHICS_VIEW_EX_H_


#include <QGraphicsView>

class QMouseEvent;

class ScrollBarEx;

class GraphicsViewEx 
	: public QGraphicsView
{
	Q_OBJECT

public:
 
	explicit	GraphicsViewEx(QGraphicsScene* pScene);
 	~GraphicsViewEx();

protected:
	void InitScrollBarEx();


protected:
	void resizeEvent(QResizeEvent *pEvent) Q_DECL_OVERRIDE;
 	void wheelEvent(QWheelEvent* pEvent) Q_DECL_OVERRIDE;

	void closeEvent(QCloseEvent *pEvent) Q_DECL_OVERRIDE;
 	void mouseMoveEvent(QMouseEvent * pEvent) Q_DECL_OVERRIDE;
 	void scrollContentsBy(int dx, int dy) Q_DECL_OVERRIDE;

public:
	void zoomIn();
	void zoomOut();

protected:
 

	std::unique_ptr<ScrollBarEx>		m_ptrVScrollBarEx;
 	std::unique_ptr<ScrollBarEx>		m_ptrHScrollBarEx;

		 
 
};

#endif//_GRAPHICS_VIEW_EX_H_
