#ifndef		_RIBBON_H_
#define		_RIBBON_H_

#include <QAbstractButton>
#include <QPushButton>
#include <QTabWidget>
#include <QWidget>
#include <memory>
#include <vector>
#include <QTabWidget>

class RibbonPage;
 

class Ribbon 
	: public QTabWidget

{
	Q_OBJECT

public:
	Ribbon(QWidget* parent = nullptr);
	virtual ~Ribbon();


public:
	void AddPage(RibbonPage* page);
	RibbonPage* GetCurrentPage()
	{
		return (RibbonPage*)currentWidget();
	}

	RibbonPage* GetPage(unsigned index);
	void RemovePage(RibbonPage* page);

	QPushButton* GetSettingsButton()
	{
		return m_pSettingsButton;
	}
	QPushButton* GetApplicationButton()
	{
		return m_pApplicationButton;
	}
	QPushButton* GetDocumentButton()
	{
		return m_pDocumentButton;
	}

	bool IsAutoHide() {
		return m_bAutoHide;
	}
	void SetAutoHide(bool state);



signals:
	void PageAdded(RibbonPage* page);
	void PageRemoved(RibbonPage* page);
	void ApplicationButtonClicked();

public slots:
	void SetRibbonDisplayed(bool state);

private slots:
	void PageActivityChanged(RibbonPage* page);
	void TabClicked(int index);
	void HandleApplicationButton(bool);


private:
	std::vector<RibbonPage*> m_vecAllPages;
	QAbstractButton*		m_pToggleRibbon;
	QPushButton*			m_pSettingsButton;
	QPushButton*			m_pApplicationButton;
	QPushButton*			m_pDocumentButton;

	/// Whether to automatically collapse the ribbon.
	bool				m_bAutoHide = false;
	int				m_bOldHeight = 0;
};



#endif//_RIBBON_H_


