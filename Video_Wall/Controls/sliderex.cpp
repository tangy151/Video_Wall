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

	setFocusPolicy(Qt::ClickFocus);	//���û�ȡ����ķ�ʽ
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
	 
	//--- �������� ---//
	if (m_SliderStyle == Single_HorizontalSlider || m_SliderStyle == Double_HorizontalSlider)	//��ˮƽ���
	{
		if (m_HandleStyle == PolygonEx || m_HandleStyle == RectangleEx)
		{
			m_minX = m_curMinValue * (width() - 8) / m_MaxRange + 4;	//����ǰ��СֵתΪx����
			m_maxX = m_curMaxValue * (width() - 8) / m_MaxRange + 4;	//����ǰ���ֵתΪx����
		}
		else
		{
			m_minX = m_curMinValue * (width() - 12) / m_MaxRange + 6;	//����ǰ��СֵתΪx����
			m_maxX = m_curMaxValue * (width() - 12) / m_MaxRange + 6;	//����ǰ���ֵתΪx����
		}
	}
	else if (m_SliderStyle == Single_VerticalSlider || m_SliderStyle == Double_VerticalSlider)	//�Ǵ�ֱ������
	{
		if (m_HandleStyle == PolygonEx || m_HandleStyle == RectangleEx)
		{
			m_minY = height() - m_curMinValue * (height() - 8) / m_MaxRange - 4;	//����ǰ��СֵתΪx����
			m_maxY = height() - m_curMaxValue * (height() - 8) / m_MaxRange - 4;	//����ǰ���ֵתΪx����
		}
		else
		{
			m_minY = height() - m_curMinValue * (height() - 12) / m_MaxRange - 6;	//����ǰ��СֵתΪx����
			m_maxY = height() - m_curMaxValue * (height() - 12) / m_MaxRange - 6;	//����ǰ���ֵתΪx����
		}
	}

	//--- ���Ʋ� ---//
	paintSlider(&painter);

	 //--- ���ƻ��� ---//
	 paintHandle(&painter);

	 //--- ���Ƶ�ǰֵ ---//
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
			paintRectangle(QRect(4, 23, width() - 8, 2), m_sliderColor, painter);		//���Ƶײ�
			paintRectangle(QRect(4, 23, m_minX, 2), m_sliderSelectionColor, painter);	//����ѡ�в�
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

	if (m_SliderStyle == Single_HorizontalSlider || m_SliderStyle == Double_HorizontalSlider)	//ˮƽ��ʽ
	{
		switch (m_HandleStyle)
		{
		case PolygonEx:	//�����
		{
			minHandlePolygon.setPoints(5, m_minX - 4, 16, m_minX + 4, 16, m_minX + 4, 28, m_minX, 32, m_minX - 4, 28);	//�󻬿�λ�ü���С
			paintPolygon(minHandlePolygon, minColor, painter);	//�����󻬿�
			if (m_SliderStyle == Double_HorizontalSlider)
			{
				maxHandlePolygon.setPoints(5, m_maxX - 4, 16, m_maxX + 4, 16, m_maxX + 4, 28, m_maxX, 32, m_maxX - 4, 28);	//�һ���λ�ü���С
				paintPolygon(maxHandlePolygon, maxColor, painter);	//�����һ���
			}
		}
		break;
		case RectangleEx:	//����
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
				//�ȱ���ƽ������ͼ��
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
		case EllipseEx:	//Բ��
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
	else if (m_SliderStyle == Single_VerticalSlider || m_SliderStyle == Double_VerticalSlider)	//��ֱ��ʽ
	{
		switch (m_HandleStyle)
		{
		case PolygonEx:
		case RectangleEx:	//����,��ֱ��ʽ��֧�ֶ����
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
				//�ȱ���ƽ������ͼ��
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
		case EllipseEx:	//Բ��
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
	//�Ƿ���Ƶ�ǰֵ
	if (m_isDrawText)
	{
		painter->setFont(QFont("Arial", 8));

		QString minValueString = QString::number(m_curMinValue, 'f', 3);	//float ת QString
		QString maxValueString = QString::number(m_curMaxValue, 'f', 3);	//float ת QString

		QFontMetrics metrics = painter->fontMetrics();
		int mintextWidth = metrics.width(minValueString);	//��ȡ�ַ������
		int maxtextWidth = metrics.width(maxValueString);	//��ȡ�ַ������
		int textHeight = metrics.height();					//��ȡ�ַ����߶�
		int minTextX, minTextY, maxTextX, maxTextY;			//���Ƶ�����
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

		//--- �����ı� ---//	
		QPalette palette;
		QColor color = palette.color(QPalette::Window);	//��ȡ���ڱ���ɫ
		if (m_state == MinHandle)
		{
			if (m_textBrush)	//m_textBrush��ʼΪfalse����ֹ�����ʱ����Ʊ�����֮���һֱΪtrue
				paintRectangle(QRect(minTextX, minTextY, mintextWidth, textHeight), color, painter);	//����һ�鱳��
			painter->drawText(QRectF(minTextX, minTextY, mintextWidth, textHeight), minValueString);	//������Сֵ
		}
		else if (m_state == MaxHandle)
		{
			if (m_textBrush)
				paintRectangle(QRect(maxTextX, maxTextY, maxtextWidth, textHeight), color, painter);	//����һ�鱳��

			painter->drawText(QRectF(maxTextX, maxTextY, maxtextWidth, textHeight), maxValueString);	//�������ֵ
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
	painter->setRenderHint(QPainter::Antialiasing, true);	//�����
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
		//���������ǻ�����ʲôҲ��������������ʾ��ǰֵ
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
		//�����ƶ������������
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
				//������ʽ�Ƕ���λ����
				if (m_minX > m_maxX - m_overlapOffset)
					m_minX = m_maxX - m_overlapOffset;
				if (m_minX < 4)
					m_minX = 4;
				m_curMinValue = (float)(m_minX - 4) / (width() - 8) *m_MaxRange;
			}
			else {
				//������Բ��
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
				//������ʽ�Ƕ���λ����
				m_maxX = pot.x();
				if (m_maxX < m_minX + m_overlapOffset)
					m_maxX = m_minX + m_overlapOffset;
				if (m_maxX > width() - 4)
					m_maxX = width() - 4;
				m_curMaxValue = (float)(m_maxX - 4) / (width() - 8) *m_MaxRange;
			}
			else {
				//������Բ��
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
				//������ʽ�Ƕ���λ����
				if (m_minY < m_maxY + m_overlapOffset)
					m_minY = m_maxY + m_overlapOffset;
				if (m_minY > height() - 4)
					m_minY = height() - 4;
				m_curMinValue = (float)(height() - m_minY - 4) / (height() - 8) *m_MaxRange;
			}
			else {
				//������Բ��
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
				//������ʽ�Ƕ���λ����
				m_maxY = pot.y();
				if (m_maxY > m_minY - m_overlapOffset)
					m_maxY = m_minY - m_overlapOffset;
				if (m_maxY < 4)
					m_maxY = 4;
				m_curMaxValue = (float)(height() - m_maxY - 4) / (height() - 8) *m_MaxRange;
			}
			else {
				//������Բ��
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
	//�����ź�
	emit valueChanged(m_curMinValue, m_curMaxValue);
	//ˢ�´���
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
					m_curMinValue = m_MinRange;		//��ǰ��Сֵ���� < ��С��Чֵ������ = ��С��Чֵ
				}
			}
			else if (m_state == MaxHandle) {
				if ((m_curMaxValue -= m_singleStep) < m_curMinValue) {
					m_curMaxValue = m_curMinValue;	//��ǰ���ֵ���� < ��ǰ��Сֵ������ = ��ǰ��Сֵ
				}
			}
		}
		else if (event->key() == Qt::Key_Right)
		{
			if (m_state == MinHandle) {
				if ((m_curMinValue += m_singleStep) > m_curMaxValue) {
					m_curMinValue = m_curMaxValue;	//��ǰ��Сֵ���� > ��ǰ���ֵ������ = ��ǰ���ֵ
				}
			}
			else if (m_state == MaxHandle) {
				if ((m_curMaxValue += m_singleStep) > m_MaxRange) {
					m_curMaxValue = m_MaxRange;		//��ǰ���ֵ���� > �����Чֵ������ = �����Чֵ
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
					m_curMinValue = m_MinRange;		//��ǰ��Сֵ���� < ��С��Чֵ������ = ��С��Чֵ
				}
			}
			else if (m_state == MaxHandle) {
				if ((m_curMaxValue -= m_singleStep) < m_curMinValue) {
					m_curMaxValue = m_curMinValue;	//��ǰ���ֵ���� < ��ǰ��Сֵ������ = ��ǰ��Сֵ
				}
			}
		}
		else if (event->key() == Qt::Key_Up)
		{
			if (m_state == MinHandle) {
				if ((m_curMinValue += m_singleStep) > m_curMaxValue) {
					m_curMinValue = m_curMaxValue;	//��ǰ��Сֵ���� > ��ǰ���ֵ������ = ��ǰ���ֵ
				}
			}
			else if (m_state == MaxHandle) {
				if ((m_curMaxValue += m_singleStep) > m_MaxRange) {
					m_curMaxValue = m_MaxRange;		//��ǰ���ֵ���� > �����Чֵ������ = �����Чֵ
				}
			}
		}
	}
	//�����ź�
	emit valueChanged(m_curMinValue, m_curMaxValue);
	//ˢ�´���
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
//-----------------------------------------------------------�ӿ�ʵ�ֲ���-----------------------------------------------------------//
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
	/*	setMaximumSize(16777215, 36);	//���ô������߶�Ϊ36*/
		setMaximumSize(16777215, 16777215);	//���ô������߶�Ϊ36
		setOverlap(true);				//��������������ص���˫������Ҫ��ʱ��������
		break;
	case Double_HorizontalSlider:
		setMaximumSize(16777215, 36);	//���ô������߶�Ϊ36
		break;
	case Single_VerticalSlider:
		//setMaximumSize(36, 16777215);	//���ô��������Ϊ36
		setMaximumSize(16777215, 16777215);	//���ô��������Ϊ36

		setOverlap(true);
		break;
	case Double_VerticalSlider:
		setMaximumSize(36, 16777215);	//���ô��������Ϊ36
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
		//����˫���鲻�����ص�ʱ��ƫ����
		if (m_isOverlap)
		{
			m_overlapOffset = 0;
 		}
		else if (m_HandleStyle == PolygonEx || m_HandleStyle == RectangleEx)	//�Ƕ���λ���Σ�����Բ��
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
		//�����鲻��Ҫƫ��
		m_isOverlap = true;
		m_overlapOffset = 0;
	}
}