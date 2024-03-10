#ifndef		_RIBBON_PAGE_H_
#define		_RIBBON_PAGE_H_
 
#include <QAbstractButton>
#include <QBoxLayout>
#include <QIcon>
#include <QWidget>
#include <memory>
#include <vector>

class RibbonSection;
  class Ribbon;
class RibbonPage
	: public QWidget
{
	Q_OBJECT;

//	friend class Ribbon;

public:
	RibbonPage(const QString& pageTitle);
	virtual ~RibbonPage();


public:
	QString GetPageLabel()
	{
		return m_strPageLabel;
	}

	void AddSection(RibbonSection* section);
	RibbonSection* GetSection(unsigned index);
	RibbonSection* RemoveSection(unsigned index);
	RibbonSection* RemoveSection(RibbonSection* section);

	void SetPageTitle(const QString& title);
	QString GetPageTitle() const
	{
		return m_strPageTitle;
	}

	bool IsActive()
	{
		return m_bActive;
	}
	void SetActive(bool state);


signals:
	void ActiveChanged(RibbonPage* self);


private:
	bool m_bActive = true;

	QString m_strPageTitle;

	Ribbon* m_pRibbon  ;

	QColor m_iPageTabColor;

	QIcon m_iPageIcon;

	QString m_strPageLabel;

	QHBoxLayout*								m_pSectionsLayout;

	std::vector<RibbonSection*>		m_vecSections;

	QAbstractButton*						m_pRibbonCollapseButton;
};


#endif//_RIBBON_PAGE_H_
