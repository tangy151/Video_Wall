#ifndef		_RIBBON_SECTION_H_
#define		_RIBBON_SECTION_H_

#include <QAbstractButton>
#include <QBoxLayout>
#include <QLabel>
#include <QWidget>
#include <memory>

class RibbonSection
	: public QWidget
{
	Q_OBJECT

public:
	RibbonSection(const QString& title);
	virtual ~RibbonSection();


public:
	QHBoxLayout* GetContentLayout()
	{
		return m_pContentLayout;
	}

	QVBoxLayout* GetMainLayout()
	{
		return m_pMainLayout;
	}

	QLabel* GetTitleLabel()
	{
		return m_pTitleLabel;
	}

 	void AddWidgets(QWidget* a, QWidget* b = 0x0, QWidget* c = 0x0);
  	void AddQuad(QWidget* topLeft, QWidget* bottomLeft, QWidget* topRight, QWidget* bottomRight);

protected:
 	QWidget*					m_pExpansionWidget;

 	QAbstractButton*		m_pExpandButton;

 	QLabel*					m_pTitleLabel;

 	QHBoxLayout*			m_pContentLayout;
  	QVBoxLayout*			m_pMainLayout;
 
};



#endif//_RIBBON_SECTION_H_
