#include "application.h"

Application::Application(int &argc, char *argv[])
	: QApplication(argc, argv)
{
}

bool Application::notify(QObject *receiver, QEvent *event)
{
	return QApplication::notify(receiver, event);

	try
	{
		return QApplication::notify(receiver, event);
	}
	catch (const std::exception &e)
	{
		std::string error("Application::notify caught an exception: " + std::string(e.what() ? e.what() : "(null)"));
		std::cout << error << std::endl;
		//throw;
	}
	catch (...)
	{
		std::string error("Application::notify caught an unknown exception!");
		std::cout << error << std::endl;
		//throw;
	}

	return false;
}