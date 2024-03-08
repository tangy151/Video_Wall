#include "localstreamlistviewchild.h"
#include "../headfiledefine.h"

LocalStreamListViewChild::LocalStreamListViewChild(QWidget *parent)
	: QWidget(parent)
{
	m_iNormalTextColor = QColor(200, 200, 200);
	m_iCheckTextColor = QColor(239, 98, 234);
	m_bLeftBtnDown = false;
	m_bEntered = false;
	m_strExePath = QCoreApplication::applicationDirPath();
}

LocalStreamListViewChild::~LocalStreamListViewChild()
{
}

void LocalStreamListViewChild::mousePressEvent(QMouseEvent *pEvent)
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
void LocalStreamListViewChild::enterEvent(QEvent *pEvent)
 {
	m_bEntered = true;
	update();

	QWidget::enterEvent(pEvent);
}

void LocalStreamListViewChild::leaveEvent(QEvent *pEvent)
 {
	m_bEntered = false;
	update();
	QWidget::leaveEvent(pEvent);
}
 
void LocalStreamListViewChild::paintEvent(QPaintEvent *pEvent)
 {
	QPainter painter(this);
	//   	painter.setRenderHint(QPainter::Antialiasing, true);
	//   	painter.fillRect(this->rect(), m_bEntered ? QColor(120,0,0) : QColor("transparent"));

	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(30, 30, 30));
	painter.setPen(QColor(210, 210, 210));
	painter.save();
	painter.setBrush(Qt::NoBrush);


	int w = this->rect().width();
	int h = this->rect().height();

	QFont font("Î¢ÈíÑÅºÚ", 12, 75);
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
 	font.setPixelSize(12);
	painter.setPen(pen);
	painter.setFont(font);
	painter.drawText(15, 5, w -10, h - 2, Qt::AlignLeft, m_pLocalStreamListItemEx->m_strItemName);
 }

void LocalStreamListViewChild::SetLeftBtnDown(bool b)
{
	m_bLeftBtnDown = b;
	update();
}


