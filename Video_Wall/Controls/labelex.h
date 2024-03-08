#ifndef		_LABEL_EX_H_
#define _LABEL_EX_H_


#include <QLabel>

#include <QtWidgets/QLabel>

class LabelEx
	: public QLabel
{
	Q_OBJECT
		Q_ENUMS(ArrowPosition)
		Q_ENUMS(TrianglePosition)
		Q_PROPERTY(int borderRadius READ getBorderRadius WRITE setBorderRadius)
		Q_PROPERTY(QColor background READ getBackground WRITE setBackground)
		Q_PROPERTY(QColor foreground READ getForeground WRITE setForeground)

		Q_PROPERTY(bool showArrow READ getShowArrow WRITE setShowArrow)
		Q_PROPERTY(int arrowSize READ getArrowSize WRITE setArrowSize)
		Q_PROPERTY(ArrowPosition arrowPosition READ getArrowPosition WRITE setArrowPosition)

		Q_PROPERTY(bool m_bShowTriangle READ getShowTriangle WRITE setShowTriangle)
		Q_PROPERTY(int triangleLen READ getTriangleLen WRITE setTriangleLen)
		Q_PROPERTY(TrianglePosition m_iTrianglePosition READ getTrianglePosition WRITE setTrianglePosition)
		Q_PROPERTY(QColor triangleColor READ getTriangleColor WRITE setTriangleColor)



public:
	enum ArrowPosition
	{
		ArrowPosition_Left = 0,     //向左箭头
		ArrowPosition_Right = 1,    //向右箭头
		ArrowPosition_Top = 2,      //向上箭头
		ArrowPosition_Bottom = 3    //向下箭头
	};

	enum TrianglePosition
	{
		TrianglePosition_Left = 0,  //左侧
		TrianglePosition_Right = 1, //右侧
		TrianglePosition_Top = 2,	//顶部
		TrianglePosition_Bottom = 3 //底部
	};

public:
	explicit  LabelEx(QWidget *parent = nullptr);

protected:
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *);
	void drawBg(QPainter *painter);
	void drawText(QPainter *painter);
	void drawTriangle(QPainter *painter);

public:
	int getBorderRadius()	const;
	QColor getBackground()	const;
	QColor getForeground()	const;

	void SetFontSize(int iSize);

	bool getShowArrow()	const;
	int getArrowSize()	const;
	ArrowPosition getArrowPosition()	const;

	bool getShowTriangle()	const;
	int getTriangleLen()	const;
	TrianglePosition getTrianglePosition()const;
	QColor getTriangleColor()	const;

	QSize sizeHint()	const;
	QSize minimumSizeHint()	const;


public Q_SLOTS:
	//设置边框圆角角度
	void setBorderRadius(int iBorderRadius);
	//设置前景色
	void setBackground(const QColor& iBackground);
	//设置前景色
	void setForeground(const QColor& iForeground);

	//设置显示箭头
	void setShowArrow(bool bShowArrow);
	//设置箭头大小
	void setArrowSize(int iArrowSize);
	//设置箭头位置
	void setArrowPosition(const ArrowPosition& iArrowPosition);

	//设置显示倒三角
	void setShowTriangle(bool bShowTriangle);
	//设置倒三角边长
	void setTriangleLen(int iTriangleLen);
	//设置倒三角位置
	void setTrianglePosition(const TrianglePosition& iTrianglePosition);
	//设置倒三角颜色
	void setTriangleColor(const QColor& iTriangleColor);

Q_SIGNALS:
	void clicked();



private:
	int						m_iBorderRadius;				//边框圆角角度
	QColor					m_iBackground;				//背景色
	QColor					m_iForeground;				//前景色

	bool						m_bShowArrow;				//显示箭头
	int						m_iArrowSize;					//箭头大小
	ArrowPosition		m_iArrowPosition;				//箭头位置

	bool						m_bShowTriangle;			//显示倒三角
	int						m_iTriangleLen;				//倒三角边长
	TrianglePosition	m_iTrianglePosition;			//倒三角位置
	QColor					m_iTriangleColor;				//倒三角颜色

	QRect					m_iBgRect;                       //绘制区域
};


#endif//_LABEL_EX_H_
