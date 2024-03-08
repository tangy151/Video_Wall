#include "comboboxex.h"
 #include "../headfiledefine.h"


ComboBoxEx::ComboBoxEx(QWidget *parent) 
	: QComboBox(parent)
{
	m_iItemWidth = 5;
	m_iItemHeight = 20;
	 
	m_bAutoWidth = true;
	this->setView(new QListView());
}

void ComboBoxEx::showEvent(QShowEvent *)
{
	if (m_bAutoWidth) 
	{
		//自动计算所有元素,找到最长的元素
		QFontMetrics fm = this->fontMetrics();
		int count = this->count();
		
		for (int i = 0; i < count; i++) 
		{
			int textWidth = fm.width(this->itemText(i));
			m_iItemWidth = textWidth > m_iItemWidth ? textWidth : m_iItemWidth;
		}

		//宽度增加像素,因为有边距
		this->view()->setFixedWidth(m_iItemWidth + 20);
	}
}

int ComboBoxEx::getItemWidth() const
{
	return this->m_iItemWidth;
}

int ComboBoxEx::getItemHeight() const
{
	return this->m_iItemHeight;
}

bool ComboBoxEx::getAutoWidth() const
{
	return this->m_bAutoWidth;
}

void ComboBoxEx::setItemWidth(int m_iItemWidth)
{
	if (this->m_iItemWidth != m_iItemWidth) 
	{
		this->m_iItemWidth = m_iItemWidth;

		if (!m_bAutoWidth) 
 			this->view()->setFixedWidth(m_iItemWidth);
 	}
}

void ComboBoxEx::setItemHeight(int m_iItemHeight)
{
	if (this->m_iItemHeight != m_iItemHeight) 
	{
		this->m_iItemHeight = m_iItemHeight;
		this->setStyleSheet(QString("QComboBox QAbstractItemView::item{min-height:%1px;}").arg(m_iItemHeight));
	}
}

void ComboBoxEx::setAutoWidth(bool m_bAutoWidth)
{
	if (this->m_bAutoWidth != m_bAutoWidth) 
 		this->m_bAutoWidth = m_bAutoWidth;
 }
