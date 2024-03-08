#ifndef		_IP_ADDRESS_LINE_EDIT_H_
#define		_IP_ADDRESS_LINE_EDIT_H_

#include <QLineEdit>
 
class QWidget;
class QFocusEvent;
class QKeyEvent;
 
class IPAddressLineEdit 
	: public QLineEdit
{
	Q_OBJECT

public:
	IPAddressLineEdit(QWidget *parent);
	~IPAddressLineEdit();

public:

	void set_prevtab_edit(QLineEdit* pCurrentTab, QLineEdit* pPrevTab);
	void set_nexttab_edit(QLineEdit* pCurrentTab, QLineEdit* pNextTab);

public:

	virtual void focusInEvent(QFocusEvent* pEvent);
	virtual void keyPressEvent(QKeyEvent* pEvent);

private slots:
	void text_edited(const QString& strText);

private:
	QLineEdit*		m_pCurrentTab;
	QLineEdit*		m_pPrevTab;
	QLineEdit*		m_pNextTab;



};


#endif//_IP_ADDRESS_LINE_EDIT_H_
