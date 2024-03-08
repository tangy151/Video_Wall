#include "ipaddresslineedit.h"
 #include "../headfiledefine.h"


IPAddressLineEdit::IPAddressLineEdit(QWidget *parent)
	: QLineEdit(parent)
{
	m_pNextTab		= nullptr;
	m_pPrevTab		= nullptr;

	this->setMaxLength(3);
	this->setFrame(false);
	this->setAlignment(Qt::AlignCenter);

	QValidator* pValidator = new QIntValidator(0, 255, this);
	this->setValidator(pValidator);

	connect(this, SIGNAL(textEdited(const QString&)), this, SLOT(text_edited(const QString&)));
}
 
IPAddressLineEdit::~IPAddressLineEdit()
{
}

void IPAddressLineEdit::set_prevtab_edit(QLineEdit* pCurrentTab, QLineEdit* pPrevTab) 
{
	m_pCurrentTab = pCurrentTab;
	m_pPrevTab = pPrevTab;
}

void IPAddressLineEdit::set_nexttab_edit(QLineEdit* pCurrentTab, QLineEdit* pNextTab)
{
	m_pCurrentTab = pCurrentTab;
	m_pNextTab = pNextTab;
}

 
void IPAddressLineEdit::focusInEvent(QFocusEvent* pEvent)
{
	this->selectAll();
	QLineEdit::focusInEvent(pEvent);
 }

void IPAddressLineEdit::keyPressEvent(QKeyEvent* pEvent)
{
	if (pEvent->key() == Qt::Key_Period)
	{
		QString  strCurrentTab = m_pCurrentTab->text();
		 
		if (m_pNextTab && (!strCurrentTab.isEmpty()))
		{
			m_pNextTab->setFocus();
			m_pNextTab->selectAll();
		}
	}
	else if (pEvent->key() == Qt::Key_Backspace)
	{
		QString strCurrentTab = m_pCurrentTab->text();
		if (m_pPrevTab && (strCurrentTab.isEmpty()))
		{
			m_pPrevTab->setFocus();
			m_pPrevTab->selectAll();
		}
	}
	 
	QLineEdit::keyPressEvent(pEvent);
 }

void IPAddressLineEdit::text_edited(const QString& strText)
{
	QIntValidator v(0, 255, this);
	QString strIPAddr = strText;

	int  iPos = 0;
	
	QValidator::State iState = v.validate(strIPAddr, iPos);

	if (iState == QValidator::Acceptable)
	{
		if (strIPAddr.size() > 1)
		{
			if (strIPAddr.size() == 2)
			{
				int ipnum = strIPAddr.toInt();

				if (ipnum > 25)
				{
					if (m_pNextTab)
					{
						m_pNextTab->setFocus();
						m_pNextTab->selectAll();
					}
				}
			}
			else
			{
				if (m_pNextTab)
				{
					m_pNextTab->setFocus();
					m_pNextTab->selectAll();
				}
			}
		}
	}
}

