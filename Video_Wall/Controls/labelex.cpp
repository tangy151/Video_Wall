#include "labelex.h"
#include "../headfiledefine.h"


LabelEx::LabelEx(QWidget *parent)
	: QLabel(parent)
{
	m_iBorderRadius = 5;
	m_iBackground = QColor(100, 184, 255);
	m_iForeground = QColor(255, 255, 255);

	m_bShowArrow = true;
	m_iArrowSize = 5;
	m_iArrowPosition = ArrowPosition_Right;

	m_bShowTriangle = false;
	m_iTriangleLen = 5;
	m_iTrianglePosition = TrianglePosition_Left;
	m_iTriangleColor = QColor(255, 255, 255);

	m_iBgRect = this->geometry();

}

void LabelEx::SetFontSize(int iSize)
{
	setFont(QFont("Microsoft Yahei", iSize));
}

void LabelEx::paintEvent(QPaintEvent *)
{
	//����׼������,���÷����
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

	//���Ʊ���
	drawBg(&painter);
	//��������
	drawText(&painter);
	//���Ƶ�����
	drawTriangle(&painter);
}

void LabelEx::mousePressEvent(QMouseEvent *)
{
	emit clicked();
}

void LabelEx::drawBg(QPainter *painter)
{
	int width = this->width();
	int height = this->height();
	int endX = width - m_iArrowSize;
	int endY = height - m_iArrowSize;

	painter->save();
	painter->setPen(Qt::NoPen);
	painter->setBrush(m_iBackground);

	QPolygon pts;
	if (m_iArrowPosition == ArrowPosition_Right)
	{
		m_iBgRect = QRect(0, 0, endX, height);
		pts.setPoints(3, endX, height / 2 - m_iArrowSize, endX, height / 2 + m_iArrowSize, width, height / 2);
	}
	else if (m_iArrowPosition == ArrowPosition_Left)
	{
		m_iBgRect = QRect(m_iArrowSize, 0, width - m_iArrowSize, height);
		pts.setPoints(3, m_iArrowSize, height / 2 - m_iArrowSize, m_iArrowSize, height / 2 + m_iArrowSize, 0, height / 2);
	}
	else if (m_iArrowPosition == ArrowPosition_Bottom)
	{
		m_iBgRect = QRect(0, 0, width, endY);
		pts.setPoints(3, width / 2 - m_iArrowSize, endY, width / 2 + m_iArrowSize, endY, width / 2, height);
	}
	else if (m_iArrowPosition == ArrowPosition_Top)
	{
		m_iBgRect = QRect(0, m_iArrowSize, width, height - m_iArrowSize);
		pts.setPoints(3, width / 2 - m_iArrowSize, m_iArrowSize, width / 2 + m_iArrowSize, m_iArrowSize, width / 2, 0);
	}

	//����Բ�Ǿ��κ����Ǽ�ͷ
	if (!m_bShowArrow)
	{
		m_iBgRect = this->rect();
		painter->drawRoundedRect(m_iBgRect, m_iBorderRadius, m_iBorderRadius);
	}
	else
	{
		painter->drawRoundedRect(m_iBgRect, m_iBorderRadius, m_iBorderRadius);
		painter->drawPolygon(pts);
	}

	painter->restore();
}
void LabelEx::drawText(QPainter *painter)
{
	painter->save();
	painter->setPen(m_iForeground);
	painter->setBrush(Qt::NoBrush);
	painter->drawText(m_iBgRect, Qt::AlignCenter, this->text());
	painter->restore();
}

void LabelEx::drawTriangle(QPainter *painter)
{
	if (!m_bShowTriangle) {
		return;
	}

	painter->save();
	painter->setPen(Qt::NoPen);
	painter->setBrush(m_iTriangleColor);

	//�������Ҳ��м�,�����趨�ĵ����ǵı߳��趨������λ��
	int width = this->width();
	int height = this->height();
	int midWidth = width / 2;
	int midHeight = height / 2;

	QPolygon pts;
	if (m_iTrianglePosition == TrianglePosition_Left)
	{
		pts.setPoints(3, m_iTriangleLen, midHeight, 0, midHeight - m_iTriangleLen, 0, midHeight + m_iTriangleLen);
	}
	else if (m_iTrianglePosition == TrianglePosition_Right)
	{
		pts.setPoints(3, width - m_iTriangleLen, midHeight, width, midHeight - m_iTriangleLen, width, midHeight + m_iTriangleLen);
	}
	else if (m_iTrianglePosition == TrianglePosition_Top)
	{
		pts.setPoints(3, midWidth, m_iTriangleLen, midWidth - m_iTriangleLen, 0, midWidth + m_iTriangleLen, 0);
	}
	else if (m_iTrianglePosition == TrianglePosition_Bottom)
	{
		pts.setPoints(3, midWidth, height - m_iTriangleLen, midWidth - m_iTriangleLen, height, midWidth + m_iTriangleLen, height);
	}


	painter->drawPolygon(pts);

	painter->restore();
}

int LabelEx::getBorderRadius()	const

{
	return this->m_iBorderRadius;
}
QColor LabelEx::getBackground()	const
{
	return this->m_iBackground;
}

QColor LabelEx::getForeground()	const
{
	return this->m_iForeground;
}

bool LabelEx::getShowArrow()	const
{
	return this->m_bShowArrow;
}

int LabelEx::getArrowSize()	const
{
	return this->m_iArrowSize;
}

LabelEx::ArrowPosition LabelEx::getArrowPosition()	const
{
	return this->m_iArrowPosition;
}

bool LabelEx::getShowTriangle()	const
{
	return this->m_bShowTriangle;
}

int LabelEx::getTriangleLen()	const
{
	return this->m_iTriangleLen;
}

LabelEx::TrianglePosition LabelEx::getTrianglePosition()const
{
	return this->m_iTrianglePosition;
}

QColor LabelEx::getTriangleColor()	const
{
	return this->m_iTriangleColor;
}

QSize LabelEx::sizeHint()	const
{
	return QSize(100, 30);
}

QSize LabelEx::minimumSizeHint()	const
{
	return QSize(20, 10);
}

//���ñ߿�Բ�ǽǶ�
void LabelEx::setBorderRadius(int iBorderRadius)
{
	if (this->m_iBorderRadius != iBorderRadius)
	{
		this->m_iBorderRadius = iBorderRadius;
		update();
	}
}
//����ǰ��ɫ
void LabelEx::setBackground(const QColor& iBackground)
{
	if (this->m_iBackground != iBackground)
	{
		this->m_iBackground = iBackground;
		update();
	}
}
//����ǰ��ɫ
void LabelEx::setForeground(const QColor& iForeground)
{
	if (this->m_iForeground != iForeground)
	{
		this->m_iForeground = iForeground;
		update();
	}

}

//������ʾ��ͷ
void LabelEx::setShowArrow(bool bShowArrow)
{
	if (this->m_bShowArrow != bShowArrow)
	{
		this->m_bShowArrow = bShowArrow;
		update();
	}
}

//���ü�ͷ��С
void LabelEx::setArrowSize(int iArrowSize)
{
	if (this->m_iArrowSize != iArrowSize)
	{
		this->m_iArrowSize = iArrowSize;
		update();
	}
}

//���ü�ͷλ��
void LabelEx::setArrowPosition(const LabelEx::ArrowPosition& iArrowPosition)
{
	if (this->m_iArrowPosition != iArrowPosition)
	{
		this->m_iArrowPosition = iArrowPosition;
		update();
	}
}

//������ʾ������
void LabelEx::setShowTriangle(bool bShowTriangle)
{
	if (this->m_bShowTriangle != bShowTriangle)
	{
		this->m_bShowTriangle = bShowTriangle;
		update();
	}
}

//���õ����Ǳ߳�
void LabelEx::setTriangleLen(int iTriangleLen)
{
	if (this->m_iTriangleLen != iTriangleLen)
	{
		this->m_iTriangleLen = iTriangleLen;
		update();
	}
}

//���õ�����λ��
void LabelEx::setTrianglePosition(const LabelEx::TrianglePosition& iTrianglePosition)
{
	if (this->m_iTrianglePosition != iTrianglePosition)
	{
		this->m_iTrianglePosition = iTrianglePosition;
		update();
	}
}

//���õ�������ɫ
void LabelEx::setTriangleColor(const QColor& iTriangleColor)
{
	if (this->m_iTriangleColor != iTriangleColor)
	{
		this->m_iTriangleColor = iTriangleColor;
		update();
	}
 }


