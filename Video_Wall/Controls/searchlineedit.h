#ifndef		_SEARCH_LINE_EDIT_H_
#define		_SEARCH_LINE_EDIT_H_


#include <QLineEdit>

class SearchLineEdit : public QLineEdit
{
	Q_OBJECT

public:
	SearchLineEdit();
	virtual ~SearchLineEdit();

signals:
	void SearchPerformed();

protected:
	virtual void mousePressEvent(QMouseEvent*) override;
	virtual void mouseReleaseEvent(QMouseEvent*) override;
	virtual void focusInEvent(QFocusEvent* pEvent) override;
	virtual void keyReleaseEvent(QKeyEvent*) override;

protected:
	bool justGotFocus_ = false;


};



#endif//_SEARCH_LINE_EDIT_H_

