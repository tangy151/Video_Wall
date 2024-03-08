#include "volumemeter.h"
#include "../headfiledefine.h"

 

VolumeMeter::VolumeMeter(QWidget *parent) : QWidget(parent)
{
	minValue		= 0;
	maxValue		= 100;
	leftValue		= 0;
	rightValue	= 0;

	colorBg = QColor(60, 60, 60);
	colorValue = Qt::white;
	colorHigh = Qt::red;
	colorLow = Qt::green;

	setFont(QFont("Arial", 12, QFont::Bold));
}

VolumeMeter::~VolumeMeter()
{

}

void VolumeMeter::paintEvent(QPaintEvent *)
{
	//绘制准备工作,启用反锯齿,平移坐标轴中心,等比例缩放
	QPainter painter(this);
 	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
// 	painter.setWindow(0, 0, 100, 540);

	//绘制边框
	drawBorder(&painter);
	
	//绘制柱状音量
	drawBar(&painter);

// 	//绘制值
 	//drawValue(&painter);
}

void VolumeMeter::drawBorder(QPainter *painter)
{ 
	painter->setClipRect(0, 0, width(), height());
 	painter->fillRect(QRectF(0, 0, width(), height()), QColor(30, 30, 30));
	painter->setClipRect(0, 0, width(), height());
	painter->fillRect(QRectF(1, 1, width()-2, height()-2), QColor(50, 50, 50));
 }

void VolumeMeter::drawBar(QPainter *painter)
{
	int iWidth = width();
	int iHeight = height();

	painter->save();

	QLinearGradient linGrad(50, 0, 50, iHeight);
	linGrad.setColorAt(0, colorHigh);
	linGrad.setColorAt(1, colorLow);
	linGrad.setSpread(QGradient::RepeatSpread);
	painter->setBrush(linGrad);

	////绘制柱状条
	//QRectF bar3(1, 1, iWidth / 2, iHeight);
 //painter->drawRect(bar3);
 //
// 
	//QRectF bar4(iWidth / 2, 0, iWidth / 2, iHeight);
// 	painter->drawRect(bar4);

	////绘制柱状背景

	double length = iHeight;

	 double leftBar = qAbs(length * (minValue - leftValue) / (maxValue - minValue));
	 double rightBar = qAbs(length * (minValue - rightValue) / (maxValue - minValue));
	  
	QRectF bar1(1, iHeight- leftBar, iWidth/2 -1,   leftBar-2);
	painter->drawRect(bar1);
	// painter->fillRect(bar1, QColor(50, 150, 50));
	 
	QRectF bar2(iWidth / 2 +1, iHeight - rightBar, iWidth/2 - 2 , rightBar -2);
	painter->drawRect(bar2);  
	 
	 painter->setBrush(QColor(50, 50, 50));
  	 painter->setPen(QPen(Qt::black, 2));
  
	painter->restore();
}

void VolumeMeter::drawValue(QPainter *painter)
{
	//painter->save();

	////绘制左右音量值背景
	//painter->setBrush(Qt::black);
	//painter->drawRect(20, 15, 25, 25);
	//painter->drawRect(55, 15, 25, 25);

	////绘制左右音量值背景右侧突出线条,形成立体感
	//painter->setPen(Qt::gray);
	//painter->drawLine(20, 40, 45, 40);
	//painter->drawLine(45, 15, 45, 40);
	//painter->drawLine(55, 40, 80, 40);
	//painter->drawLine(80, 15, 80, 40);

	////设置音量值字体
	//painter->setPen(QPen(colorValue, 1));

	////绘制左音量值
	//QRectF leftR(20, 15, 25, 25);
	//QString lVal = QString("%1").arg(leftValue, 0, 'f', 0);
	//painter->drawText(leftR, Qt::AlignCenter, lVal);

	////绘制右音量值
	//QRectF rightR(55, 15, 25, 25);
	//QString rVal = QString("%1").arg(rightValue, 0, 'f', 0);
	//painter->drawText(rightR, Qt::AlignCenter, rVal);

	//painter->restore();

	//发送音量值改变信号
	emit valueLChanged(leftValue);
	emit valueRChanged(rightValue);
}

QColor VolumeMeter::getColorBg() const
{
	return this->colorBg;
}

QColor VolumeMeter::getColorValue() const
{
	return this->colorValue;
}

QColor VolumeMeter::getColorLow() const
{
	return this->colorLow;
}

QColor VolumeMeter::getColorHigh() const
{
	return this->colorHigh;
}

double VolumeMeter::getMinValue() const
{
	return this->minValue;
}

double VolumeMeter::getMaxValue() const
{
	return this->maxValue;
}

double VolumeMeter::getLeftValue() const
{
	return this->leftValue;
}

double VolumeMeter::getRightValue() const
{
	return this->rightValue;
}

void VolumeMeter::setMinValue(double minValue)
{
	if (this->minValue > maxValue) {
		this->minValue = maxValue;
		this->maxValue = minValue;
	}
	else {
		this->minValue = minValue;
	}

	update();
}

void VolumeMeter::setMaxValue(double maxValue)
{
	if (this->maxValue < minValue) {
		this->maxValue = minValue;
		this->minValue = maxValue;
	}
	else {
		this->maxValue = maxValue;
	}

	update();
}

void VolumeMeter::setLeftValue(double leftValue)
{
	if (this->leftValue > maxValue) {
		this->leftValue = maxValue;
	}
	else if (this->leftValue < minValue) {
		this->leftValue = minValue;
	}
	else {
		this->leftValue = leftValue;
	}

	update();
}

void VolumeMeter::setRightValue(double rightValue)
{
	if (this->rightValue > maxValue) {
		this->rightValue = maxValue;
	}
	else if (this->rightValue < minValue) {
		this->rightValue = minValue;
	}
	else {
		this->rightValue = rightValue;
	}

	update();
}

void VolumeMeter::setColorBg(const QColor &colorBg)
{
	if (this->colorBg != colorBg) {
		this->colorBg = colorBg;
		update();
	}
}

void VolumeMeter::setColorValue(const QColor &colorValue)
{
	if (this->colorValue != colorValue) {
		this->colorValue = colorValue;
		update();
	}
}

void VolumeMeter::setColorHigh(const QColor &colorHigh)
{
	if (this->colorHigh != colorHigh) {
		this->colorHigh = colorHigh;
		update();
	}
}

void VolumeMeter::setColorLow(const QColor &colorLow)
{
	if (this->colorLow != colorLow) {
		this->colorLow = colorLow;
		update();
	}
}

QSize VolumeMeter::sizeHint() const
{
	return QSize(100, 540);
}

QSize VolumeMeter::minimumSizeHint() const
{
	return QSize(10, 54);
}
