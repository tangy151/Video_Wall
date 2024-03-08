#include "rulerlineex.h"
#include "../headfiledefine.h"
 
#include "../globaldefine.h"

RulerLineEx::RulerLineEx(QWidget *parent) : QWidget(parent)
{
	minValue = 0;
	maxValue = 100;
	value = 0;
	alarmValue = 90;

	minValueRight = 0;
	maxValueRight = 100;
	valueRight = 0;
	alarmValueRight = 90;

	longStep = 10;
	shortStep = 2;
	longStepRight = 10;
	shortStepRight = 2;

	bgColor = QColor(2, 16, 34);
	scaleColor = QColor(255, 255, 255);
	textColor = QColor(200, 200, 200);
	alarmScaleColor = QColor(255, 107, 107);

  	space = 20;
 	scaleStyle = ScaleStyle_Single;
 
#if PIX_1080p
	setFont(QFont("Microsoft YaHei", 10, 75));
 #else
	setFont(QFont("Microsoft YaHei", 8, 75));
 #endif
 }

void RulerLineEx::paintEvent(QPaintEvent *)
{
	//����׼������,���÷����
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

	//���Ʊ���
	drawBg(&painter);

	//������߿̶ȳ�
 	drawLeftScale(&painter); 

	//�����ұ߿̶ȳ�
	 //drawRightScale(&painter);

  	//������߿̶�ֵ
  	drawLeftText(&painter);

	//������߿̶�ֵ
	//drawRightText(&painter);

	//�������ָʾ��
	//drawLeftPointer(&painter);

	//�����ұ�ָʾ��
		//  drawRightPointer(&painter);
}

void RulerLineEx::drawBg(QPainter *painter)
{
	painter->save();
	painter->setPen(Qt::NoPen);
	painter->setBrush(QColor(50, 50, 50));
	painter->drawRect(rect());
	painter->restore();
}

void RulerLineEx::drawLeftScale(QPainter *painter)
{
	double minValue = this->minValue;
	double maxValue = this->maxValue;
	int longStep = this->longStep;
	int shortStep = this->shortStep;

	QPen pen;
	pen.setWidth(2);
	pen.setCapStyle(Qt::RoundCap);
	pen.setColor(QColor(120, 120, 120));
	painter->save();
	painter->setPen(pen);

	//������������

	int iWidth = width();

	double initLeftX = iWidth - 5;
	double initY = space / 4;

// 	double initLeftX = space;
// 	double initY = space/4;

	//�����������
 	// painter->drawLine(QPointF(initLeftX, initY), QPointF(initLeftX, height() - space/4));
	 
	//���������߿̶�
	double length = height() - 2 * space/4;

	//����ÿһ���ƶ�����
	double increment = length / (maxValue - minValue);

	//����������������
	int longLineLen		= 1;
	int shortLineLen		= 1;

	//���ݷ�Χֵ���ƿ̶�ֵ���̶�ֵ
	for (int i = maxValue; i >= minValue; i = i - shortStep) 
	{
		if (i % longStep == 0) 
		{
			painter->drawLine(QPointF(initLeftX + longLineLen, initY), QPointF(initLeftX, initY));
		}
		else
		{
			if (i % (longStep / 2) == 0) 
			{
				shortLineLen = 1;
			}
			else 
			{
				shortLineLen = 1;
			}

			painter->drawLine(QPointF(initLeftX + shortLineLen, initY), QPointF(initLeftX, initY));
		}

		initY += increment * shortStep;
	}

	painter->restore();
}

void RulerLineEx::drawRightScale(QPainter *painter)
{
	double minValue = this->minValue;
	double maxValue = this->maxValue;
	int longStep = this->longStep;
	int shortStep = this->shortStep;

	//�����˫������ʽ,��Χֵ������ȡ�ұߵķ�Χֵ������
	if (scaleStyle == ScaleStyle_Double) {
		minValue = this->minValueRight;
		maxValue = this->maxValueRight;
		longStep = this->longStepRight;
		shortStep = this->shortStepRight;
	}

	QPen pen;
	pen.setWidth(2);
	pen.setCapStyle(Qt::RoundCap);
	pen.setColor(scaleColor);
	painter->save();
	painter->setPen(pen);

	//������������
	double initRightX = this->width() - space/4;
	double initY = space;

	//�Ҳ���������
	painter->drawLine(QPointF(initRightX, initY), QPointF(initRightX, height() - space));

	//���������߿̶�
	double length = height() - 2 * space;
	//����ÿһ���ƶ�����
	double increment = length / (maxValue - minValue);
	//����������������
	int longLineLen = 1;
	int shortLineLen = 1;

	//���ݷ�Χֵ���ƿ̶�ֵ���̶�ֵ
	for (int i = maxValue; i >= minValue; i = i - shortStep) 
	{
		if (i % longStep == 0)
		{
			painter->drawLine(QPointF(initRightX - longLineLen, initY), QPointF(initRightX, initY));
		}
		else
		{
			if (i % (longStep / 2) == 0)
			{
				shortLineLen = 1;
			}
			else
			{
				shortLineLen = 1;
			}

			painter->drawLine(QPointF(initRightX - shortLineLen, initY), QPointF(initRightX, initY));
		}

		initY += increment * shortStep;
	}

	painter->restore();
}

void RulerLineEx::drawLeftText(QPainter *painter)
{
	double minValue		= this->minValue;
	double maxValue	= this->maxValue;

	int longStep		= this->longStep;
	int shortStep	= this->shortStep;

	painter->save();
	painter->setPen(QColor(140, 140, 140));

	int iWidth = width();

	double initLeftX = iWidth - 5;
	double initY = space ;
	 

	double initCenterX =   5;
	double initCenterY = space/2 ;
	 

// 	double initLeftX = space;
  	double initLeftY = space;

	//���������߿̶�
	double length = this->height() - 2 * space;

	//����ÿһ���ƶ�����
	double increment = length / (maxValue - minValue);

	//����������������
	int longLineLen = 1;
	int shortLineLen = 1;

	for (int i = maxValue; i >= minValue; i = i - shortStep) 
	{
		if (i % longStep == 0) 
		{
			QString strValue = QString("%1").arg(i);

			if (scaleStyle == ScaleStyle_Single)
			{
				//�м�̶�ֵ
// 				QRect textRect(initCenterX, initCenterY, this->width() - space * 2, 20);

				QRect textRect(initCenterX, initCenterY, iWidth - 15, 20);

				painter->drawText(textRect, Qt::AlignRight, strValue);
			}
			else if (scaleStyle == ScaleStyle_Double)
			{
				//��̶�ֵ
				QPointF textLeftPot(initLeftX + longLineLen + shortLineLen, initLeftY + 4);
				painter->drawText(textLeftPot, strValue);
			}
		}

		initCenterY += increment * shortStep;
		initLeftY += increment * shortStep;
	}

	painter->restore();
}

void RulerLineEx::drawRightText(QPainter *painter)
{
	double minValue = this->minValue;
	double maxValue = this->maxValue;
	int longStep = this->longStep;
	int shortStep = this->shortStep;

	//�����˫������ʽ,��Χֵ������ȡ�ұߵķ�Χֵ������
	if (scaleStyle == ScaleStyle_Double) {
		minValue = this->minValueRight;
		maxValue = this->maxValueRight;
		longStep = this->longStepRight;
		shortStep = this->shortStepRight;
	}

	painter->save();
	painter->setPen(textColor);

	double initCenterX = space;
	double initCenterY = space / 2;

	double initRightX = this->width() - space;
	double initRightY = space;

	//���������߿̶�
	double length = this->height() - 2 * space;
	//����ÿһ���ƶ�����
	double increment = length / (maxValue - minValue);
	//����������������
	int longLineLen = 10;
	int shortLineLen = 7;

	for (int i = maxValue; i >= minValue; i = i - shortStep) {
		if (i % longStep == 0) {
			QString strValue = QString("%1").arg(i);

			if (scaleStyle == ScaleStyle_Single) {
				//�м�̶�ֵ
				QRect textRect(initCenterX, initCenterY, this->width() - space * 2, 20);
				painter->drawText(textRect, Qt::AlignCenter, strValue);
			}
			else if (scaleStyle == ScaleStyle_Double) {
				//�ҿ̶�ֵ
				double fontWidth = painter->fontMetrics().width(strValue);
				QPointF textRightPot(initRightX - longLineLen - shortLineLen - fontWidth, initRightY + 4);
				painter->drawText(textRightPot, strValue);
			}
		}

		initCenterY += increment * shortStep;
		initRightY += increment * shortStep;
	}

	painter->restore();
}

void RulerLineEx::drawLeftPointer(QPainter *painter)
{
	double minValue = this->minValue;
	double maxValue = this->maxValue;
	double value = this->value;

	painter->save();
	painter->setPen(alarmScaleColor);
	painter->setBrush(alarmScaleColor);

	//�ҵ���ǰֵ��������
	double barHeight = this->height() - space * 2;
	double increment = (double)barHeight / (maxValue - minValue);

	int offset = 10;
	double initLeftX = space + offset;
	double initY = this->height() - space - ((value - minValue) * increment);

	//���������ָʾ��
	QPolygon leftPts;
	leftPts.append(QPoint(initLeftX, initY));
	leftPts.append(QPoint(initLeftX + offset, initY - offset / 2));
	leftPts.append(QPoint(initLeftX + offset, initY + offset / 2));
	painter->drawPolygon(leftPts);

	painter->restore();
}

void RulerLineEx::drawRightPointer(QPainter *painter)
{
	double minValue = this->minValue;
	double maxValue = this->maxValue;
	double value = this->value;

	//�����˫������ʽ,��Χֵ������ȡ�ұߵķ�Χֵ������
	if (scaleStyle == ScaleStyle_Double) {
		minValue = this->minValueRight;
		maxValue = this->maxValueRight;
		value = this->valueRight;
	}

	painter->save();
	painter->setPen(alarmScaleColor);
	painter->setBrush(alarmScaleColor);

	//�ҵ���ǰֵ��������
	double barHeight = this->height() - space * 2;
	double increment = (double)barHeight / (maxValue - minValue);

	int offset = 10;
	double initRightX = this->width() - space - offset;
	double initY = this->height() - space - ((value - minValue) * increment);

	//�Ҳ�������ָʾ��
	QPolygon rightPts;
	rightPts.append(QPoint(initRightX, initY));
	rightPts.append(QPoint(initRightX - offset, initY - offset / 2));
	rightPts.append(QPoint(initRightX - offset, initY + offset / 2));
	painter->drawPolygon(rightPts);

	painter->restore();
}

double RulerLineEx::getMinValue() const
{
	return this->minValue;
}

double RulerLineEx::getMaxValue() const
{
	return this->maxValue;
}

double RulerLineEx::getValue() const
{
	return this->value;
}

double RulerLineEx::getAlarmValue() const
{
	return this->alarmValue;
}

double RulerLineEx::getMinValueRight() const
{
	return this->minValueRight;
}

double RulerLineEx::getMaxValueRight() const
{
	return this->maxValueRight;
}

double RulerLineEx::getValueRight() const
{
	return this->valueRight;
}

double RulerLineEx::getAlarmValueRight() const
{
	return this->alarmValueRight;
}

int RulerLineEx::getLongStep() const
{
	return this->longStep;
}

int RulerLineEx::getShortStep() const
{
	return this->shortStep;
}

int RulerLineEx::getLongStepRight() const
{
	return this->longStepRight;
}

int RulerLineEx::getShortStepRight() const
{
	return this->shortStepRight;
}

QColor RulerLineEx::getBgColor() const
{
	return this->bgColor;
}

QColor RulerLineEx::getScaleColor() const
{
	return this->scaleColor;
}

QColor RulerLineEx::getTextColor() const
{
	return this->textColor;
}

QColor RulerLineEx::getAlarmScaleColor() const
{
	return this->alarmScaleColor;
}

int RulerLineEx::getSpace() const
{
	return this->space;
}

RulerLineEx::ScaleStyle RulerLineEx::getScaleStyle() const
{
	return this->scaleStyle;
}

QSize RulerLineEx::sizeHint() const
{
	return QSize(120, 300);
}

QSize RulerLineEx::minimumSizeHint() const
{
	return QSize(50, 100);
}

void RulerLineEx::setRange(double minValue, double maxValue)
{
	//�����Сֵ���ڻ��ߵ������ֵ������
	if (minValue >= maxValue) {
		return;
	}

	this->minValue = minValue;
	this->maxValue = maxValue;

	//���Ŀ��ֵ���ڷ�Χֵ��,����������Ŀ��ֵ
	if (value < minValue || value > maxValue) {
		setValue(value);
	}

	update();
}

void RulerLineEx::setRange(int minValue, int maxValue)
{
	setRange((double)minValue, (double)maxValue);
}

void RulerLineEx::setRangeRight(double minValueRight, double maxValueRight)
{
	//�����Сֵ���ڻ��ߵ������ֵ������
	if (minValueRight >= maxValueRight) {
		return;
	}

	this->minValueRight = minValueRight;
	this->maxValueRight = maxValueRight;

	//���Ŀ��ֵ���ڷ�Χֵ��,����������Ŀ��ֵ
	if (valueRight < minValueRight || valueRight > maxValueRight) {
		setValueRight(valueRight);
	}

	update();
}

void RulerLineEx::setRangeRight(int minValueRight, int maxValueRight)
{
	setRangeRight((double)minValueRight, (double)maxValueRight);
}

void RulerLineEx::setMinValue(double minValue)
{
	setRange(minValue, maxValue);
}

void RulerLineEx::setMaxValue(double maxValue)
{
	setRange(minValue, maxValue);
}

void RulerLineEx::setMinValueRight(double minValue)
{
	setRangeRight(minValue, maxValue);
}

void RulerLineEx::setMaxValueRight(double maxValue)
{
	setRangeRight(minValue, maxValue);
}

void RulerLineEx::setValue(double value)
{
	//ֵС����Сֵ����ֵ�������ֵ�����账��
	if (value < minValue || value > maxValue) {
		return;
	}

	this->value = value;
	update();
}

void RulerLineEx::setValue(int value)
{
	setValue((double)value);
}

void RulerLineEx::setValueRight(double valueRight)
{
	//ֵС����Сֵ����ֵ�������ֵ�����账��
	if (valueRight < minValueRight || valueRight > maxValueRight) {
		return;
	}

	this->valueRight = valueRight;
	update();
}

void RulerLineEx::setValueRight(int valueRight)
{
	setValueRight((double)valueRight);
}

void RulerLineEx::setAlarmValue(double alarmValue)
{
	if (this->alarmValue != alarmValue) {
		this->alarmValue = alarmValue;
		update();
	}
}

void RulerLineEx::setAlarmValueRight(double alarmValueRight)
{
	if (this->alarmValueRight != alarmValueRight) {
		this->alarmValueRight = alarmValueRight;
		update();
	}
}

void RulerLineEx::setLongStep(int longStep)
{
	//�̲������ܳ���������
	if (longStep < shortStep) {
		return;
	}

	if (this->longStep != longStep) {
		this->longStep = longStep;
		update();
	}
}

void RulerLineEx::setShortStep(int shortStep)
{
	//�̲������ܳ���������
	if (longStep < shortStep) {
		return;
	}

	if (this->shortStep != shortStep) {
		this->shortStep = shortStep;
		update();
	}
}

void RulerLineEx::setLongStepRight(int longStepRight)
{
	//�̲������ܳ���������
	if (longStepRight < shortStepRight) {
		return;
	}

	if (this->longStepRight != longStepRight) {
		this->longStepRight = longStepRight;
		update();
	}
}

void RulerLineEx::setShortStepRight(int shortStepRight)
{
	//�̲������ܳ���������
	if (longStepRight < shortStepRight) {
		return;
	}

	if (this->shortStepRight != shortStepRight) {
		this->shortStepRight = shortStepRight;
		update();
	}
}

void RulerLineEx::setBgColor(const QColor &bgColor)
{
	if (this->bgColor != bgColor) {
		this->bgColor = bgColor;
		update();
	}
}

void RulerLineEx::setScaleColor(const QColor &scaleColor)
{
	if (this->scaleColor != scaleColor) {
		this->scaleColor = scaleColor;
		update();
	}
}

void RulerLineEx::setTextColor(const QColor &textColor)
{
	if (this->textColor != textColor) {
		this->textColor = textColor;
		update();
	}
}

void RulerLineEx::setAlarmScaleColor(const QColor &alarmScaleColor)
{
	if (this->alarmScaleColor != alarmScaleColor) {
		this->alarmScaleColor = alarmScaleColor;
		update();
	}
}

void RulerLineEx::setSpace(int space)
{
	if (this->space != space) {
		this->space = space;
		update();
	}
}

void RulerLineEx::setScaleStyle(const RulerLineEx::ScaleStyle &scaleStyle)
{
	if (this->scaleStyle != scaleStyle) {
		this->scaleStyle = scaleStyle;
		update();
	}
}

