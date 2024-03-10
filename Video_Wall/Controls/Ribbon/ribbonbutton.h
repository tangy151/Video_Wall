#ifndef		_RIBBON_BUTTON_H_
#define		_RIBBON_BUTTON_H_

#include <QAction>
#include <QToolButton>
#include <memory>

class RibbonButton 
	: public QToolButton
{ 
public:
	RibbonButton();
	RibbonButton(QAction* action);
 
public:
	void InitLarge();
	void InitMedium();
	void InitSmall(bool wide = false);
	void MakeLarge();
	void MakeMedium();
	void MakeSmall(bool wide = false);
	void MakeRegular();

	QSize GetSizeForType(int btnType) const;

	void SetWeight(float value)
	{
		m_fWeight = value;
	}
	
	float GetWeight() const
	{
		return m_fWeight;
	}

	int GetDesiredButtonType() const
	{
		return m_iButtonType;
	}

	bool IsWide() const
	{
		return m_bIsWide;
	}

private:
	float			m_fWeight = 1.0f;
	bool			m_bIsWide = false;
	int			m_iButtonType = 0; // default as Large

};


#endif//_RIBBON_BUTTON_H_


