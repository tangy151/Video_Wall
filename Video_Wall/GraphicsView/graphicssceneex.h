#ifndef			_GRAPHICS_SCENE_EX_H_
#define		_GRAPHICS_SCENE_EX_H_


#include <QGraphicsScene>

class GraphicsSceneEx
	: public QGraphicsScene
{
	Q_OBJECT

public:
	explicit 	GraphicsSceneEx(QObject *parent = nullptr);
	~GraphicsSceneEx();


signals:
	void itemMoved(QGraphicsItem * item, const QPointF & oldPosition);
	void itemRotate(QGraphicsItem * item, const qreal oldAngle);
	void itemAdded(QGraphicsItem * item);
	void itemResize(QGraphicsItem * item, int handle, const QPointF& scale);
	void itemControl(QGraphicsItem * item, int handle, const QPointF & newPos, const QPointF& lastPos_);

protected:
	void drawBackground(QPainter *painter, const QRectF &rect) Q_DECL_OVERRIDE;
	void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvet) Q_DECL_OVERRIDE;
	void keyPressEvent(QKeyEvent *e) Q_DECL_OVERRIDE;
	void keyReleaseEvent(QKeyEvent *e) Q_DECL_OVERRIDE;


	void mouseEvent(QGraphicsSceneMouseEvent *mouseEvent);

	void destroyGroup(QGraphicsItemGroup *group);

public:
	void setView(QGraphicsView * view) 
	{
		m_view = view; 
	}
	QGraphicsView * view() 
	{ 
		return m_view;
	}
	 

private:
	QGraphicsView * m_view;
	qreal m_dx;
	qreal m_dy;
	bool  m_moved;
 


};

#endif//_GRAPHICS_SCENE_EX_H_
