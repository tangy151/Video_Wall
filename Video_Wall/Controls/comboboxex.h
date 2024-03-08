#ifndef		_COMBO_BOX_H_
#define		_COMBO_BOX_H_

#include <QComboBox>

class ComboBoxEx 
	: public QComboBox
{
	Q_OBJECT

		Q_PROPERTY(int itemWidth READ getItemWidth WRITE setItemWidth)
		Q_PROPERTY(int itemHeight READ getItemHeight WRITE setItemHeight)
		Q_PROPERTY(bool autoWidth READ getAutoWidth WRITE setAutoWidth)
		 
public:
	explicit ComboBoxEx(QWidget *parent = 0);

protected:
	void showEvent(QShowEvent *);
	 
public:
	int getItemWidth()	const;
	int getItemHeight()	const;
	bool getAutoWidth()	const;


public Q_SLOTS:
	void setItemWidth(int itemWidth);
	void setItemHeight(int itemHeight);
	void setAutoWidth(bool autoWidth);

private:
	int		m_iItemWidth;			//Ԫ�ؿ��
	int		m_iItemHeight;			//Ԫ�ظ߶�
	bool		m_bAutoWidth;			//�Ƿ��Զ�����Ԫ�ؿ��
	int		m_iMaxItemWidth;	//���Ԫ�ؿ��
};


#endif//_COMBO_BOX_H_

