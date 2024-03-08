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
		ArrowPosition_Left = 0,     //�����ͷ
		ArrowPosition_Right = 1,    //���Ҽ�ͷ
		ArrowPosition_Top = 2,      //���ϼ�ͷ
		ArrowPosition_Bottom = 3    //���¼�ͷ
	};

	enum TrianglePosition
	{
		TrianglePosition_Left = 0,  //���
		TrianglePosition_Right = 1, //�Ҳ�
		TrianglePosition_Top = 2,	//����
		TrianglePosition_Bottom = 3 //�ײ�
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
	//���ñ߿�Բ�ǽǶ�
	void setBorderRadius(int iBorderRadius);
	//����ǰ��ɫ
	void setBackground(const QColor& iBackground);
	//����ǰ��ɫ
	void setForeground(const QColor& iForeground);

	//������ʾ��ͷ
	void setShowArrow(bool bShowArrow);
	//���ü�ͷ��С
	void setArrowSize(int iArrowSize);
	//���ü�ͷλ��
	void setArrowPosition(const ArrowPosition& iArrowPosition);

	//������ʾ������
	void setShowTriangle(bool bShowTriangle);
	//���õ����Ǳ߳�
	void setTriangleLen(int iTriangleLen);
	//���õ�����λ��
	void setTrianglePosition(const TrianglePosition& iTrianglePosition);
	//���õ�������ɫ
	void setTriangleColor(const QColor& iTriangleColor);

Q_SIGNALS:
	void clicked();



private:
	int						m_iBorderRadius;				//�߿�Բ�ǽǶ�
	QColor					m_iBackground;				//����ɫ
	QColor					m_iForeground;				//ǰ��ɫ

	bool						m_bShowArrow;				//��ʾ��ͷ
	int						m_iArrowSize;					//��ͷ��С
	ArrowPosition		m_iArrowPosition;				//��ͷλ��

	bool						m_bShowTriangle;			//��ʾ������
	int						m_iTriangleLen;				//�����Ǳ߳�
	TrianglePosition	m_iTrianglePosition;			//������λ��
	QColor					m_iTriangleColor;				//��������ɫ

	QRect					m_iBgRect;                       //��������
};


#endif//_LABEL_EX_H_
