#ifndef		_IPADDRESS_EDIT_H_
#define		_IPADDRESS_EDIT_H_

#include <QWidget>

class QLineEdit;
class QLabel; 
class IPAddressLineEdit;



class IPAddressEdit 
	: public QWidget
{
	Q_OBJECT

public:
	IPAddressEdit(QWidget *parent);
	~IPAddressEdit();

public:
	void settext(const QString &text);
	QString text();
	void getIp(QString& ip1, QString& ip2, QString& ip3, QString& ip4);
	void setStyleSheet(const QString &styleSheet);



signals:
	void textchanged(const QString& text);
	void textedited(const QString &text);

private slots:
	void textchangedslot(const QString& text);
	void texteditedslot(const QString &text);

private:
	IPAddressLineEdit*		m_pIPPart1;
	IPAddressLineEdit*		m_pIPPart2;
	IPAddressLineEdit*		m_pIPPart3;
 	IPAddressLineEdit*		m_pIPPart4;
	 

	QLabel*		m_pLabeldot1;
	QLabel*		m_pLabeldot2;
	QLabel*		m_pLabeldot3;


};



#endif//_IPADDRESS_EDIT_H_

