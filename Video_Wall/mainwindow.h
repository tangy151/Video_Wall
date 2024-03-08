#ifndef		_MAIN_WINDOW_H_
#define	_MAIN_WINDOW_H_

#include <QMainWindow>
#include <memory>
#include <stdio.h>

#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QWidgetAction>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QDesktopWidget>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtCore/QCoreApplication>

#include <QCheckBox>

#include <QMainWindow>
#include <memory>
#include <stdio.h>

//#include "Ptr.h"
//#include "Context.h"

class QSplitter;

class VirtualAreaUtilWindow;
class VideoAreaUtilWindow;

class MonitorAreaUtilWindow;
class ChannelAreaUtilWindow;
class SelectMediaSourceWindow;

class VideoSourceEditroWindow;
class PlayListEditorWindow;
class PictureEditorWindow;
class LocalStreamEditorWindow;
class IPStreamEditorWindow;

class MainWindow
	: public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

protected:

	void CreatePreviewWindows();
	void CreateEditroWindow();

	void CreateMenuBar();
	void CreateActions();

	void InitConnects();


public:
	void SetApplicationObject(QObject* pObject);


protected:
	void resizeEvent(QResizeEvent* pEvent);
	//void closeEvent(QCloseEvent *pEvent);


public slots:
	void	OnActNew();
	void	OnActOpen();
	void	OnActSave();
	void	OnActSaveAs();
	void	OnActQuit();

	void	OnActPic1();
	void	OnActPic2();
	void	OnActLogo1();
	void	OnActLogo2();
	void	OnActTimer();
	void	OnActSubtitles();

	void	OnActFullScreen();

	void	OnActMedia();
	void	OnActSetting();
	void	OnActInputData();

	void	OnActAbout();


protected:
 
	std::unique_ptr<QToolBar>				m_ptrTopToolBar;

	std::unique_ptr<QMenuBar>				m_ptrMenuBar;


	std::unique_ptr<QMenu>				m_ptrMenuFile;
	std::unique_ptr<QMenu>				m_ptrMenuEidt;
	std::unique_ptr<QMenu>				m_ptrMenuLook;
	std::unique_ptr<QMenu>				m_ptrMenuTool;
	std::unique_ptr<QMenu>				m_ptrMenuHelp;

	std::unique_ptr<QAction>				m_ptrActNew;
	std::unique_ptr<QAction>				m_ptrActOpen;
	std::unique_ptr<QAction>				m_ptrActSave;
	std::unique_ptr<QAction>				m_ptrActSaveAs;
	std::unique_ptr<QAction>				m_ptrActQuit;

	std::unique_ptr<QAction>				m_ptrActPic1;
	std::unique_ptr<QAction>				m_ptrActPic2;
	std::unique_ptr<QAction>				m_ptrActLogo1;
	std::unique_ptr<QAction>				m_ptrActLogo2;
	std::unique_ptr<QAction>				m_ptrActTimer;
	std::unique_ptr<QAction>				m_ptrActSubtitles;

	std::unique_ptr<QAction>				m_ptrActFullScreen;

	std::unique_ptr<QAction>				m_ptrActMedia;
	std::unique_ptr<QAction>				m_ptrActSetting;
	std::unique_ptr<QAction>				m_ptrActInputData;

	std::unique_ptr<QAction>				m_ptrActAbout;



	std::unique_ptr<QSplitter>				m_ptrMainSplitter;
	std::unique_ptr<QSplitter>				m_ptrTopSplitter;



	std::unique_ptr<VirtualAreaUtilWindow>		m_ptrVirtualAreaUtilWindow;
	std::unique_ptr<VideoAreaUtilWindow>		m_ptrVideoAreaUtilWindow;

	std::unique_ptr<MonitorAreaUtilWindow>			m_ptrMonitorManagerWindow;
	std::unique_ptr<ChannelAreaUtilWindow>			m_ptrChannelManagerWindow;

	std::unique_ptr<VideoSourceEditroWindow>		m_ptrVideoSourceEditroWindow;
	std::unique_ptr<PlayListEditorWindow>				m_ptrPlayListEditorWindow;
	std::unique_ptr<PictureEditorWindow>					m_ptrPictureEditorWindow;
	std::unique_ptr<LocalStreamEditorWindow>			m_ptrLocalStreamEditorWindow;
	std::unique_ptr<IPStreamEditorWindow>				m_ptrIPStreamEditorWindow;


private:
	QString					m_strExePath;
	QTabWidget*			m_pEditorTab;

 };

extern MainWindow*	g_ptrMainWindow;
 
#endif//_MAIN_WINDOW_H_
