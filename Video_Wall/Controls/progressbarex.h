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
	//设置范围值
	void setRange(double minValue, double maxValue);
	void setRange(int minValue, int maxValue);

	//设置最大最小值
	void setMinValue(double minValue);
	void setMaxValue(double maxValue);

	//设置目标值
	void setValue(double value);
	void setValue(int value);

	//设置精确度
	void setPrecision(int precision);

	//设置步长
	void setStep(int step);
	//设置间距
	void setSpace(int space);
  
	//设置背景颜色
	void setBgColorStart(const QColor &bgColorStart);
	void setBgColorEnd(const QColor &bgColorEnd);
	  
	//设置进度颜色
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
	double minValue;	//最小值
	double maxValue;	//最大值
	double value;			//目标值

	int		precision;		//精确度,小数点后几位

	int		step;		//步长
	int		space;	//间距
 
	QColor		m_iBgColorStart;	//背景渐变开始颜色
	QColor		m_iBgColorEnd;	//背景渐变结束颜色
  
	QColor		m_iBarFrameColor;	//边框颜色
	QColor		m_iBarBgColor;		//背景颜色

	QColor		m_iBarBKColor;		//背景颜色


	QColor		m_iBarColor;		//进度颜色
	 
};


#endif//_PROGRESS_BAR_EX_H_
