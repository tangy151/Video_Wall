#include "searchlineedit.h"
#include "../headfiledefine.h"
 

SearchLineEdit::SearchLineEdit()
{

}

SearchLineEdit::~SearchLineEdit()
{

}

void SearchLineEdit::focusInEvent(QFocusEvent* pEvent)
{
	QLineEdit::focusInEvent(pEvent);
	selectAll();
	justGotFocus_ = true;
}

void SearchLineEdit::keyReleaseEvent(QKeyEvent* pEvent)
{
	if (pEvent->key() == Qt::Key::Key_Enter || pEvent->key() == Qt::Key::Key_Return)
	{
		emit SearchPerformed();
		pEvent->accept();
	}
	else
	{
		QLineEdit::keyReleaseEvent(pEvent);
 	}
}

void SearchLineEdit::mousePressEvent(QMouseEvent* pEvent)
{
	if (!hasFocus() || justGotFocus_)
	{
		pEvent->accept();
		selectAll();
		justGotFocus_ = false;
	}
	else
	{
		QLineEdit::mousePressEvent(pEvent);
 	}
}

void SearchLineEdit::mouseReleaseEvent(QMouseEvent* pEvent)
{
	if (!hasFocus())
	{
		pEvent->accept();
 	}
	else
	{
		QLineEdit::mouseReleaseEvent(pEvent);
 	}
}






