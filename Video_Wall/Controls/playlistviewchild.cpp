#include "playlistviewchild.h"
#include "../headfiledefine.h"

PlayListViewChild::PlayListViewChild(QWidget *parent)
	: QWidget(parent)
{
	m_iNormalTextColor = QColor(200,200,200);
	m_iCheckTextColor = QColor(239, 98, 234);
	m_bLeftBtnDown = false;
	m_bEntered = false;
	m_strExePath = QCoreApplication::applicationDirPath();
}

PlayListViewChild::~PlayListViewChild()
{
}

void PlayListViewChild::mousePressEvent(QMouseEvent *pEvent)
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
void PlayListViewChild::SetLeftBtnDown(bool b)
{
	m_bLeftBtnDown = b;
	update();
}
void PlayListViewChild::enterEvent(QEvent *pEvent)
{
	m_bEntered = true;
	update();

	QWidget::enterEvent(pEvent);
}

void PlayListViewChild::leaveEvent(QEvent *pEvent)
{
	m_bEntered = false;
	update();
	QWidget::leaveEvent(pEvent);
}

void PlayListViewChild::paintEvent(QPaintEvent *pEvent)
{
	QPainter painter(this);
//   	painter.setRenderHint(QPainter::Antialiasing, true);
//   	painter.fillRect(this->rect(), m_bEntered ? QColor(120,0,0) : QColor("transparent"));

	int w = this->rect().width();
	int h = this->rect().height();

#if  PIX_1080p
	QFont font("Î¢ÈíÑÅºÚ", 12, 65);
 #else
	QFont font("Î¢ÈíÑÅºÚ", 7, 65);
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
	font.setPixelSize(12);
	painter.setPen(pen);
	painter.setFont(font);
	painter.drawText(10, 4, w/2, h  - 2, Qt::AlignLeft, m_pPlayListItemEx->m_strFileName);

	
	// »æÖÆsubtitile
// 	pen.setColor(m_iNormalTextColor);
	font.setPixelSize(12);
	painter.setPen(pen);
	painter.setFont(font);
	painter.drawText(w - 70,  4, w  , h  , Qt::AlignLeft, m_pPlayListItemEx->m_strTotalName);
}
