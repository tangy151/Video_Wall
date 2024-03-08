#include "ipaddressedit.h"

#include "../headfiledefine.h"
 #include "ipaddresslineedit.h"
#include "qjsondocument.h"

IPAddressEdit::IPAddressEdit(QWidget *parent)
	: QWidget(parent)
{
	QFont font("Microsoft Yahei", 10);
	  
	m_pIPPart1 = new IPAddressLineEdit(this);
	m_pIPPart2 = new IPAddressLineEdit(this);
	m_pIPPart3 = new IPAddressLineEdit(this);
	m_pIPPart4 = new IPAddressLineEdit(this);
	 
	m_pLabeldot1 = new QLabel(this);
	m_pLabeldot2 = new QLabel(this);
	m_pLabeldot3 = new QLabel(this);

	m_pIPPart1->setGeometry(QRect(0, 0, 44, 28));
	m_pIPPart2->setGeometry(QRect(44, 0, 44, 28));
	m_pIPPart3->setGeometry(QRect(88, 0, 44, 28));
	m_pIPPart4->setGeometry(QRect(132, 0, 44, 28));

	m_pIPPart1->setFont(font);
	m_pIPPart2->setFont(font);
	m_pIPPart3->setFont(font);
	m_pIPPart4->setFont(font);

	m_pLabeldot1->setText(" .");
	m_pLabeldot1->setFont(font);
	m_pLabeldot1->setGeometry(QRect(41, 5, 6, 18));
	m_pLabeldot1->setAlignment(Qt::AlignCenter);
	 
	m_pLabeldot2->setText(" .");
	m_pLabeldot2->setFont(font);
	m_pLabeldot2->setGeometry(QRect(85, 5, 6, 18));
	m_pLabeldot2->setAlignment(Qt::AlignCenter);

	m_pLabeldot3->setText(" .");
	m_pLabeldot3->setFont(font);
	m_pLabeldot3->setGeometry(QRect(129, 5, 6, 18));
	m_pLabeldot3->setAlignment(Qt::AlignCenter);

	QWidget::setTabOrder(m_pIPPart1, m_pIPPart2);//定义切换焦点顺序
	QWidget::setTabOrder(m_pIPPart2, m_pIPPart3);
	QWidget::setTabOrder(m_pIPPart3, m_pIPPart4);

	m_pIPPart1->set_nexttab_edit(m_pIPPart1, m_pIPPart2);
	m_pIPPart2->set_nexttab_edit(m_pIPPart2, m_pIPPart3);
	m_pIPPart3->set_nexttab_edit(m_pIPPart3, m_pIPPart4);

	m_pIPPart2->set_prevtab_edit(m_pIPPart2, m_pIPPart1);
	m_pIPPart3->set_prevtab_edit(m_pIPPart3, m_pIPPart2);
	m_pIPPart4->set_prevtab_edit(m_pIPPart4, m_pIPPart3);

	connect(m_pIPPart1, SIGNAL(textChanged(const QString&)), this, SLOT(textchangedslot(const QString&)));
	connect(m_pIPPart2, SIGNAL(textChanged(const QString&)), this, SLOT(textchangedslot(const QString&)));
	connect(m_pIPPart3, SIGNAL(textChanged(const QString&)), this, SLOT(textchangedslot(const QString&)));
	connect(m_pIPPart4, SIGNAL(textChanged(const QString&)), this, SLOT(textchangedslot(const QString&)));

	connect(m_pIPPart1, SIGNAL(textEdited(const QString&)), this, SLOT(texteditedslot(const QString&)));
	connect(m_pIPPart2, SIGNAL(textEdited(const QString&)), this, SLOT(texteditedslot(const QString&)));
	connect(m_pIPPart3, SIGNAL(textEdited(const QString&)), this, SLOT(texteditedslot(const QString&)));
	connect(m_pIPPart4, SIGNAL(textEdited(const QString&)), this, SLOT(texteditedslot(const QString&)));
 }

IPAddressEdit::~IPAddressEdit()
{
}

void IPAddressEdit::settext(const QString &text)
{
 	QString ippart1 = "", ippart2 ="", ippart3 = "", ippart4 = "";
	QString qstring_validate = text;

	// IP地址验证  
	QRegExp regexp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
	QRegExpValidator regexp_validator(regexp, this);
	
	int nPos = 0;
	QValidator::State state = regexp_validator.validate(qstring_validate, nPos);
	
	// IP合法  
	if (state == QValidator::Acceptable)
	{
		QStringList ippartlist = text.split(".");

		int strcount = ippartlist.size();
		int index = 0;

		if (index < strcount)
			ippart1 = ippartlist.at(index);

		if (++index < strcount)
			ippart2 = ippartlist.at(index);

		if (++index < strcount)
			ippart3 = ippartlist.at(index);

		if (++index < strcount)
			ippart4 = ippartlist.at(index);
	}

	m_pIPPart1->setText(ippart1);
	m_pIPPart2->setText(ippart2);
	m_pIPPart3->setText(ippart3);
	m_pIPPart4->setText(ippart4);
 }

QString IPAddressEdit::text()
{
	QString ippart1, ippart2, ippart3, ippart4;
	ippart1 = m_pIPPart1->text();
	ippart2 = m_pIPPart2->text();
	ippart3 = m_pIPPart3->text();
	ippart4 = m_pIPPart4->text();

	return QString("%1.%2.%3.%4").arg(ippart1).arg(ippart2).arg(ippart3).arg(ippart4);
}

void IPAddressEdit::getIp(QString& ip1, QString& ip2, QString& ip3, QString& ip4)
{
	ip1 = m_pIPPart1->text();
	ip2 = m_pIPPart2->text();
	ip3 = m_pIPPart3->text();
	ip4 = m_pIPPart4->text();
}

void IPAddressEdit::setStyleSheet(const QString &styleSheet)
{
	m_pIPPart1->setStyleSheet(styleSheet);
	m_pIPPart2->setStyleSheet(styleSheet);
	m_pIPPart3->setStyleSheet(styleSheet);
	m_pIPPart4->setStyleSheet(styleSheet);
}
 
void IPAddressEdit::textchangedslot(const QString& text)
{
	QString ippart1, ippart2, ippart3, ippart4;
	ippart1 = m_pIPPart1->text();
	ippart2 = m_pIPPart2->text();
	ippart3 = m_pIPPart3->text();
	ippart4 = m_pIPPart4->text();

	QString ipaddr = QString("%1.%2.%3.%4").arg(ippart1).arg(ippart2).arg(ippart3).arg(ippart4);

	emit textchanged(ipaddr);
}

void IPAddressEdit::texteditedslot(const QString &text)
{
	QString ippart1="", ippart2="", ippart3="", ippart4="";

	ippart1 = m_pIPPart1->text();
	ippart2 = m_pIPPart2->text();
	ippart3 = m_pIPPart3->text();
	ippart4 = m_pIPPart4->text();

	QString ipaddr = QString("%1.%2.%3.%4").arg(ippart1).arg(ippart2).arg(ippart3).arg(ippart4);

	emit textedited(ipaddr);
}



