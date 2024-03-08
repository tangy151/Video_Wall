#ifndef			_GRAPHICS_WINDOW_H_
#define		_GRAPHICS_WINDOW_H_


#include <QGraphicsObject>

class GraphicsWindow
	: public QGraphicsObject
{
	Q_OBJECT
 
public:
	GraphicsWindow(QGraphicsItem *  parent = nullptr);
	~GraphicsWindow();

public:

 
	QRectF boundingRect() const Q_DECL_OVERRIDE;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;



public:
	QGraphicsItem* graphicsItem()  
	{
		return this;
	}
 
};

#endif//_GRAPHICS_WINDOW_H_
