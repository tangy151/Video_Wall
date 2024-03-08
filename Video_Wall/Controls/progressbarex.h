#ifndef		_PROGRESS_BAR_EX_H_
#define		_PROGRESS_BAR_EX_H_
 
#include <QWidget>

class ProgressBarEx 
	: public QWidget
{
	Q_OBJECT
		Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
		Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)

		Q_PROPERTY(double value READ getValue WRITE setValue)
		Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)

		Q_PROPERTY(double step READ getStep WRITE setStep)
		Q_PROPERTY(double space READ getSpace WRITE setSpace)
 
		Q_PROPERTY(QColor bgColorStart READ getBgColorStart WRITE setBgColorStart)
		Q_PROPERTY(QColor bgColorEnd READ getBgColorEnd WRITE setBgColorEnd)
		 
		Q_PROPERTY(QColor barFrameColor READ getBarFrameColor WRITE setBarFrameColor)
		Q_PROPERTY(QColor barBgColor READ getBarBgColor WRITE setBarBgColor)
		 

		Q_PROPERTY(QColor barColor READ getBarColor WRITE setBarColor)

public:
	explicit	ProgressBarEx(QWidget *parent = nullptr);
 
protected:
	void paintEvent(QPaintEvent *);
	void drawBg(QPainter *painter);
	void drawBar(QPainter *painter);
	void drawBar2(QPainter *painter);

	 
public:
	double getMinValue()	const;
	double getMaxValue()	const;
	double getValue()	const;
	int getPrecision()	const;

	int getStep()	const;
	int getSpace()	const;
 
	QColor getBgColorStart()const;
	QColor getBgColorEnd()	const;
	 
	QColor getBarFrameColor()const;
	QColor getBarBgColor()	const;
  	QColor getBarColor()	const;

	QSize sizeHint()	const;
	QSize minimumSizeHint()	const;
	 

public Q_SLOTS:
	//���÷�Χֵ
	void setRange(double minValue, double maxValue);
	void setRange(int minValue, int maxValue);

	//���������Сֵ
	void setMinValue(double minValue);
	void setMaxValue(double maxValue);

	//����Ŀ��ֵ
	void setValue(double value);
	void setValue(int value);

	//���þ�ȷ��
	void setPrecision(int precision);

	//���ò���
	void setStep(int step);
	//���ü��
	void setSpace(int space);
  
	//���ñ�����ɫ
	void setBgColorStart(const QColor &bgColorStart);
	void setBgColorEnd(const QColor &bgColorEnd);
	  
	//���ý�����ɫ
	void setBarFrameColor(QColor barBgColor);
	void setBarBgColor(QColor barBgColor);
 	void setBarColor(QColor barColor);

Q_SIGNALS:
	void valueChanged(double value);

public:
	void OnTransparent(bool bOk)
	{
		m_bTransparent = bOk;
	}

private:

	bool				m_bTransparent;


private:
	double minValue;	//��Сֵ
	double maxValue;	//���ֵ
	double value;			//Ŀ��ֵ

	int		precision;		//��ȷ��,С�����λ

	int		step;		//����
	int		space;	//���
 
	QColor		m_iBgColorStart;	//�������俪ʼ��ɫ
	QColor		m_iBgColorEnd;	//�������������ɫ
  
	QColor		m_iBarFrameColor;	//�߿���ɫ
	QColor		m_iBarBgColor;		//������ɫ

	QColor		m_iBarBKColor;		//������ɫ


	QColor		m_iBarColor;		//������ɫ
	 
};


#endif//_PROGRESS_BAR_EX_H_
