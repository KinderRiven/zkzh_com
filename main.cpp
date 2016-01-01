#include "comport.h"
#include "headFile.h"

#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	comPort w;
	w.show();

	return a.exec();
}
