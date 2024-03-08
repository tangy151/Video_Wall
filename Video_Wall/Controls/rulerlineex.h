#ifndef			_RULER_LINE_EX_H_
#define		_RULER_LINE_EX_H_

#include <QWidget>

class RulerLineEx 
		: public QWidget
 {
	Q_OBJECT
		Q_ENUMS(ScaleStyle)
		Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
		Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
		Q_PROPERTY(double value READ getValue WRITE setValue)
		Q_PROPERTY(double alarmValue READ getAlarmValue WRITE setAlarmValue)

		Q_PROPERTY(double minValueRight READ getMinValueRight WRITE setMinValueRight)
		Q_PROPERTY(double maxValueRight READ getMaxValueRight WRITE setMaxValueRight)
		Q_PROPERTY(double valueRight READ getValueRight WRITE setValueRight)
		Q_PROPERTY(double alarmValueRight READ getAlarmValueRight WRITE setAlarmValueRight)

		Q_PROPERTY(int longStep READ getLongStep WRITE setLongStep)
		Q_PROPERTY(int shortStep READ getShortStep WRITE setShortStep)
		Q_PROPERTY(int longStepRight READ getLongStepRight WRITE setLongStepRight)
		Q_PROPERTY(int shortStepRight READ getShortStepRight WRITE setShortStepRight)

		Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
		Q_PROPERTY(QColor scaleColor READ getScaleColor WRITE setScaleColor)
		Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
		Q_PROPERTY(QColor alarmScaleColor READ getAlarmScaleColor WRITE setAlarmScaleColor)

		Q_PROPERTY(int space READ getSpace WRITE setSpace)
		Q_PROPERTY(ScaleStyle scaleStyle READ getScaleStyle WRITE setScaleStyle)

public:
	enum ScaleStyle 
	{
		ScaleStyle_Single = 0,    //������
		ScaleStyle_Double = 1     //˫����
	};

	explicit RulerLineEx(QWidget *parent = 0);

protected:
	void paintEvent(QPaintEvent *);
	void drawBg(QPainter *painter);
	void drawLeftScale(QPainter *painter);
	void drawRightScale(QPainter *painter);
	void drawLeftText(QPainter *painter);
	void drawRightText(QPainter *painter);
	void drawLeftPointer(QPainter *painter);
	void drawRightPointer(QPainter *painter);

private:
	double minValue;                //��Сֵ
	double maxValue;                //���ֵ
	double value;                   //Ŀ��ֵ
	double alarmValue;              //�澯ֵ

	double maxValueRight;           //�ұ���Сֵ
	double minValueRight;           //�ұ����ֵ
	double valueRight;              //�ұ�Ŀ��ֵ
	double alarmValueRight;         //�ұ߸澯ֵ

	int longStep;                   //�������ȷֲ���
	int shortStep;                  //�������ȷֲ���
	int longStepRight;              //�ұ߳������ȷֲ���
	int shortStepRight;             //�ұ߶������ȷֲ���

	QColor bgColor;                 //����ɫ
	QColor scaleColor;              //�̶���ɫ
	QColor textColor;               //������ɫ
	QColor alarmScaleColor;         //�澯�̶���ɫ

	int space;                      //���
	ScaleStyle scaleStyle;          //�̶ȱ����ʽ

public:
	double getMinValue()            const;
	double getMaxValue()            const;
	double getValue()               const;
	double getAlarmValue()          const;

	double getMinValueRight()       const;
	double getMaxValueRight()       const;
	double getValueRight()          const;
	double getAlarmValueRight()     const;

	int getLongStep()               const;
	int getShortStep()              const;
	int getLongStepRight()          const;
	int getShortStepRight()         const;

	QColor getBgColor()             const;
	QColor getScaleColor()          const;
	QColor getTextColor()           const;
	QColor getAlarmScaleColor()     const;

	int getSpace()                  const;
	ScaleStyle getScaleStyle()      const;

	QSize sizeHint()                const;
	QSize minimumSizeHint()         const;

public Q_SLOTS:
	//���÷�Χֵ
	void setRange(double minValue, double maxValue);
	void setRange(int minValue, int maxValue);
	void setRangeRight(double minValueRight, double maxValueRight);
	void setRangeRight(int minValueRight, int maxValueRight);

	//���������Сֵ
	void setMinValue(double minValue);
	void setMaxValue(double maxValue);
	void setMinValueRight(double minValue);
	void setMaxValueRight(double maxValue);

	//����Ŀ��ֵ
	void setValue(double value);
	void setValue(int value);
	void setValueRight(double valueRight);
	void setValueRight(int valueRight);

	//���þ���ֵ
	void setAlarmValue(double alarmValue);
	void setAlarmValueRight(double alarmValueRight);

	//���������ȷֲ���
	void setLongStep(int longStep);
	void setShortStep(int shortStep);
	void setLongStepRight(int longStepRight);
	void setShortStepRight(int shortStepRight);

	//���ñ���ɫ
	void setBgColor(const QColor &bgColor);
	//���ÿ̶���ɫ
	void setScaleColor(const QColor &scaleColor);
	//�����ı���ɫ
	void setTextColor(const QColor &textColor);
	//���ø澯�̶���ɫ
	void setAlarmScaleColor(const QColor &alarmScaleColor);

	//���ü��
	void setSpace(int space);
	//���ÿ̶���ʽ
	void setScaleStyle(const ScaleStyle &scaleStyle);
};

#endif//_RULER_LINE_EX_H_
