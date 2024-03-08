#ifndef		_ICON_HELPER_H_
#define _ICON_HELPER_H_


#include <QtCore>
#include <QtGui>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#endif
#include <QObject>

//ͼ�����崦����
class IconHelper : public QObject
{
	Q_OBJECT

public:
	static IconHelper *Instance();
	explicit IconHelper(QObject *parent = 0);

	void setIcon(QLabel *lab, const QChar &str, quint32 size = 12);
	void setIcon(QAbstractButton *btn, const QChar &str, quint32 size = 12);
	QPixmap getPixmap(const QColor &color, const QChar &str, quint32 size = 12,
		quint32 pixWidth = 15, quint32 pixHeight = 15,
		int flags = Qt::AlignCenter);

	//���ݰ�ť��ȡ�ð�ť��Ӧ��ͼ��
	QPixmap getPixmap(QToolButton *btn, bool normal);

	//ָ�����������ʽ,����ͼ��
	static void setStyle(QWidget *widget, const QString &type = "left", int borderWidth = 3,
		const QString &borderColor = "#029FEA",
		const QString &normalBgColor = "#292F38",
		const QString &darkBgColor = "#1D2025",
		const QString &normalTextColor = "#54626F",
		const QString &darkTextColor = "#FDFDFD");

	//ָ�����������ʽ,��ͼ���Ч���л�
	void setStyle(QWidget *widget, QList<QToolButton *> btns, QList<int> pixChar,
		quint32 iconSize = 12, quint32 iconWidth = 15, quint32 iconHeight = 15,
		const QString &type = "left", int borderWidth = 3,
		const QString &borderColor = "#029FEA",
		const QString &normalBgColor = "#292F38",
		const QString &darkBgColor = "#1D2025",
		const QString &normalTextColor = "#54626F",
		const QString &darkTextColor = "#FDFDFD");

	//ָ��������ť��ʽ,��ͼ���Ч���л�
	void setStyle(QFrame *frame, QList<QToolButton *> btns, QList<int> pixChar,
		quint32 iconSize = 12, quint32 iconWidth = 15, quint32 iconHeight = 15,
		const QString &normalBgColor = "#2FC5A2",
		const QString &darkBgColor = "#3EA7E9",
		const QString &normalTextColor = "#EEEEEE",
		const QString &darkTextColor = "#FFFFFF");

protected:
	bool eventFilter(QObject *watched, QEvent *event);

private:
	static QScopedPointer<IconHelper> self;
	QFont iconFont;             //ͼ������
	QList<QToolButton *> btns;  //��ť����
	QList<QPixmap> pixNormal;   //����ͼƬ����
	QList<QPixmap> pixDark;     //����ͼƬ����
};

#endif//_ICON_HELPER_H_

