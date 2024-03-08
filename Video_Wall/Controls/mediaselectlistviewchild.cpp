#include "mediaselectlistviewchild.h"

#include "../headfiledefine.h"
#include "../globaldefine.h"

MediaSelectListViewChild::MediaSelectListViewChild(QWidget *parent)
	: QWidget(parent)
{
#if  PIX_1080p
	m_iNormalTextColor = QColor(180, 180, 180);
 #else
	m_iNormalTextColor = QColor(180, 180, 180);
 #endif

	m_iCheckTextColor = QColor(239, 98, 234);
	m_bLeftBtnDown = false;
	m_bEntered = false;
	m_strExePath = QCoreApplication::applicationDirPath();
}
 
void MediaSelectListViewChild::mousePressEvent(QMouseEvent *pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		m_bLeftBtnDown = true;
		emit onChildSelected(this);
		update();
	}
	else if (Qt::RightButton == pEvent->button())
	{
	}
}
void MediaSelectListViewChild::SetLeftBtnDown(bool b)
{
	m_bLeftBtnDown = b;
	update();
}
void MediaSelectListViewChild::enterEvent(QEvent *pEvent)
{
	m_bEntered = true;
	update();

	QWidget::enterEvent(pEvent);
}

void MediaSelectListViewChild::leaveEvent(QEvent *pEvent)
{
	m_bEntered = false;
	update();
	QWidget::leaveEvent(pEvent);
}

void MediaSelectListViewChild::paintEvent(QPaintEvent *pEvent)
{
	QPainter painter(this);
 
	/*painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(30, 130, 30));
	painter.setPen(QColor(210, 210, 210));
	painter.save();
	painter.setBrush(Qt::NoBrush);*/
	 
	int w = this->rect().width();
	int h = this->rect().height();

#if PIX_1080p 
	QFont font("Î¢ÈíÑÅºÚ", 20, 65);
	//font.setPixelSize(20);
 #else
	QFont font("Î¢ÈíÑÅºÚ", 8, 65);
	//font.setPixelSize(10);
 #endif


	QPen pen;

	if (m_bLeftBtnDown)
	{
		pen.setColor(m_iCheckTextColor);
	}
	else
	{
		pen.setColor(m_iNormalTextColor);
 	}

	// »æÖÆÃû×Ö
// 	pen.setColor(m_iNormalTextColor);

	painter.setPen(pen);
	painter.setFont(font);

#if  PIX_1080p
	painter.drawText(10, 1, w, h - 1, Qt::AlignLeft, m_pPlayListItemEx->m_strFileName);
 #else
	painter.drawText(5, 1, w, h - 1, Qt::AlignLeft, m_pPlayListItemEx->m_strFileName);
 #endif


	// »æÖÆsubtitile
// 	pen.setColor(m_iNormalTextColor);
// 	font.setPixelSize(12);
// 	painter.setPen(pen);
// 	painter.setFont(font);
// 	painter.drawText(w - 70, 4, w, h, Qt::AlignLeft, m_pPlayListItemEx->m_strTotalName);
}
