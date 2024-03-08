#include "buttonex.h"
#include "../headfiledefine.h"

#define  GAP_COUNT			7


ButtonEx::ButtonEx(QWidget *parent)
	: QPushButton(parent)
{
 	m_iPaddingLeft = 20;
	m_iPaddingRight = 5;
	m_iPaddingTop = 5;
	m_iPaddingBottom = 5;
	m_iTextAlign = TextAlign_Left;
	m_bBigStyle = true;
	m_bShowPlayState = false;

 	m_iPlayButtonSate = Button_Play;

	m_iButtonSateColor = QColor(255, 255, 255);

	m_bShowIcon = false;
	m_iIconSpace = 10;
	m_iIconSize = QSize(16, 16);
	m_iIconNormal = QPixmap();
	m_iIconHover = QPixmap();
	m_iIconCheck = QPixmap();

	m_bShowLine = false;
	m_iLineSpace = 0;
	m_iLineWidth = 5;
	m_iLinePosition = LinePosition_Left;
	m_iLineColor = QColor(0, 187, 158);

	m_iNormalFrameColor = QColor(50, 50, 50);
	m_iNormalBkColor   = QColor(50, 50, 50);

	m_iHoverBgColor = QColor(130, 130, 130);
	m_iCheckBgColor = QColor(80, 80, 80);
	
	m_iNormalTextColor = QColor(100, 100, 100);
	m_iHoverTextColor = QColor(255, 255, 255);
	m_iCheckTextColor = QColor(255, 255, 255);

	m_iNormalBgBrush = Qt::NoBrush;
	m_iHoverBgBrush = Qt::NoBrush;
	m_iCheckBgBrush = Qt::NoBrush;

	m_bHover = false;
	setCheckable(true);
 }

void ButtonEx::enterEvent(QEvent *)
{
	m_bHover = true;
	update();
}

void ButtonEx::leaveEvent(QEvent *)
{
	m_bHover = false;
	update();
}

void ButtonEx::mousePressEvent(QMouseEvent * pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		emit clicked();
		pEvent->accept();
	}
}

void ButtonEx::mouseReleaseEvent(QMouseEvent *pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		int i = 0;
	}
}

void ButtonEx::paintEvent(QPaintEvent *)
{
	//����׼������,���÷����
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

// 	//���Ʊ���
  	drawBg(&painter);
// 	//��������
  	drawText(&painter);
// 	//����ͼ��
  	drawIcon(&painter);
	//���Ʊ߿�����
	drawLine(&painter);
	drawButtonState(&painter);
}


void ButtonEx::drawBg(QPainter *painter)
{
	painter->save();
	painter->setPen(Qt::NoPen);

	int width	= this->width();
	int height	= this->height();

	QRect bgRect;
	QRect bgRect2;
	 
	if (m_iLinePosition == LinePosition_Left)
	{
		bgRect = QRect(m_iLineSpace, 0, width - m_iLineSpace, height);
	}
	else if (m_iLinePosition == LinePosition_Right)
	{
		bgRect = QRect(0, 0, width - m_iLineSpace, height);
	}
	else if (m_iLinePosition == LinePosition_Top)
	{
		bgRect = QRect(0, m_iLineSpace, width, height - m_iLineSpace);
	}
	else if (m_iLinePosition == LinePosition_Bottom)
	{
		bgRect = QRect(0, 0, width, height - m_iLineSpace);
	}

	bgRect2 = bgRect;

	bgRect2.adjust(1, 1, -1, -1);

	//�����ˢ������ȡ��ˢ
	QBrush bgBrush;
	if (isChecked())
	{
		bgBrush = m_iCheckBgBrush;
	}
	else if (m_bHover)
	{
		bgBrush = m_iHoverBgBrush;
	}
	else
	{
		bgBrush = m_iNormalBgBrush;
	}

	if (bgBrush != Qt::NoBrush) 
	{
		painter->setBrush(bgBrush);
	}
	else
	{
		//���ݵ�ǰ״̬ѡ���Ӧ��ɫ
		QColor bgColor;
		if (isChecked())
		{
			bgColor = m_iCheckBgColor;
		}
		else if (m_bHover)
		{
			bgColor = m_iHoverBgColor;
		}
		else
		{
			bgColor = m_iNormalFrameColor;
		}

		painter->setBrush(bgColor);
	}


	painter->drawRect(bgRect);
	 
	if (isChecked())
	{
		painter->setBrush(m_iCheckBgColor);
 	}
	else
	{
		painter->setBrush(m_iNormalBkColor);
 	}

	painter->drawRect(bgRect2);

	painter->restore();
}

void ButtonEx::drawText(QPainter *painter)
{
	painter->save();
	painter->setBrush(Qt::NoBrush);

	//���ݵ�ǰ״̬ѡ���Ӧ��ɫ
	QColor textColor;
	if (isChecked())
	{
		textColor = m_iCheckTextColor;
	}
	else if (m_bHover)
	{
		textColor = m_iHoverTextColor;
	}
	else
	{
		textColor = m_iNormalTextColor;
	}

	QRect textRect = QRect(m_iPaddingLeft, m_iPaddingTop, width() - m_iPaddingLeft - m_iPaddingRight, height() - m_iPaddingTop - m_iPaddingBottom);
	painter->setPen(textColor);
	painter->drawText(textRect, m_iTextAlign | Qt::AlignVCenter, text());

	painter->restore();
}

void ButtonEx::drawIcon(QPainter *painter)
{
	if (!m_bShowIcon)
		return;

	painter->save();

	QPixmap pix;

	if (isChecked())
	{
		pix = m_iIconCheck;
	}
	else if (m_bHover)
	{
		pix = m_iIconHover;
	}
	else
	{
		pix = m_iIconNormal;
	}

	if (!pix.isNull())
	{
		//�ȱ���ƽ������ͼ��
		pix = pix.scaled(m_iIconSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
		painter->drawPixmap(m_iIconSpace, (height() - m_iIconSize.height()) / 2, pix);
	}

	painter->restore();
}

void ButtonEx::drawLine(QPainter *painter)
{
	if (!m_bShowLine)
		return;

	if (!isChecked())
		return;

	painter->save();

	QPen pen;
	pen.setWidth(m_iLineWidth);
	pen.setColor(m_iLineColor);
	painter->setPen(pen);

	//��������λ��������������
	QPoint pointStart, pointEnd;
	if (m_iLinePosition == LinePosition_Left)
	{
		pointStart = QPoint(0, 0);
		pointEnd = QPoint(0, height());
	}
	else if (m_iLinePosition == LinePosition_Right)
	{
		pointStart = QPoint(width(), 0);
		pointEnd = QPoint(width(), height());
	}
	else if (m_iLinePosition == LinePosition_Top)
	{
		pointStart = QPoint(0, 0);
		pointEnd = QPoint(width(), 0);
	}
	else if (m_iLinePosition == LinePosition_Bottom)
	{
		pointStart = QPoint(0, height());
		pointEnd = QPoint(width(), height());
	}

	painter->drawLine(pointStart, pointEnd);

	painter->restore();
}

void ButtonEx::drawButtonState(QPainter *painter)
{
	if (!m_bShowPlayState)
		return;

	////ѡ�л�����ͣ��ʾ
	//if (!m_bHover && !isChecked())
	//	return;

	painter->save();
	painter->setPen(Qt::NoPen);

	if (m_bHover)
	{
		painter->setBrush(QColor(255,255, 255));
 	} 
	else
	{
		painter->setBrush(m_iButtonSateColor);
 	}

	//�������Ҳ��м�,�����趨�ĵ����ǵı߳��趨������λ��
	int width = this->width();
	int height = this->height();
	int midWidth = width / 2;
	int midHeight = height / 2;

	int iPrev = width / GAP_COUNT;
	
	QPolygon pts;


	if (m_bBigStyle)
	{
		if (m_iPlayButtonSate == Button_Pause)
		{
			painter->drawRect(width / 4, height / 4, width / 8, height / 2);
			painter->drawRect(width / 2, height / 4, width / 8, height / 2);
		}
		else if (m_iPlayButtonSate == Button_Play)
		{
			pts.setPoints(3, 25, midHeight, width / 4, midHeight - 10, width / 4, midHeight + 10);
			painter->drawPolygon(pts);
		}
		else if (m_iPlayButtonSate == Button_Stop)
		{
			painter->drawRect(iPrev * 2, iPrev * 2, iPrev*(GAP_COUNT - 4), iPrev*(GAP_COUNT - 4)); //x,y,w,h
		}
		else if (m_iPlayButtonSate == Button_Prev)
		{
			painter->drawRect(width / 4, height / 4, width / 8, height / 2);

			pts.setPoints(3, width - 23, midHeight, width - 10, midHeight - 10, width - 10, midHeight + 10);

			painter->drawPolygon(pts);
		}
		else if (m_iPlayButtonSate == Button_Next)
		{
			painter->drawRect(iPrev*(GAP_COUNT - 3), height / 4, iPrev, height / 2);
			pts.setPoints(3, iPrev*(GAP_COUNT - 3), midHeight, 10, midHeight - 10, 10, midHeight + 10);

			painter->drawPolygon(pts);
		}

	} 
	else
	{
 		if (m_iPlayButtonSate == Button_Pause)
		{
			painter->drawRect(width / 4, height / 4, width / 8, height / 2);
			painter->drawRect(width / 2, height / 4, width / 8, height / 2);
		}
		else if (m_iPlayButtonSate == Button_Play)
		{
			pts.setPoints(3, 14, midHeight, width / 4, midHeight - 6, width / 4, midHeight + 6);
			painter->drawPolygon(pts);
		}
		else if (m_iPlayButtonSate == Button_Arrow_Down)
		{
			pts.setPoints(3, midWidth, 16, midWidth - 6, 6, midWidth + 6, 6);
			painter->drawPolygon(pts);
		}
		else if (m_iPlayButtonSate == Button_Arrow_Right)
		{
			pts.setPoints(3, 14, midHeight, width / 4, midHeight - 6, width / 4, midHeight + 6);
			painter->drawPolygon(pts);
		}
		else if (m_iPlayButtonSate == Button_Stop)
		{
			painter->drawRect(iPrev * 2, iPrev * 2, iPrev*(GAP_COUNT - 4), iPrev*(GAP_COUNT - 4)); //x,y,w,h
		}
		else if (m_iPlayButtonSate == Button_Prev)
		{
			painter->drawRect(width / 4, height / 4, width / 8, height / 2);

			pts.setPoints(3, width - 15, midHeight, width - 6, midHeight - 6, width - 6, midHeight + 6);

			painter->drawPolygon(pts);
		}
		else if (m_iPlayButtonSate == Button_Next)
		{
			painter->drawRect(iPrev*(GAP_COUNT - 3) + 2, height / 4, width / 8, height / 2);
			pts.setPoints(3, iPrev*(GAP_COUNT - 3) + 2, midHeight, 6, midHeight - 6, 6, midHeight + 6);
			painter->drawPolygon(pts);
		}

	}
	 
	painter->restore();
}


bool ButtonEx::getBigStyle() const
{
	return m_bBigStyle;
}


void ButtonEx::setBigStyle(bool bBigStyle)
{
	m_bBigStyle = bBigStyle;
}

int ButtonEx::getPaddingLeft() const
{
	return this->m_iPaddingLeft;
}

int ButtonEx::getPaddingRight() const
{
	return this->m_iPaddingRight;
}

int ButtonEx::getPaddingTop() const
{
	return this->m_iPaddingTop;
}

int ButtonEx::getPaddingBottom() const
{
	return this->m_iPaddingBottom;
}

ButtonEx::TextAlign ButtonEx::getTextAlign() const
{
	return this->m_iTextAlign;
}

bool ButtonEx::getShowPlayButtonState() const
{
	return  m_bShowPlayState;
}
 
ButtonEx::PlayBttonState ButtonEx::getPlayButtonState()const
 {
	return m_iPlayButtonSate;
}
 
QColor ButtonEx::getButtonStateColor() const
 {
	return  m_iButtonSateColor;
}

bool ButtonEx::getShowIcon() const

{
	return this->m_bShowIcon;
}
int ButtonEx::getIconSpace() const

{
	return this->m_iIconSpace;
}
QSize ButtonEx::getIconSize() const

{
	return this->m_iIconSize;
}
QPixmap ButtonEx::getIconNormal() const

{
	return this->m_iIconNormal;
}
QPixmap ButtonEx::getIconHover() const

{
	return this->m_iIconHover;
}
QPixmap ButtonEx::getIconCheck() const
 {
	return this->m_iIconCheck;
}
bool ButtonEx::getShowLine() const

{
	return this->m_bShowLine;
}
int ButtonEx::getLineSpace() const

{
	return this->m_iLineSpace;
}
int ButtonEx::getLineWidth() const

{
	return this->m_iLineWidth;
}
ButtonEx::LinePosition ButtonEx::getLinePosition() const

{
	return this->m_iLinePosition;
}
QColor ButtonEx::getLineColor() const

{
	return this->m_iLineColor;
}
QColor ButtonEx::getNormalBgColor() const
{
	return m_iNormalFrameColor;
}

QColor ButtonEx::getHoverBgColor() const

{
	return this->m_iHoverBgColor;
}
QColor ButtonEx::getCheckBgColor() const

{
	return this->m_iCheckBgColor;
}
QColor ButtonEx::getNormalTextColor() const

{
	return this->m_iNormalTextColor;
}
QColor ButtonEx::getHoverTextColor() const

{
	return this->m_iHoverTextColor;
}
QColor ButtonEx::getCheckTextColor() const

{
	return this->m_iCheckTextColor;
}
QSize ButtonEx::sizeHint() const

{
	return QSize(100, 30);
}
QSize ButtonEx::minimumSizeHint() const

{
	return QSize(20, 10);
}

//�������ּ��
void ButtonEx::setPaddingLeft(int iPaddingLeft)
{
	if (this->m_iPaddingLeft != iPaddingLeft)
	{
		this->m_iPaddingLeft = iPaddingLeft;
		update();
	}
}
void ButtonEx::setPaddingRight(int iPaddingRight)

{
	if (this->m_iPaddingRight != iPaddingRight)
	{
		this->m_iPaddingRight = iPaddingRight;
		update();
	}
}
void ButtonEx::setPaddingTop(int iPaddingTop)

{
	if (this->m_iPaddingTop != iPaddingTop)
	{
		this->m_iPaddingTop = iPaddingTop;
		update();
	}
}
void ButtonEx::setPaddingBottom(int iPaddingBottom)
 {
	if (this->m_iPaddingBottom != iPaddingBottom)
	{
		this->m_iPaddingBottom = iPaddingBottom;
		update();
	}
}

void ButtonEx::setPadding(int iPadding)
{
	setPadding(iPadding, iPadding, iPadding, iPadding);
}

void ButtonEx::setPadding(int iPaddingLeft, int iPaddingRight, int iPaddingTop, int iPaddingBottom)
{
	this->m_iPaddingLeft = iPaddingLeft;
	this->m_iPaddingRight = iPaddingRight;
	this->m_iPaddingTop = iPaddingTop;
	this->m_iPaddingBottom = iPaddingBottom;
	update();
}

//�������ֶ���
void ButtonEx::setTextAlign(const TextAlign& iTextAlign)
{
	if (this->m_iTextAlign != iTextAlign)
	{
		this->m_iTextAlign = iTextAlign;
		update();
	}
}

//������ʾ������
void ButtonEx::setShowPlayButtonState(bool bShowTriangle)
 {
	if (m_bShowPlayState != bShowTriangle)
	{
		m_bShowPlayState = bShowTriangle;
		update();
	}
}
 

//���õ�����λ��
void ButtonEx::setShowPlayButtonState(const PlayBttonState& iTrianglePosition)
 {
	if (m_iPlayButtonSate != iTrianglePosition)
	{
		m_iPlayButtonSate = iTrianglePosition;
		update();
	}
}

// ���ò��Ű�ť״̬��ɫ
void ButtonEx::setButtonStateColor(const QColor& iTriangleColor)
{
	if (m_iButtonSateColor != iTriangleColor)
	{
		m_iButtonSateColor = iTriangleColor;
		update();
	}
}

//������ʾͼ��
void ButtonEx::setShowIcon(bool bShowIcon)
{
	if (this->m_bShowIcon != bShowIcon)
	{
		this->m_bShowIcon = bShowIcon;
		update();
	}
}

//����ͼ����
void ButtonEx::setIconSpace(int iIconSpace)
{
	if (this->m_iIconSpace != iIconSpace)
	{
		this->m_iIconSpace = iIconSpace;
		update();
	}
}

//����ͼ��ߴ�
void ButtonEx::setIconSize(const QSize& iIconSize)
{
	if (this->m_iIconSize != iIconSize)
	{
		this->m_iIconSize = iIconSize;
		update();
	}
}

//��������ͼ��
void ButtonEx::setIconNormal(const QPixmap &iIconNormal)
{
	this->m_iIconNormal = iIconNormal;
	update();
}

//������ͣͼ��
void ButtonEx::setIconHover(const QPixmap &iIconHover)
{
	this->m_iIconHover = iIconHover;
	update();
}

//���ð���ͼ��
void ButtonEx::setIconCheck(const QPixmap &iIconCheck)
{
	this->m_iIconCheck = iIconCheck;
	update();
}

//������ʾ����
void ButtonEx::setShowLine(bool bShowLine)
{
	if (this->m_bShowLine != bShowLine)
	{
		this->m_bShowLine = bShowLine;
		update();
	}
}

//�����������
void ButtonEx::setLineSpace(int iLineSpace)
{
	if (this->m_iLineSpace != iLineSpace)
	{
		this->m_iLineSpace = iLineSpace;
		update();
	}
}

//�����������
void ButtonEx::setLineWidth(int iLineWidth)
{
	if (this->m_iLineWidth != iLineWidth)
	{
		this->m_iLineWidth = iLineWidth;
		update();
	}
}

//��������λ��
void ButtonEx::setLinePosition(const ButtonEx::LinePosition &iLinePosition)
{
	if (this->m_iLinePosition != iLinePosition)
	{
		this->m_iLinePosition = iLinePosition;
		update();
	}
}

//����������ɫ
void ButtonEx::setLineColor(const QColor &iLineColor)
{
	if (m_iLineColor != iLineColor)
	{
		m_iLineColor = iLineColor;
		update();
	}
}

//��������������ɫ
void ButtonEx::setNormalBgColor(const QColor &iNormalBkColor)
{
	if (m_iNormalBkColor != iNormalBkColor)
	{
		m_iNormalBkColor = iNormalBkColor;
		update();
	}
}

void ButtonEx::setNormalFrameColor(const QColor &iNormalFrameColor)
{
	if (m_iNormalFrameColor != iNormalFrameColor)
	{
		m_iNormalFrameColor = iNormalFrameColor;
		update();
	}
}


//������ͣ������ɫ
void ButtonEx::setHoverBgColor(const QColor &iHoverBgColor)
{
	if (this->m_iHoverBgColor != iHoverBgColor)
	{
		this->m_iHoverBgColor = iHoverBgColor;
		update();
	}
}

//����ѡ�б�����ɫ
void ButtonEx::setCheckBgColor(const QColor &iCheckBgColor)
{
	if (m_iCheckBgColor != iCheckBgColor)
	{
		m_iCheckBgColor = iCheckBgColor;
		update();
	}
}

//��������������ɫ
void ButtonEx::setNormalTextColor(const QColor & iNormalTextColor)
{
	if (this->m_iNormalTextColor != iNormalTextColor)
	{
		this->m_iNormalTextColor = iNormalTextColor;
		update();
	}
}

//������ͣ������ɫ
void ButtonEx::setHoverTextColor(const QColor &iHoverTextColor)
{
	if (this->m_iHoverTextColor != iHoverTextColor)
	{
		this->m_iHoverTextColor = iHoverTextColor;
		update();
	}
}

//����ѡ��������ɫ
void ButtonEx::setCheckTextColor(const QColor &iCheckTextColor)
{
	if (this->m_iCheckTextColor != iCheckTextColor)
	{
		this->m_iCheckTextColor = iCheckTextColor;
		update();
	}
}

//��������������ˢ
void ButtonEx::setNormalBgBrush(const QBrush &iNormalBgBrush)
{
	if (this->m_iNormalBgBrush != iNormalBgBrush)
	{
		this->m_iNormalBgBrush = iNormalBgBrush;
		update();
	}
}

//������ͣ������ˢ
void ButtonEx::setHoverBgBrush(const QBrush &iHoverBgBrush)
{
	if (this->m_iHoverBgBrush != iHoverBgBrush)
	{
		this->m_iHoverBgBrush = iHoverBgBrush;
		update();
	}
}

//����ѡ�б�����ˢ
void ButtonEx::setCheckBgBrush(const QBrush &iCheckBgBrush)
 {
	if (this->m_iCheckBgBrush != iCheckBgBrush)
	{
		this->m_iCheckBgBrush = iCheckBgBrush;
		update();
	}
}
