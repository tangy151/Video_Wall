#include "progressbarex.h"
#include "../headfiledefine.h"

ProgressBarEx::ProgressBarEx(QWidget *parent)
	: QWidget(parent)
{
	minValue = 0;
	maxValue = 100;
	value = 0;
	m_bTransparent = false;
	precision = 0;
	step = 0;
	space = 1;

	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);
	m_iBgColorStart = QColor(50, 50, 50, 1);

	m_iBgColorEnd = QColor(50, 50, 50, 1);
	 
	m_iBarFrameColor = QColor(250, 250, 250);
	m_iBarBgColor = QColor(250, 250, 250);
	
 	m_iBarColor = QColor(100, 184, 255);
  }

void ProgressBarEx::paintEvent(QPaintEvent *)
{
	//����׼������,���÷����
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

	if (m_bTransparent)
	{ 
 		//���ƽ���
		drawBar2(&painter);
	} 
	else
	{
		//���Ʊ���
		drawBg(&painter);
 		//���ƽ���
		drawBar(&painter);
	}
 } 

void ProgressBarEx::drawBg(QPainter *painter)
{ 
	painter->save();
	painter->setPen(Qt::NoPen);
	QLinearGradient bgGradient(QPointF(0, 0), QPointF(0, height()));

	bgGradient.setColorAt(0.0, m_iBgColorStart);
	bgGradient.setColorAt(1.0, m_iBgColorEnd);

	painter->setBrush(bgGradient);
	painter->drawRect(rect());
	painter->restore();
}
 
void ProgressBarEx::drawBar(QPainter *painter)
 {
	painter->save();
 	 
	int iWidth = width();
	int iHeight = height();

	//���ƽ�������߿�
	QRectF barBgRect(QPointF(space, iHeight/2 - 5), QPointF(width() - space*2 , iHeight/2+5));
	painter->setPen(Qt::NoPen);
	painter->setBrush(m_iBarFrameColor);
	painter->drawRect(barBgRect);
	 

	//���ƽ������ڲ�����
	QRectF barInBgRect(QPointF(space*2+3, height() / 2 - 3 ), QPointF(width() -3-space*2, height() / 2 + 3));
	painter->setPen(Qt::NoPen);
	painter->setBrush(m_iBarBgColor);
	painter->drawRect(barInBgRect);
	  
	//���ƽ�����
	double length = width() - space - space * 2;
 	
	//����ÿһ���ƶ�����
	double increment = length / (maxValue - minValue);
	QRectF barRect(QPointF(space*2 + 3, height() / 2 - 3), QPointF(width()  /2, height() / 2 + 3));
	painter->setBrush(m_iBarColor);
	painter->drawRect(barRect);
	   
	painter->restore();
}

void ProgressBarEx::drawBar2(QPainter *painter)
{
	painter->save();

	QPen pen;
	pen.setWidth(1);
	pen.setColor(QColor(0, 0, 0));
	painter->setPen(pen);
	 
	int iWidth = width();
	int iHeight = height();
	 

	//��������λ��������������
	QPoint pointStart, pointEnd;

	pointStart = QPoint(space, iHeight / 2 - 5);
	pointEnd = QPoint(width() - space * 2, iHeight / 2- 5);

	painter->drawLine(pointStart, pointEnd);

	//---------------------------------------------------------------
	 
	pointStart = QPoint(space, iHeight / 2 + 5);
	pointEnd = QPoint(width() - space * 2, iHeight / 2 + 5);

	painter->drawLine(pointStart, pointEnd);

	//---------------------------------------------------------------

	pointStart = QPoint(width() - space * 2, iHeight / 2 - 5);
	pointEnd = QPoint(width() - space * 2, iHeight / 2 + 5);

	painter->drawLine(pointStart, pointEnd);

	//---------------------------------------------------------------

 	pointStart = QPoint(space * 2, iHeight / 2 - 5);
	pointEnd = QPoint(space * 2, iHeight / 2 + 5);

	painter->drawLine(pointStart, pointEnd);

	//---------------------------------------------------------------

 
	//���ƽ�����
	double length = width() - space - space * 2;

	//����ÿһ���ƶ�����
	double increment = length / (maxValue - minValue);
	QRectF barRect(QPointF(space * 2 +2, height() / 2 - 3), QPointF(width() / 2, height() / 2 + 3));
	painter->setBrush(m_iBarColor);
	painter->drawRect(barRect);

	
	painter->restore();
}


double ProgressBarEx::getMinValue() const
{
	return this->minValue;
}

double ProgressBarEx::getMaxValue() const
{
	return this->maxValue;
}

double ProgressBarEx::getValue() const
{
	return this->value;
}

int ProgressBarEx::getPrecision() const
{
	return this->precision;
}

int ProgressBarEx::getStep() const
{
	return this->step;
}

int ProgressBarEx::getSpace() const
{
	return this->space;
}
 
QColor ProgressBarEx::getBgColorStart() const
{
	return  m_iBgColorStart;
}

QColor ProgressBarEx::getBgColorEnd() const
{
	return m_iBgColorEnd;
}
 
QColor ProgressBarEx::getBarFrameColor() const
{
	return m_iBarFrameColor;
}

QColor ProgressBarEx::getBarBgColor() const
{
	return m_iBarBgColor;
}
 
QColor ProgressBarEx::getBarColor() const
{
	return  m_iBarColor;
}

QSize ProgressBarEx::sizeHint() const
{
	return QSize(300, 30);
}

QSize ProgressBarEx::minimumSizeHint() const
{
	return QSize(50, 20);
}

void ProgressBarEx::setRange(double minValue, double maxValue)
{
	//�����Сֵ���ڻ��ߵ������ֵ������
	if (minValue >= maxValue) 
		return;

	this->minValue = minValue;
	this->maxValue = maxValue;

	//���Ŀ��ֵ���ڷ�Χֵ��,����������Ŀ��ֵ
	if (value < minValue || value > maxValue) 
 		setValue(value);
 
	update();
}

void ProgressBarEx::setRange(int minValue, int maxValue)
{
	setRange((double)minValue, (double)maxValue);
}

void ProgressBarEx::setMinValue(double minValue)
{
	setRange(minValue, maxValue);
}

void ProgressBarEx::setMaxValue(double maxValue)
{
	setRange(minValue, maxValue);
}

void ProgressBarEx::setValue(double value)
{
	//ֵС����Сֵ����ֵ�������ֵ����ֵ�͵�ǰֵһ�������账��
	if (value < minValue || value > maxValue || value == this->value) 
 		return;
 
	this->value = value;
	emit valueChanged(value);
	update();
}

void ProgressBarEx::setValue(int value)
{
	setValue((double)value);
}

void ProgressBarEx::setPrecision(int precision)
{
	//���ȷ��Ϊ 3
	if (precision <= 3 && this->precision != precision) 
	{
		this->precision = precision;
		update();
	}
}

void ProgressBarEx::setStep(int step)
{
	if (this->step != step)
	{
		this->step = step;
		update();
	}
}

void ProgressBarEx::setSpace(int space)
{
	if (this->space != space) 
	{
		this->space = space;
		update();
	}
}
 
void ProgressBarEx::setBgColorStart(const QColor &bgColorStart)
{
	if (m_iBgColorStart != bgColorStart)
	{
		m_iBgColorStart = bgColorStart;
		update();
	}
}

void ProgressBarEx::setBgColorEnd(const QColor &bgColorEnd)
{
	if (m_iBgColorEnd != bgColorEnd)
	{
		m_iBgColorEnd = bgColorEnd;
		update();
	}
}

void ProgressBarEx::setBarFrameColor(QColor barBgColor)
{
	if (m_iBarFrameColor != barBgColor)
	{
		m_iBarFrameColor = barBgColor;
		update();
	}
}
 
void ProgressBarEx::setBarBgColor(QColor barBgColor)
{
	if (m_iBarBgColor != barBgColor)
	{
		m_iBarBgColor = barBgColor;
		update();
	}
}
 
void ProgressBarEx::setBarColor(QColor barColor)
{
	if (m_iBarColor != barColor)
	{
		m_iBarColor = barColor;
		update();
	}
}


