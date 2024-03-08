#include "navlabelex.h"
#include "../headfiledefine.h"

NavLabelEx::NavLabelEx(QWidget *parent)
	: QLabel(parent)
{
	m_iPaddingLeft		= 5;
	m_iPaddingRight		= 5;
	m_iPaddingTop		= 5;
	m_iPaddingBottom	= 5;

	m_iTextAlign = TextAlign_Left;

	m_bShowIcon = false;
 

	m_iIconLeftSpace = 5;
	m_iIconTopSpace = 5;

	m_iIconSize = QSize(0, 0);
	m_iIconNormal = QPixmap();

	m_iTextLeft = m_iPaddingLeft + m_iIconSize.width();

	m_iNormalBgBrush = Qt::NoBrush;

	m_iNormalTextColor = QColor(100, 100, 100);
	m_iNormalBgColor	= QColor(0, 0, 0);
}

void NavLabelEx::paintEvent(QPaintEvent *)
{
	//绘制准备工作,启用反锯齿
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

	//绘制背景
	drawBg(&painter);
	
	//绘制图标
	drawIcon(&painter);
	 
	//绘制文字
	drawText(&painter);
 }

void NavLabelEx::drawBg(QPainter *painter)
{
	painter->save();
	painter->setPen(Qt::NoPen);

	int width = this->width();
	int height = this->height();

	QRect bgRect;

	bgRect = QRect(0, 0, width  , height);
	painter->setBrush(m_iNormalBgColor);
	//painter->setBrush(QColor(120,24,89));

 	painter->drawRect(bgRect);
 	painter->restore();
}

void NavLabelEx::drawText(QPainter *painter)
 {
	painter->save();
	painter->setBrush(Qt::NoBrush);

	//根据当前状态选择对应颜色
	QColor textColor;

	textColor = m_iNormalTextColor;


// 	QRect textRect = QRect(m_iPaddingLeft, m_iPaddingTop, width() - m_iPaddingLeft - m_iPaddingRight, height() - m_iPaddingTop - m_iPaddingBottom);
// 	

	QRect textRect = QRect(m_iTextLeft, m_iPaddingTop, width() - m_iPaddingLeft - m_iPaddingRight,
		height() - m_iPaddingTop - m_iPaddingBottom);

	painter->setPen(textColor);
	painter->drawText(textRect, m_iTextAlign | Qt::AlignVCenter, text());

	painter->restore();
}
void NavLabelEx::drawIcon(QPainter *painter)
{
	int iWidth = height();
	int iHeight = width();

	if (!m_bShowIcon)
		return;

	painter->save();

	QPixmap pix;

	pix = m_iIconNormal;

	if (!pix.isNull()) 
	{
		//等比例平滑缩放图标
		pix = pix.scaled(m_iIconSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  		painter->drawPixmap(m_iIconLeftSpace, m_iIconTopSpace, pix);
 	}

	m_iTextLeft = m_iIconLeftSpace + m_iIconSize.width() + m_iPaddingLeft;

	painter->restore();
}

int NavLabelEx::getPaddingLeft()	const
{
	return  m_iPaddingLeft;
}

int NavLabelEx::getPaddingRight()	const
{
	return  m_iPaddingRight;
}

int NavLabelEx::getPaddingTop()	const 
{
	return m_iPaddingTop;

}
int NavLabelEx::getPaddingBottom()	const 
{
	return m_iPaddingBottom;
}

NavLabelEx::TextAlign NavLabelEx::getTextAlign()	const
{
	return m_iTextAlign;
}

bool NavLabelEx::getShowIcon()	const
{
	return m_bShowIcon;
}

int NavLabelEx::getIconLeftSpace()	const
{
	return m_iIconLeftSpace;
}
int NavLabelEx::getIconTopSpace()	const
{
	return m_iIconTopSpace;
}
 

QSize NavLabelEx::getIconSize()	const
{
	return m_iIconSize;
}

QPixmap NavLabelEx::getIconNormal()	const
{
	return this->m_iIconNormal;
}
void NavLabelEx::setShowIcon(bool showIcon)
{
	if (m_bShowIcon != showIcon)
	{
		m_bShowIcon = showIcon;
		update();
	}

}
void NavLabelEx::setIconLeftSpace(int iconSpace)
{
	if ( m_iIconLeftSpace != iconSpace)
	{
		m_iIconLeftSpace = iconSpace;
		update();
	}
 }

void NavLabelEx::setIconTopSpace(int iconSpace) 
{
	if (m_iIconTopSpace != iconSpace)
	{
		m_iIconTopSpace = iconSpace;
		update();
	}
}
  

void NavLabelEx::setIconSize(const QSize &iconSize)
{
	if (m_iIconSize != iconSize)
	{
		m_iIconSize = iconSize;
		update();
	}
}

void NavLabelEx::setIconNormal(const QPixmap &iconNormal) 
{
	this->m_iIconNormal = iconNormal;
	update();
}

QColor NavLabelEx::getNormalBgColor()	const
{
	return m_iNormalBgColor;
 }

void NavLabelEx::setNormalTextColor(const QColor &normalTextColor)
{
	if (m_iNormalTextColor != normalTextColor) 
	{
		m_iNormalTextColor = normalTextColor;
		update();
	}
 }

QColor NavLabelEx::getNormalTextColor()         const
{
	return  m_iNormalTextColor;
}

//设置文字对齐
void NavLabelEx::setTextAlign(const NavLabelEx::TextAlign &textAlign)
{
	if (m_iTextAlign != textAlign) 
	{
		m_iTextAlign = textAlign;
		update();
	}
 }

//设置正常背景颜色
void NavLabelEx::setNormalBgColor(const QColor &normalBgColor)
{
	if (m_iNormalBgColor != normalBgColor)
	{
		m_iNormalBgColor = normalBgColor;
		update();
	}

}
void NavLabelEx::setPaddingLeft(int paddingLeft)
{
	if (m_iPaddingLeft != paddingLeft)
	{
		m_iPaddingLeft = paddingLeft;
		update();
	}
}

void NavLabelEx::setPaddingRight(int paddingRight)
{
	if (m_iPaddingRight != paddingRight) 
	{
		m_iPaddingRight = paddingRight;
		update();
	}
}

void NavLabelEx::setPaddingTop(int paddingTop)
{
	if (m_iPaddingTop != paddingTop) 
	{
		m_iPaddingTop = paddingTop;
		update();
	}
}

void NavLabelEx::setPaddingBottom(int paddingBottom)
{
	if (m_iPaddingBottom != paddingBottom)
	{
		m_iPaddingBottom = paddingBottom;
		update();
	}

}
void NavLabelEx::setPadding(int padding)
{
	setPadding(padding, padding, padding, padding);

}
void NavLabelEx::setPadding(int paddingLeft, int paddingRight, int paddingTop, int paddingBottom)
{
	m_iPaddingLeft = paddingLeft;
	m_iPaddingRight = paddingRight;
	m_iPaddingTop = paddingTop;
	m_iPaddingBottom = paddingBottom;


	update();
}
