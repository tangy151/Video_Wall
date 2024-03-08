#include "sliderex.h"
#include "../headfiledefine.h"
#include "../globaldefine.h"

SliderEx::SliderEx(QWidget *parent)
	: QWidget(parent)
	, m_MinRange(0.00f)
	, m_MaxRange(100.00f)
	, m_singleStep(0.5f)
	, m_curMinValue(0.00f)
	, m_curMaxValue(100.00f)
	, m_state(None)
	, m_lastHandle(None)
	, m_SliderStyle(Single_HorizontalSlider)
	, m_HandleStyle(PolygonEx)
	//, m_HandleStyle(RectangleEx)
	//, m_HandleStyle(Circular)
	, m_sliderColor(QColor(0, 0, 0))
	, m_sliderSelectionColor(QColor(154, 205, 50))
	, m_sliderHandleColor(QColor(154, 205, 50))
	, m_unSliderHandleColor(Qt::darkGray)
	, m_overlapOffset(0)
	, m_textBrush(false)
{
	m_iIconNormal = QPixmap();

	m_bDrawVolume = false;

	setFocusPolicy(Qt::ClickFocus);	//设置获取焦点的方式
}

SliderEx::~SliderEx()
{

}

void SliderEx::paintEvent(QPaintEvent *event)
{
	QWidget::paintEvent(event);
	QPainter painter(this);

	painter.setClipRect(0, 0, width(), height());
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(50, 50, 50));
	 
	//--- 计算坐标 ---//
	if (m_SliderStyle == Single_HorizontalSlider || m_SliderStyle == Double_HorizontalSlider)	//是水平活动条
	{
		if (m_HandleStyle == PolygonEx || m_HandleStyle == RectangleEx)
		{
			m_minX = m_curMinValue * (width() - 8) / m_MaxRange + 4;	//将当前最小值转为x坐标
			m_maxX = m_curMaxValue * (width() - 8) / m_MaxRange + 4;	//将当前最大值转为x坐标
		}
		else
		{
			m_minX = m_curMinValue * (width() - 12) / m_MaxRange + 6;	//将当前最小值转为x坐标
			m_maxX = m_curMaxValue * (width() - 12) / m_MaxRange + 6;	//将当前最大值转为x坐标
		}
	}
	else if (m_SliderStyle == Single_VerticalSlider || m_SliderStyle == Double_VerticalSlider)	//是垂直滑动条
	{
		if (m_HandleStyle == PolygonEx || m_HandleStyle == RectangleEx)
		{
			m_minY = height() - m_curMinValue * (height() - 8) / m_MaxRange - 4;	//将当前最小值转为x坐标
			m_maxY = height() - m_curMaxValue * (height() - 8) / m_MaxRange - 4;	//将当前最大值转为x坐标
		}
		else
		{
			m_minY = height() - m_curMinValue * (height() - 12) / m_MaxRange - 6;	//将当前最小值转为x坐标
			m_maxY = height() - m_curMaxValue * (height() - 12) / m_MaxRange - 6;	//将当前最大值转为x坐标
		}
	}

	//--- 绘制槽 ---//
	paintSlider(&painter);

	 //--- 绘制滑块 ---//
	 paintHandle(&painter);

	 //--- 绘制当前值 ---//
	//paintText(&painter);
}

void SliderEx::paintSlider(QPainter* painter)
{
	switch (m_SliderStyle)
	{
	case Single_HorizontalSlider:
	{
 		if (m_bDrawVolume)
		{
			int iHeight = height() / 2;
 #if PIX_1080p
			paintRectangle(QRect(3, iHeight - 1, width() - 6, 2), QColor(10, 10, 10), painter);
#else
			paintRectangle(QRect(3, iHeight - 1, width() - 6, 2), QColor(10, 10, 10), painter);
  #endif
 		}
		else
		{
			paintRectangle(QRect(4, 23, width() - 8, 2), m_sliderColor, painter);		//绘制底槽
			paintRectangle(QRect(4, 23, m_minX, 2), m_sliderSelectionColor, painter);	//绘制选中槽
		}
 	}

	break;
	case Double_HorizontalSlider:
	{
		paintRectangle(QRect(4, 23, width() - 8, 2), m_sliderColor, painter);
		paintRectangle(QRect(m_minX, 23, m_maxX - m_minX, 2), m_sliderSelectionColor, painter);
	}

	break;
	case Single_VerticalSlider:
	{
		if (m_bDrawVolume)
		{
			int iWidth = width()/2;

#if PIX_1080p
			paintRectangle(QRect(iWidth , 2, 2, height() - 4), QColor(10, 10, 10), painter);
#else
			paintRectangle(QRect(iWidth - 1 , 2, 2, height() - 8), QColor(10, 10, 10), painter);
 #endif
 		}
		else
		{
			paintRectangle(QRect(10, 0, 15, height() - 8), m_sliderColor, painter);
			paintRectangle(QRect(10, m_minY, 15, height() - m_minY), m_sliderSelectionColor, painter);
		}
	}

	break;
	case Double_VerticalSlider:
	{
		paintRectangle(QRect(17, 4, 2, height() - 8), m_sliderColor, painter);
		paintRectangle(QRect(17, m_minY, 2, m_maxY - m_minY), m_sliderSelectionColor, painter);
	}

	break;
	default:
		break;
	}
}

void SliderEx::paintHandle(QPainter* painter)
{
	QColor minColor = (m_state == MinHandle) ? m_sliderHandleColor : m_unSliderHandleColor;
	QColor maxColor = (m_state == MaxHandle) ? m_sliderHandleColor : m_unSliderHandleColor;

	if (m_SliderStyle == Single_HorizontalSlider || m_SliderStyle == Double_HorizontalSlider)	//水平样式
	{
		switch (m_HandleStyle)
		{
		case PolygonEx:	//多边形
		{
			minHandlePolygon.setPoints(5, m_minX - 4, 16, m_minX + 4, 16, m_minX + 4, 28, m_minX, 32, m_minX - 4, 28);	//左滑块位置及大小
			paintPolygon(minHandlePolygon, minColor, painter);	//绘制左滑块
			if (m_SliderStyle == Double_HorizontalSlider)
			{
				maxHandlePolygon.setPoints(5, m_maxX - 4, 16, m_maxX + 4, 16, m_maxX + 4, 28, m_maxX, 32, m_maxX - 4, 28);	//右滑块位置及大小
				paintPolygon(maxHandlePolygon, maxColor, painter);	//绘制右滑块
			}
		}
		break;
		case RectangleEx:	//矩形
		{
 			if (m_bDrawVolume)
			{
				minHandleRect.setRect(m_minX - 4 , 0, 10, height());
			}
	 
			int iWidth = width();
			int iHeight = height();

 			int iX = minHandleRect.width( )-2;
			int iY = minHandleRect.height();

			QPixmap pix;

			pix = m_iIconNormal;

			if (!pix.isNull())
			{
				//等比例平滑缩放图标
			//QSize iSize = pix.size();
 		//	 pix = pix.scaled(QSize(iX, iY), Qt::KeepAspectRatio, Qt::SmoothTransformation);
 
#if PIX_1080p 
				painter->drawPixmap(m_minX, height() / 4 -1 , pix);
#else
				painter->drawPixmap(m_minX  , height() /4 - 1 , pix);
#endif
			}
			 
			if (m_SliderStyle == Double_HorizontalSlider)
			{
				maxHandleRect.setRect(m_maxX - 4, 16, 8, 16);
				paintRectangle(maxHandleRect, maxColor, painter);
			}
 		}

		break;
		case EllipseEx:	//圆形
		{
			minHandleRect.setRect(m_minX - 6, 18, 12, 12);
			paintEllipse(minHandleRect, minColor, painter);

			if (m_SliderStyle == Double_HorizontalSlider) 
			{
				maxHandleRect.setRect(m_maxX - 6, 18, 12, 12);
				paintEllipse(maxHandleRect, maxColor, painter);
			}
		}
 			break;
		default:
			break;
		}
	}
	else if (m_SliderStyle == Single_VerticalSlider || m_SliderStyle == Double_VerticalSlider)	//垂直样式
	{
		switch (m_HandleStyle)
		{
		case PolygonEx:
		case RectangleEx:	//矩形,垂直样式不支持多边形
		{
			if (m_bDrawVolume)
			{
 				minHandleRect.setRect(0, m_minY - 4, width(), 8);
 			}
		 
			int iWidth = width();
			int iHeight = height();
			int iX = minHandleRect.width();
			int iY = minHandleRect.height();
			  
			QPixmap pix;

			pix = m_iIconNormal;

			if (!pix.isNull())
			{
				//等比例平滑缩放图标
				QSize iSize = pix.size();
				//pix = pix.scaled(QSize(iWidth, iSize.height()), Qt::KeepAspectRatio, Qt::SmoothTransformation);
				  
#if PIX_1080p 
				painter->drawPixmap(iWidth / 2 - iSize.width()/2 +1, m_minY - iY * 2 - 5, pix);
#else
				painter->drawPixmap(iWidth / 2 - iSize.width() / 2, m_minY - iY * 2 - 5, pix);
#endif
  			}
			  
 			if (m_SliderStyle == Double_VerticalSlider)
			{
				maxHandleRect.setRect(10, m_maxY - 4, 16, 8);
				paintRectangle(maxHandleRect, maxColor, painter);
			}
		}
		break;
		case EllipseEx:	//圆形
		{
			minHandleRect.setRect(12, m_minY - 6, 12, 12);
			paintEllipse(minHandleRect, minColor, painter);

			if (m_SliderStyle == Double_VerticalSlider)
			{
				maxHandleRect.setRect(12, m_maxY - 6, 12, 12);
				paintEllipse(maxHandleRect, maxColor, painter);
			}
		}

		break;
		default:
			break;
		}
	}
}

void SliderEx::paintText(QPainter* painter)
{
	//是否绘制当前值
	if (m_isDrawText)
	{
		painter->setFont(QFont("Arial", 8));

		QString minValueString = QString::number(m_curMinValue, 'f', 3);	//float 转 QString
		QString maxValueString = QString::number(m_curMaxValue, 'f', 3);	//float 转 QString

		QFontMetrics metrics = painter->fontMetrics();
		int mintextWidth = metrics.width(minValueString);	//获取字符串宽度
		int maxtextWidth = metrics.width(maxValueString);	//获取字符串宽度
		int textHeight = metrics.height();					//获取字符串高度
		int minTextX, minTextY, maxTextX, maxTextY;			//绘制的坐标
		if (m_SliderStyle == Single_HorizontalSlider || m_SliderStyle == Double_HorizontalSlider)
		{
			minTextX = m_minX - (mintextWidth / 2);
			minTextY = 2;
			maxTextX = m_maxX - (maxtextWidth / 2);
			maxTextY = 2;

			if (minTextX < 0) minTextX = 0;
			if ((minTextX + mintextWidth) > width()) minTextX = width() - mintextWidth;

			if ((maxTextX + maxtextWidth) > width()) maxTextX = width() - maxtextWidth;
			if (maxTextX < 0) maxTextX = 0;
		}
		else if (m_SliderStyle == Single_VerticalSlider || m_SliderStyle == Double_VerticalSlider)
		{
			minTextX = 1;
			minTextY = m_minY - 6 - textHeight;
			maxTextX = 1;
			maxTextY = m_maxY - 6 - textHeight;

			if (minTextY <= 0 || minTextY <= m_maxY + 6) minTextY = m_minY + 6 + textHeight;
			if (minTextY > height() - textHeight) minTextY = m_maxY - 6 - textHeight;

			if (maxTextY <= 0) maxTextY = m_maxY + 6 + textHeight;
			if (maxTextY + textHeight > m_minY - 6) maxTextY = m_minY + 6 + textHeight;
		}

		//--- 绘制文本 ---//	
		QPalette palette;
		QColor color = palette.color(QPalette::Window);	//获取窗口背景色
		if (m_state == MinHandle)
		{
			if (m_textBrush)	//m_textBrush初始为false，防止构造的时候绘制背景，之后就一直为true
				paintRectangle(QRect(minTextX, minTextY, mintextWidth, textHeight), color, painter);	//绘制一块背景
			painter->drawText(QRectF(minTextX, minTextY, mintextWidth, textHeight), minValueString);	//绘制最小值
		}
		else if (m_state == MaxHandle)
		{
			if (m_textBrush)
				paintRectangle(QRect(maxTextX, maxTextY, maxtextWidth, textHeight), color, painter);	//绘制一块背景

			painter->drawText(QRectF(maxTextX, maxTextY, maxtextWidth, textHeight), maxValueString);	//绘制最大值
		}

		m_textBrush = true;
	}
}

void SliderEx::paintRectangle(QRect rect, QColor color, QPainter* painter)
{
	painter->fillRect(rect, color);
}

void SliderEx::paintPolygon(QPolygon polygon, QColor color, QPainter* painter)
{
	QPainterPath path;
	path.addPolygon(polygon);
	painter->fillPath(path, color);
}

void SliderEx::paintEllipse(QRect rect, QColor color, QPainter* painter)
{
	painter->setRenderHint(QPainter::Antialiasing, true);	//抗锯齿
	QPainterPath path;
	path.addEllipse(rect);
	painter->fillPath(path, color);
}

void SliderEx::mousePressEvent(QMouseEvent *event)
{
	switch (m_SliderStyle)
	{
	case Single_HorizontalSlider:
	case Single_VerticalSlider:
		//如果点击的是滑块则什么也不做，单纯的显示当前值
		if (minHandlePolygon.containsPoint(event->pos(), Qt::OddEvenFill) || minHandleRect.contains(event->pos())) {
			m_isDrawText = true;
			update();
			break;
		}
	case Double_HorizontalSlider:
	case Double_VerticalSlider:
		if (minHandlePolygon.containsPoint(event->pos(), Qt::OddEvenFill) || minHandleRect.contains(event->pos())) {
			m_state = m_lastHandle = MinHandle;
			m_isDrawText = true;
			update();
			break;
		}
		else if (maxHandlePolygon.containsPoint(event->pos(), Qt::OddEvenFill) || maxHandleRect.contains(event->pos())) {
			m_state = m_lastHandle = MaxHandle;
			m_isDrawText = true;
			update();
			break;
		}
	default:
		//否则移动滑块至点击处
		calculationPos(event->pos());
		break;
	}
}

void SliderEx::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons() & Qt::LeftButton) {
		calculationPos(event->pos());
	}
}

void SliderEx::mouseReleaseEvent(QMouseEvent *event)
{
	m_isDrawText = false;
	update();
}

void SliderEx::calculationPos(QPoint pot)
{
	if (m_SliderStyle == Single_HorizontalSlider || m_SliderStyle == Double_HorizontalSlider)
	{
		switch (m_state)
		{
		case MinHandle: {
			m_minX = pot.x();
			if (m_HandleStyle == PolygonEx || m_HandleStyle == RectangleEx)
			{
				//滑块样式是多边形或矩形
				if (m_minX > m_maxX - m_overlapOffset)
					m_minX = m_maxX - m_overlapOffset;
				if (m_minX < 4)
					m_minX = 4;
				m_curMinValue = (float)(m_minX - 4) / (width() - 8) *m_MaxRange;
			}
			else {
				//否则是圆形
				if (m_minX > m_maxX - m_overlapOffset)
					m_minX = m_maxX - m_overlapOffset;
				if (m_minX < 6)
					m_minX = 6;
				m_curMinValue = (float)(m_minX - 6) / (width() - 12) *m_MaxRange;
			}
			break;
		}
		case MaxHandle: {
			if (m_HandleStyle == PolygonEx || m_HandleStyle == RectangleEx)
			{
				//滑块样式是多边形或矩形
				m_maxX = pot.x();
				if (m_maxX < m_minX + m_overlapOffset)
					m_maxX = m_minX + m_overlapOffset;
				if (m_maxX > width() - 4)
					m_maxX = width() - 4;
				m_curMaxValue = (float)(m_maxX - 4) / (width() - 8) *m_MaxRange;
			}
			else {
				//否则是圆形
				m_maxX = pot.x();
				if (m_maxX < m_minX + m_overlapOffset)
					m_maxX = m_minX + m_overlapOffset;
				if (m_maxX > width() - 6)
					m_maxX = width() - 6;
				m_curMaxValue = (float)(m_maxX - 6) / (width() - 12) *m_MaxRange;
			}
			break;
		}
		case None:
		default:
			break;
		}
	}
	else if (m_SliderStyle == Single_VerticalSlider || m_SliderStyle == Double_VerticalSlider)
	{
		switch (m_state)
		{
		case MinHandle: {
			m_minY = pot.y();
			if (m_HandleStyle == PolygonEx || m_HandleStyle == RectangleEx)
			{
				//滑块样式是多边形或矩形
				if (m_minY < m_maxY + m_overlapOffset)
					m_minY = m_maxY + m_overlapOffset;
				if (m_minY > height() - 4)
					m_minY = height() - 4;
				m_curMinValue = (float)(height() - m_minY - 4) / (height() - 8) *m_MaxRange;
			}
			else {
				//否则是圆形
				if (m_minY < m_maxY + m_overlapOffset)
					m_minY = m_maxY + m_overlapOffset;
				if (m_minY > height() - 6)
					m_minY = height() - 6;
				m_curMinValue = (float)(height() - m_minY - 6) / (height() - 12) *m_MaxRange;
			}
			break;
		}
		case MaxHandle: {
			if (m_HandleStyle == PolygonEx || m_HandleStyle == RectangleEx)
			{
				//滑块样式是多边形或矩形
				m_maxY = pot.y();
				if (m_maxY > m_minY - m_overlapOffset)
					m_maxY = m_minY - m_overlapOffset;
				if (m_maxY < 4)
					m_maxY = 4;
				m_curMaxValue = (float)(height() - m_maxY - 4) / (height() - 8) *m_MaxRange;
			}
			else {
				//否则是圆形
				m_maxY = pot.y();
				if (m_maxY > m_minY - m_overlapOffset)
					m_maxY = m_minY - m_overlapOffset;
				if (m_maxY < 6)
					m_maxY = 6;
				m_curMaxValue = (float)(height() - m_maxY - 6) / (height() - 12) *m_MaxRange;
			}
			break;
		}
		case None:
		default:
			break;
		}
	}
	//发射信号
	emit valueChanged(m_curMinValue, m_curMaxValue);
	//刷新窗口
	m_isDrawText = true;
	update();
}

void SliderEx::keyPressEvent(QKeyEvent *event)
{
	QWidget::keyPressEvent(event);
	if (m_SliderStyle == Single_HorizontalSlider || m_SliderStyle == Double_HorizontalSlider)
	{
		if (event->key() == Qt::Key_Left)
		{
			if (m_state == MinHandle) {
				if ((m_curMinValue -= m_singleStep) < m_MinRange) {
					m_curMinValue = m_MinRange;		//当前最小值不能 < 最小有效值，否则 = 最小有效值
				}
			}
			else if (m_state == MaxHandle) {
				if ((m_curMaxValue -= m_singleStep) < m_curMinValue) {
					m_curMaxValue = m_curMinValue;	//当前最大值不能 < 当前最小值，否则 = 当前最小值
				}
			}
		}
		else if (event->key() == Qt::Key_Right)
		{
			if (m_state == MinHandle) {
				if ((m_curMinValue += m_singleStep) > m_curMaxValue) {
					m_curMinValue = m_curMaxValue;	//当前最小值不能 > 当前最大值，否则 = 当前最大值
				}
			}
			else if (m_state == MaxHandle) {
				if ((m_curMaxValue += m_singleStep) > m_MaxRange) {
					m_curMaxValue = m_MaxRange;		//当前最大值不能 > 最大有效值，否则 = 最大有效值
				}
			}
		}
	}
	else if (m_SliderStyle == Single_VerticalSlider || m_SliderStyle == Double_VerticalSlider)
	{
		if (event->key() == Qt::Key_Down)
		{
			if (m_state == MinHandle) {
				if ((m_curMinValue -= m_singleStep) < m_MinRange) {
					m_curMinValue = m_MinRange;		//当前最小值不能 < 最小有效值，否则 = 最小有效值
				}
			}
			else if (m_state == MaxHandle) {
				if ((m_curMaxValue -= m_singleStep) < m_curMinValue) {
					m_curMaxValue = m_curMinValue;	//当前最大值不能 < 当前最小值，否则 = 当前最小值
				}
			}
		}
		else if (event->key() == Qt::Key_Up)
		{
			if (m_state == MinHandle) {
				if ((m_curMinValue += m_singleStep) > m_curMaxValue) {
					m_curMinValue = m_curMaxValue;	//当前最小值不能 > 当前最大值，否则 = 当前最大值
				}
			}
			else if (m_state == MaxHandle) {
				if ((m_curMaxValue += m_singleStep) > m_MaxRange) {
					m_curMaxValue = m_MaxRange;		//当前最大值不能 > 最大有效值，否则 = 最大有效值
				}
			}
		}
	}
	//发射信号
	emit valueChanged(m_curMinValue, m_curMaxValue);
	//刷新窗口
	m_isDrawText = true;
	update();
}

void SliderEx::keyReleaseEvent(QKeyEvent *event)
{
	QWidget::keyReleaseEvent(event);
	m_isDrawText = false;
	update();
}

void SliderEx::enterEvent(QEvent *event)
{
	QWidget::enterEvent(event);
	if (m_SliderStyle == Single_HorizontalSlider || m_SliderStyle == Single_VerticalSlider) {
		m_state = MinHandle;
		m_sliderHandleColor = QColor(154, 205, 50);
	}
	else {
		m_state = m_lastHandle;
		m_sliderHandleColor = QColor(154, 205, 50);
	}
	m_isDrawText = false;
	update();
}

void SliderEx::leaveEvent(QEvent* event)
{
	QWidget::leaveEvent(event);
	m_state = None;
	update();
}

void SliderEx::resizeEvent(QResizeEvent *event)
{

}
//-----------------------------------------------------------接口实现部分-----------------------------------------------------------//
void SliderEx::setRange(float min, float max)
{
	m_MinRange = min;
	m_MaxRange = max;

	m_curMinValue = m_curMinValue < m_MinRange ? m_MinRange : m_curMinValue;
	m_curMaxValue = m_curMaxValue < m_MaxRange ? m_curMaxValue : m_MaxRange;
}

void SliderEx::setMinRange(float value)
{
	m_MinRange = value;
}
void SliderEx::setMaxRange(float value)
{
	m_MaxRange = value;
}

void SliderEx::setCurMinValue(float value)
{
	m_curMinValue = value;
}
void SliderEx::setCurMaxRange(float value)
{
	m_curMaxValue = value;
}

void SliderEx::setSingleStep(float step)
{
	m_singleStep = step;
}

void SliderEx::setDrawVolume(bool bDraw)
{
	m_bDrawVolume = bDraw;
	update();
 }

void SliderEx::setIconNormal(const QPixmap &iconNormal)
{
	m_iIconNormal = iconNormal;
	update();
 }

float SliderEx::getMinRange() const
{
	return m_MinRange;
}

float SliderEx::getMaxRange() const
{
	return m_MaxRange;
}

float SliderEx::getCurMinValue() const
{
	return m_curMinValue;
}

float SliderEx::getCurMaxValue() const
{
	return m_curMaxValue;
}

void SliderEx::setSliderColor(QColor botColor, QColor selColor)
{
	m_sliderColor = botColor;
	m_sliderSelectionColor = selColor;
}

void SliderEx::setHandleColor(QColor selColor, QColor unSelColor)
{
	m_sliderHandleColor = selColor;
	m_unSliderHandleColor = unSelColor;
}

void SliderEx::setStyle(SliderStyle sliderStyle, HandleStyle handleStyle)
{
	m_SliderStyle = sliderStyle;
	m_HandleStyle = handleStyle;

	switch (sliderStyle)
	{
	case Single_HorizontalSlider:
	/*	setMaximumSize(16777215, 36);	//设置窗口最大高度为36*/
		setMaximumSize(16777215, 16777215);	//设置窗口最大高度为36
		setOverlap(true);				//单滑块必须允许重叠，双滑块需要的时候在设置
		break;
	case Double_HorizontalSlider:
		setMaximumSize(16777215, 36);	//设置窗口最大高度为36
		break;
	case Single_VerticalSlider:
		//setMaximumSize(36, 16777215);	//设置窗口最大宽度为36
		setMaximumSize(16777215, 16777215);	//设置窗口最大宽度为36

		setOverlap(true);
		break;
	case Double_VerticalSlider:
		setMaximumSize(36, 16777215);	//设置窗口最大宽度为36
		break;
	default:
		break;
	}
}

void SliderEx::setOverlap(bool bl)
{
	m_isOverlap = bl;

	if (m_SliderStyle == Double_HorizontalSlider || m_SliderStyle == Double_VerticalSlider)
	{
		//设置双滑块不允许重叠时的偏移量
		if (m_isOverlap)
		{
			m_overlapOffset = 0;
 		}
		else if (m_HandleStyle == PolygonEx || m_HandleStyle == RectangleEx)	//是多边形或矩形，否则圆形
		{
			m_overlapOffset = 8;
 		}
		else
		{
			m_overlapOffset = 12;
 		}
	}
	else
	{
		//单滑块不需要偏移
		m_isOverlap = true;
		m_overlapOffset = 0;
	}
}