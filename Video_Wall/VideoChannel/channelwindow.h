#ifndef		_CHANNEL_WINDOW_H_
#define _CHANNEL_WINDOW_H_

 
#include <memory>
#include <QWidget>

class PreviewWindow;
class QLabel;


class ChannelWindow 
	: public QWidget
{
	Q_OBJECT

public:
	ChannelWindow(QWidget *parent);
	~ChannelWindow();

protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent* pEvent);

protected:
	void InitUI();

public:
	void SetChannelIndex(int iChannelIndex);

private:
	int		m_iChannelIndex;


 	std::unique_ptr<PreviewWindow>	m_ptPreviewWindow;
	std::unique_ptr<QLabel>				m_ptrTitleLabel;

};  


#endif//_CHANNEL_WINDOW_H_
